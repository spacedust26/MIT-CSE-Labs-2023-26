from django.urls import path
from . import views

urlpatterns = [
    path('', views.feedback_form, name="feedback_form"),
]
