# Document de suivi individuel : 

ce que j’ai fait, les problemes, les solutions, les tests, les validations, les limites, les cas critiques, les exemples, les demos, les maths mobilisees, etc

Initialisation du projet et du git

Dessin des axes en mode Debug

Exercies sur les equa diff :

Démo de m(dv/dt) = G - kv
a pour solution : v(t) = G/k + A*e(-t/τ)

On dérive cette solution, et on arrive à : m(dv/dt) = -k * A * e(-t/τ)
puis on repart de m(dv/dt) = G - kv,
et en remplaçant k*v par la solution on retombe bien sur -kAe(-t/τ)

Difficulté : j'ai d'abord tenté de retrouver formellement le chemin entre dv/dt et la solution quand il suffisait de dériver la solution.

Expression de A :
	v(t) = G/k + A*e(-t/τ)
<=> v(t) - G/k = A*e(-t/τ)
<=> (v(t)-G/k) / e(-t/τ) = A

Pour tracer la courbe : on remplace par les valeurs à t=0 et on trouve A = -100/1,8

En traçant la courbe, la vitesse semble se stabiliser vers un peu plus de 55m/s.
Dans la mesure où la propulsion est constante et le coefficient de frottements aussi, il semble logique que la vitesse augmente jusqu'à se stabiliser :
    m(dv/dt) = G - kv
<=> dv/dt = (G-kv)/m
<=> dv/dt = G/m - k/m * v
<=> dv/dt = G/m - v/τ
or G/m est constant et v tend vers +∞, donc dv/dt tend vers 0.

En retraçant la courbe avec k = 0.65 USI plutôt que 1.8, le personnage étant plus aérodynamique atteint des vitesses plus élevées : + de 137 m/s au lieu de 55.
De plus, l'accélération du personnage (coeff. dir. de la tangente à la courbe) est plus importante que tout à l'heure en tout point.

Pour les 2 courbes : τ1 ≃ 671s puis τ2 ≃ 1858s.
À ces temps là : v1(t) semble commencer à se stabiliser à ce temps-là. Cela est moins visible pour v2(t) (le serait peut-être avec plus de valeurs).
Pour la solution théorique :
    v(τ) = G/k + A * e(-τ/τ)
<=> v(t) = G/k + A * 1/e(1) = G/k + A/e(1)
or G/k = -A, d'où :
    v(t) = -A + A/e(1)
<=> v(t) = -Ae(1)/e(1) + A/e(1)
<=> v(t) = A(-e(1) + 1) / e(1) = A * ((-e(1) +1) / e(1)) ≃ 2/3.
Or, en reprenant les questions précédentes, on a remarqué que A était la vitesse limite de notre module, puisque quand t -> +∞, e(-t/τ) -> 0.
Ainsi, τ représente le temps auquel on aura atteint les 2/3 de la vitesse max théorique, puisque les 2/3 de A.
