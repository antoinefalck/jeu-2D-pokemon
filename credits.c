/**
 * \file credits.c
 *
 * \brief Partie crédits du jeu Pokémon
 *
 * Petit commentaire sur le code, on remarque qu'on a dû créer 16
 * pointeurs sur SDL_Surface pour chaque ligne de texte. En effet
 * c'est la seule technique possible.
 *
 * Il est impossible de créer un tableau de pointeur sur SDL_Surface
 * ou bien d'inclure un symbole (type "\n") dans le char pour pouvoir
 * sauter une ligne.
 *
 * \version 1.0
 * \author Antoine Falck
 * \date Avril 2015
 */

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "credits.h"
#include "discours.h"

void credits(SDL_Surface *ecran) {
	SDL_Surface *texte1=NULL, *texte2=NULL, *texte3=NULL, *texte4=NULL;
	SDL_Surface *texte5=NULL, *texte6=NULL, *texte7=NULL, *texte8=NULL;
	SDL_Surface *texte9=NULL, *texte10=NULL, *texte11=NULL, *texte12=NULL;
	SDL_Surface *texte13=NULL, *texte14=NULL, *texte15=NULL, *texte16=NULL;
	SDL_Surface *texte17=NULL, *texte18=NULL;
	SDL_Surface *banniere=NULL;
	SDL_Rect positionTexte[17];
	SDL_Rect positionBanniere1, positionBanniere2;
	SDL_Event event;
	TTF_Font *police=NULL;
	SDL_Color couleurNoire={0, 0, 0}, couleurBlanche={255, 255, 255};
	int continuer;
	int i;
	int saut[]={0, 3, 4, 8, 10, 14, 15, 17, 19, 21, 25, 27, 31, 33, 37, 39, 43, 44};
	int tempsPrecedent=0, tempsActuel=0;
	char credit1[124]="", credit2[124]="", credit3[124]="", credit4[124]="";
	char credit5[124]="", credit6[124]="", credit7[124]="", credit8[124]="";
	char credit9[124]="", credit10[124]="", credit11[124]="", credit12[124]="";
	char credit13[124]="", credit14[124]="", credit15[124]="", credit16[124]="";
	char credit17[124]="", credit18[124]="";

	continuer=1;

	sprintf(credit1, "%s", CREDIT1);
	sprintf(credit2, "%s", CREDIT2);
	sprintf(credit3, "%s", CREDIT3);
	sprintf(credit4, "%s", CREDIT4);
	sprintf(credit5, "%s", CREDIT5);
	sprintf(credit6, "%s", CREDIT6);
	sprintf(credit7, "%s", CREDIT7);
	sprintf(credit8, "%s", CREDIT8);
	sprintf(credit9, "%s", CREDIT9);
	sprintf(credit10, "%s", CREDIT10);
	sprintf(credit11, "%s", CREDIT11);
	sprintf(credit12, "%s", CREDIT12);
	sprintf(credit13, "%s", CREDIT13);
	sprintf(credit14, "%s", CREDIT14);
	sprintf(credit15, "%s", CREDIT15);
	sprintf(credit16, "%s", CREDIT16);
	sprintf(credit17, "%s", CREDIT17);
	sprintf(credit18, "%s", CREDIT18);

	TTF_Init();

	police=TTF_OpenFont("./texte/f25bank.ttf", 27);

	texte1=TTF_RenderUTF8_Shaded(police, credit1, couleurNoire, couleurBlanche);
	texte2=TTF_RenderUTF8_Shaded(police, credit2, couleurNoire, couleurBlanche);
	texte3=TTF_RenderUTF8_Shaded(police, credit3, couleurNoire, couleurBlanche);
	texte4=TTF_RenderUTF8_Shaded(police, credit4, couleurNoire, couleurBlanche);
	texte5=TTF_RenderUTF8_Shaded(police, credit5, couleurNoire, couleurBlanche);
	texte6=TTF_RenderUTF8_Shaded(police, credit6, couleurNoire, couleurBlanche);
	texte7=TTF_RenderUTF8_Shaded(police, credit7, couleurNoire, couleurBlanche);
	texte8=TTF_RenderUTF8_Shaded(police, credit8, couleurNoire, couleurBlanche);
	texte9=TTF_RenderUTF8_Shaded(police, credit9, couleurNoire, couleurBlanche);
	texte10=TTF_RenderUTF8_Shaded(police, credit10, couleurNoire, couleurBlanche);
	texte11=TTF_RenderUTF8_Shaded(police, credit11, couleurNoire, couleurBlanche);
	texte12=TTF_RenderUTF8_Shaded(police, credit12, couleurNoire, couleurBlanche);
	texte13=TTF_RenderUTF8_Shaded(police, credit13, couleurNoire, couleurBlanche);
	texte14=TTF_RenderUTF8_Shaded(police, credit14, couleurNoire, couleurBlanche);
	texte15=TTF_RenderUTF8_Shaded(police, credit15, couleurNoire, couleurBlanche);
	texte16=TTF_RenderUTF8_Shaded(police, credit16, couleurNoire, couleurBlanche);
	texte17=TTF_RenderUTF8_Shaded(police, credit17, couleurNoire, couleurBlanche);
	texte18=TTF_RenderUTF8_Shaded(police, credit18, couleurNoire, couleurBlanche);

	banniere=SDL_LoadBMP("./image/banniere.bmp");

	positionTexte[0].x=ecran->w/2 - texte1->w/2;
	positionTexte[0].y=ecran->h;

	positionTexte[1].x=ecran->w/2 - texte2->w/2;
	positionTexte[2].x=ecran->w/2 - texte3->w/2;
	positionTexte[3].x=ecran->w/2 - texte4->w/2;
	positionTexte[4].x=ecran->w/2 - texte5->w/2;
	positionTexte[5].x=ecran->w/2 - texte6->w/2;
	positionTexte[6].x=ecran->w/2 - texte7->w/2;
	positionTexte[7].x=ecran->w/2 - texte8->w/2;
	positionTexte[8].x=ecran->w/2 - texte9->w/2;
	positionTexte[9].x=ecran->w/2 - texte10->w/2;
	positionTexte[10].x=ecran->w/2 - texte11->w/2;
	positionTexte[11].x=ecran->w/2 - texte12->w/2;
	positionTexte[12].x=ecran->w/2 - texte13->w/2;
	positionTexte[13].x=ecran->w/2 - texte14->w/2;
	positionTexte[14].x=ecran->w/2 - texte15->w/2;
	positionTexte[15].x=ecran->w/2 - texte16->w/2;
	positionTexte[16].x=ecran->w/2 - texte17->w/2;
	positionTexte[17].x=ecran->w/2 - texte18->w/2;

	positionBanniere1.x=0;
	positionBanniere1.y=0;

	positionBanniere2.x=0;
	positionBanniere2.y=ecran->h - banniere->h;

	for (i=1 ; i<=17 ; i++) {
		positionTexte[i].y=positionTexte[0].y + saut[i]*texte1->h;
	}

	while(continuer) {
		SDL_PollEvent(&event);

		tempsActuel=SDL_GetTicks();
		if(tempsActuel-tempsPrecedent>20) {
			for (i=0 ; i<=17 ; i++)
				positionTexte[i].y--;
			tempsPrecedent=tempsActuel;
		}
		else
			SDL_Delay(20-tempsActuel+tempsPrecedent);

		if(tempsActuel>=48000)
			continuer=0;

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

		SDL_BlitSurface(texte1, NULL, ecran, &positionTexte[0]);
		SDL_BlitSurface(texte2, NULL, ecran, &positionTexte[1]);
		SDL_BlitSurface(texte3, NULL, ecran, &positionTexte[2]);
		SDL_BlitSurface(texte4, NULL, ecran, &positionTexte[3]);
		SDL_BlitSurface(texte5, NULL, ecran, &positionTexte[4]);
		SDL_BlitSurface(texte6, NULL, ecran, &positionTexte[5]);
		SDL_BlitSurface(texte7, NULL, ecran, &positionTexte[6]);
		SDL_BlitSurface(texte8, NULL, ecran, &positionTexte[7]);
		SDL_BlitSurface(texte9, NULL, ecran, &positionTexte[8]);
		SDL_BlitSurface(texte10, NULL, ecran, &positionTexte[9]);
		SDL_BlitSurface(texte11, NULL, ecran, &positionTexte[10]);
		SDL_BlitSurface(texte12, NULL, ecran, &positionTexte[11]);
		SDL_BlitSurface(texte13, NULL, ecran, &positionTexte[12]);
		SDL_BlitSurface(texte14, NULL, ecran, &positionTexte[13]);
		SDL_BlitSurface(texte15, NULL, ecran, &positionTexte[14]);
		SDL_BlitSurface(texte16, NULL, ecran, &positionTexte[15]);
		SDL_BlitSurface(texte17, NULL, ecran, &positionTexte[16]);
		SDL_BlitSurface(texte18, NULL, ecran, &positionTexte[17]);

		SDL_BlitSurface(banniere, NULL, ecran, &positionBanniere1);
		SDL_BlitSurface(banniere, NULL, ecran, &positionBanniere2);

		SDL_Flip(ecran);

	}

	TTF_CloseFont(police);
	TTF_Quit();

	SDL_FreeSurface(texte1);
	SDL_FreeSurface(texte2);
	SDL_FreeSurface(texte3);
	SDL_FreeSurface(texte4);
	SDL_FreeSurface(texte5);
	SDL_FreeSurface(texte6);
	SDL_FreeSurface(texte7);
	SDL_FreeSurface(texte8);
	SDL_FreeSurface(texte9);
	SDL_FreeSurface(texte10);
	SDL_FreeSurface(texte11);
	SDL_FreeSurface(texte12);
	SDL_FreeSurface(texte13);
	SDL_FreeSurface(texte14);
	SDL_FreeSurface(texte15);
	SDL_FreeSurface(texte16);
	SDL_FreeSurface(texte17);
	SDL_FreeSurface(texte18);

	SDL_FreeSurface(banniere);
}
