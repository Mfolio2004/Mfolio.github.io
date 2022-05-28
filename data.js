data = {Name:"FOLIO Maxence", Age:"19", Nationalité: "Française (Réunionnais)",
Lycée: "Lycée St-Paul IV, Réunion", Etudes: "Epitech IT Promo 2025 (2ème année)",
Expérience: [
    {Lieu: "Stage DSEM La Poste", Durée: "15 Août 2021 au 15 Décembre 2021", Métier: "Technicien de maintenance"}],
Technologie: [
    {Name: "C / C++"}, 
    {Name: "Python"}, 
    {Name: "HTML"}],
Outils: [
    {Name: "Visual Studi Code"}, 
    {Name: "GitHub"}, 
    {Name: "Teams"}],
Projets: [
    {Name: "Need4Stek", Description: "Ce projet pousse les étudiants a réaliser une Intelligence Artificiel qui va permettre a une voiture (virtuelles) de réaliser un parcour\n\t\tle plus rapidement possible sans toucher de murs."},
    {Name: "Indie", Description: "L'Indie est un projet qui a pour but de réaliser un Boomberman (produit achevé).\n\t\tCe projet a été réaliser durant ma seconde année à Epitech en groupe de 8"}],
Email: "maxence.folio@epitech.eu", Tel: "06 41 22 99 36"}

function load() {
    var title = document.getElementById("output");

    title.innerHTML = data.Name;
}

function pres() {
    var title = document.getElementById("content");

    title.innerHTML = 'Nom et Prénom: ' + data.Name + '\nAge: ' + data.Age + 'ans\nNationalité: ' + data.Nationalité + 
    '\n\nLycée: ' + data.Lycée + '\nEtudes supérieur: ' + data.Etudes;
}

function cv() {
    var title = document.getElementById("content");

    title.innerHTML = 'Expérience :\n\t-' +  data.Expérience[0].Lieu + ' (' + data.Expérience[0].Durée + '), Métier suivi: ' + data.Expérience[0].Métier +
    '\n\nTechnologie :\n\t-' + data.Technologie[0].Name + '\n\t-' + data.Technologie[1].Name + '\n\t-' + data.Technologie[2].Name +
    '\nOutils :\n\t-' + data.Outils[0].Name + '\n\t-' + data.Outils[1].Name + '\n\t-' + data.Outils[2].Name
}

function projet() {
    var title = document.getElementById("content");

    title.innerHTML = 'Projets marquants :\n\t-' +  data.Projets[0].Name + ':\n\t\t' + data.Projets[0].Description + '\n\n\t-' +  data.Projets[1].Name + ':\n\t\t' + data.Projets[1].Description
}

function contact() {
    var title = document.getElementById("content");

    title.innerHTML = '\tEmail: ' + data.Email + '\n\tTéléphone: ' + data.Tel
}