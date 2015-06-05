#ifdef GL_ES                                
precision lowp float;                        
#endif                                        
                    
uniform sampler2D u_texture;                
uniform sampler2D u_mask;				
uniform float factor;
uniform float width; 				
uniform float offset; 				
uniform vec3 color; 

varying vec4 v_fragmentColor;                
varying vec2 v_texCoord;

const float SQRT_2 = 1.414f;

void main()                                    
{                                            
	vec4 texColor = texture2D(u_texture, v_texCoord);
	// line (x+y-offset=0) offset:[0, 2] (2->0)
	//     |y
	//	   |
	// ____|0___ 1___2____x
	//     |	|
	// 	   |____|*
    float distance = abs(v_texCoord[0]+v_texCoord[1]-offset)/SQRT_2; 
	// linear gradient 
	// (1/width)x + y = 1
	distance = 1.0f-(1.0f/width)*distance;
	distance = max(distance, 0.0f);
	
    vec4 sample = vec4(0.0f,0.0f,0.0f,0.0f);
	sample.rgb = color * distance;
	sample.a = distance;
	
	// blend additive 
	float alpha = sample[3]*texColor[3];
	texColor[0] = texColor[0] + sample[0]*alpha*factor;
	texColor[1] = texColor[1] + sample[1]*alpha*factor;
	texColor[2] = texColor[2] + sample[2]*alpha*factor;
	gl_FragColor = v_fragmentColor * texColor;            
}