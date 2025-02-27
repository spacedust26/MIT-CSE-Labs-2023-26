from django.urls import path
from . import views

urlpatterns = [
    path('', views.input_page, name="input_page"),  # Home Page
    path('bill/', views.bill_page, name="bill_page"),  # Bill Page
]
