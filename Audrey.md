# Document de suivi individuel :

ce que j’ai fait, les problemes, les solutions, les tests, les validations, les limites, les cas critiques, les exemples, les demos, les maths mobilisees, etc

## Cours du 09/09/26

### Réponses aux questions du sujet

**1.2 Coordonnées physiques vs écran**

*(1) On note H la hauteur de l’écran en pixels et W sa largeur. Le monde physique sera centré sur l’écran. Quelle est la position écran du centre du monde?*

La position écran du centre du monde sera noté : x = W/2 et y = H/2

*(2) On note z le facteur de zoom, qu’on exprime en pixels par mètre. Pour une distance d dans le monde physique, que vaut la distance D à l’écran?*

D = d*z

## Cours du 10/09/26

### Continuation des réponses aux questions du sujet

*(3) Pour un point M de coordonnée horizontale x dans le monde physique, que vaut sa coordonnée X dans le monde écran?*

X = W/2 + x*z

*(4) Inversement, connaissant X, comment retrouver x?*

X = W/2 + (x * z)

=> X - W/2 = x * z

=> x = (X - W/2)/z

*(5) Pour un point M de coordonnée verticale y dans le monde physique, que vaut sa coordonnée Y dans le monde écran? Attention : en général les bibliothèques graphiques comptent les distances verticales à partir du haut de la fenêtre (l’axe des Y est donc inversé!).*

Y = -H + (y * z)

*(6) Inversement, connaissant Y , comment retrouver y?*

Y = -H + (y * z)

=> Y + H = y * z

=> y = (Y + H)/z


Ensuite j'ai essayé de fix les bug du code (qui étaient prévu pour une version anterieur)