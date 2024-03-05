from django.urls import path
from api42 import views

from .views import *

urlpatterns = [
    path('', home_view, name='home'),
    path('data/', connect_api42, name='connect_api42'),
    path('keeploging/index.html', get_42_datas, name='api_datas'),
    # path('user_info/', user_info, name='user_info'),
	path('get-session/', get_session_data, name='session_data'),
	path('remove-session/', remove_session_data, name='remove_session'),

	path('highscores/', get_highscores, name='highscores'),
	path('update-score/', update_score, name='update_score'),
	path('normal_login/', normal_login, name='normal_login'),
	path('register-new-user/', registerNewUser, name='registerNewUser'),

	path('multi-login/', multi_login, name='multi_login'),
	path('multi-logout/', multi_logout, name='multi_logout'),
	path('get_multi_session_data/', get_multi_session_data, name='get_multi_session_data'),
	path('reset-multi/', reset_multi, name='reset_multi'),

	path('get_saved_qr_code/', get_saved_qr_code, name='get_saved_qr_code'),
	path('switch_double_auth/', switch_double_auth, name='switch_double_auth'),
	path('check_double_auth/', check_double_auth, name='check_double_auth'),
]
