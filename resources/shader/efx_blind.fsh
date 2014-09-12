#ifdef GL_ES                                
precision lowp float;                       
#endif                                      

uniform sampler2D texture0;					
uniform sampler2D texture1;					
uniform float flag;							
uniform float lineWidth;					
uniform float offset;						

varying vec4 v_fragmentColor;                
varying vec2 v_texCoord;                    

void main()														
{																
	//vec4 texColor = texture2D(texture1, v_texCoord);			
	float modPart = mod(v_texCoord[0], lineWidth);				
	float solidPart = (1.0-offset) * lineWidth;					
	// reduce tex-switch times									
	// (0, 1) (2, 1) (2, 3) (0, 3)								
	//modPart = modPart * flag;									
	//solidPart = solidPart * flag;								
	if (modPart > solidPart)			 						
	{														
		gl_FragColor = v_fragmentColor * texture2D(texture1, v_texCoord);			
	}															
	else														
	{															
		gl_FragColor = v_fragmentColor * texture2D(texture0, v_texCoord);			
	}														
}
