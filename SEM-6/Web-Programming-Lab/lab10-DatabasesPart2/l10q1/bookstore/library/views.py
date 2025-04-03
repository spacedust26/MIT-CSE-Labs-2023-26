from django.shortcuts import render, redirect
from .models import Author, Publisher, Book
from .forms import AuthorForm, PublisherForm, BookForm

def add_author(request):
    if request.method == "POST":
        form = AuthorForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('list_authors')
    else:
        form = AuthorForm()
    return render(request, 'library/form.html', {'form': form, 'title': 'Add Author'})

def add_publisher(request):
    if request.method == "POST":
        form = PublisherForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('list_publishers')
    else:
        form = PublisherForm()
    return render(request, 'library/form.html', {'form': form, 'title': 'Add Publisher'})

def add_book(request):
    if request.method == "POST":
        form = BookForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('list_books')
    else:
        form = BookForm()
    return render(request, 'library/form.html', {'form': form, 'title': 'Add Book'})

def list_authors(request):
    authors = Author.objects.all()
    return render(request, 'library/list.html', {'items': authors, 'title': 'Authors'})

def list_publishers(request):
    publishers = Publisher.objects.all()
    return render(request, 'library/list.html', {'items': publishers, 'title': 'Publishers'})

def list_books(request):
    books = Book.objects.all()
    return render(request, 'library/list.html', {'items': books, 'title': 'Books'})
