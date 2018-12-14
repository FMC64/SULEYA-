uniform sampler2D texture;
uniform sampler2D base;
uniform sampler2D rough;

uniform vec3 lightpos;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    vec3 texnorm = vec3(pixel.xyz) * 2.0 - 1.0;
    texnorm.y = -texnorm.y;
    vec3 diff = lightpos - vec3(gl_TexCoord[0].xy * 512.0, 0.0);
    vec3 lightnorm = normalize(diff);
    float dist = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
    vec3 r = 2.0 * dot(lightnorm, texnorm) * texnorm - lightnorm;

    gl_FragColor = (texture2D(base, gl_TexCoord[0].xy)
    * dot(lightnorm, texnorm) * 300000.0) / dist;
    //+ dot(r, vec3(0.0, 0.0, 1.0)) * 0.1 * texture2D(rough, gl_TexCoord[0].xy);
}
