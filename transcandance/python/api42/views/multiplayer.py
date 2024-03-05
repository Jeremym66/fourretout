from django.http import JsonResponse, HttpResponse
from django.contrib.sessions.models import Session
from ..models import User


def get_multi_session_data(request):
    # Vérifier si la liste des joueurs existe dans la session
    if 'players' in request.session:
        # Renvoyer les joueurs en JSON
        return JsonResponse({'players': request.session['players']})
    else:
        # Renvoyer une liste vide si aucun joueur n'est dans la session
        return JsonResponse({'players': []})



def reset_multi(request):
    # Supprimer la liste des joueurs de la session
    if 'players' in request.session:
        del request.session['players']
    if 'nb_players' in request.session:
        request.session['nb_players'] = 1
    return JsonResponse({'status': 'success'}, status=200)



def multi_logout(request):
    player_id = request.POST.get('no_player')

    if player_id is not None:
        player_id = int(player_id)

    session = request.session
    try:
        if 'players' in session:
            del session['players'][player_id]
            session['nb_players'] = session.get('nb_players', 0) - 1
    except:
        return JsonResponse({'error': 'error'}, status=200)

    return JsonResponse({'status': 'success',
                         'nb_players':session.get('nb_players', 0),
                         'id':player_id}, status=200)



def multi_login(request):
    login = request.POST.get('username')
    password = request.POST.get('password')
    no_player = request.POST.get('no_player')

    session = request.session

    user = User.objects.filter(login=login).first()
    if not user:
        return JsonResponse({'error': 'username'}, status=200)
    if login == session.get('user'):
        return JsonResponse({'error': 'already logged'}, status=200)
    if user.loginWithApi:
        return JsonResponse({'error': 'api'}, status=200)
    if user.password != password:
        return JsonResponse({'error': 'password'}, status=200)
    # if user.twoStepsActive:
    #     return JsonResponse({'status': 'success',
    #                             'f2a': user.twoStepsActive}, status=200)

    session = request.session
    session['nb_players'] = session.get('nb_players', 0) + 1

    player = {'login': login, "img: ": user.image_link}
    # Ajouter le joueur à la liste des joueurs dans la session
    if 'players' in request.session:
        request.session['players'].append(player)
    else:
        request.session['players'] = [player]

    return JsonResponse({'status': 'success',
                            'user': user.login,
                            'img': user.image_link,
                            'score': user.score,
                            'f2a': user.twoStepsActive,
                            'nb_players':session.get('nb_players', 0)}, status=200)
