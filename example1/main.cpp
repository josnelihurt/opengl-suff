#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"

using namespace std;

int main()
{
    Display display(800, 600, "my new wnd");

    Vertex vertices[] = {
        Vertex{glm::vec3{-0.5f, -0.5f, 0}},
        Vertex{glm::vec3{0, 0.5f, 0}},
        Vertex{glm::vec3{0.5f, -0.5f, 0}}};
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    while(!display.IsClose()){
        display.Clear(0.0f,0.15f,0.3f,1.0f);

        mesh.Draw();

        display.Update();
    }
    return 0;
}
