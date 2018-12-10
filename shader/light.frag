uniform sampler2D texture;

uniform vec3 lightpos;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    vec3 texnorm = vec3(pixel.xyz) * 2.0 - 1.0;
    vec3 diff = lightpos - vec3(gl_TexCoord[0].xy * 512.0, 0.0);
    vec3 lightnorm = normalize(diff);
    float dist = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;

    gl_FragColor = (vec4(1.0, 1.0, 1.0, 1.0) * dot(lightnorm, texnorm) * 16000.0) / dist;
}
