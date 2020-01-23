#include "mesh.h"

Mesh::Mesh(Vertex* vertices, std::uint32_t numVertices)
{
    _drawCount = numVertices;

    glGenVertexArrays(1, &_vertexArrayObj);
    glBindVertexArray(_vertexArrayObj);

    glGenBuffers(NUM_BUFFERS, _vertexArrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexArrayBuffer[POSITION_VD]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &_vertexArrayObj);
}

void Mesh::Draw()
{
    glBindVertexArray(_vertexArrayObj);

    glDrawArrays(GL_TRIANGLES, 0, _drawCount);

    glBindVertexArray(0);
}

