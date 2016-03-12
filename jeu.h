/**
 * \file jeu.h
 *
 * \brief
 *
 * \author Julien Claus
 * \date Avril 2015
 */

#ifndef __Pokemon___jeu__
#define __Pokemon___jeu__
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Fonction qui lance le jeu à partir du menu
 *
 * \param[in] ecran Fenêtre de l'application
 */

void jouer(SDL_Surface *ecran);

/**
 * \brief Fonction qui rempli un tableau d'entiers.
 *
 * Ce tableau d'entier rempli à partir d'un fichier a pour but de charger les cartes. Chaque caractère correspond à
 * un élément de la carte qui est placée à la position souhaitée. Cette position est tout simplement l'odre des caractères.
 *
 * param[in, out] tabcarte Tableau d'entier à remplir
 * param[in] fichier Fichier texte utilisé pour remplir le tableau
 */

void remplirTableau(int tabcarte[10][7],FILE *fichier);

/**
 * \brief Fonction qui gère le déplacement du joueur.
 *
 * param[in] ecran
 * param[in] tabcarte Tableau d'entier qui défini la carte sur laquelle le joueur est présent
 * param[in, out] pos Position du joueur en pixels ; (0;0) en haut à gauche
 * param[in] direction Direction du joueur, ou plutôt son orientation (haut, bas, gauche, droite)
 */

void deplacerJoueur(SDL_Surface *ecran, int tabcarte[10][7], SDL_Rect *pos, int direction);

/**
 * \brief Fonction qui rempli la carte à partir du tableau précédemment rempli.
 *
 * param[in] tabcarte
 * param[in] pos
 * param[in] arbre
 * param[in] centre
 * param[in] herbe
 * param[in] ecran
 * param[in] maison1
 * param[in] maison2
 * param[in] pnj1
 * param[in] bureau
 * param[in] carrenoir
 * param[in] oss
 */

void remplirmap(int tabcarte[10][7], SDL_Rect *pos ,SDL_Surface *arbre, SDL_Surface *centre,SDL_Surface *herbe, SDL_Surface *ecran,SDL_Surface *maison1, SDL_Surface *maison2,SDL_Surface * pnj1,SDL_Surface * bureau,SDL_Surface * carrenoir, SDL_Surface * oss);

#endif /* defined(__Pokemon___jeu__) */
