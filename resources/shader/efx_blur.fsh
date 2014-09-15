#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D u_texture;
varying vec2 v_texCoord;
varying vec4 v_fragmentColor;

uniform vec2 pix_size;

void main(void)  
{
	vec4 sum = vec4(0, 0, 0, 0);
	
	// nine-sample
	sum += texture2D(u_texture, v_texCoord - 4.0 * pix_size) * 0.05;
	sum += texture2D(u_texture, v_texCoord - 3.0 * pix_size) * 0.09;
	sum += texture2D(u_texture, v_texCoord - 2.0 * pix_size) * 0.12;
	sum += texture2D(u_texture, v_texCoord - 1.0 * pix_size) * 0.15;
	sum += texture2D(u_texture, v_texCoord                 ) * 0.16;
	sum += texture2D(u_texture, v_texCoord + 1.0 * pix_size) * 0.15;
	sum += texture2D(u_texture, v_texCoord + 2.0 * pix_size) * 0.12;
	sum += texture2D(u_texture, v_texCoord + 3.0 * pix_size) * 0.09;
	sum += texture2D(u_texture, v_texCoord + 4.0 * pix_size) * 0.05;

	gl_FragColor = sum;
}   

