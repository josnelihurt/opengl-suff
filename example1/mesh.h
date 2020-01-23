#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <stdint.h>

struct Vertex
{
    glm::vec3 pos;
};

class Mesh
{
public:
    Mesh(Vertex* vertices, std::uint32_t numVertices);
    void Draw();
    virtual ~Mesh();
private:
    enum{
        POSITION_VD= 0,
        NUM_BUFFERS
    };

    GLuint _vertexArrayObj;
    GLuint _vertexArrayBuffer[NUM_BUFFERS];
    std::uint32_t _drawCount;
};
