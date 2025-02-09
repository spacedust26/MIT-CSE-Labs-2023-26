from django.urls import path
from . import views

urlpatterns = [
    path('', views.cover_generator, name='cover_generator'),
]