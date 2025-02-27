from django.shortcuts import render, redirect
from .forms import VoteForm
from .models import Vote
from django.db.models import Count

def vote_view(request):
    if request.method == "POST":
        form = VoteForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('results')
    else:
        form = VoteForm()

    return render(request, 'voting/vote.html', {'form': form})

def results_view(request):
    total_votes = Vote.objects.count()
    results = (
        Vote.objects.values('choice')
        .annotate(count=Count('choice'))
        .order_by('-count')
    )

    percentages = {}
    for result in results:
        choice = result['choice']
        count = result['count']
        percentages[choice] = round((count / total_votes) * 100, 2) if total_votes else 0

    return render(request, 'voting/results.html', {'percentages': percentages})
