from django.http import JsonResponse, HttpResponse
from django.contrib.sessions.models import Session
from ..models import User
from .session_datas import fill_session_with_user_info, get_user_from_request

import base64
import io
import os
import qrcode

from django.http import HttpResponse
from pathlib import Path

def switch_double_auth(request):
    player = get_user_from_request(request)
    if not player:
        return JsonResponse({'error': 'user not found'}, status=200)
    try:
        state = request.POST.get('state')
        if state == '0':
            player.twoStepsActive = False
        else:
            player.twoStepsActive = True
        player.save()
        return JsonResponse({'status': 'success',
                             'new_state':state}, status=200)
    except:
        return JsonResponse({'error': 'error'}, status=200)



def check_double_auth(request):
    import pyotp

    username = request.POST.get('user')
    player = User.objects.filter(login=username).first()
    if not player:
        return JsonResponse({'error': 'error user not found'}, status=200)

    code = request.POST.get('code')
    totp = pyotp.TOTP(player.twoStepsCode)
    caller = request.POST.get('caller')
    if totp.verify(code):
        if caller == 'login':
            fill_session_with_user_info(request, player)

        return JsonResponse({'status': 'success',
                            'user': player.login,
                            'img': player.image_link,
                            'f2a': player.twoStepsActive}, status=200)
    else:
        return JsonResponse({'error': 'wrong code'}, status=200)


def get_saved_qr_code(request):
    import pyotp

    player = get_user_from_request(request)
    if not player:
        return JsonResponse({'error': 'error user not found'}, status=200)

    secret_key = player.twoStepsCode
    if not secret_key:
        secret_key = pyotp.random_base32()
        player.twoStepsCode = secret_key
        player.save()

    user_email = player.email  # ou tout autre identifiant utilisateur
    otp_uri = pyotp.totp.TOTP(secret_key).provisioning_uri(user_email, issuer_name='ft_transcendance')

    qr = qrcode.QRCode(version=1, error_correction=qrcode.constants.ERROR_CORRECT_L, box_size=10, border=4,)
    qr.add_data(otp_uri)
    qr.make(fit=True)
    img = qr.make_image(fill_color="black", back_color="white")
    buffer = io.BytesIO()
    img.save(buffer)
    img_base64 = base64.b64encode(buffer.getvalue()).decode()
    html_content = f'<img src="data:image/png;base64,{img_base64}" alt="QR Code">'

    return HttpResponse(html_content)
