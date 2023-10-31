#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>
#include <cstdlib>
#include "lab_m1/Tema1/Tema1transform2D.h"
#include "lab_m1/Tema1/Tema1object2D.h"
#include <cmath>

using namespace std;
using namespace m1;
float squareSide;
 //COORDONATE
int tx=500;
int ty=100;
int rad = 0;
float cornerX;
float cornerY;
float speed = 7;
float scor = 0;

//TIMPI
float limit_time = 4;
float game_time;

//VITEZE
float angle = 0.777;
float incX = speed * cos(angle);
float incY = speed * sin(angle);

float omega1 = 0;
float  omega2 = 0;

int combo_ducks;





int viata = 3;
int gloante_full = 3;
int gloante = 3;

bool free_duck = false;
bool is_dead = false;
bool exit_screen = false;





int nr_ducks;
Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{

    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);



    glm::vec3 corner = glm::vec3(0, 0, 0);
    squareSide = 200;

    

    float cx = corner.x + squareSide / 2;
    float cy = corner.y + squareSide / 2;
    cornerX = cx;
    cornerY = cy;


    
    translateX = 0;
    translateY = 0;

    
    scaleX = 1;
    scaleY = 1;

    
    angularStep = 0;

    Mesh* headbody = object2D::CreateHeadBody("headbody", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(headbody);

    

    Mesh* rectangle = object2D::CreateScor("rectangle", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(rectangle);

    Mesh* firstwing = object2D::CreateFirstWing("firstwing", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(firstwing);

    Mesh* secondwing = object2D::CreateSecondWing("secondwing", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(secondwing);

    Mesh* viata1 = object2D::CreateViata("viata1", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(viata1);
   
    Mesh* glont = object2D::CreateGlont("glont", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(glont);

    Mesh* maxim_score = object2D::CreateScor("maxim_score", corner, squareSide, glm::vec3(1, 1, 1), false);
    AddMeshToList(maxim_score);

    Mesh* score = object2D::CreateScor("score", corner, squareSide, glm::vec3(0, 0, 1), true);
    AddMeshToList(score);

   

}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)

{
   
     //DREPTUNGHI JOS
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Scale(7, 2);
    RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);


    if (viata == 0)
        exit(0);

    if (free_duck || exit_screen) {
        nr_ducks++;
        int ducks = nr_ducks;
        speed = (1 + ducks / 5) * 7;

        ty = 100;
        tx = 500;
        game_time = 0;
        angle = glm::radians(rand() % 150 + 0.f);
        free_duck = false;
        incX = speed * cos(angle);
        incY = speed * sin(angle);
        exit_screen = false;
        is_dead = false;
        gloante = 3;
        
        if (combo_ducks == 5 && viata < 3)
        {
            viata++;
            combo_ducks = 0;
        }


    }

    game_time += deltaTimeSeconds;

    modelMatrix = glm::mat3(1);
    modelWing1 = glm::mat3(1);
    modelWing2 = glm::mat3(1);
       
    tx += incX; 
    ty += incY;
        
    modelMatrix *= transform2D::Translate(0 + tx, 0 + ty);
    modelWing1 *= transform2D::Translate(0 + tx, 0 + ty);
    modelWing2 *= transform2D::Translate(0 + tx, 0 + ty);

    if (game_time < limit_time && !is_dead) {


        if (ty > 800) {
            incY = -speed;
            angle = 2 * 3.14 - angle;


        }

        if (ty < 20) {
            incY = speed;
            angle = 2 * 3.14 - angle;

        }

        if (tx > 1190) {
            incX = -speed;
            angle = 3.14 - angle;

        }
        //rx += 0.2;

        if (tx < 20) {
            incX = speed;
            angle = 3.14 - angle;

        }

    }

    if (game_time > limit_time && ty < 1000 && !is_dead)
    {
        incX = 0;
        incY = 10;

    }

    if (ty > 1000 && !is_dead) {
        free_duck = true;
        combo_ducks = 0;
        viata--;
        if (viata < 0) viata = 0;
    }
    if (ty < -300)
    {
        exit_screen = true;
        
    }

    modelMatrix *= transform2D::Rotate(angle);
        
   
    //PASARE

    RenderMesh2D(meshes["headbody"], shaders["VertexColor"], modelMatrix);
    /*RenderMesh2D(meshes["firstwing"], shaders["VertexColor"], modelMatrix);*/
    //RenderMesh2D(meshes["secondwing"], shaders["VertexColor"], modelMatrix);
    //RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
   
    if (omega1 > 3.14 / 20) {
        omega1 = 0;
    }

    omega1 += 0.01;

    if (omega2 > 3.14 / 20) {
        omega2 = 0;
    }

   omega2 += 0.01;

    modelMatrix *= transform2D::Rotate(omega1);
    RenderMesh2D(meshes["firstwing"], shaders["VertexColor"], modelMatrix);
    modelWing2 *=transform2D::Rotate(angle);
    modelWing2 *= transform2D::Rotate(-omega2);
    RenderMesh2D(meshes["secondwing"], shaders["VertexColor"], modelWing2);

    
    
        

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(850, 610);
    modelMatrix *= transform2D::Scale(scor, 1);
   
    RenderMesh2D(meshes["score"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(850, 600);
    modelMatrix *= transform2D::Scale(2.1, 1.3);
    RenderMesh2D(meshes["maxim_score"], shaders["VertexColor"], modelMatrix);

   


    //VIETI+GLOANTE
    for (int i = 1; i <= gloante; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(50 + i * 40, 620);
        RenderMesh2D(meshes["glont"], shaders["VertexColor"], modelMatrix);

    }


    for (int i = 1; i <= viata; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(50 + i * 40, 670);
        RenderMesh2D(meshes["viata1"], shaders["VertexColor"], modelMatrix);

    }


}


void Tema1::FrameEnd()
{
}





void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{

    if ( -mouseY + 720 >= ty - 200 && -mouseY + 720 <= ty + 200 && mouseX >= tx - 300 && mouseX <= tx + 200)
    {
        incY = -15;
        incX = 0;
        is_dead = true;
        combo_ducks++;
        scor += 0.15;

    }
    else {
        gloante--;
        combo_ducks = 0;
        // cout << "gloante="<<gloante << '\n';
        if (gloante == 0)
        {
            game_time = limit_time+1;

        }
        //cout<<"viata=" << viata << '\n';

    }

}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}