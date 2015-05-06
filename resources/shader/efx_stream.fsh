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

void main()                                    
{                                            
	vec4 texColor = texture2D(u_texture, v_texCoord);
	// line (x+y-offset=0) offset:[0, 2] (2->0)
	//     |y
	//	   |
	// ____|0___ 1___2____x
	//     |	|
	// 	   |____|*
    float distance = abs(v_texCoord[0]+v_texCoord[1]-offset)/1.414; 
	// linear gradient 
	// (1/width)x + y = 1
	distance = 1.0-(1.0/width)*distance;
	distance = max(distance, 0.0);
    vec4 sample = vec4(0.0,0.0,0.0,0.0);
	sample[0] = color[0] * distance;
	sample[1] = color[1] * distance;
	sample[2] = color[2] * distance;
	sample[3] = distance;
	
	// blend additive 
	float alpha = sample[3]*texColor[3];
	texColor[0] = texColor[0] + sample[0]*alpha*factor;
	texColor[1] = texColor[1] + sample[1]*alpha*factor;
	texColor[2] = texColor[2] + sample[2]*alpha*factor;
	gl_FragColor = v_fragmentColor * texColor;            
}