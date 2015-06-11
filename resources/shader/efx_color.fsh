#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D u_texture;
uniform vec3 color;

varying vec2 v_texCoord;
varying vec4 v_fragmentColor;

void main(void)  
{   
	vec4 texColor = texture2D(u_texture, v_texCoord);
	texColor.rgb = texColor.rgb * color;
	gl_FragColor = texColor;
}
