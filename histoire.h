/**
 * \file histoire.h
 *
 * \brief Interface de l'histoire du jeu Pokémon
 *
 * \version 2.3
 * \author Antoine Falck
 * \date Avril 2015
 */


#ifndef DEF_JEU
#define DEF_JEU

	/**
	 * \def NB_FENETRE
	 * Nombre de fenêtre maximum que l'on peut ouvrir dans le petit
	 * encart réservé à l'affichage du texte
	 */

	#define NB_FENETRE		100

	/**
	 * \def NB_MAX_CARACTERE
	 * Nombre maximum de caractère que l'on peut placer dans le texte
	 * qui s'affiche lors de l'histoire
	 */

	#define NB_MAX_CARACTERE	1024

	/**
	 * \brief Fonction qui lance l'histoire du jeu Pokémon
	 *
	 * \param[in] ecran Fenêtre de l'application
	 */

	void histoire(SDL_Surface *ecran);

	/**
	 * \brief Fonction qui charge le texte de discours.h dans un tableau de tableau de caractères.
	 *
	 * \param[in,out] script Tableau de tableau de caractères, qui est chargé dans texte (SDL_Surface)
	 *			 dès que le joueur appuie sur "Enter".
	 */

	void peech(char script[NB_FENETRE][NB_MAX_CARACTERE]);

#endif
