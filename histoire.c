/**
 * \file histoire.c
 *
 * \brief Partie histoire du jeu Pokémon
 *
 * \version 2.3
 * \author Antoine Falck
 * \date Avril 2015
 */

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "histoire.h"
#include "discours.h"

void histoire(SDL_Surface *ecran) {
	SDL_Surface *fond=NULL, *texte=NULL, *chen=NULL, *pokedex=NULL, *pika=NULL, *nom1=NULL, *nom2=NULL, *nom3=NULL;
	SDL_Rect positionFond, positionTexte, positionChen, positionPokedex, positionPika, positionNom1, positionNom2, positionNom3;;
	SDL_Event event;
	TTF_Font *police=NULL;
	SDL_Color couleurNoire={0,0,0};
	char script[NB_FENETRE][NB_MAX_CARACTERE];
	char tiret1[124]="", tiret2[124]="", tiret3[124]="";

	TTF_Init();

	police=TTF_OpenFont("./texte/f25bank.ttf", 27);

	peech(script);

	int i=0;
	int continuer=1;

	positionFond.x=0;
	positionFond.y=0;

	fond=IMG_Load("./image/fond.jpg");
	chen=IMG_Load("./image/chen_v2.png");
	pokedex=IMG_Load("./image/pokedex_v2.png");
	pika=IMG_Load("./image/pika.png");

	sprintf(tiret1, "- %s   (1)", NOM1);
	sprintf(tiret2, "- %s   (2)", NOM2);
	sprintf(tiret3, "- %s   (3)", NOM3);

	nom1=TTF_RenderUTF8_Blended(police, tiret1, couleurNoire);
	nom2=TTF_RenderUTF8_Blended(police, tiret2, couleurNoire);
	nom3=TTF_RenderUTF8_Blended(police, tiret3, couleurNoire);

	positionChen.x=ecran->w/2 - chen->w/2;
	positionChen.y=233 - chen->h/2;

	positionPokedex.x=ecran->w/2 - pokedex->w/2;
	positionPokedex.y=233 - pokedex->h/2;

	positionPika.x=ecran->w/2 - pika->w/2;
	positionPika.y=233 - pika->h/2;

	positionNom2.x=ecran->w/3 - nom1->w/2;
	positionNom2.y=233 - nom1->h/2;

	positionNom1.x=positionNom2.x;
	positionNom1.y=positionNom2.y - 2*nom1->h;

	positionNom3.x=positionNom2.x;
	positionNom3.y=positionNom2.y + 2*nom1->h;

	positionTexte.x=80;
	positionTexte.y=540;

	while(continuer) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						continuer=0;
						break;
					case SDLK_RETURN:
						if(i==27) {
							continuer=0;
						}
						else {
							if(i==2) {
							}
							else
								i++;
						}
						break;
					case SDLK_AMPERSAND: case SDLK_1:
						sprintf(script[3], script[53], NOM1);
						sprintf(script[11], script[61], NOM1);
						sprintf(script[13], script[63], NOM1);
						sprintf(script[26], script[76], NOM1);
						i=3;
						break;
					case SDLK_WORLD_73: case SDLK_2:
						sprintf(script[3], script[53], NOM2);
						sprintf(script[11], script[61], NOM2);
						sprintf(script[13], script[63], NOM2);
						sprintf(script[26], script[76], NOM2);
						i=3;
						break;
					case SDLK_QUOTEDBL: case SDLK_3:
						sprintf(script[3], script[53], NOM3);
						sprintf(script[11], script[61], NOM3);
						sprintf(script[13], script[63], NOM3);
						sprintf(script[26], script[76], NOM3);
						i=3;
						break;
					default:
						break;
				}
				break;
		}

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		SDL_BlitSurface(fond, NULL, ecran, &positionFond);

		if(i==2) {
			SDL_BlitSurface(nom1, NULL, ecran, &positionNom1);
			SDL_BlitSurface(nom2, NULL, ecran, &positionNom2);
			SDL_BlitSurface(nom3, NULL, ecran, &positionNom3);
		}
		else {
			if(i==12 || i==13)
				SDL_BlitSurface(pika, NULL, ecran, &positionPika);
			else {
				if(i==23)
					SDL_BlitSurface(pokedex, NULL, ecran, &positionPokedex);
				else
					SDL_BlitSurface(chen, NULL, ecran, &positionChen);

			}

		}

		texte=TTF_RenderUTF8_Blended(police, script[i], couleurNoire);

		SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
		SDL_Flip(ecran);
	}

	TTF_CloseFont(police);
	TTF_Quit();

	SDL_FreeSurface(texte);
	SDL_FreeSurface(fond);
}

void peech(char script[NB_FENETRE][NB_MAX_CARACTERE]) {
	char part0[]=TEXT0, part1[]=TEXT1, part2[]=TEXT2;
	char part3[]=TEXT3, part4[]=TEXT4, part5[]=TEXT5;
	char part6[]=TEXT6, part7[]=TEXT7, part8[]=TEXT8;
	char part9[]=TEXT9, part10[]=TEXT10, part11[]=TEXT11;
	char part12[]=TEXT12, part13[]=TEXT13, part14[]=TEXT14;
	char part15[]=TEXT15, part16[]=TEXT16, part17[]=TEXT17;
	char part18[]=TEXT18, part19[]=TEXT19, part20[]=TEXT20;
	char part21[]=TEXT21, part22[]=TEXT22, part23[]=TEXT23;
	char part24[]=TEXT24, part25[]=TEXT25, part26[]=TEXT26, part27[]=TEXT27;
	sprintf(script[0], "%s", part0);
	sprintf(script[1], "%s", part1);
	sprintf(script[2], "%s", part2);
	sprintf(script[53], "%s", part3);
	sprintf(script[4], "%s", part4);
	sprintf(script[5], "%s", part5);
	sprintf(script[6], "%s", part6);
	sprintf(script[7], "%s", part7);
	sprintf(script[8], "%s", part8);
	sprintf(script[9], "%s", part9);
	sprintf(script[10], "%s", part10);
	sprintf(script[61], "%s", part11);
	sprintf(script[12], "%s", part12);
	sprintf(script[63], "%s", part13);
	sprintf(script[14], "%s", part14);
	sprintf(script[15], "%s", part15);
	sprintf(script[16], "%s", part16);
	sprintf(script[17], "%s", part17);
	sprintf(script[18], "%s", part18);
	sprintf(script[19], "%s", part19);
	sprintf(script[20], "%s", part20);
	sprintf(script[21], "%s", part21);
	sprintf(script[22], "%s", part22);
	sprintf(script[23], "%s", part23);
	sprintf(script[24], "%s", part24);
	sprintf(script[25], "%s", part25);
	sprintf(script[76], "%s", part26);
	sprintf(script[27], "%s", part27);
}
