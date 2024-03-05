from django.shortcuts import render, redirect
from django.http import JsonResponse, HttpResponse
from django.conf import settings
from django.core.mail import send_mail
from api42.forms import ContactUsForm
from django.contrib.sessions.models import Session

from .models import User
import requests
import json

def home_view(request):
    return HttpResponse("Bienvenue sur ma page d'accueil !")

def token_error_view(request):
    return render(request, 'token_error.html')

# def get_highscores(request):
#     data = list(User.objects.all().values().order_by('-score')[:10])
#     return JsonResponse(data, safe=False)


# def get_user_from_request(request):
#     session_key = request.COOKIES.get('sessionid')
#     # Retrieve session data from the database
#     try:
#         session = Session.objects.get(session_key=session_key)
#         session_data = session.get_decoded()

#         user_login = session_data.get('user')
#         if user_login is None:
#             return None

#         try:
#             user = User.objects.filter(login=user_login).first()
#             return user
#         except User.DoesNotExist:
#             return None

#     except Session.DoesNotExist:
#         return None



# def update_score(request):
#     player = get_user_from_request(request)
#     if not player:
#         return JsonResponse({'status': 'error user not found'}, status=200)

#     if request.method == 'POST':
#         new_score = request.POST.get('score')
#         won = request.POST.get('won')

#         player.score = player.score + new_score
#         if (won == 1):
#             player.wins_games = player.wins_games + 1
#         player.total_games = player.total_games + 1
#         player.save()

#         return JsonResponse({'status': 'success'}, status=200)
#     else:
#         return JsonResponse({'status': 'bad request'}, status=400)




# def get_session_data(request):
#     # Get session key from client-side cookies
#     session_key = request.COOKIES.get('sessionid')
#     # Retrieve session data from the database
#     try:
#         session = Session.objects.get(session_key=session_key)
#         session_data = session.get_decoded()
#         return JsonResponse(session_data)
#     except Session.DoesNotExist:
#         return JsonResponse({'error': 'Session not found'}, status=200)




# def remove_session_data(request):
#     # Get session key from client-side cookies
#     session_key = request.COOKIES.get('sessionid')
#     # Delete session data from the database
#     try:
#         session = Session.objects.get(session_key=session_key)
#         session.delete()
#         return JsonResponse({'message': 'Session deleted successfully'})
#     except Session.DoesNotExist:
#         return JsonResponse({'error': 'Session not found'}, status=200)




# def fill_session_with_user_info(request, user):
#     session = request.session
#     session['user'] = user.login
#     session['is_authenticated'] = True
#     session['img'] = user.image_link
#     session['id'] = user.id
#     session['email'] = user.email
#     session['first_name'] = user.first_name
#     session['last_name'] = user.last_name
#     session['score'] = user.score
#     session['win_games'] = user.win_games
#     session['total_games'] = user.total_games
#     session['loginWithApi'] = user.loginWithApi
#     session['nb_players'] = 1




# def connect_api42(request):
#     redirect_uri = "https://localhost/api/keeploging/index.html"
#     client_id = settings.FORTYTWO_API_UID

#     auth_url = f'https://api.intra.42.fr/oauth/authorize?client_id={client_id}&redirect_uri={redirect_uri}&response_type=code'
#     return redirect(auth_url)



# def get_42_datas(request):
#     code = request.GET.get('code')

#     if code:
#         access_token = get_access_token(code)

#         if access_token:
#             api_url = 'https://api.intra.42.fr/v2/me'
#             headers = {'Authorization': f'Bearer {access_token}'}
#             response = requests.get(api_url, headers=headers)

#             if response.status_code == 200:
#                 user_info = response.json()
#                 image_link = user_info.get('image', {}).get('link', '')  # Get the image link
#                 # Vérifiez si l'utilisateur existe déjà dans la base de données
#                 user, created = User.objects.get_or_create(
#                     login=user_info.get('login'),
#                     defaults={
#                         'id': user_info.get('id'),
#                         'email': user_info.get('email'),
#                         'first_name': user_info.get('first_name'),
#                         'last_name': user_info.get('last_name'),
#                         'image_link': image_link,
#                         'loginWithApi': True
#                     }
#                 )
#                 user.save()

#                 fill_session_with_user_info(request, user)

#                 return redirect("https://localhost/")

#             else:
#                 return JsonResponse({
#                     'status': 'error',
#                     'message': 'Erreur d\'authentification avec l\'API de 42.'
#                 }, status=401)
#         else:
#             return JsonResponse({
# 					'status': 'error',
# 					'message': 'Erreur de verfification du token dans l\'API de 42.'
# 				}, status=402)




# def get_access_token(code):
#     redirect_uri = "https://localhost/api/keeploging/index.html"

#     token_url = 'https://api.intra.42.fr/oauth/token'
#     data = {
#         'grant_type': 'authorization_code',
#         'client_id': settings.FORTYTWO_API_UID,
#         'client_secret': settings.FORTYTWO_API_SECRET,
#         'code': code,
#         'redirect_uri': redirect_uri
#     }
#     response = requests.post(token_url, data=data)
#     if response.status_code == 200:
#         return response.json().get('access_token')
#     else:
#         return None




# def normal_login(request):
#     # Get the user's login and password from the request
#     login = request.POST.get('username')
#     password = request.POST.get('password')
#     # Check if the user exists in the database
#     user = User.objects.filter(login=login).first()
#     if user:
#         if user.loginWithApi:
#             return JsonResponse({'error': 'api'}, status=200)
#         if user.password == password:

#             if user.twoStepsActive:
#                 return JsonResponse({'status': 'success',
#                                      'f2a': user.twoStepsActive}, status=200)

#             # Save the user's information in the session
#             fill_session_with_user_info(request, user)

#             return JsonResponse({'status': 'success',
#                                  'user': user.login,
#                                  'img': user.image_link,
#                                  'f2a': user.twoStepsActive}, status=200)
#         else:
#             return JsonResponse({'error': 'password'}, status=200)
#     # return an json message if the user does not exist
#     else:
#         return JsonResponse({'error': 'username'}, status=200)




# def multi_login(request):
#     login = request.POST.get('username')
#     password = request.POST.get('password')
#     no_player = request.POST.get('no_player')

#     session = request.session

#     user = User.objects.filter(login=login).first()
#     if not user:
#         return JsonResponse({'error': 'username'}, status=200)
#     if login == session.get('user'):
#         return JsonResponse({'error': 'already logged'}, status=200)
#     if user.loginWithApi:
#         return JsonResponse({'error': 'api'}, status=200)
#     if user.password != password:
#         return JsonResponse({'error': 'password'}, status=200)
#     # if user.twoStepsActive:
#     #     return JsonResponse({'status': 'success',
#     #                             'f2a': user.twoStepsActive}, status=200)

#     session = request.session
#     session['mp' + no_player + "_login"] = user.login
#     session['mp' + no_player + '_img'] = user.image_link



#     session['nb_players'] = session.get('nb_players', 0) + 1


#     player = {'login': login, "img: ": user.image_link}
#     # Ajouter le joueur à la liste des joueurs dans la session
#     if 'players' in request.session:
#         request.session['players'].append(player)
#     else:
#         request.session['players'] = [player]

#     return JsonResponse({'status': 'success',
#                             'user': user.login,
#                             'img': user.image_link,
#                             'score': user.score,
#                             'f2a': user.twoStepsActive,
#                             'nb_players':session.get('nb_players', 0)}, status=200)




# def multi_logout(request):
#     player_id = request.POST.get('no_player')

#     if player_id is not None:
#         player_id = int(player_id)

#     session = request.session
#     try:
#         if 'players' in session:
#             del session['players'][player_id]
#             session['nb_players'] = session.get('nb_players', 0) - 1
#     except:
#         return JsonResponse({'error': 'error'}, status=200)

#     return JsonResponse({'status': 'success',
#                          'nb_players':session.get('nb_players', 0),
#                          'id':player_id}, status=200)




# def get_multi_session_data(request):
#     # Vérifier si la liste des joueurs existe dans la session
#     if 'players' in request.session:
#         # Renvoyer les joueurs en JSON
#         return JsonResponse({'players': request.session['players']})
#     else:
#         # Renvoyer une liste vide si aucun joueur n'est dans la session
#         return JsonResponse({'players': []})



# def reset_multi(request):
#     # Supprimer la liste des joueurs de la session
#     if 'players' in request.session:
#         del request.session['players']
#     if 'nb_players' in request.session:
#         request.session['nb_players'] = 1
#     return JsonResponse({'status': 'success'}, status=200)



# def registerNewUser(request):
#     # Get the user's information from the request
#     login = request.POST.get('username')
#     email = request.POST.get('email')
#     password = request.POST.get('password')
#     firstname = request.POST.get('firstname')

#     # Check if the user already exists in the database
#     user = User.objects.filter(login=login).first()
#     if user:
#         return JsonResponse({'error': 'username'}, status=200)

#     # Check if the email already exists in the database
#     user = User.objects.filter(email=email).first()
#     if user:
#         return JsonResponse({'error': 'email'}, status=200)

#     # Create a new user in the database
#     user = User.objects.create(
#         login=login,
#         email=email,
#         password=password,
#         first_name=firstname,
#         loginWithApi=False,
#         image_link='./assets/anonymous-icon.png',
#     )
#     user.save()

#     # Save the user's information in the session
#     fill_session_with_user_info(request, user)

#     return JsonResponse({'status': 'success'}, status=200)




# import base64
# import io
# import os
# import qrcode

# from django.http import HttpResponse
# from pathlib import Path

# def switch_double_auth(request):
#     player = get_user_from_request(request)
#     if not player:
#         return JsonResponse({'error': 'user not found'}, status=200)
#     try:
#         state = request.POST.get('state')
#         if state == '0':
#             player.twoStepsActive = False
#         else:
#             player.twoStepsActive = True
#         player.save()
#         return JsonResponse({'status': 'success',
#                              'new_state':state}, status=200)
#     except:
#         return JsonResponse({'error': 'error'}, status=200)



# def check_double_auth(request):
#     import pyotp

#     username = request.POST.get('user')
#     player = User.objects.filter(login=username).first()
#     if not player:
#         return JsonResponse({'error': 'error user not found'}, status=200)

#     code = request.POST.get('code')
#     totp = pyotp.TOTP(player.twoStepsCode)
#     if totp.verify(code):
#         fill_session_with_user_info(request, player)

#         return JsonResponse({'status': 'success',
#                             'user': player.login,
#                             'img': player.image_link,
#                             'f2a': player.twoStepsActive}, status=200)
#     else:
#         return JsonResponse({'error': 'wrong code'}, status=200)


# def get_saved_qr_code(request):
#     import pyotp

#     player = get_user_from_request(request)
#     if not player:
#         return JsonResponse({'error': 'error user not found'}, status=200)

#     secret_key = player.twoStepsCode
#     if not secret_key:
#         secret_key = pyotp.random_base32()
#         player.twoStepsCode = secret_key
#         player.save()

#     user_email = player.email  # ou tout autre identifiant utilisateur
#     otp_uri = pyotp.totp.TOTP(secret_key).provisioning_uri(user_email, issuer_name='ft_transcendance')

#     qr = qrcode.QRCode(version=1, error_correction=qrcode.constants.ERROR_CORRECT_L, box_size=10, border=4,)
#     qr.add_data(otp_uri)
#     qr.make(fit=True)
#     img = qr.make_image(fill_color="black", back_color="white")
#     buffer = io.BytesIO()
#     img.save(buffer)
#     img_base64 = base64.b64encode(buffer.getvalue()).decode()
#     html_content = f'<img src="data:image/png;base64,{img_base64}" alt="QR Code">'

#     return HttpResponse(html_content)
