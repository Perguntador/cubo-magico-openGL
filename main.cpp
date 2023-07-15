#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include "cubinho.h"



Cubinho cubo1;

Cubinho *cubos;

float dOrtho = 5;

float theta = 135;
float phi = 45;
float gamma1 = 90;
float s = 1;

bool mov = false;
int xb, yb;

using namespace std;

void config(){
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-dOrtho, dOrtho, -dOrtho, dOrtho, -dOrtho, dOrtho);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(gamma1, 0, 0, 1);
	glRotatef(phi, 0, 1, 0);
	glRotatef(theta, 0, 0, 1);
	glScalef(s, s, s);
}


void display(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// cubo1.displayCubinho();
	// for(int i = 0; i < 27; i++)
	// 	cubos[i].displayCubinho();

	cubos[13].displayCubinho();
	cubos[26].displayCubinhoPolar();

	glutSwapBuffers();

}



void botao(int b, int state, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			xb = x;
			yb = y;
			mov = true;
		}
		else
			mov = false;
	}
}

void botao_mov(int x, int y) {
  if (mov) {
    float dx = x - xb;
    float dy = y - yb;

    theta += dx;
    phi -= dy;
    if (phi > 180)
      phi = 180.f;
    else if (phi < 0)
      phi = 0.f;

    config();
    glutPostRedisplay();
    xb = x;
    yb = y;
  }
}


void teclado(unsigned char key, int x, int y) {
  cout << key << endl;
  switch (key)
  {
  case '1':
	// cout << "1\n";
	break;
  default:
	break;
  }
}


int main(int argc, char **argv){
	int i;
	cubos = new Cubinho[27];
	
	for(i = 0; i < 27; i++){
		cubos[i].setCZ(-1+i/9%3);
		cubos[i].setCY(-1+i%3);
		cubos[i].setCX(-1+i/3%3);
	}


	// cubos[0].setCentro(1,1,1);




    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("3D");
	config();
	glutDisplayFunc(display);
	// glutKeyboardFunc(teclado);
	glutKeyboardFunc(teclado);
	//	glutIdleFunc(executa);

	glutMouseFunc(botao);
	glutMotionFunc(botao_mov);

	glutMainLoop();


    return 0;
}