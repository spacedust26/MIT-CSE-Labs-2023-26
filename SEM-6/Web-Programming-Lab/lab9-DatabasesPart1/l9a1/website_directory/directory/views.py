# directory/views.py
from django.shortcuts import render, redirect
from .models import Category, Page
from .forms import CategoryForm, PageForm

def category_list(request):
    categories = Category.objects.all()
    return render(request, 'directory/category_list.html', {'categories': categories})

def page_list(request, category_id):
    category = Category.objects.get(id=category_id)
    pages = Page.objects.filter(category=category)
    return render(request, 'directory/page_list.html', {'category': category, 'pages': pages})

def add_category(request):
    if request.method == 'POST':
        form = CategoryForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('category_list')
    else:
        form = CategoryForm()
    return render(request, 'directory/add_category.html', {'form': form})

def add_page(request, category_id):
    category = Category.objects.get(id=category_id)
    if request.method == 'POST':
        form = PageForm(request.POST)
        if form.is_valid():
            page = form.save(commit=False)
            page.category = category
            page.save()
            return redirect('page_list', category_id=category.id)
    else:
        form = PageForm()
    return render(request, 'directory/add_page.html', {'form': form, 'category': category})
