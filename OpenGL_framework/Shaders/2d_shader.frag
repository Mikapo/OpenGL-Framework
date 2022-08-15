
#version 330 core

layout(location = 0) out vec4 out_frag_color;

in OUT 
{
    vec2 tex_coordinates;
} shader_in;

uniform vec4 u_color = vec4(0.9f, 0.9f, 0.9f, 1.0f);

uniform int u_uses_texture = 0;
uniform sampler2D u_texture;

void main() 
{    
	if (u_uses_texture == 1)
		out_frag_color = texture(u_texture, shader_in.tex_coordinates);
	else
		out_frag_color = u_color;
}