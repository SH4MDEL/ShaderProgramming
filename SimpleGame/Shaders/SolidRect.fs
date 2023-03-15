#version 330

layout(location=0) out vec4 FragColor;

uniform vec4 u_color;

void main()
{
	FragColor = vec4(u_color.r, u_color.g, u_color.b, u_color.a);
}
