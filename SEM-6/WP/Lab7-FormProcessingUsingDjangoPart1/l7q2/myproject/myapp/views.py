from django.shortcuts import render, redirect
def first_page(request):
  if request.method == "POST":
      # Get data from the form
      name = request.POST.get('name')
      roll = request.POST.get('roll')
      subject = request.POST.get('subject')
      # Store data in session
      request.session['name'] = name
      request.session['roll'] = roll
      request.session['subject'] = subject
      # Redirect to second page
      return redirect('second_page')
  return render(request, 'firstPage.html')
def second_page(request):
  # Retrieve data from session
  name = request.session.get('name')
  roll = request.session.get('roll')
  subject = request.session.get('subject')
  # Check if the session data exists, if not, redirect to the first page
  if not name or not roll or not subject:
      return redirect('first_page')
  context = {
      'name': name,
      'roll': roll,
      'subject': subject
  }
  return render(request, 'secondPage.html', context)