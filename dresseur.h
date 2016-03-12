/**
 * \file dresseur.h
 *
 * \brief
 *
 * \author Pierre-Antoine Chantal et Julien Violet
 * \date Mai 2015
 */

#ifndef __DRESSEUR__H__
#define __DRESSEUR__H__

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

/**
 * \brief Les différents types de Pokémon et d'attaques.
 */

typedef enum type{TERRE, EAU, FEU, PLANTE, NORMAL, COMBAT, ROCHE, VOL, ELEK} Type;

/**
 * \brief Structure d'une attaque
 */

typedef struct attaque
{
    SDL_Surface *imageEnnemi;	/**< Surface de l'attaque si elle est lancée par le Pokémon ennemi sur le Pokémon allié. */
    SDL_Surface *imageAllie;	/**< Surface de l'attaque si elle est lancée par le Pokémon allié sur le Pokémon ennemi. */
    const char* nom;		/**< Nom de l'attaque. */
    Type type;			/**< Type de l'attaque. */
    int precision;		/**< Précision de l'attaque. C'est ce paramètre qui fait que des fois l'attaque rate. */
    int degatBase;		/**< Dégâts sans le coefficient de multiplication. */
    int degatParNiveau;
    int degatParForce;
}Attaque;

/**
 * \brief Structure Pokémon
 */

typedef struct pokemon
{
    SDL_Surface *imageAllie;	/**< Surface du Pokémon s'il est du côté allié. */
    SDL_Surface *imageEnnemi;	/**< Surface du Pokémon s'il est du côté ennemi. */
    const char* nom;		/**< Nom du Pokémon. */
    int vie;			/**< Points de vie actuels du Pokémon. */
    int vieMax;			/**< Points de vie maximums. */
    int force;
    int vitesse;
    int niveau;
    Type type;			/**< Type du Pokémon. */
    int experience;
    Attaque attaque1;
    Attaque attaque2;
    Attaque attaque3;
    Attaque attaque4;
}Pokemon;

/**
 * \brief Fonction qui lance le combat.
 *
 * param[in] ecran
 * param[in, out] niveauPika
 * param[in] numeroEnnemi
 * param[in] niveauEnnemi
 * param[in, out] ko
 */

void lancerCombat(SDL_Surface *ecran, int *niveauPika, int numeroEnnemi, int niveauEnnemi, int* ko);

/**
 * \brief Fonction qui permet d'égaliser les statisques des deux Pokémon qui combattent.
 *
 * param[in, out] a
 * param[in] b
 */

void egaliteStatistiques (Pokemon *a, Pokemon b);

/**
 * \brief Fonction qui permet d'égaliser les attaques des deux Pokémon qui combattent.
 *
 * param[in, out] a
 * param[in] b
 */

void egaliteAttaque (Attaque *a, Attaque b);

/**
 * \brief Fonction qui fait la temporisation entre les évènements du combat.
 */

void temporisation(void);

/**
 * \brief Fonction qui gère les coups critiques.
 */

int crit();

/**
 * \brief Fonction qui gère le coefficient multiplicateur.
 *
 * Suivant les types des Pokémon les dégats sont plus ou moins important. Par exemple un Pokémon FEU
 * ne fera pas beaucoup de dégâts sur un Pokémon EAU. Cette fonction permet donc de gérer le coeficient
 * multiplicateur des dégats d'une certaine attaque sur un certain type de Pokémon.
 *
 * param[in] A
 * param[in] B
 */

int coef(Type A, Type D);

/**
 * \brief Fonction qui permet d'afficher le texte des attaques.
 *
 * param[in] nomAtak
 * param[in] texteAtak
 * param[in] position
 * param[in] police
 * param[in] ecran
 */

void afficherTexteAttaque(const char* nomAtak, SDL_Surface texteAtak, SDL_Rect position, TTF_Font police, SDL_Surface ecran);

#endif // __DRESSEUR__H__
