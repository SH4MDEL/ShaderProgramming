#version 330

layout(location=0) out vec4 FragColor;

uniform vec4 u_color;
in vec4 v_color;

void main()
{
	FragColor = vec4(v_color.r, v_color.g, v_color.b, v_color.a);
}
