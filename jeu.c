/**
 * \file jeu.c
 *
 * \brief Fonction qui lance la partie jeu à partir du menu.
 *
 * \author Julien Claus
 * \date Avril 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "jeu.h"
#include "dresseur.h"
#include "constantes.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void jouer(SDL_Surface *ecran)
{
    // déclaration et initiation
    
    SDL_Surface *arbre = NULL, *centre = NULL, *herbe = NULL,*maison1=NULL, *maison2=NULL, *pnj1=NULL, *bureau=NULL,*carrenoir=NULL,*oss=NULL, *sachaActuel=NULL;  // surfaces à blitter
    SDL_Rect pos,positionjoueur;
    SDL_Event event; // La variable contenant l'événement
    SDL_Surface *sacha[4] = {NULL};
    int continuer = 1; // Notre booléen pour la boucle
    FILE *fichier;
    SDL_EnableKeyRepeat(10, 70); // Activation de la répétition des touches : normal 10 70
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 100, 227, 71));
    positionjoueur.x=HAUTEUR_FENETRE/2;
    positionjoueur.y=LARGEUR_FENETRE/2;
    
    int tabcarte[10][7];
    int i = 0, j = 0;
    
    // chargement des images :
    
    fichier = fopen("./texte/niveau.txt", "r");
    remplirTableau(tabcarte,fichier);
    oss= IMG_Load("./image/OSS.png");
    carrenoir= IMG_Load("./image/carrenoir.png");
    pnj1 = IMG_Load("./image/pnjgauche.png");
    maison1 = IMG_Load("./image/maison1.png");
    maison2 = IMG_Load("./image/maison2.png");
    herbe = IMG_Load("./image/herbe4.png");
    arbre = IMG_Load("./image/arbre2.png");
    centre = IMG_Load("./image/poke.png");
    bureau = IMG_Load("./image/pokebureau.png");
    sacha[BAS] = IMG_Load("./image/avant2.png");
    sacha[GAUCHE] = IMG_Load("./image/gauche2.png");
    sacha[HAUT] = IMG_Load("./image/arriere2.png");
    sacha[DROITE] = IMG_Load("./image/droite2.png");
    
    sachaActuel = sacha[BAS]; // initialisation du personnage
    
    // mise en place de la map
    SDL_BlitSurface(sachaActuel, NULL, ecran, &positionjoueur);
    remplirmap(tabcarte,&pos,arbre,centre,herbe,ecran,maison1,maison2,pnj1,bureau,carrenoir,oss);
    
    while (continuer){
        
        
        SDL_WaitEvent(&event);
        
        SDL_Flip(ecran);
        switch(event.type) // gestion des évènements
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                case SDLK_UP:
                    sachaActuel = sacha[HAUT];
                    deplacerJoueur(ecran, tabcarte, &positionjoueur, HAUT);
                    break;
                case SDLK_DOWN:
                    sachaActuel = sacha[BAS];
                    deplacerJoueur(ecran, tabcarte, &positionjoueur, BAS);
                    break;
                case SDLK_RIGHT:
                    sachaActuel = sacha[DROITE];
                    deplacerJoueur(ecran, tabcarte, &positionjoueur, DROITE);
                    break;
                case SDLK_LEFT:
                    sachaActuel = sacha[GAUCHE];
                    deplacerJoueur(ecran, tabcarte, &positionjoueur, GAUCHE);
                    break;
		default:
			break;
            }
                break;
                
        }
        
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 100, 227, 71));
        for (j = 0 ; j < 7 ; j++)
            remplirmap(tabcarte,&pos,arbre,centre,herbe,ecran,maison1,maison2,pnj1,bureau,carrenoir,oss);
        
        
        SDL_BlitSurface(sachaActuel, NULL, ecran, &positionjoueur);
        
    }
    SDL_Flip(ecran);
    SDL_FreeSurface(oss);
    SDL_FreeSurface(maison1);
    SDL_FreeSurface(maison2);
    SDL_FreeSurface(carrenoir);
    SDL_FreeSurface(pnj1);
    SDL_FreeSurface(arbre);
    SDL_FreeSurface(centre);
    SDL_FreeSurface(herbe);
    SDL_FreeSurface(bureau);
    for (i = 0 ; i < 4 ; i++)
        SDL_FreeSurface(sacha[i]);
    SDL_EnableKeyRepeat(0, 0);
}






void remplirTableau(int tabcarte[10][7], FILE *fichier){
    
char ligneFichier[70];
int i = 0, j = 0;
    
if (fichier == NULL) // si le fichier n'existe pas
printf("pas de fichier");
    
fgets(ligneFichier, 71, fichier);
for (j = 0 ; j < 7 ; j++)
{
    for (i = 0 ; i < 10 ; i++)
    {
        switch (ligneFichier[i+j*10]) // remplissage du tableau en fonction des symboles du fichier
        {
            case '0':  // centre pokemon
                tabcarte[i][j] = 0;
                break;
            case '1': // arbre
                tabcarte[i][j] = 1;
                break;
            case '2': // vide
                tabcarte[i][j] = 2;
                break;
            case '3':  // herbe
                tabcarte[i][j] = 3;
                break;
            case '4': //"porte bas"
                tabcarte[i][j] = 4;
                break;
            case '5': //maison1
                tabcarte[i][j] = 5;
                break;
            case '6': //maison2
                tabcarte[i][j] = 6;
                break;
            case '7': //porte haut
                tabcarte[i][j] = 7;
                break;
            case '8': //porte droite
                tabcarte[i][j] = 8;
                break;
            case '9': //porte gauche
                tabcarte[i][j] = 9;
                break;
            case 'a': //pnj
                tabcarte[i][j] = 10;
                break;
            case 'b': //bureau
                tabcarte[i][j] = 11;
                break;
            case 'c': //casenoire
                tabcarte[i][j] = 12;
                break;
            case 'd': //couleurpoké
                tabcarte[i][j] = 13;
                break;
            case 'e': //oss
                tabcarte[i][j] = 14;
                break;
            case 'f': //couleur map2
                tabcarte[i][j] = 15;
                break;
            case 'g': //couleur map3
                tabcarte[i][j] = 16;
                break;
            case 'h': //couleur map4
                tabcarte[i][j] = 17;
                break;

        }
    }
}

fclose(fichier);
}






void deplacerJoueur(SDL_Surface *ecran, int tabcarte[10][7], SDL_Rect *pos, int direction)
{
    static int niveau=1,posx,posy,nb_alea,niveau_pika=30;
    int a, b,ko=1;
    FILE *fichier;   


    switch(direction) // réaction aux divers évènements
    {
        case HAUT:
            if (pos->y -1 < 0) // Si le joueur dÈpasse l'Ècran, on arrête
                break;
            
            if (tabcarte[(pos->x+10)/100][(pos->y-0)/100] == 0){ // si il y a un centre pokemon on arrête
                pos->y=pos->y + 5;
            }
            
            if (tabcarte[(pos->x)/100][(pos->y-10)/100] == 0){
                if (((pos->x % 100)==50)&&((pos->y % 100)< 60) ){ // on rentre dans le centre pokemon
                    pos->y=650;
                    pos->x=500;
                    fichier = fopen("./texte/centrepokemon.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    if (niveau==1)
                        niveau=6;
                    if (niveau==5)
                        niveau=7;
                }
                if (((pos->x % 100)==40)&&((pos->y % 100)< 60) ){
                    pos->y=650;
                    pos->x=500;
                    fichier = fopen("./texte/centrepokemon.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    if (niveau==1)
                        niveau=6;
                    if (niveau==5)
                        niveau=7;
                }
                pos->y=pos->y + 5;
                break;}
            
            if (tabcarte[(pos->x)/100][(pos->y-10)/100] == 1){ // S'il y a un arbre, on arrete
                pos->y=pos->y + 5;
                break;}
            
            if (tabcarte[(pos->x-15)/100][(pos->y)/100] == 3){ // probabilité de faire un combat
		srand(time(NULL));
                nb_alea = (rand() % 100) + 1;
                if (nb_alea<=10){
		        a=(rand()%3);
			if ( niveau == 3 )
				a=(rand()%5);
			if ( niveau == 4 )
				a=(rand()%5 + 5);
			if ( niveau == 6 )
				a=(rand()%3 + 8);
                    b=(rand()%6);
                    lancerCombat(ecran, &niveau_pika,a,niveau_pika-2+b,&ko);
			if ( ko == 0 ){
			fichier = fopen("./texte/niveau.txt","r");
			remplirTableau(tabcarte,fichier);
			pos->y=400;
                        pos->x=140;
			niveau=1;
				}
		    nb_alea=10;
                }
                pos->y=pos->y-10; // a remplacer par combat
                break;}
            
            if (tabcarte[(pos->x)/100][(pos->y+15)/100] == 6){
                if (((pos->x % 100)==30)&&((pos->y % 100)< 90) ){ // on rentre dans la maison
                    posx=pos->x;
                    posy=pos->y;
                    pos->y=650;
                    pos->x=500;
                    fichier = fopen("./texte/maison1.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    if (niveau==1)
                        niveau=11;
                    if (niveau==2)
                        niveau=12;
                }
                if (((pos->x % 100)==40)&&((pos->y % 100)< 90) ){ // on rentre dans la maison
                    posx=pos->x;
                    posy=pos->y;
                    pos->y=650;
                    pos->x=500;
                    fichier = fopen("./texte/maison1.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    if (niveau==1)
                        niveau=11;
                    if (niveau==2)
                        niveau=12;
                }
                pos->y=pos->y + 5; // si on arrive devant une maison, on s'arrête
                break;}
            
            
            
            if (tabcarte[(pos->x)/100][(pos->y+85)/100] == 7){ // passage d'un niveau à l'autre
                if ( niveau == 2){
                    fichier = fopen("./texte/niveau.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->y=700-pos->y;
                    niveau =1;
                }
                break;}
            
            if (tabcarte[(pos->x-280)/100][(pos->y-80)/100] == 11){ // devant un objet, on s'arrête
                pos->y=pos->y + 10;
            }
            
            if (tabcarte[(pos->x)/100][(pos->y-10)/100] == 12){ // cas d'arrêt obstacle'
                pos->y=pos->y + 5;
                break;}
            
            
            
            if (tabcarte[(pos->x)/100][(pos->y)/100] == 10){ // si on s'approche d'un PNJ, on s'arrete
                if (((pos->x % 100)==30)&&((pos->y % 100)== 50) ){
                    pos->y=pos->y + 10;
                    break;}
                if (((pos->x % 100)==50)&&((pos->y % 100)== 50) ){
                    pos->y=pos->y + 10;
                    break;}
                if (((pos->x % 100)==40)&&((pos->y % 100)== 50) ){
                    pos->y=pos->y + 10;
                    break;}
            }
            if (tabcarte[(pos->x)/100][(pos->y+10)/100] == 5){
                if (((pos->x % 100)==20)&&(((pos->y+20) % 100)< 50) ){ // on rentre dans la maison 1
                    posx=pos->x;
                    posy=pos->y;
                    pos->y=650;
                    pos->x=500;
                    fichier = fopen("./texte/maison1.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    if (niveau==1)
                        niveau=8;
                    if (niveau==3)
                        niveau=9;
                    if (niveau==5)
                        niveau=10;
                }
                if (((pos->x % 100)==30)&&(((pos->y+20) % 100)< 50) ){
                    posx=pos->x;
                    posy=pos->y;
                    pos->y=650;
                    pos->x=500;
                    fichier = fopen("./texte/maison1.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    if (niveau==1)
                        niveau=8;
                    if (niveau==3)
                        niveau=9;
                    if (niveau==5)
                        niveau=10;
                }
                pos->y=pos->y + 5;
                break;}
            
            
            else
                pos->y=pos->y - 10; // On peut enfin faire monter le joueur
            break;
            
            
        case BAS:  // la suite est similaire mais pour les autres mouvements
            if (pos->y >= 670)
                break;
            if (tabcarte[(pos->x)/100][(pos->y+10)/100] == 1){
                pos->y=pos->y -5;
                break;}
            if (tabcarte[(pos->x+10)/100][(pos->y+15)/100] == 0){
                pos->y=pos->y - 10;
                break;}
            if (tabcarte[(pos->x-15)/100][(pos->y)/100] == 3){
		srand(time(NULL));
                nb_alea = (rand() % 100) + 1;
                if (nb_alea<=10){
		        a=(rand()%3);
                    if ( niveau == 3 )
				a=(rand()%5);
			if ( niveau == 4 )
				a=(rand()%5 + 5);
			if ( niveau == 6 )
				a=(rand()%3 + 8);
                    b=(rand()%6);
                    lancerCombat(ecran, &niveau_pika,a,niveau_pika-2+b,&ko);
			if ( ko == 0 ){
			fichier = fopen("./texte/niveau.txt","r");
			remplirTableau(tabcarte,fichier);
			pos->y=400;
                        pos->x=140;
			niveau=1;
				}
 		    nb_alea=8;}
                pos->y =pos->y+10;
                break;}
            if (tabcarte[(pos->x)/100][(pos->y-60)/100] == 4){
                if ( niveau==1){
                    fichier = fopen("./texte/niveau2.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->y=-(700-pos->y);
                    niveau =2;
                }
                if ( niveau==6){
                    fichier = fopen("./texte/niveau.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->y=400;
                    pos->x=140;
                    niveau =1;
                }
                if ( niveau==7){
                    fichier = fopen("./texte/niveau5.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->y=200;
                    pos->x=840;
                    niveau =5;
                }
                if (niveau==8){
                    fichier = fopen("./texte/niveau.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=posx;
                    pos->y=posy;
                    niveau=1;}
                if (niveau==9){
                    fichier = fopen("./texte/niveau3.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=posx;
                    pos->y=posy;
                    niveau=3;}
                if (niveau==10){
                    fichier = fopen("./texte/niveau5.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=posx;
                    pos->y=posy;
                    niveau=5;}
                if (niveau==11){
                    fichier = fopen("./texte/niveau.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=posx;
                    pos->y=posy;
                    niveau=1;}
                if (niveau==12){
                    fichier = fopen("./texte/niveau2.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=posx;
                    pos->y=posy;
                    niveau=2;}
                break;}
            
            if (tabcarte[(pos->x)/100][(pos->y+40)/100] == 12){
                pos->y=pos->y -5;
                break;}
            
            if (tabcarte[(pos->x)/100][(pos->y+35)/100] == 5){
                pos->y=pos->y - 5;
                break;}
            if (tabcarte[(pos->x)/100][(pos->y+35)/100] == 6){
                pos->y=pos->y - 5;
                break;}
            if (tabcarte[(pos->x)/100][(pos->y+30)/100] == 10){
                if (((pos->x % 100)==30)&&(((pos->y-50) % 100)== 50) ){ // A REVOIR
                    pos->y=pos->y - 10;
                    break;}
                if (((pos->x % 100)==40)&&(((pos->y-50) % 100)== 50) ){
                    pos->y=pos->y - 10;
                    break;}
                if (((pos->x % 100)==50)&&(((pos->y+50) % 100)== 50) ){
                    pos->y=pos->y - 10;
                    break;}
                pos->y=pos->y + 10;
            }
            
            
            else
                pos->y=pos-> y +10;
            break;
            
            
        case GAUCHE:
            if (pos->x - 1 < 0)
                break;
            if (tabcarte[(pos->x-10)/100][(pos->y)/100] == 1){
                pos->x=pos->x + 5;
                break;}
            if (tabcarte[(pos->x-10)/100][(pos->y)/100] == 0){
                pos->x=pos->x + 5;
                break;}
            if (tabcarte[(pos->x-15)/100][(pos->y)/100] == 3){
		srand(time(NULL));
                nb_alea = (rand() % 100) + 1;
                if (nb_alea<=10){
		        a=(rand()%3);
                    if ( niveau == 3 )
				a=(rand()%5);
			if ( niveau == 4 )
				a=(rand()%5 + 5);
			if ( niveau == 6 )
				a=(rand()%3 + 8);
                    b=(rand()%6);
                    lancerCombat(ecran, &niveau_pika,a,niveau_pika-2+b,&ko);
			if ( ko == 0 ){
			fichier = fopen("./texte/niveau.txt","r");
			remplirTableau(tabcarte,fichier);
			pos->y=400;
                        pos->x=140;
			niveau=1;
				}
 		    nb_alea=8;}
                pos->x=pos->x-10;
                break;}
            if (tabcarte[(pos->x-10)/100][(pos->y+25)/100] == 5){
                pos->x=pos->x + 5;
                break;}
            if (tabcarte[(pos->x-15)/100][(pos->y+25)/100] == 6){
                pos->x=pos->x + 5;
                break;}
            if (tabcarte[(pos->x-20)/100][(pos->y+10)/100] == 12){
                pos->x=pos->x + 5;
                break;}
            if (tabcarte[(pos->x+80)/100][(pos->y)/100] == 9){
                if ( niveau == 3){
                    fichier = fopen("./texte/niveau2.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x= 1000-pos->x;
                    niveau =2;
                }
                if ( niveau == 4){
                    fichier = fopen("./texte/niveau.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x= 1000-pos->x;
                    niveau =1;
                }
                if ( niveau == 5){
                    fichier = fopen("./texte/niveau4.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x= 1000-pos->x;
                    niveau =4;
                }
                if ( niveau == 6){
                    fichier = fopen("./texte/niveau5.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x= 1000-pos->x;
                    niveau =5;
                }

                break;}
            if (tabcarte[(pos->x)/100][(pos->y)/100] == 10){
                if (((pos->x % 100)==60)&&((pos->y % 100)==30 ) ){
                    pos->x=pos->x + 10;
                    break;}
                if (((pos->x % 100)==60)&&(((pos->y) % 100)==20 ) ){
                    pos->x=pos->x + 10;
                    break;}
                pos->x=pos->x - 10;
            }
            
            
            else
                pos->x=pos->x-10;
            break;
            
            
        case DROITE:
            if (pos->x+ 30 >= 1000)
                break;
            if (tabcarte[(pos->x+10)/100][(pos->y)/100] == 1){
                pos->x=pos->x - 5;
                break;}
            if (tabcarte[(pos->x+24)/100][(pos->y)/100] == 0){
                pos->x=pos->x - 5;
                break;}
            if (tabcarte[(pos->x-270)/100][(pos->y-60)/100] == 11){
                pos->x=pos->x - 5;
                break;}
               if (tabcarte[(pos->x-15)/100][(pos->y)/100] == 3){
		srand(time(NULL));
                nb_alea = (rand() % 100) + 1;
           	 if (nb_alea<=10){
		        a=(rand()%3);
             	    if ( niveau == 3 )
				a=(rand()%5);
			if ( niveau == 4 )
				a=(rand()%5 + 5);
			if ( niveau == 6 )
				a=(rand()%3 + 8);
                    b=(rand()%6);
                    lancerCombat(ecran, &niveau_pika,a,niveau_pika-2+b,&ko);
			if ( ko == 0 ){
			fichier = fopen("./texte/niveau.txt","r");
			remplirTableau(tabcarte,fichier);
			pos->y=400;
                        pos->x=140;
			niveau=1;
				}
 		    nb_alea=8;
			}
		pos->x=pos->x+10;
            break;}
            if (tabcarte[(pos->x+15)/100][(pos->y+25)/100] == 5){
                pos->x=pos->x - 5;
                break;}
            if (tabcarte[(pos->x+15)/100][(pos->y+25)/100] == 6){
                pos->x=pos->x - 5;
                break;}
            if (tabcarte[(pos->x+30)/100][(pos->y+10)/100] == 12){
                pos->x=pos->x - 5;
                break;}
            if (tabcarte[(pos->x-60)/100][(pos->y)/100] == 8){
                if ( niveau == 2){
                    fichier = fopen("./texte/niveau3.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=-(1000-pos->x);
                    niveau =3;
                }
                if ( niveau == 4){
                    fichier = fopen("./texte/niveau5.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=-(1000-pos->x);
                    niveau =5;
                    break;
                }
                if ( niveau == 1){
                    fichier = fopen("./texte/niveau4.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=-(1000-pos->x);
                    niveau =4;
                    break;
                }
                if ( (niveau == 5)&&(niveau_pika>=30)){
                    fichier = fopen("./texte/niveau6.txt", "r");
                    remplirTableau(tabcarte,fichier);
                    pos->x=-(1000-pos->x);
                    niveau =6;
                    break;
                }

                break;}
            if (tabcarte[(pos->x)/100][(pos->y)/100] == 10){
                if ((((pos->x) % 100)==20)&&(((pos->y) % 100)==20 ) ){
                    if (niveau ==6){
			 pos->x=pos->x-10;
                         lancerCombat(ecran, &niveau_pika,11,40,&ko);}
                     pos->x=pos->x-10;
                    break;}
                if ((((pos->x) % 100)==20)&&(((pos->y) % 100)==30 ) ){
                    if (niveau ==6){
			 pos->x=pos->x-10;
                         lancerCombat(ecran, &niveau_pika,11,40,&ko);}
                    pos->x=pos->x-10;
                    break;}
                pos->x=pos->x + 10;
            }
            
    
            else
                pos->x=pos->x+10;
            break;
    }

}








void remplirmap(int tabcarte[10][7], SDL_Rect *pos ,SDL_Surface *arbre, SDL_Surface *centre, SDL_Surface *herbe, SDL_Surface *ecran, SDL_Surface *maison1, SDL_Surface *maison2, SDL_Surface *pnj1, SDL_Surface *bureau,SDL_Surface * carrenoir,SDL_Surface * oss) { // blitage des images en fonction de leur position dans le fichier
    int i,j;
    for (j = 0 ; j < 7 ; j++)
    {
        for (i = 0 ; i < 10 ; i++)
        {
            if (tabcarte[i][j]==0){
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(centre, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==1){
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(arbre, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==3){
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(herbe, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==5){
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(maison1, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==6){
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(maison2, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==10){
                pos->x=100*i+30;
                pos->y=100*j+30;
                SDL_BlitSurface(pnj1, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==11){
                pos->x=100*i+50;
                pos->y=100*j+35;
                SDL_BlitSurface(bureau, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==12){
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(carrenoir, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==13){
                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 0));
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(carrenoir, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==14){
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(oss,NULL, ecran, pos);
                SDL_BlitSurface(carrenoir, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==15){
                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 200, 173, 127));
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(arbre, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==16){
                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 136, 46, 27));
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(arbre, NULL, ecran, pos);
            }
            if (tabcarte[i][j]==17){
                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 254, 254, 226));
                pos->x=100*i;
                pos->y=100*j;
                SDL_BlitSurface(arbre, NULL, ecran, pos);
            }

        }
    }
}
