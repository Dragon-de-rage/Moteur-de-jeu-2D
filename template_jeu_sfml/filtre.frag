uniform sampler2D texture;
uniform float time;

void main() {
    // Coordonnées normalisées du pixel actuel (entre 0.0 et 1.0)
    vec2 uv = gl_TexCoord[0].xy;

    // Effet d'ondulation (eau / chaleur)
    uv.x += sin(uv.y * 20.0 + time * 3.0) * 0.01;
    uv.y += cos(uv.x * 20.0 + time * 3.0) * 0.01;

    // Lire la couleur du pixel à la nouvelle position
    vec4 pixel = texture2D(texture, uv);

    // Filtre couleur (ex: teinte cyberpunk / cycle de couleurs)
    pixel.r *= 0.8 + 0.2 * sin(time);
    pixel.b *= 0.8 + 0.2 * cos(time);

    // Appliquer le résultat final
    gl_FragColor = pixel * gl_Color;
}
