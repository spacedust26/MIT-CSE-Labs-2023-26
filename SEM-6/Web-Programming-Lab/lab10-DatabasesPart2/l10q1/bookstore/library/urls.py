from django.urls import path
from . import views

urlpatterns = [
    path('add-author/', views.add_author, name='add_author'),
    path('add-publisher/', views.add_publisher, name='add_publisher'),
    path('add-book/', views.add_book, name='add_book'),
    path('authors/', views.list_authors, name='list_authors'),
    path('publishers/', views.list_publishers, name='list_publishers'),
    path('books/', views.list_books, name='list_books'),
]
