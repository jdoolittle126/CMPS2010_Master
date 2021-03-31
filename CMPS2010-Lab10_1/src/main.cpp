#include "MyScene.h"

using namespace std;

int main()
{
    printf("\x1b[2J");

    Scene * scene = new MyScene();


    scene->run();

    return 0;
}

