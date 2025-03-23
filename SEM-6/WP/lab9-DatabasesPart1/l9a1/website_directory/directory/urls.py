# directory/urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('', views.category_list, name='category_list'),
    path('category/<int:category_id>/', views.page_list, name='page_list'),
    path('category/add/', views.add_category, name='add_category'),
    path('category/<int:category_id>/add/', views.add_page, name='add_page'),
]
