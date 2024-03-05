# views/__init__.py
from django.shortcuts import render, redirect
from django.conf import settings

from django.http import JsonResponse, HttpResponse
from django.contrib.sessions.models import Session
from ..models import User

import requests
import json

from .double_auth import *
from .session_datas import *
from .api42 import *
from .multiplayer import *
from .registrations import *

def home_view(request):
    return HttpResponse("Bienvenue sur ma page d'accueil !")
