#include "Tema1object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* object2D::CreateScor(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
         VertexFormat(corner + glm::vec3(0, 0, 0), color),
        VertexFormat(corner + glm::vec3(200,0 , 0), color),
        VertexFormat(corner + glm::vec3(200,50, 0), color),
        VertexFormat(corner + glm::vec3(0, 50, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}




Mesh* object2D::CreateGlont(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
         VertexFormat(corner + glm::vec3(-5, -20, 0), color),
        VertexFormat(corner + glm::vec3(5, -20, 0), color),
        VertexFormat(corner + glm::vec3(5,20, 0), color),
        VertexFormat(corner + glm::vec3(-5, 20, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}





Mesh* object2D::CreateFirstWing(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        //cioc
        VertexFormat(corner + glm::vec3(-100, 100, 0), glm::vec3(0, 255, 255)),
        VertexFormat(corner + glm::vec3(-100, 0, 0), glm::vec3(0, 255, 255)),
        VertexFormat(corner + glm::vec3(-20, 0, 0), glm::vec3(0, 255, 255))
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2  //0
    };

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateSecondWing(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-100, -100, 0), glm::vec3(0, 255, 255)),
        VertexFormat(corner + glm::vec3(-100, 0, 0), glm::vec3(0, 255, 255)),
        VertexFormat(corner + glm::vec3(-20, 0, 0), glm::vec3(0, 255, 255))
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2  //0
    };

    square->InitFromData(vertices, indices);
    return square;
}



Mesh* object2D::CreateCioc(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        //cioc
    VertexFormat(corner + glm::vec3(0, 40, 0), glm::vec3(255, 0, 0)),//0
    VertexFormat(corner + glm::vec3(0, -40, 0), glm::vec3(255, 0, 0)),//1
    VertexFormat(corner + glm::vec3(70, 0, 0), glm::vec3(255, 0, 0))//2
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 //0
    };

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateHead(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    float radius = 50;

    const int numberOfVertices = 360;
    std::vector<VertexFormat> verticesFirstCircle;
    std::vector<unsigned int> indicesFirstCircle;
    GLfloat twicePi = 2.0f * M_PI;

    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];

    circleVerticesX[0] = leftBottomCorner.x;
    circleVerticesY[0] = leftBottomCorner.y;
    circleVerticesZ[0] = leftBottomCorner.z;

    for (int i = 1; i < numberOfVertices; i++)
    {
        circleVerticesX[i] = leftBottomCorner.x + (radius * cos(i * twicePi / numberOfVertices - 2));
        circleVerticesY[i] = leftBottomCorner.y + (radius * sin(i * twicePi / numberOfVertices - 2));
        circleVerticesZ[i] = leftBottomCorner.z;
    }

    //cap
    for (int i = 0; i < numberOfVertices; i++)
    {
        verticesFirstCircle.push_back(VertexFormat(glm::vec3(circleVerticesX[i], circleVerticesY[i], circleVerticesZ[i]), glm::vec3(255, 255, 255)));
    }

    for (int i = 1; i < numberOfVertices - 1; i++)
    {
        indicesFirstCircle.push_back(0);
        indicesFirstCircle.push_back(i);
        indicesFirstCircle.push_back(i + 1);
    }

    indicesFirstCircle.push_back(0);
    indicesFirstCircle.push_back(numberOfVertices - 1);
    indicesFirstCircle.push_back(1);

    Mesh* square = new Mesh(name);
    square->InitFromData(verticesFirstCircle, indicesFirstCircle);
    return square;
}



Mesh* object2D::CreateViata(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    float radius = 15;

    const int numberOfVertices = 360;
    std::vector<VertexFormat> verticesFirstCircle;
    std::vector<unsigned int> indicesFirstCircle;
    GLfloat twicePi = 2.0f * M_PI;

    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];

    circleVerticesX[0] = leftBottomCorner.x;
    circleVerticesY[0] = leftBottomCorner.y;
    circleVerticesZ[0] = leftBottomCorner.z;

    for (int i = 1; i < numberOfVertices; i++)
    {
        circleVerticesX[i] = leftBottomCorner.x + (radius * cos(i * twicePi / numberOfVertices - 2));
        circleVerticesY[i] = leftBottomCorner.y + (radius * sin(i * twicePi / numberOfVertices - 2));
        circleVerticesZ[i] = leftBottomCorner.z;
    }

    //cap
    for (int i = 0; i < numberOfVertices; i++)
    {
        verticesFirstCircle.push_back(VertexFormat(glm::vec3(circleVerticesX[i], circleVerticesY[i], circleVerticesZ[i]), glm::vec3(255, 0, 0)));
    }

    for (int i = 1; i < numberOfVertices - 1; i++)
    {
        indicesFirstCircle.push_back(0);
        indicesFirstCircle.push_back(i);
        indicesFirstCircle.push_back(i + 1);
    }

    indicesFirstCircle.push_back(0);
    indicesFirstCircle.push_back(numberOfVertices - 1);
    indicesFirstCircle.push_back(1);

    Mesh* square = new Mesh(name);
    square->InitFromData(verticesFirstCircle, indicesFirstCircle);
    return square;
}



Mesh* object2D::CreateHeadBody(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    float radius = 40;

    const int numberOfVertices = 360;
    std::vector<VertexFormat> verticesFirstCircle;
    std::vector<unsigned int> indicesFirstCircle;
    GLfloat twicePi = 2.0f * M_PI;

    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];

    circleVerticesX[0] = leftBottomCorner.x;
    circleVerticesY[0] = leftBottomCorner.y;
    circleVerticesZ[0] = leftBottomCorner.z;

    for (int i = 1; i < numberOfVertices; i++)
    {
        circleVerticesX[i] = leftBottomCorner.x + (radius * cos(i * twicePi / numberOfVertices - 2));
        circleVerticesY[i] = leftBottomCorner.y + (radius * sin(i * twicePi / numberOfVertices - 2));
        circleVerticesZ[i] = leftBottomCorner.z;
    }

    //cap
    for (int i = 0; i < numberOfVertices; i++)
    {
        verticesFirstCircle.push_back(VertexFormat(glm::vec3(circleVerticesX[i], circleVerticesY[i], circleVerticesZ[i]), glm::vec3(255, 255, 255)));
    }

    for (int i = 1; i < numberOfVertices - 1; i++)
    {
        indicesFirstCircle.push_back(0);
        indicesFirstCircle.push_back(i);
        indicesFirstCircle.push_back(i + 1);
    }

    indicesFirstCircle.push_back(0);
    indicesFirstCircle.push_back(numberOfVertices - 1);
    indicesFirstCircle.push_back(1);

    /////////////////////////////////////


        //corp

    verticesFirstCircle.push_back(VertexFormat(corner + glm::vec3(-150,70, 0), glm::vec3(255, 0, 255)));//0sus
    verticesFirstCircle.push_back(VertexFormat(corner + glm::vec3(-159, -70, 0), glm::vec3(255, 0, 255)));//1

    verticesFirstCircle.push_back(VertexFormat(corner + glm::vec3(0, 40, 0), glm::vec3(255, 0, 255)));
    verticesFirstCircle.push_back(VertexFormat(corner + glm::vec3(0, -40, 0), glm::vec3(255, 0, 255)));
    verticesFirstCircle.push_back(VertexFormat(corner + glm::vec3(70, 0, 0), glm::vec3(255, 0, 255)));



    indicesFirstCircle.push_back(0);
    indicesFirstCircle.push_back(numberOfVertices);
    indicesFirstCircle.push_back(numberOfVertices + 1);

    indicesFirstCircle.push_back(numberOfVertices + 2);
    indicesFirstCircle.push_back(numberOfVertices + 3);
    indicesFirstCircle.push_back(numberOfVertices + 4);
    //indicesFirstCircle.push_back(numberOfVertices + 0);

   

    Mesh* square = new Mesh(name);

    square->InitFromData(verticesFirstCircle, indicesFirstCircle);

    return square;
}


