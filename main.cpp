#include <iostream>
#include <GL/glut.h>
#include "cubo.h"


Cubo cubo1(0,0,0,1);

Cubo cubo2;
Cubo cubo3(1.7,3.2,2,2.7);

float dOrtho = 5;

float theta = 135;
float phi = 45;
float gamma = 90;
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
	glRotatef(gamma, 0, 0, 1);
	glRotatef(phi, 0, 1, 0);
	glRotatef(theta, 0, 0, 1);
	glScalef(s, s, s);
}


void display(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cubo2.displayCubo();

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
	cubo2.tecla1();
	glutPostRedisplay();
	break;
  case '2':
    cubo2.tecla2();
	glutPostRedisplay();
	break;
  case '3':
    cubo2.tecla3();
	glutPostRedisplay();
	break;
  case '4':
    cubo2.tecla4();
	glutPostRedisplay();
	break;
  case '5':
    cubo2.tecla5();
	glutPostRedisplay();
	break;
  case '6':
    cubo2.tecla6();
	glutPostRedisplay();
	break;
  case '7':
    cubo2.tecla7();
	glutPostRedisplay();
	break;
  case '8':
    cubo2.tecla8();
	glutPostRedisplay();
	break;
  case '9':
    cubo2.tecla9();
	glutPostRedisplay();
	break;
  case '0':
    cubo2.tecla0();
	glutPostRedisplay();
	break;
  case '.':
    cubo2.teclaPonto();
	glutPostRedisplay();
	break;

	

  case 'r':
    cubo2.vermelhoHorario();
	break;
  case 'R':
    cubo2.vermelhoAntiHorario();
	break;
  case 'y':
    cubo2.amareloHorario();
	break;
  case 'Y':
    cubo2.amareloAntiHorario();
	break;
  case 'b':
    cubo2.azulHorario();
	break;
  case 'B':
    cubo2.azulAntiHorario();
	break;
  case 'g':
    cubo2.verdeHorario();
	break;
  case 'G':
    cubo2.verdeAntiHorario();
	break;
  case 'w':
    cubo2.brancoHorario();
	break;
  case 'W':
    cubo2.brancoAntiHorario();
	break;
  case 'o':
    cubo2.laranjaHorario();
	break;
  case 'O':
    cubo2.laranjaAntiHorario();
	break;

   case '+':
    s *= 1.1;
		config();
		glutPostRedisplay();
    break;

  case '-':
    s /= 1.1;
		config();
		glutPostRedisplay();
    break;


  case ' ':
    cubo2.printId();
	glutPostRedisplay();
	break;
  default:
	break;
  }
}


int main(int argc, char **argv){
	int i;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Cubo Magico 3D (JAS)");
	config();
	glutDisplayFunc(display);
	glutKeyboardFunc(teclado);
	// glutIdleFunc(executa);
	glutMouseFunc(botao);
	glutMotionFunc(botao_mov);

	glutMainLoop();

    return 0;
}