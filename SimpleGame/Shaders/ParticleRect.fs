#version 330

layout(location=0) out vec4 FragColor;
uniform vec4 u_color;

void main()
{
	FragColor = vec4(u_color.x, u_color.y, u_color.z, u_color.w);
}
