#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in int vertAngle;
layout (location = 2) in float time;
layout (location = 3) in float stepAngle;
layout (location = 4) in float scale;

out float vector_color;

void main(void) {
	
	mat4 scaleMat = mat4(scale, 0.0, 0.0, 0.0,
						 0.0, scale, 0.0, 0.0,
						 0.0, 0.0, scale, 0.0,
						 0.0, 0.0, 0.0, 1.0);
	
	
	mat4 rotXMat = mat4(1.00000, 0.00000, 0.00000, 0.0,
						0.00000, cos(radians(vertAngle)),-sin(radians(vertAngle)), 0.0,
						0.00000, sin(radians(vertAngle)), cos(radians(vertAngle)), 0.0,
						0.00000, 0.00000, 0.00000, 1.0);
	
	mat4 rotTimeMat = mat4( cos(time), 0.0, sin(time), 0.0,
							0.0		 , 1.0, 0.0		 , 0.0,
						   -sin(time), 0.0, cos(time), 0.0,
						    0.0		 , 0.0, 0.0		 , 1.0);
	
	mat4 transStepMat = mat4( 1.0, 0.0, 0.0, 0.0,
							  0.0, 1.0, 0.0, 0.0,
							  0.0, 0.0,	1.0, 0.0,
							  0.7 * cos(radians(stepAngle)), 0.7 * sin(radians(stepAngle)),	0.0, 1.0);
	
	
	vector_color = gl_VertexID;
	
	gl_Position =  transStepMat * rotXMat * rotTimeMat * scaleMat * vec4(position.x, position.y, position.z, 1.0);
}