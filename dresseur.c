/**
 * \file dresseur.c
 *
 * \brief
 *
 * \author Pierre-Antoine Chantal et Julien Violet
 * \date Mai 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "dresseur.h"

void lancerCombat(SDL_Surface *ecran, int *niveauPika, int numeroEnnemi, int niveauEnnemi, int * ko)
{
    int i;

	char vieAllie[20] = ""; /* Tableau de char suffisamment grand */
	char vieEnnemi[20] = ""; /* Tableau de char suffisamment grand */
	char pokeAtak[50] = "";
    char texteAttaque[20] = "";
    char niveauAllie[20] = "";
    char printNiveauEnnemi[20] = "";
    SDL_Surface *attaqueEchouee = NULL, *texteVieAllie = NULL, *texteVieEnnemi=NULL, *imageFinCombat=NULL, *textePokeAtak=NULL;
    SDL_Surface *cadre=NULL;
    SDL_Surface *texteAttaque1 = NULL, *texteAttaque2 = NULL, *texteAttaque3 = NULL, *texteAttaque4 = NULL;
    SDL_Surface *imageCarapuceAllie = NULL, *imageCarapuceEnnemi = NULL;
    SDL_Surface *imageSalamecheAllie = NULL, *imageSalamecheEnnemi = NULL;
    SDL_Surface *imageBulbizarreAllie = NULL, *imageBulbizarreEnnemi = NULL;
    SDL_Surface *imageKickleeAllie=NULL, *imageKickleeEnnemi=NULL;
    SDL_Surface *imageAttaqueGriffe = NULL;
    SDL_Surface *imageAttaqueTomberocheAllie=NULL, *imageAttaqueTomberocheEnnemi=NULL;
    SDL_Surface *imageAttaqueEbullilaveAllie=NULL, *imageAttaqueEbullilaveEnnemi=NULL;
    SDL_Surface *imageAttaqueFlammecheAllie=NULL, *imageAttaqueFlammecheEnnemi=NULL;
    SDL_Surface *imageAttaqueBulleDOAllie=NULL, *imageAttaqueBulleDOEnnemi=NULL;
    SDL_Surface *imageCasseBriqueAllie=NULL, *imageCasseBriqueEnnemi=NULL;
    SDL_Surface *imageAttaqueHydrocanonAllie=NULL, *imageAttaqueHydrocanonEnnemi=NULL;
    SDL_Surface *imageAttaqueOuraganAllie=NULL, *imageAttaqueOuraganEnnemi=NULL;
    SDL_Surface *imageFouetLianeAllie=NULL, *imageFouetLianeEnnemi=NULL;
    SDL_Surface *imageTrancherbeAllie=NULL, *imageTrancherbeEnnemi=NULL;
    SDL_Surface *imageBalayetteAllie=NULL, *imageBalayetteEnnemi=NULL;
    SDL_Surface *imageBouleRocAllie=NULL, *imageBouleRocEnnemi=NULL;
    SDL_Surface *imageRapaceAllie=NULL, *imageRapaceEnnemi=NULL;
    SDL_Surface *imageTonnerreAllie=NULL, *imageTonnerreEnnemi=NULL;
    SDL_Surface *imagePsykokwakAllie=NULL, *imagePsykokwakEnnemi=NULL;
    SDL_Surface *imagePyroliAllie=NULL, *imagePyroliEnnemi=NULL;
    SDL_Surface *imageRacaillouAllie=NULL, *imageRacaillouEnnemi=NULL;
    SDL_Surface *imageMachocAllie=NULL, *imageMachocEnnemi=NULL;
    SDL_Surface *imageNoadkokoAllie=NULL, *imageNoadkokoEnnemi=NULL;
    SDL_Surface *imageTogekissAllie=NULL, *imageTogekissEnnemi=NULL;
    SDL_Surface *imageRoucoulAllie=NULL, *imageRoucoulEnnemi=NULL;
    SDL_Surface *imageRhinocorneAllie=NULL, *imageRhinocorneEnnemi=NULL;
    SDL_Surface *imagePikachuAllie=NULL, *imagePikachuEnnemi=NULL;
    SDL_Surface *texteNiveauAllie=NULL, *texteNiveauEnnemi=NULL;
    SDL_Rect positionCadre;
    SDL_Rect positionPokemon1;
    SDL_Rect positionPokemon2;
    SDL_Rect positionAttaqueAllie;
    SDL_Rect positionTexteAttaque;
    SDL_Rect positionAttaqueEnnemi;
    SDL_Rect positionFinCombat;
    SDL_Rect positionVieAllie;
    SDL_Rect positionVieEnnemi;
    SDL_Rect positionAttaque1;
    SDL_Rect positionAttaque2;
    SDL_Rect positionAttaque3;
    SDL_Rect positionAttaque4;
    SDL_Rect positionNiveauAllie;
    SDL_Rect positionNiveauEnnemi;

    // Position des images des Pokemon par rapport à leur coin en haut à gauche
    positionPokemon1.x = 20;
    positionPokemon1.y = 250;
    positionPokemon2.x = 760;
    positionPokemon2.y = 0;
    positionAttaqueAllie.x = 720;
    positionAttaqueAllie.y = 30;
    positionTexteAttaque.x = 60;
    positionTexteAttaque.y = 550;
    positionAttaqueEnnemi.x = 120;
    positionAttaqueEnnemi.y = 260;
    positionFinCombat.x = 230;
    positionFinCombat.y = 80;
    positionVieAllie.x = 350;
    positionVieAllie.y = 350;
    positionVieEnnemi.x = 470;
    positionVieEnnemi.y = 120;
    positionAttaque1.x = 37;
    positionAttaque1.y = 510;
    positionAttaque2.x = 37;
    positionAttaque2.y = 600;
    positionAttaque3.x = 500;
    positionAttaque3.y = 510;
    positionAttaque4.x = 500;
    positionAttaque4.y = 600;
    positionCadre.x = 1;
    positionCadre.y = 451;
    positionNiveauAllie.x=350;
    positionNiveauAllie.y=300;
    positionNiveauEnnemi.x=470;
    positionNiveauEnnemi.y=70;

    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};

    TTF_Init();

    /* Chargement de la police */
    police = TTF_OpenFont("./texte/f25bank.ttf", 48);

    // Chargement de l'icone AVANT SDL_SetVideoMode
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);

    // Ouverture fenetre  + gestion d'erreur
    // SDL_SetVideoMode(1000, 700, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("Combat POKEMON", NULL);

    // Remplissage de l'arriere plan par une couleur unie
    SDL_FillRect(ecran, NULL, 0x3366ff);

    //Chargement des images
    cadre = IMG_Load("./image/cadre.bmp");

    imageSalamecheAllie = SDL_LoadBMP("./image/SalamecheAllie.bmp");
    imageSalamecheEnnemi = SDL_LoadBMP("./image/SalamecheEnnemi.bmp");

    imageCarapuceEnnemi= SDL_LoadBMP("./image/carapuceEnnemi.bmp");
    imageCarapuceAllie= SDL_LoadBMP("./image/carapuceAllie.bmp");

    imageBulbizarreEnnemi = SDL_LoadBMP("./image/bulbizarreEnnemi.bmp");
    imageBulbizarreAllie = SDL_LoadBMP("./image/bulbizarreAllie.bmp" );

    imageKickleeAllie = SDL_LoadBMP("./image/KickleeAllie.bmp");
    imageKickleeEnnemi = SDL_LoadBMP("./image/KickleeEnnemi.bmp");

    imagePsykokwakAllie = SDL_LoadBMP("./image/psykokwakAllie.bmp");
    imagePsykokwakEnnemi = SDL_LoadBMP("./image/psykokwakEnnemi.bmp");

    imagePyroliAllie = SDL_LoadBMP("./image/PyroliAllie.bmp");
    imagePyroliEnnemi = SDL_LoadBMP("./image/PyroliEnnemi.bmp");

    imageRacaillouAllie = SDL_LoadBMP("./image/RacaillouAllie.bmp");
    imageRacaillouEnnemi = SDL_LoadBMP("./image/RacaillouEnnemi.bmp");

    imageMachocAllie = SDL_LoadBMP("./image/machocAllie.bmp");
    imageMachocEnnemi = SDL_LoadBMP("./image/machocEnnemi.bmp");

    imageNoadkokoAllie = SDL_LoadBMP("./image/NoadkokoAllie.bmp");
    imageNoadkokoEnnemi = SDL_LoadBMP("./image/NoadkokoEnnemi.bmp");

    imageTogekissAllie = SDL_LoadBMP("./image/TogekissAllie.bmp");
    imageTogekissEnnemi = SDL_LoadBMP("./image/TogekissEnnemi.bmp");

    imageRoucoulAllie = SDL_LoadBMP("./image/RoucoulAllie.bmp");
    imageRoucoulEnnemi = SDL_LoadBMP("./image/RoucoulEnnemi.bmp");

    imageAttaqueGriffe = SDL_LoadBMP("./image/griffe.bmp");

    imageAttaqueHydrocanonAllie = SDL_LoadBMP("./image/HydrocanonAllie.bmp");
    imageAttaqueHydrocanonEnnemi = SDL_LoadBMP("./image/HydrocanonEnnemi.bmp");

    imageAttaqueBulleDOAllie = SDL_LoadBMP("./image/bulleDOallie.bmp");
    imageAttaqueBulleDOEnnemi = SDL_LoadBMP("./image/bulleDOennemi.bmp");

    imageCasseBriqueAllie = SDL_LoadBMP("./image/CasseBriqueAllie.bmp");
    imageCasseBriqueEnnemi = SDL_LoadBMP("./image/CasseBriqueEnnemi.bmp");

    imageAttaqueFlammecheAllie = SDL_LoadBMP("./image/flammecheAllie.bmp");
    imageAttaqueFlammecheEnnemi = SDL_LoadBMP("./image/flammecheEnnemi.bmp");

    imageAttaqueEbullilaveAllie = SDL_LoadBMP("./image/ebullilaveAllie.bmp");
    imageAttaqueEbullilaveEnnemi = SDL_LoadBMP("./image/ebullilaveEnnemi.bmp");

    imageAttaqueTomberocheAllie = SDL_LoadBMP("./image/tomberocheAllie.bmp");
    imageAttaqueTomberocheEnnemi= SDL_LoadBMP("./image/tomberocheEnnemi.bmp");

    imageAttaqueOuraganAllie = SDL_LoadBMP("./image/ouraganAllie.bmp");
    imageAttaqueOuraganEnnemi = SDL_LoadBMP("./image/ouraganEnnemi.bmp");

    imageFouetLianeAllie = SDL_LoadBMP("./image/fouetLianeAllie.bmp");
    imageFouetLianeEnnemi = SDL_LoadBMP("./image/fouetLianeEnnemi.bmp");

    imageTrancherbeAllie= SDL_LoadBMP("./image/trancherbeAllie.bmp");
    imageTrancherbeEnnemi = SDL_LoadBMP("./image/trancherbeEnnemi.bmp");

    imageBalayetteAllie = SDL_LoadBMP("./image/balayetteAllie.bmp");
    imageBalayetteEnnemi = SDL_LoadBMP("./image/balayetteEnnemi.bmp");

    imageBouleRocAllie = SDL_LoadBMP("./image/BouleRocAllie.bmp");
    imageBouleRocEnnemi = SDL_LoadBMP("./image/BouleRocEnnemi.bmp");

    imageRapaceAllie = SDL_LoadBMP("./image/rapaceAllie.bmp");
    imageRapaceEnnemi = SDL_LoadBMP("./image/rapaceEnnemi.bmp");

    imageTonnerreAllie=SDL_LoadBMP("./image/tonnerre.bmp");
    imageTonnerreEnnemi=SDL_LoadBMP("./image/tonnerre.bmp");

    imageRhinocorneAllie = SDL_LoadBMP("./image/RhinocorneAllie.bmp");
    imageRhinocorneEnnemi = SDL_LoadBMP("./image/RhinocorneEnnemi.bmp");

    imagePikachuAllie=SDL_LoadBMP("./image/pikachuAllie.bmp");
    imagePikachuEnnemi=SDL_LoadBMP("./image/pikachuEnnemi.bmp");

    const char* nomGriffe = "griffe";
    Attaque Griffe;
    Griffe.imageAllie=imageAttaqueGriffe;
    Griffe.imageEnnemi=imageAttaqueGriffe;
    Griffe.nom=nomGriffe;
    Griffe.type=NORMAL;
    Griffe.precision=100;
    Griffe.degatBase=5;
    Griffe.degatParNiveau=1;
    Griffe.degatParForce=1;

    const char* nomHydrocanon = "hydrocanon";
    Attaque Hydrocanon;
    Hydrocanon.imageAllie=imageAttaqueHydrocanonAllie;
    Hydrocanon.imageEnnemi=imageAttaqueHydrocanonEnnemi;
    Hydrocanon.nom=nomHydrocanon;
    Hydrocanon.type=EAU;
    Hydrocanon.precision=70;
    Hydrocanon.degatBase=9;
    Hydrocanon.degatParNiveau=1;
    Hydrocanon.degatParForce=2;

    const char* nomBulleDO = "bulleDO";
    Attaque BulleDO;
    BulleDO.imageAllie=imageAttaqueBulleDOAllie;
    BulleDO.imageEnnemi=imageAttaqueBulleDOEnnemi;
    BulleDO.nom=nomBulleDO;
    BulleDO.type=EAU;
    BulleDO.precision=95;
    BulleDO.degatBase=6;
    BulleDO.degatParNiveau=2;
    BulleDO.degatParForce=1;

    const char* nomCasseBrique = "casse brique";
    Attaque CasseBrique;
    CasseBrique.imageAllie=imageCasseBriqueAllie;
    CasseBrique.imageEnnemi=imageCasseBriqueEnnemi;
    CasseBrique.nom=nomCasseBrique;
    CasseBrique.type=COMBAT;
    CasseBrique.precision=100;
    CasseBrique.degatBase=4;
    CasseBrique.degatParNiveau=1;
    CasseBrique.degatParForce=2;

    const char* nomFlammeche = "flammeche";
    Attaque Flammeche;
    Flammeche.imageAllie=imageAttaqueFlammecheAllie;
    Flammeche.imageEnnemi=imageAttaqueFlammecheEnnemi;
    Flammeche.nom=nomFlammeche;
    Flammeche.type=FEU;
    Flammeche.precision=95;
    Flammeche.degatBase=3;
    Flammeche.degatParNiveau=2;
    Flammeche.degatParForce=2;

    const char* nomEbullilave = "ebullilave";
    Attaque Ebullilave;
    Ebullilave.imageAllie=imageAttaqueEbullilaveAllie;
    Ebullilave.imageEnnemi=imageAttaqueEbullilaveEnnemi;
    Ebullilave.nom=nomEbullilave;
    Ebullilave.type=FEU;
    Ebullilave.precision=60;
    Ebullilave.degatBase=3;
    Ebullilave.degatParNiveau=2;
    Ebullilave.degatParForce=3;

    const char* nomTomberoche = "tomberoche";
    Attaque Tomberoche;
    Tomberoche.imageAllie=imageAttaqueTomberocheAllie;
    Tomberoche.imageEnnemi=imageAttaqueTomberocheEnnemi;
    Tomberoche.nom=nomTomberoche;
    Tomberoche.type=ROCHE;
    Tomberoche.precision=85;
    Tomberoche.degatBase=3;
    Tomberoche.degatParNiveau=3;
    Tomberoche.degatParForce=1;

    const char* nomOuragan="ouragan";
    Attaque Ouragan;
    Ouragan.imageAllie =imageAttaqueOuraganAllie;
    Ouragan.imageEnnemi=imageAttaqueOuraganEnnemi;
    Ouragan.nom=nomOuragan;
    Ouragan.type=VOL;
    Ouragan.precision=68;
    Ouragan.degatBase=4;
    Ouragan.degatParNiveau=1;
    Ouragan.degatParForce=3;

    const char* nomFouetLiane="fouet liane";
    Attaque FouetLiane;
    FouetLiane.nom=nomFouetLiane;
    FouetLiane.imageAllie=imageFouetLianeAllie;
    FouetLiane.imageEnnemi=imageFouetLianeEnnemi;
    FouetLiane.type=PLANTE;
    FouetLiane.precision=100;
    FouetLiane.degatBase=5;
    FouetLiane.degatParNiveau=1;
    FouetLiane.degatParForce=1;

    const char* nomTrancherbe="trancherbe";
    Attaque Trancherbe;
    Trancherbe.nom=nomTrancherbe;
    Trancherbe.imageAllie=imageTrancherbeAllie;
    Trancherbe.imageEnnemi=imageTrancherbeEnnemi;
    Trancherbe.type=PLANTE;
    Trancherbe.precision=75;
    Trancherbe.degatBase=2;
    Trancherbe.degatParNiveau=4;
    Trancherbe.degatParForce=1;

    const char* nomBalayette="balayette";
    Attaque Balayette;
    Balayette.imageAllie=imageBalayetteAllie;
    Balayette.imageEnnemi=imageBalayetteEnnemi;
    Balayette.type=COMBAT;
    Balayette.nom=nomBalayette;
    Balayette.precision=80;
    Balayette.degatBase=1;
    Balayette.degatParNiveau=1;
    Balayette.degatParForce=4;

    const char* nomBouleRoc="boule roc";
    Attaque BouleRoc;
    BouleRoc.imageAllie=imageBouleRocAllie;
    BouleRoc.imageEnnemi=imageBouleRocEnnemi;
    BouleRoc.nom=nomBouleRoc;
    BouleRoc.type=ROCHE;
    BouleRoc.precision=50;
    BouleRoc.degatBase=6;
    BouleRoc.degatParNiveau=3;
    BouleRoc.degatParForce=3;

    const char* nomRapace="rapace";
    Attaque Rapace;
    Rapace.nom=nomRapace;
    Rapace.imageAllie=imageRapaceAllie;
    Rapace.imageEnnemi=imageRapaceEnnemi;
    Rapace.type=VOL;
    Rapace.precision=82;
    Rapace.degatBase=3;
    Rapace.degatParNiveau=2;
    Rapace.degatParForce=2;

    const char* nomTonnerre="tonnerre";
    Attaque Tonnerre;
    Tonnerre.type=ELEK;
    Tonnerre.nom=nomTonnerre;
    Tonnerre.imageAllie=imageTonnerreAllie;
    Tonnerre.imageEnnemi=imageTonnerreEnnemi;
    Tonnerre.precision=99;
    Tonnerre.degatBase=3;
    Tonnerre.degatParNiveau=3;
    Tonnerre.degatParForce=1;

    const char* nomCarapuce = "Carapuce";
    Pokemon Carapuce;
    Carapuce.imageAllie=imageCarapuceAllie;
    Carapuce.imageEnnemi=imageCarapuceEnnemi;
    Carapuce.nom=nomCarapuce;
    Carapuce.niveau=niveauEnnemi;
    Carapuce.vie=120+20*(Carapuce.niveau);
    Carapuce.vieMax=120+20*(Carapuce.niveau);
    Carapuce.force=4;
    Carapuce.vitesse=30;
    Carapuce.type=EAU;
    Carapuce.experience=0;
    Carapuce.attaque1=Griffe;
    Carapuce.attaque2=Hydrocanon;
    Carapuce.attaque3=BulleDO;
    Carapuce.attaque4=CasseBrique;

    const char* nomSalameche = "Salameche";
    Pokemon Salameche;
    Salameche.imageAllie=imageSalamecheAllie;
    Salameche.imageEnnemi=imageSalamecheEnnemi;
    Salameche.nom=nomSalameche;
    Salameche.niveau=niveauEnnemi;
    Salameche.vie=110+20*(Salameche.niveau);
    Salameche.vieMax=110+20*(Salameche.niveau);
    Salameche.force=4;
    Salameche.vitesse=25;
    Salameche.type=FEU;
    Salameche.experience=0;
    Salameche.attaque1=Griffe;
    Salameche.attaque2=Flammeche;
    Salameche.attaque3=Ebullilave;
    Salameche.attaque4=Tomberoche;

    const char* nomBulbizarre="Bulbizarre";
    Pokemon Bulbizarre;
    Bulbizarre.nom=nomBulbizarre;
    Bulbizarre.imageAllie=imageBulbizarreAllie;
    Bulbizarre.imageEnnemi=imageBulbizarreEnnemi;
    Bulbizarre.niveau=niveauEnnemi;
    Bulbizarre.vie=110+20*(Bulbizarre.niveau);
    Bulbizarre.vieMax=110+20*(Bulbizarre.niveau);
    Bulbizarre.force=5;
    Bulbizarre.type=PLANTE;
    Bulbizarre.experience=0;
    Bulbizarre.attaque1=Griffe;
    Bulbizarre.attaque2=FouetLiane;
    Bulbizarre.attaque3=Trancherbe;
    Bulbizarre.attaque4=Ouragan;

    Pokemon Kicklee;
    const char* nomKicklee="Kicklee";
    Kicklee.imageAllie=imageKickleeAllie;
    Kicklee.imageEnnemi=imageKickleeEnnemi;
    Kicklee.nom=nomKicklee;
    Kicklee.niveau=niveauEnnemi;
    Kicklee.vie=130+20*(Kicklee.niveau);
    Kicklee.vieMax=130+20*(Kicklee.niveau);
    Kicklee.force=5;
    Kicklee.type=COMBAT;
    Kicklee.experience=0;
    Kicklee.attaque1=Balayette;
    Kicklee.attaque2=CasseBrique;
    Kicklee.attaque3=BouleRoc;
    Kicklee.attaque4=FouetLiane;

    const char* nomPsykokwak="Psykokwak";
    Pokemon Psykokwak;
    Psykokwak.nom=nomPsykokwak;
    Psykokwak.imageAllie=imagePsykokwakAllie;
    Psykokwak.imageEnnemi=imagePsykokwakEnnemi;
    Psykokwak.niveau=niveauEnnemi;
    Psykokwak.vie=105+20*(Psykokwak.niveau);
    Psykokwak.vieMax=105+20*(Psykokwak.niveau);
    Psykokwak.force=4;
    Psykokwak.type=EAU;
    Psykokwak.experience=0;
    Psykokwak.attaque1=Hydrocanon;
    Psykokwak.attaque2=BulleDO;
    Psykokwak.attaque3=Griffe;
    Psykokwak.attaque4=Rapace;

    const char* nomPyroli="Pyroli";
    Pokemon Pyroli;
    Pyroli.nom=nomPyroli;
    Pyroli.imageAllie=imagePyroliAllie;
    Pyroli.imageEnnemi=imagePyroliEnnemi;
    Pyroli.niveau=niveauEnnemi;
    Pyroli.vie=80+20*(Pyroli.niveau);
    Pyroli.vieMax=80+20*(Pyroli.niveau);
    Pyroli.force=7;
    Pyroli.type=FEU;
    Pyroli.experience=0;
    Pyroli.attaque1=Flammeche;
    Pyroli.attaque2=Ebullilave;
    Pyroli.attaque3=Balayette;
    Pyroli.attaque4=Tomberoche;

    const char* nomRacaillou="Racaillou";
    Pokemon Racaillou;
    Racaillou.nom=nomRacaillou;
    Racaillou.imageAllie=imageRacaillouAllie;
    Racaillou.imageEnnemi=imageRacaillouEnnemi;
    Racaillou.niveau=niveauEnnemi;
    Racaillou.vie=140+20*(Racaillou.niveau);
    Racaillou.force=3;
    Racaillou.vieMax=140+20*(Racaillou.niveau);
    Racaillou.type=ROCHE;
    Racaillou.experience=0;
    Racaillou.attaque1=CasseBrique;
    Racaillou.attaque2=Tomberoche;
    Racaillou.attaque3=Griffe;
    Racaillou.attaque4=BouleRoc;


    const char* nomMachoc="Machoc";
    Pokemon Machoc;
    Machoc.nom=nomMachoc;
    Machoc.imageAllie=imageMachocAllie;
    Machoc.imageEnnemi=imageMachocEnnemi;
    Machoc.niveau=niveauEnnemi;
    Machoc.vie=100+20*(Machoc.niveau);
    Machoc.vieMax=100+20*(Machoc.niveau);
    Machoc.force=6;
    Machoc.type=COMBAT;
    Machoc.experience=0;
    Machoc.attaque1=Griffe;
    Machoc.attaque2=CasseBrique;
    Machoc.attaque3=Balayette;
    Machoc.attaque4=Tomberoche;


    const char* nomNoadkoko="Noadkoko";
    Pokemon Noadkoko;
    Noadkoko.nom=nomNoadkoko;
    Noadkoko.imageAllie=imageNoadkokoAllie;
    Noadkoko.imageEnnemi=imageNoadkokoEnnemi;
    Noadkoko.niveau=niveauEnnemi;
    Noadkoko.vie=94+20*(Noadkoko.niveau);
    Noadkoko.vieMax=94+20*(Noadkoko.niveau);
    Noadkoko.force=5;
    Noadkoko.type=PLANTE;
    Noadkoko.experience=0;
    Noadkoko.attaque1=Trancherbe;
    Noadkoko.attaque2=FouetLiane;
    Noadkoko.attaque3=Ouragan;
    Noadkoko.attaque4=BouleRoc;


    const char* nomTogekiss="Togekiss";
    Pokemon Togekiss ;
    Togekiss.nom=nomTogekiss;
    Togekiss.imageAllie=imageTogekissAllie;
    Togekiss.imageEnnemi=imageTogekissEnnemi;
    Togekiss.niveau=niveauEnnemi;
    Togekiss.vie=101+20*(Togekiss.niveau);
    Togekiss.vieMax=101+20*(Togekiss.niveau);
    Togekiss.force=4;
    Togekiss.type=VOL;
    Togekiss.experience=0;
    Togekiss.attaque1=Ouragan;
    Togekiss.attaque2=Rapace;
    Togekiss.attaque3=Hydrocanon;
    Togekiss.attaque4=Flammeche;


    const char* nomRoucoul="Roucoul";
    Pokemon Roucoul;
    Roucoul.nom=nomRoucoul;
    Roucoul.imageAllie=imageRoucoulAllie;
    Roucoul.imageEnnemi=imageRoucoulEnnemi;
    Roucoul.niveau=niveauEnnemi;
    Roucoul.vie=100+20*(Roucoul.niveau);
    Roucoul.vieMax=100+20*(Roucoul.niveau);
    Roucoul.force=3;
    Roucoul.type=VOL;
    Roucoul.experience=0;
    Roucoul.attaque1=Griffe;
    Roucoul.attaque2=Ouragan;
    Roucoul.attaque3=CasseBrique;
    Roucoul.attaque4=Rapace;

    const char* nomRhinocorne="Rhinocorne";
    Pokemon Rhinocorne;
    Rhinocorne.imageAllie=imageRhinocorneAllie;
    Rhinocorne.imageEnnemi=imageRhinocorneEnnemi;
    Rhinocorne.nom=nomRhinocorne;
    Rhinocorne.niveau=niveauEnnemi;
    Rhinocorne.vie=125+20*(Rhinocorne.niveau);
    Rhinocorne.vieMax=125+20*(Rhinocorne.niveau);
    Rhinocorne.force=5;
    Rhinocorne.type=ROCHE;
    Rhinocorne.experience=0;
    Rhinocorne.attaque1=BouleRoc;
    Rhinocorne.attaque2=Tomberoche;
    Rhinocorne.attaque3=Rapace;
    Rhinocorne.attaque4=Balayette;

    const char* nomPikachu="Pikachu";
    Pokemon Pikachu;
    Pikachu.type=ELEK;
    Pikachu.imageAllie=imagePikachuAllie;
    Pikachu.imageEnnemi=imagePikachuEnnemi;
    Pikachu.nom=nomPikachu;
    Pikachu.niveau=*niveauPika;
    Pikachu.vie=135+20*(Pikachu.niveau);
    Pikachu.force=4;
    Pikachu.experience=0;
    Pikachu.vieMax=135+20*(Pikachu.niveau);
    Pikachu.force=4;
    Pikachu.attaque1=Griffe;
    Pikachu.attaque2=Tonnerre;
    Pikachu.attaque3=CasseBrique;
    Pikachu.attaque4=Rapace;

    Pokemon pokemonAllie; //on crée le pokemon allié du combat
    egaliteStatistiques(&pokemonAllie, Pikachu);
    Pokemon pokemonEnnemi; //on crée le pokemon ennemi du combat

    if (numeroEnnemi==0)
        {
            egaliteStatistiques(&pokemonEnnemi, Carapuce);
        }
    if (numeroEnnemi==1)
        {
            egaliteStatistiques(&pokemonEnnemi, Salameche);
        }
    if (numeroEnnemi==2)
        {
            egaliteStatistiques(&pokemonEnnemi, Bulbizarre);
        }
    if (numeroEnnemi==3)
        {
            egaliteStatistiques(&pokemonEnnemi, Kicklee);
        }
    if (numeroEnnemi==4)
        {
            egaliteStatistiques(&pokemonEnnemi, Psykokwak);
        }
    if (numeroEnnemi==11)
        {
            egaliteStatistiques(&pokemonEnnemi, Pyroli);
        }
    if (numeroEnnemi==6)
        {
            egaliteStatistiques(&pokemonEnnemi, Racaillou);
        }
    if (numeroEnnemi==7)
        {
            egaliteStatistiques(&pokemonEnnemi, Machoc);
        }
    if (numeroEnnemi==8)
        {
            egaliteStatistiques(&pokemonEnnemi, Noadkoko);
        }
    if (numeroEnnemi==9)
        {
            egaliteStatistiques(&pokemonEnnemi, Togekiss);
        }
    if (numeroEnnemi==10)
        {
            egaliteStatistiques(&pokemonEnnemi, Roucoul);
        }
    if (numeroEnnemi==5)
        {
            egaliteStatistiques(&pokemonEnnemi, Rhinocorne);
        }

    Attaque attaque; //Cela permettra de prendre les attaques

    // Affichage de l'image du prmeier pokemon
    SDL_SetColorKey(pokemonAllie.imageAllie, SDL_SRCCOLORKEY, SDL_MapRGB(pokemonAllie.imageAllie->format, 255, 255, 255));
    SDL_SetAlpha(pokemonAllie.imageAllie, SDL_SRCALPHA, 255);
    SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);

    // Affichage de l'image du second pokemon
    SDL_SetColorKey(pokemonEnnemi.imageEnnemi, SDL_SRCCOLORKEY, SDL_MapRGB(pokemonEnnemi.imageEnnemi->format, 255, 255, 255));
    SDL_SetAlpha(pokemonEnnemi.imageEnnemi, SDL_SRCALPHA, 255);
    SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);

    // Afichage
    SDL_Flip(ecran);

    for(i=1;i<=25;i++)
    {
        positionPokemon1.x+=2;
        SDL_FillRect(ecran, NULL, 0xffffff);
        SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
        SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
        SDL_Flip(ecran);
        SDL_Delay(80);
    }
    for(i=1;i<=25;i++)
    {
        positionPokemon2.x-=2;
        SDL_FillRect(ecran, NULL, 0xffffff);
        SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
        SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
        SDL_Flip(ecran);
        SDL_Delay(80);
    }

    while (pokemonAllie.vie > 0 && pokemonEnnemi.vie > 0)
    {
        SDL_SetColorKey(cadre, SDL_SRCCOLORKEY, SDL_MapRGB(cadre->format, 255, 255, 255));
        SDL_SetAlpha(cadre, SDL_SRCALPHA, 255);
        SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
        sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
        texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
        SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
        sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
        texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
        SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
        sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
        texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
        SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
        sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
        texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
        SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

        sprintf(texteAttaque, "1)%s", pokemonAllie.attaque1.nom);
        texteAttaque1 = TTF_RenderText_Blended(police, texteAttaque, couleurNoire);
        SDL_BlitSurface(texteAttaque1, NULL, ecran, &positionAttaque1);

        sprintf(texteAttaque, "2)%s", pokemonAllie.attaque2.nom);
        texteAttaque2 = TTF_RenderText_Blended(police, texteAttaque, couleurNoire);
        SDL_BlitSurface(texteAttaque2, NULL, ecran, &positionAttaque2);

        sprintf(texteAttaque, "3)%s", pokemonAllie.attaque3.nom);
        texteAttaque3 = TTF_RenderText_Blended(police, texteAttaque, couleurNoire);
        SDL_BlitSurface(texteAttaque3, NULL, ecran, &positionAttaque3);

        sprintf(texteAttaque, "4)%s", pokemonAllie.attaque4.nom);
        texteAttaque4 = TTF_RenderText_Blended(police, texteAttaque, couleurNoire);
        SDL_BlitSurface(texteAttaque4, NULL, ecran, &positionAttaque4);

        SDL_Flip(ecran);

        // Attente de la part du joueur d'appuyer sur la touche Espace pour continuer
        int continuer2=1;
        SDL_Event event2;
        while (continuer2)
        {
            SDL_WaitEvent(&event2);
            switch(event2.type)
            {
                case SDL_KEYDOWN:   // On teste lorsqu'une touche est appuyée
                    switch (event2.key.keysym.sym)
                    {
                        case SDLK_AMPERSAND: case SDLK_1:
                            {
                            continuer2=0;
                            SDL_FillRect(ecran, NULL, 0xffffff);
                            SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
                            SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
                            SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
                            sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
                            texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
                            SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
                            sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
                            texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
                            SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
                            sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
                            texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
                            SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
                            sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
                            texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
                            SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

                            egaliteAttaque(&attaque, pokemonAllie.attaque1);
                            sprintf(pokeAtak, "%s lance %s", pokemonAllie.nom, attaque.nom);
                            textePokeAtak = TTF_RenderText_Blended(police, pokeAtak, couleurNoire);
                            SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
                            break;
                            }
                        case SDLK_WORLD_73: case SDLK_2:
                            {
                            continuer2=0;
                            SDL_FillRect(ecran, NULL, 0xffffff);
                            SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
                            SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
                            SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
                            sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
                            texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
                            SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
                            sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
                            texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
                            SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
                            sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
                            texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
                            SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
                            sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
                            texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
                            SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

                            egaliteAttaque(&attaque, pokemonAllie.attaque2);
                            sprintf(pokeAtak, "%s lance %s", pokemonAllie.nom, attaque.nom);
                            textePokeAtak = TTF_RenderText_Blended(police, pokeAtak, couleurNoire);
                            SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
                            break;
                            }
                        case SDLK_QUOTEDBL: case SDLK_3:
                            {
                            continuer2=0;
                            SDL_FillRect(ecran, NULL, 0xffffff);
                            SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
                            SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
                            SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
                            sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
                            texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
                            SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
                            sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
                            texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
                            SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
                            sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
                            texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
                            SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
                            sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
                            texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
                            SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

                            egaliteAttaque(&attaque, pokemonAllie.attaque3);
                            sprintf(pokeAtak, "%s lance %s", pokemonAllie.nom, attaque.nom);
                            textePokeAtak = TTF_RenderText_Blended(police, pokeAtak, couleurNoire);
                            SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
                            break;
                            }
                        case SDLK_QUOTE: case SDLK_4:
                            {
                            continuer2=0;
                            SDL_FillRect(ecran, NULL, 0xffffff);
                            SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
                            SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
                            SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
                            sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
                            texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
                            SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
                            sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
                            texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
                            SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
                            sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
                            texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
                            SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
                            sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
                            texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
                            SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

                            egaliteAttaque(&attaque, pokemonAllie.attaque4);
                            sprintf(pokeAtak, "%s lance %s", pokemonAllie.nom, attaque.nom);
                            textePokeAtak = TTF_RenderText_Blended(police, pokeAtak, couleurNoire);
                            SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
                            break;
                            }


                        default : break;
                    }
                break;
                default : break;
            }
        }
        SDL_Flip(ecran);
        SDL_Delay(1000);

        // Attente de la part du joueur d'appuyer sur la touche Espace pour continuer
        temporisation();

        srand(time(NULL));
        if ((rand()%101)<attaque.precision)
        {
            // Affichage de l'attaque sur le pokemon 2
            SDL_SetColorKey(attaque.imageAllie, SDL_SRCCOLORKEY, SDL_MapRGB(attaque.imageAllie->format, 255, 255, 255));
            SDL_SetAlpha(attaque.imageAllie, SDL_SRCALPHA, 255);
            SDL_BlitSurface(attaque.imageAllie, NULL, ecran, &positionAttaqueAllie);

            sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
            texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
            SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
            sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
            sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
            texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
            SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
            sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
            texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
            SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);
            texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
            SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
            SDL_Flip(ecran);
            pokemonEnnemi.vie-=(attaque.degatBase+attaque.degatParNiveau*pokemonAllie.niveau+attaque.degatParForce*pokemonAllie.force)*crit()*coef(attaque.type, pokemonEnnemi.type);
        }
        else
        {
            SDL_FillRect(ecran, NULL, 0xffffff);
            SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
            SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
            SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);

            attaqueEchouee = TTF_RenderUTF8_Blended(police, "Mais l'attaque rate !", couleurNoire);
            SDL_BlitSurface(attaqueEchouee, NULL, ecran, &positionTexteAttaque); /* Blit du texte */

            sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
            texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
            SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
            sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
            texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
            SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
            sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
            texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
            SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
            sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
            texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
            SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

            SDL_Flip(ecran);
        }

        SDL_Delay(2000);

        SDL_FillRect(ecran, NULL, 0xffffff);
        SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
        SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
        SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
        sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
        texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
        SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
        sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
        texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
        SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
        sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
        texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
        SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
        sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
        texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
        SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

        SDL_Flip(ecran);

        SDL_Delay(1000);

        if (pokemonEnnemi.vie > 0)
        {
            srand(time(NULL));
            int z = rand()%100;
            if (0<=z && z<25)
            {
                egaliteAttaque(&attaque, pokemonEnnemi.attaque1);
                sprintf(pokeAtak, "%s lance %s", pokemonEnnemi.nom, attaque.nom);
                textePokeAtak = TTF_RenderText_Blended(police, pokeAtak, couleurNoire);
                SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
            }
            if (25<=z && z<50)
            {
                egaliteAttaque(&attaque, pokemonEnnemi.attaque2);
                sprintf(pokeAtak, "%s lance %s", pokemonEnnemi.nom, attaque.nom);
                textePokeAtak = TTF_RenderText_Blended(police, pokeAtak, couleurNoire);
                SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
            }
            if (50<=z && z<75)
            {
                egaliteAttaque(&attaque, pokemonEnnemi.attaque3);
                sprintf(pokeAtak, "%s lance %s", pokemonEnnemi.nom, attaque.nom);
                textePokeAtak = TTF_RenderText_Blended(police, pokeAtak, couleurNoire);
                SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
            }
            if (75<=z && z<100)
            {
                egaliteAttaque(&attaque, pokemonEnnemi.attaque4);
                sprintf(pokeAtak, "%s lance %s", pokemonEnnemi.nom, attaque.nom);
                textePokeAtak = TTF_RenderText_Blended(police, pokeAtak, couleurNoire);
                SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
            }

            SDL_Flip(ecran);
            SDL_Delay(1000);

            // Attente de la part du joueur d'appuyer sur la touche Espace pour continuer
            temporisation();

            srand(time(NULL));
            if ((rand()%101)<attaque.precision)
            {
                // Affichage de l'attaque sur le pokemon 1
                SDL_SetColorKey(attaque.imageEnnemi, SDL_SRCCOLORKEY, SDL_MapRGB(attaque.imageEnnemi->format, 255, 255, 255));
                SDL_SetAlpha(attaque.imageEnnemi, SDL_SRCALPHA, 255);
                SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
                SDL_BlitSurface(textePokeAtak, NULL, ecran, &positionTexteAttaque);
                SDL_BlitSurface(attaque.imageEnnemi, NULL, ecran, &positionAttaqueEnnemi);

                sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
                texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
                SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
                sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
                texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
                SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
                sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
                texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
                SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
                sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
                texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
                SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);
                SDL_Flip(ecran);
                pokemonAllie.vie-=(attaque.degatBase+attaque.degatParNiveau*pokemonEnnemi.niveau+attaque.degatParForce*pokemonEnnemi.force)*crit()*coef(attaque.type, pokemonAllie.type);
            }
            else
            {
                SDL_FillRect(ecran, NULL, 0xffffff);
                SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
                SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
                SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
                attaqueEchouee = TTF_RenderUTF8_Blended(police, "Mais l'attaque rate !", couleurNoire);
                SDL_BlitSurface(attaqueEchouee, NULL, ecran, &positionTexteAttaque); /* Blit du texte */
                sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
                texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
                SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
                sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
                texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
                SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
                sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
                texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
                SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
                sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
                texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
                SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

                SDL_Flip(ecran);
            }

            SDL_Delay(2000);

            SDL_FillRect(ecran, NULL, 0xffffff);
            SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
            SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
            SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
            sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
            texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
            SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
            sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
            texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
            SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
            sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
            texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
            SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
            sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
            texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
            SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);

            SDL_Flip(ecran);

            SDL_Delay(1000);
        }
    }

    if (pokemonEnnemi.vie <= 0)
    {
        SDL_FillRect(ecran, NULL, 0xffffff);
        SDL_BlitSurface(pokemonAllie.imageAllie, NULL, ecran, &positionPokemon1);
        SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
        sprintf(vieAllie, "%d/%d", pokemonAllie.vie, pokemonAllie.vieMax);
        texteVieAllie = TTF_RenderText_Blended(police, vieAllie, couleurNoire);
        SDL_BlitSurface(texteVieAllie, NULL, ecran, &positionVieAllie);
        sprintf(niveauAllie, "lvl:%d", pokemonAllie.niveau);
        texteNiveauAllie = TTF_RenderText_Blended(police, niveauAllie, couleurNoire);
        SDL_BlitSurface(texteNiveauAllie, NULL, ecran, &positionNiveauAllie);
        SDL_Flip(ecran);
        SDL_Delay(1000);
	(*niveauPika)=(*niveauPika)+1;
	*ko=1;
    }
    if (pokemonAllie.vie <= 0)
    {
        SDL_FillRect(ecran, NULL, 0xffffff);
        SDL_BlitSurface(pokemonEnnemi.imageEnnemi, NULL, ecran, &positionPokemon2);
        SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
        sprintf(vieEnnemi, "%d/%d", pokemonEnnemi.vie, pokemonEnnemi.vieMax);
        texteVieEnnemi = TTF_RenderText_Blended(police, vieEnnemi, couleurNoire);
        SDL_BlitSurface(texteVieEnnemi, NULL, ecran, &positionVieEnnemi);
        sprintf(printNiveauEnnemi, "lvl:%d", pokemonEnnemi.niveau);
        texteNiveauEnnemi = TTF_RenderText_Blended(police, printNiveauEnnemi, couleurNoire);
        SDL_BlitSurface(texteNiveauEnnemi, NULL, ecran, &positionNiveauEnnemi);
        SDL_Flip(ecran);
        SDL_Delay(1000);
	*ko=0;
    }

    imageFinCombat = SDL_LoadBMP("./image/FinCombat.bmp");
    SDL_BlitSurface(imageFinCombat, NULL, ecran, &positionFinCombat);
    SDL_Flip(ecran);
    SDL_Delay(2000);

    //gestionEvent();

    TTF_CloseFont(police);
  //  SDL_FreeSurface(ecran);
    SDL_FreeSurface(imageCarapuceAllie);
    SDL_FreeSurface(imageCarapuceEnnemi);
    SDL_FreeSurface(imageSalamecheAllie);
    SDL_FreeSurface(imageSalamecheEnnemi);
    SDL_FreeSurface(imageBulbizarreAllie);
    SDL_FreeSurface(imageBulbizarreEnnemi);
    SDL_FreeSurface(imageKickleeAllie);
    SDL_FreeSurface(imageKickleeEnnemi);
    SDL_FreeSurface(attaqueEchouee);
    SDL_FreeSurface(texteVieAllie);
    SDL_FreeSurface(texteVieEnnemi);
    SDL_FreeSurface(imageAttaqueGriffe);
    SDL_FreeSurface(imageFinCombat);
    SDL_FreeSurface(textePokeAtak);
    SDL_FreeSurface(imageAttaqueBulleDOAllie);
    SDL_FreeSurface(imageAttaqueBulleDOEnnemi);
    SDL_FreeSurface(imageCasseBriqueAllie);
    SDL_FreeSurface(imageCasseBriqueEnnemi);
    SDL_FreeSurface(imageAttaqueHydrocanonAllie);
    SDL_FreeSurface(imageAttaqueHydrocanonEnnemi);
    SDL_FreeSurface(imageAttaqueFlammecheAllie);
    SDL_FreeSurface(imageAttaqueFlammecheEnnemi);
    SDL_FreeSurface(imageAttaqueEbullilaveAllie);
    SDL_FreeSurface(imageAttaqueEbullilaveEnnemi);
    SDL_FreeSurface(imageAttaqueTomberocheAllie);
    SDL_FreeSurface(imageAttaqueTomberocheEnnemi);
    SDL_FreeSurface(texteAttaque1);
    SDL_FreeSurface(texteAttaque2);
    SDL_FreeSurface(texteAttaque3);
    SDL_FreeSurface(texteAttaque4);
    SDL_FreeSurface(imageAttaqueOuraganAllie);
    SDL_FreeSurface(imageAttaqueOuraganEnnemi);
    SDL_FreeSurface(imageFouetLianeAllie);
    SDL_FreeSurface(imageFouetLianeEnnemi);
    SDL_FreeSurface(imageTrancherbeAllie);
    SDL_FreeSurface(imageTrancherbeEnnemi);
    SDL_FreeSurface(imageBalayetteAllie);
    SDL_FreeSurface(imageBalayetteEnnemi);
    SDL_FreeSurface(imageBouleRocAllie);
    SDL_FreeSurface(imageBouleRocEnnemi);
    SDL_FreeSurface(imageRapaceAllie);
    SDL_FreeSurface(imageRapaceEnnemi);
    SDL_FreeSurface(imagePsykokwakAllie);
    SDL_FreeSurface(imagePsykokwakEnnemi);
    SDL_FreeSurface(imagePyroliAllie);
    SDL_FreeSurface(imagePyroliEnnemi);
    SDL_FreeSurface(imageRacaillouAllie);
    SDL_FreeSurface(imageRacaillouEnnemi);
    SDL_FreeSurface(imageMachocAllie);
    SDL_FreeSurface(imageMachocEnnemi);
    SDL_FreeSurface(imageNoadkokoEnnemi);
    SDL_FreeSurface(imageNoadkokoAllie);
    SDL_FreeSurface(imageTogekissAllie);
    SDL_FreeSurface(imageTogekissEnnemi);
    SDL_FreeSurface(imageRoucoulAllie);
    SDL_FreeSurface(imageRoucoulEnnemi);
    SDL_FreeSurface(imageRhinocorneAllie);
    SDL_FreeSurface(imageRhinocorneEnnemi);
    SDL_FreeSurface(imagePikachuAllie);
    SDL_FreeSurface(imagePikachuEnnemi);
    SDL_FreeSurface(imageTonnerreAllie);
    SDL_FreeSurface(imageTonnerreEnnemi);

    SDL_FreeSurface(texteNiveauAllie);
    SDL_FreeSurface(texteNiveauEnnemi);
}

void egaliteStatistiques (Pokemon *a, Pokemon b)
{
    a->imageAllie=b.imageAllie;
    a->imageEnnemi=b.imageEnnemi;
    a->nom=b.nom;
    a->vie=b.vie;
    a->vieMax=b.vieMax;
    a->force=b.force;
    a->vitesse=b.vitesse;
    a->niveau=b.niveau;
    a->type=b.type;
    a->experience=b.experience;
    a->attaque1=b.attaque1;
    a->attaque2=b.attaque2;
    a->attaque3=b.attaque3;
    a->attaque4=b.attaque4;
}

void egaliteAttaque (Attaque *a, Attaque b)
{
    a->imageAllie=b.imageAllie;
    a->imageEnnemi=b.imageEnnemi;
    a->nom=b.nom;
    a->type=b.type;
    a->precision=b.precision;
    a->degatBase=b.degatBase;
    a->degatParNiveau=b.degatParNiveau;
    a->degatParForce=b.degatParForce;
}

void temporisation(void)
{
    int continuer3=1;
    SDL_Event event3;
    while (continuer3)
    {
        SDL_WaitEvent(&event3);
        switch(event3.type)
        {
            case SDL_KEYDOWN:   // On teste lorsqu'une touche est appuyée
                switch (event3.key.keysym.sym)
                {
                    case SDLK_SPACE:   // La touche ECHAP permet de quitter le programme
                        continuer3=0;
                        break;
                    default : break;
                }
                break;
            default : break;
        }
    }
}

int crit()
{
    srand (time(NULL));
    if ((rand()%101)>10)
    {
        return(1);
    }
    else
    {
        return(2);
    }
}

int coef(Type A,Type D)  //A=Attaquant et D=Defenseur
{
    if (A==PLANTE)
    {
        if(D==PLANTE)
            return (1);
        if(D == EAU)
            return (4);
        if(D==FEU)
            return(1);
        if(D==VOL)
            return(1);
        if(D==ROCHE)
            return(4);
        if(D==ELEK)
            return(1);
        return(2);
    }

    if (A==EAU)
    {
        if(D==PLANTE)
            return (1);
        if(D==EAU)
            return (1);
        if(D==FEU)
            return(4);
        if(D==VOL)
            return(2);
        if(D==ROCHE)
            return(2);
        return(2);
    }

    if(A==FEU)
    {
        if(D == PLANTE)
            return (4);
        if(D == EAU)
            return (1);
        if(D==FEU)
            return(1);
        if(D==ROCHE)
            return(1);
        return(2);
    }

    if (A==VOL)
    {
        if(D==PLANTE)
            return (4);
        if(D==ROCHE)
            return(1);
        if(D==COMBAT)
            return(4);
        if(D==ELEK)
            return(1);
        return(2);
    }

    if (A==ROCHE)
    {
        if(D==FEU)
            return(4);
        if(D==VOL)
            return(4);
        if(D==COMBAT)
            return(1);
        if(D==ELEK)
            return(4);
        return(2);
    }

    if (A==COMBAT)
    {
        if(D==VOL)
            return(1);
        if(D==ROCHE)
            return(4);
        return (2);
    }

    if(A==ELEK)
    {
        if(D==EAU)
            return(4);
        if(D==VOL)
            return(4);
        if(D==PLANTE)
            return(1);
	if(D==ROCHE)
            return(1);
        return(2);
    }
    return (2);
}
