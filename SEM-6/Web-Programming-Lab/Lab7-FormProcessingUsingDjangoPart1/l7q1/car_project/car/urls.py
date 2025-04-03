from django.urls import path
from . import views
urlpatterns = [
  path('', views.car_form, name='car_form'),
  path('car_result/', views.car_result, name='car_result'),
]