#define glsl(src) "#version 330 core\n"#src




namespace vert {
    const char *shader = glsl(
    layout(location = 0) in vec3 position;
    void main()
    {
        gl_Position = vec4(position, 1.0);
    }
    );
}


namespace frag {
    const char *shader = glsl(
    out vec4 color;
    void main()
    {
        color = vec4(0.3, 0.8, 0.2, 1.0);
    }
    );
}

