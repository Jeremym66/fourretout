import uuid
from django.db import models

def create_uuid():
    return str(uuid.uuid4())

class User(models.Model):

    login = models.CharField(max_length=255,unique=True)
    id = models.CharField(max_length=255, primary_key=True, default=create_uuid)
    email = models.EmailField(unique=True)
    first_name = models.CharField(max_length=255, null=True, blank=True)
    last_name = models.CharField(max_length=255, null=True, blank=True)
    is_active = models.BooleanField(default=True)
    token = models.CharField(max_length=255, null=True, blank=True)
    last_login = models.DateTimeField(null=True, blank=True)
    image_link = models.URLField(null=True, blank=True)
    total_games = models.PositiveIntegerField(default=0)
    win_games = models.PositiveIntegerField(default=0)
    score = models.IntegerField(default=0)
    twoStepsCode = models.CharField(max_length=255, null=True, blank=True)
    twoStepsActive = models.BooleanField(default=False)
    password = models.CharField(max_length=255, blank=True, null=True)
    loginWithApi = models.BooleanField(default=False)


    def __str__(self):
        return self.email
