from django.http import HttpResponse
from django.shortcuts import render, redirect
from listings.models import Band
from listings.models import Listing
from listings.forms import ListingsForm, BandForm, ContactUsForm
from django.core.mail import send_mail

def band_list(request):
    bands = Band.objects.all()
    return render(request, 'listings/band_list.html', {'bands': bands})

def band_detail(request, id):  # notez le paramètre id supplémentaire
   band = Band.objects.get(id=id)
   return render(request,
          'listings/band_detail.html',
         {'band': band}) # nous passons l'id au modèle

def band_create(request):
    if request.method == 'POST':
        form = BandForm(request.POST)
        if form.is_valid():
            band = form.save()
            return redirect('band-detail', band.id)
    else:
        form = BandForm()

    return render(request,
            'listings/band_create.html',
            {'form': form})

def band_update(request, id):
    band = Band.objects.get(id=id)
    if request.method == 'POST':
        form = BandForm(request.POST, instance=band)
        if form.is_valid():
            form.save()
            return redirect('band-detail', band.id)
    else:
        form = BandForm(instance=band)

    return render(request,
                    'listings/band_update.html',
                    {'form': form})

def band_delete(request, id):
    band = Band.objects.get(id=id)
    if request.method == 'POST':
        band.delete()
        return redirect('band-list')

    return render(request,
                    'listings/band_delete.html',
                    {'band': band})

def about(request):
    return render(request, 'listings/about.html')

def listings_list(request):
    lists = Listing.objects.all()
    return render(request, 'listings/listings_list.html', {'lists' : lists})

def listings_detail(request, id):
    listss = Listing.objects.get(id=id)
    return render(request,
            'listings/listings_detail.html', 
            {'listss': listss})

def listings_create(request):
    if request.method == 'POST':
        form = ListingsForm(request.POST)
        if form.is_valid():
            listss = form.save()
            return redirect('listings-detail', listss.id)
    else:
        form = ListingsForm()

    return render(request,
            'listings/listings_create.html',
            {'form': form})

def listings_update(request, id):
    listss = Listing.objects.get(id=id)
    if request.method == 'POST':
        form = ListingsForm(request.POST, instance=listss)
        if form.is_valid():
            form.save()
            return redirect('listings-detail', listss.id)
    else:
        form = ListingsForm(instance=listss)

    return render(request,
                    'listings/listings_update.html',
                    {'form': form})

def listings_delete(request, id):
    listss = Listing.objects.get(id=id)
    if request.method == 'POST':
        listss.delete()
        return redirect('listings-list')

    return render(request,
                    'listings/listings_delete.html',
                    {'listss': listss})

def contact(request):
    print('La méthode de requete est: ', request.method)
    print('Les données POST sont : ', request.POST)
    if request.method == 'POST':
        form = ContactUsForm(request.POST)
        if form.is_valid():
            send_mail(
            subject=f'Message from {form.cleaned_data["name"] or "anonyme"} via MerchEx Contact Us form',
            message=form.cleaned_data['message'],
            from_email=form.cleaned_data['email'],
            recipient_list=['admin@merchex.xyz'],
        )
        return redirect('email-sent')
    else:
        form = ContactUsForm()

    return render(request,
            'listings/contact.html',
            {'form': form})

def email_sent(request):
    return render(request, 'listings/email-sent.html')
