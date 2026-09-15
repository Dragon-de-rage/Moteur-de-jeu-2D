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

Pour tracer la courbe : on remplace par les valeurs à t=0 et on trouve A = 100/1,8

La vitesse semble se stabiliser vers 57m/s ou un peu moins.
Dans la mesure où la propulsion est constante et le coefficient de frottements aussi, il semble logique que la vitesse augmente jusqu'à se stabiliser
