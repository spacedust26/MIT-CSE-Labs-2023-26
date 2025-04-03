from django.urls import path
from . import views

urlpatterns = [
    path('', views.input_page, name="input_page"),  # Home Page
    path('result/', views.result_page, name="result_page"),  # Result Page
]
