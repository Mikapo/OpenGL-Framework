#version 330 core

layout (location = 0) in vec2 l_position;
layout (location = 1) in vec2 l_tex_coordinates;

out OUT 
{
    vec2 tex_coordinates;
} shader_out;

uniform mat4 u_projection = mat4(1);
uniform mat4 u_model = mat4(1);

void main() 
{
    gl_Position = u_projection *  u_model * vec4(l_position, 0, 1);
    shader_out.tex_coordinates = l_tex_coordinates;
}