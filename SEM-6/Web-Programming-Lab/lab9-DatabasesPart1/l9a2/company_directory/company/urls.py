# company/urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('insert/works/', views.insert_works_data, name='insert_works_data'),
    path('insert/lives/', views.insert_lives_data, name='insert_lives_data'),
    path('search/', views.search_company, name='search_company'),
]
