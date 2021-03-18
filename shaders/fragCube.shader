#version 450 core

in float vector_color;

out vec4 color;

void main() {

	int faceID = int(vector_color/6);
	switch(faceID) {
	case 0:
		color = vec4(0.0, 0.0, 1.0, 1.0);
		break;
	case 1:
		color = vec4(0.0, 1.0, 1.0, 1.0);
		break;
	case 2:
		color = vec4(1.0, 0.0, 1.0, 1.0);
		break;
	case 3:
		color = vec4(1.0, 1.0, 0.0, 1.0);
		break;
	case 4:
		color = vec4(1.0, 0.0, 0.0, 1.0);
		break;
	case 5:
		color = vec4(0.0, 1.0, 0.0, 1.0);
		break;
	}



	//color = vec4(1.0, 1.0, 1.0, 1.0);
}
