from django.http import JsonResponse, HttpResponse
from django.contrib.sessions.models import Session
from ..models import User
from django.conf import settings
from django.shortcuts import render, redirect
import requests
from .session_datas import fill_session_with_user_info


def get_access_token(code):
    redirect_uri = "https://localhost/api/keeploging/index.html"

    token_url = 'https://api.intra.42.fr/oauth/token'
    data = {
        'grant_type': 'authorization_code',
        'client_id': settings.FORTYTWO_API_UID,
        'client_secret': settings.FORTYTWO_API_SECRET,
        'code': code,
        'redirect_uri': redirect_uri
    }
    response = requests.post(token_url, data=data)
    if response.status_code == 200:
        return response.json().get('access_token')
    else:
        return None



def connect_api42(request):
    redirect_uri = "https://localhost/api/keeploging/index.html"
    client_id = settings.FORTYTWO_API_UID

    auth_url = f'https://api.intra.42.fr/oauth/authorize?client_id={client_id}&redirect_uri={redirect_uri}&response_type=code'
    return redirect(auth_url)



def get_42_datas(request):
    code = request.GET.get('code')

    if code:
        access_token = get_access_token(code)

        if access_token:
            api_url = 'https://api.intra.42.fr/v2/me'
            headers = {'Authorization': f'Bearer {access_token}'}
            response = requests.get(api_url, headers=headers)

            if response.status_code == 200:
                user_info = response.json()
                image_link = user_info.get('image', {}).get('link', '')  # Get the image link
                # Vérifiez si l'utilisateur existe déjà dans la base de données
                user, created = User.objects.get_or_create(
                    login=user_info.get('login'),
                    defaults={
                        'id': user_info.get('id'),
                        'email': user_info.get('email'),
                        'first_name': user_info.get('first_name'),
                        'last_name': user_info.get('last_name'),
                        'image_link': image_link,
                        'loginWithApi': True
                    }
                )
                user.save()

                fill_session_with_user_info(request, user)

                return redirect("https://localhost/")

            else:
                return JsonResponse({
                    'status': 'error',
                    'message': 'Erreur d\'authentification avec l\'API de 42.'
                }, status=401)
        else:
            return JsonResponse({
					'status': 'error',
					'message': 'Erreur de verfification du token dans l\'API de 42.'
				}, status=402)

