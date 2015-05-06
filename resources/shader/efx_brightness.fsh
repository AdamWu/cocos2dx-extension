#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D u_texture;
varying vec2 v_texCoord;
varying vec4 v_fragmentColor;

const float intensity_offset = 1.0;
const float intensity_scale = 2.0;

void main(void)  
{   
    vec4 texColor = texture2D(u_texture, v_texCoord);
	// gray value
	float gray = dot(texColor.rgb, vec3(0.3, 0.59, 0.11));
	// new gray
	float new_intensity = (gray + intensity_offset) * intensity_scale;
	
	// fixed color
	texColor *= new_intensity;
	texColor.r = 0.2 * texColor.a;
	texColor.g = 0.5 * texColor.a;
	texColor.b = 0.2 * texColor.a;
	
	gl_FragColor = texColor;
}   

