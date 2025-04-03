from django.shortcuts import render, redirect
from .models import Product
from .forms import ProductForm

# View for adding a product
def add_product(request):
    if request.method == "POST":
        form = ProductForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('index')
    else:
        form = ProductForm()
    return render(request, 'products/form.html', {'form': form, 'title': 'Add Product'})

# View for displaying all products
def index(request):
    products = Product.objects.all()
    return render(request, 'products/index.html', {'products': products})
