from django.urls import path
from .views import promotion_view

urlpatterns = [
    path('', promotion_view, name='promotion_check'),
]
