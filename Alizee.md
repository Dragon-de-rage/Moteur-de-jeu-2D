# Document de suivi individuel : 

ce que j’ai fait, les problemes, les solutions, les tests, les validations, les limites, les cas critiques, les exemples, les demos, les maths mobilisees, etc

*Question 1*

Réponse :
Le monde physique étant centré sur l’écran, le centre du monde correspond au centre de l’écran :

(X,Y) = ( W/2, H/2)

*Question 2*

Le facteur de zoom z représente le nombre de pixels par mètre.

Pour une distance d exprimée en mètres, la distance correspondante à l’écran est : D = z * d

*Question 3*

Réponse :
Pour une coordonnée physique horizontale x, on part du centre de l’écran puis on se déplace de x * z pixels vers la droite : X = W/2 + x * z

*Question 4*
Réponse :
On inverse la formule précédente : x = (X - W/2) / z

*Question 5*

Réponse :
L'axe vertical de l'écran est inversé par rapport au monde physique :

dans le monde physique, \(y\) augmente vers le haut ;
sur l'écran, \(Y\) augmente vers le bas. Y = H/2 - y * z 

*Question 6*

Réponse :
On inverse la formule précédente : y = (H/2 - Y) / z

*Question 7* 

using ScreenPoint = std::pair<int, int>;
using WorldPoint = std::pair<double, double>;

ScreenPoint toScreen(const WorldPoint &point)
{
    int X = W / 2 + point.first * z;
    int Y = H / 2 - point.second * z;

    return {X, Y};
}
La première coordonnée correspond à (x) et la deuxième à (y).

*Question 8*
WorldPoint toPhysical(const ScreenPoint &point)
{
    double x = (point.first - W / 2) / z;
    double y = (H / 2 - point.second) / z;

    return {x, y};
}
On retrouve ainsi les coordonnées physiques à partir des coordonnées écran.

*Question 9*

Réponse :
En mode Debug, il faut afficher les deux axes correspondant à (x=0) et (y=0).

L'axe x est une ligne horizontale passant par le centre de l'écran :

DEBUG_LINE(0, H / 2, W, H / 2, RED);

L'axe y est une ligne verticale passant par le centre :

DEBUG_LINE(W / 2, 0, W / 2, H, RED);

Les deux lignes rouges se croisent au centre de l'écran, qui correspond au point physique (0,0).