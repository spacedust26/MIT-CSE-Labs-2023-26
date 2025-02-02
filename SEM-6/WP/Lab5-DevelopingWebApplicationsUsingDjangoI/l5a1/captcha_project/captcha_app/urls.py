from django.urls import path
from .views import captcha_view

urlpatterns = [
    path('', captcha_view, name='captcha_page'),
]
