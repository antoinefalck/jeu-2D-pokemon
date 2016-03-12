#2D Pokemon game

Extraire le fichier avec la commande `tar xvzf pokemon.tgz`

Placez vous dans le repertoire pokemon `cd pokemon`

Installer les bibliothèques `<SDL/SDL.h>`, `<SDL/SDL_image.h>` et `<SDL/SDL_ttf.h>`

Sous Linux entrer les commandes dans le terminal
```
sudo apt-get install libsdl1.2-dev
sudo apt-get install libsdl-image1.2-dev
sudo apt-get install libsdl-ttf2.0-dev
```

Sous MAC OSX se rendre sur la page : http://www.libsdl.org/download-1.2.php et telecharger le paquet `SDL-1.2.14.dmg`. Prenez le `SDL.frameworks` qui se trouve dans `SDL.dmg` et placez le dans `Macintosh HD/Librabry/Frameworks`. Faire de meme pour `SDL_image` et `SDL_ttf` aux adresses http://www.libsdl.org/projects/SDL_image/release-1.2.html et http://www.libsdl.org/projects/SDL_ttf/release-1.2.html

S'il y a des problemes à la compilation, remplacer 
	`#include <SDL/SDL_image.h>` par `#include "SDL_image.h"` par exemple (faire de meme pour `SDL` et `SDL_ttf`)

Pour compiler taper la commande `make`

Pour lancer l'executable taper la commande `./main`
