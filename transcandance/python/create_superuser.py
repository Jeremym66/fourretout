import os
from django.contrib.auth import get_user_model

User = get_user_model()
username = os.environ.get('DB_USER')
password = os.environ.get('DB_PASSWORD')

if not User.objects.filter(username=username).exists():
    User.objects.create_superuser(username, '', password)
