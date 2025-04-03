from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('get_human/<int:human_id>/', views.get_human_details, name='get_human'),
    path('update_human/<int:human_id>/', views.update_human, name='update_human'),
    path('delete_human/<int:human_id>/', views.delete_human, name='delete_human'),
]
