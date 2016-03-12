/**
 * \mainpage Jeu 2D type Pokémon
 *
 * Cette application est un jeu de rôle sui s'inspire grandement des jeux Pokémon.
 *
 * Une fois l'application lancée le joueur est sur le menu, à partir de là il choisit de suivre l'histoire du jeu
 * (h), de voir les crédits (c), ou bien de jouer au jeu (j).
 *
 * Dans la partie jeu il y a deux interfaces entre lesquelles le joueur bascule de l'une à l'autre :
 * <ul>
 * <li> Une interface carte où le joueur se déplace sur la carte et peut intéragir avec l'extérieur</li>
 * <li> Une interface combat où le joueur lance son Pokémon pour qu'il combatte avec un Pokémon ennemi</li>
 * </ul>
 *
 * \file main.c
 *
 * Programme principal qui gère entre autre le lancement et
 * l'arrêt de la bibliothèque SDL.
 *
 * \version 1.0
 * \author Antoine Falck
 * \date Avril 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "histoire.h"
#include "jeu.h"
#include "credits.h"
#include "constantes.h"

/**
 * \brief Fonction qui fait appel à la SDL et charge l'écran (au sens interface graphique)
 *	  de l'application.
 *
 * \param[in] &ecran Pointeur sur ecran, ecran étant la fenêtre de l'application.
 */

void initialisationSDL(SDL_Surface **ecran);

/**
 * \brief Fonction qui a pour fonction de charger le menu du jeu.
 *
 * \param[in] &menu  Pointeur sur menu qui est en fait l'image du menu que l'on
 *		     collera plus tard sur ecran (la fenêtre de l'application).
 * \param[in] &positionMenu  Pointeur sur positionMenu qui gère la position de l'image "menu"
 *			     à coller sur la fenêtre.
 */

void chargementMenu(SDL_Surface **menu, SDL_Rect *positionMenu);

/**
 * \brief Fonction qui permet d'afficher le menu chargé précédemment.
 *
 * \param[in] ecran La surface qui recevera le collage.
 * \param[in] menu La surface collée.
 * \param[in] positionMenu : La position de la surface collée.
 */

void affichageMenu(SDL_Surface *ecran, SDL_Surface *menu, SDL_Rect positionMenu);

/**
 * \brief Fonction qui ferme la SDL et désalloue les surfaces (SDL_Surface) allouées.
 *
 * \param[in] ecran Première surface allouée.
 * \param[in] menu Deuxième surface allouée.
 */

void fermetureSDL(SDL_Surface *ecran, SDL_Surface *menu);

/**
 * \brief Fonction principale. Elle lance l'application et fait l'appel de la SDL.
 *
 * \param[in] argc
 * \param[in] argv
 * \return EXIT_SUCCESS ou EXIT_FAILURE
 */

int main(int argc, char *argv[]) {

	SDL_Surface *ecran=NULL, *menu=NULL;
	SDL_Rect positionMenu;
	SDL_Event event;

	int continuer=1;

	initialisationSDL(&ecran);
	chargementMenu(&menu, &positionMenu);

	while(continuer) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				continuer=0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						continuer=0;
						break;
					case SDLK_j:
						jouer(ecran);
						break;
					case SDLK_h:
						histoire(ecran);
						break;
					case SDLK_c:
						credits(ecran);
						break;
					default:
						break;
				}
				break;
		}
		affichageMenu(ecran, menu, positionMenu);
	}

	fermetureSDL(ecran, menu);
	return EXIT_SUCCESS;
}

void initialisationSDL(SDL_Surface **ecran) {
	if(SDL_Init(SDL_INIT_VIDEO)==-1) {
		fprintf(stderr, "Erreur initialisation SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	*ecran=SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
	SDL_ShowCursor(SDL_DISABLE);		// Cache la souris
}

void chargementMenu(SDL_Surface **menu, SDL_Rect *positionMenu) {
	*menu=IMG_Load("./image/menu.jpg");

	positionMenu->x=0;
	positionMenu->y=0;
}

void affichageMenu(SDL_Surface *ecran, SDL_Surface *menu, SDL_Rect positionMenu) {
	SDL_FillRect(ecran, NULL, 0xffffff);
	SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
	SDL_Flip(ecran);
}

void fermetureSDL(SDL_Surface *ecran, SDL_Surface *menu) {
	SDL_FreeSurface(menu);
	SDL_FreeSurface(ecran);
	SDL_Quit();
}
