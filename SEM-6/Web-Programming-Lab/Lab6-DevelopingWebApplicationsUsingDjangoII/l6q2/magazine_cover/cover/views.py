from django.shortcuts import render
from .forms import CoverForm

def cover_generator(request):
    if request.method == 'POST':
        form = CoverForm(request.POST, request.FILES)
        if form.is_valid():
            # Process the form data
            context = {
                'image': form.cleaned_data['image'],
                'background_color': form.cleaned_data['background_color'],
                'font_family': form.cleaned_data['font_family'],
                'font_size': form.cleaned_data['font_size'],
                'font_color': form.cleaned_data['font_color'],
                'message': form.cleaned_data['message'],
            }
            return render(request, 'cover/cover.html', context)
    else:
        form = CoverForm()
    return render(request, 'cover/cover_generator.html', {'form': form})