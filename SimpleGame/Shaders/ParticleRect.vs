#version 330

layout(location = 0) in vec3 a_position;		// Attribute (vs input)
layout(location = 1) in vec4 a_color;
uniform vec4 u_trans;
uniform float u_scale;
uniform float u_timeElapsed;

out vec4 v_color;

const vec3 c_velocity = vec3(0.01f, 1.f, 0.f);
const vec3 g_gravity = vec3(0.f, -2.8f, 0.f);

void main()
{
	vec4 newPosition;
	newPosition.xyz =	u_scale * a_position.xyz * u_trans.w + 
						u_trans.xyz + c_velocity * u_timeElapsed + 
						0.5 * g_gravity * u_timeElapsed * u_timeElapsed;
	newPosition.xyz = u_scale * (a_position.xyz + u_trans.xyz);
	newPosition.w = 1;
	gl_Position = newPosition;
	v_color = a_color;
}