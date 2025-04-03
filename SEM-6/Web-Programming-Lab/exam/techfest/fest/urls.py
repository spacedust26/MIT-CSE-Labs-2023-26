from django.urls import path, include
from . import views

urlpatterns = [
    path('page1', views.page1, name='page1'),
    path('page2', views.page2, name='page2'),
]
