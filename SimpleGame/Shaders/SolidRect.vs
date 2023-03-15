#version 330

layout(location = 0) in vec3 a_position;		// Attribute (vs input)
layout(location = 1) in vec3 a_color;
uniform vec4 u_trans;
uniform float u_scale;

void main()
{
	vec4 newPosition;
	newPosition.xy = u_scale * a_position.xy * u_trans.w + u_trans.xy;
	newPosition.z = 0;
	newPosition.w = 1;
	gl_Position = newPosition;
}
