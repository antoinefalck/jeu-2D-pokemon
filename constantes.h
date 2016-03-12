/**
 * \version 1.0
 * \author Antoine Falck
 * \date Avril 2015
 *
 * \file constantes.h
 * \brief Répertorie les constantes du projet.
 *
 * Ce fichier contient toutes les constantes liés au programmes.
 *
 * Ce qui simplifie les choses lorsque l'on veut changer la taille de l'écran par exemple, il suffit de changer la valeur en question et de recompiler.
 *
 * \def TAILLE_CASE
 * \brief Taille de la case.
 *
 * Taille de la case en pixel.
 * La valeur par défault est 100 pixels.
 *
 * \def NB_CASES_LARGEUR
 * \brief Nombre de cases en largeur, ici 10.
 *
 * \def NB_CASES_HAUTEUR
 * \brief Nombre cases en hauteur, ici 7.
 *
 * \def LARGEUR_FENETRE
 * \brief Largeur de la fenêtre.
 *
 * Par définition \f$L_f=T.N_Lc\f$
 *
 * Avec \f$L_f\f$ la largeur de la fenêtre en pixel, \f$T\f$ la taille de la case en pixel, et \f$N_Lc\f$ le nombre de cases en largeur.
 *
 * \def HAUTEUR_FENETRE
 * \brief Hauteur de la fenêtre.
 *
 * Par définition \f$l_f=T.N_lc\f$
 *
 * Avec \f$l_f\f$ la hauteur de la fenêtre en pixel, \f$T\f$ la taille de la case en pixel, et \f$N_lc\f$ le nombre de cases en hauteur.
 *
 * \enum orientationJoueur
 * \brief Gère les quatre orientations du joueur.
 */

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

	#define TAILLE_CASE		100
	#define	NB_CASES_LARGEUR	10
	#define NB_CASES_HAUTEUR	7
	#define LARGEUR_FENETRE		TAILLE_CASE * NB_CASES_LARGEUR
	#define HAUTEUR_FENETRE		TAILLE_CASE * NB_CASES_HAUTEUR

	enum orientationJoueur {
		HAUT,		/**< Dans le cas où le joueur est orienté vers le haut. */
		BAS,		/**< Dans le cas où le joueur est orienté vers le bas. */
		GAUCHE,		/**< Dans le cas où le joueur est orienté vers la gauche. */
		DROITE		/**< Dans le cas où le joueur est orienté vers la droite. */
	};

#endif
