from django.shortcuts import render, redirect
from .forms import RegisterForm

def register(request):
    if request.method == "POST":
        form = RegisterForm(request.POST)
        if form.is_valid():
            # Securely store form data in session
            request.session['username'] = form.cleaned_data['username']
            request.session['email'] = form.cleaned_data['email']
            request.session['contact'] = form.cleaned_data['contact']
            return redirect('success')  # Redirect to success page
    else:
        form = RegisterForm()
    return render(request, 'registration/register.html', {'form': form})

def success(request):
    # Fetch stored session data
    username = request.session.get('username', 'Guest')
    email = request.session.get('email', 'Not Provided')
    contact = request.session.get('contact', 'Not Provided')

    return render(request, 'registration/success.html', {'username': username, 'email': email, 'contact': contact})
