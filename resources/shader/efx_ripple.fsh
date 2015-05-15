#ifdef GL_ES
precision mediump float;
#endif

varying vec2 v_texCoord;
varying vec4 v_fragmentColor;

uniform sampler2D u_texture;
uniform sampler2D u_texNoise;
uniform float u_time;

uniform float u_factor_tile;
uniform float u_factor_noise;
uniform float u_factor_speed;

void main() 
{
	vec2 uv = v_texCoord;

    float offset = u_time*u_factor_speed;

    vec2 texCoordNormal = uv * u_factor_tile;
    texCoordNormal += offset;

    vec3 normal = texture2D(u_texNoise, texCoordNormal).rgb*2.0-1.0;

    // disturbed the final texture cooridnate using the normal texture
    vec2 uv2 =  uv + normal.xy * u_factor_noise;

	gl_FragColor = texture2D(u_texture, uv2);
} 