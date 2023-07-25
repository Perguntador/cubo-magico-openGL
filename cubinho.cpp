#include "cubinho.h"
#include <GL/glut.h>
#include <iostream>

using namespace std;

namespace cor {
    float RED[3] = {1, 0, 0};
    float BLUE[3] = {0, 0, 1};
    float GREEN[3] = {0, 1, 0};
    float WHITE[3] = {1, 1, 1};
    float YELLOW[3] = {1, 1, 0};
    float ORANGE[3] = {1, 0.5, 0};
} // namespace cor

void displayContornoCubinho(float pts[8][3]) {
    glColor3f(0, 0.5, 0.5);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[0 + 4]);
    glVertex3fv(pts[1 + 4]);
    glVertex3fv(pts[1]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[2]);
    glVertex3fv(pts[2 + 4]);
    glVertex3fv(pts[3 + 4]);
    glVertex3fv(pts[3]);
    glEnd();

    /*-------------------------------------*/

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[3 + 4]);
    glVertex3fv(pts[1 + 4]);
    glVertex3fv(pts[1]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[0 + 4]);
    glVertex3fv(pts[2 + 4]);
    glVertex3fv(pts[2]);
    glEnd();

    /*-------------------------------------*/

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[1]);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[2]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[0 + 4]);
    glVertex3fv(pts[1 + 4]);
    glVertex3fv(pts[3 + 4]);
    glVertex3fv(pts[2 + 4]);
    glEnd();
}

void Cubinho::displayCubinho() {
    int i;
    float pts[8][3];
    float d = largAresta / 2.f;

    for (i = 0; i < 8; i++) {
        if (i < 4) {
            pts[i][0] = d;
        }
        else {
            pts[i][0] = -d;
        }
        if ((i / 2) % 2) {
            pts[i][1] = d;
        }
        else {
            pts[i][1] = -d;
        }
        if (i % 2) {
            pts[i][2] = d;
        }
        else {
            pts[i][2] = -d;
        }
    }

    glPushMatrix();

    glTranslatef(cx, cy, cz);
    glRotatef(rotX, 0, 0, 1);
    glRotatef(rotY, 0, 1, 0);
    glRotatef(rotZ, 0, 0, 1);

    displayContornoCubinho(pts);

    glColor3fv(cor::GREEN);
    glBegin(GL_QUADS);
    glVertex3fv(pts[2]);
    glVertex3fv(pts[2 + 4]);
    glVertex3fv(pts[3 + 4]);
    glVertex3fv(pts[3]);
    glEnd();

    glColor3fv(cor::BLUE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[0 + 4]);
    glVertex3fv(pts[1 + 4]);
    glVertex3fv(pts[1]);
    glEnd();

    // /*-------------------------------------*/

    /* Topo */
    glColor3fv(cor::YELLOW);
    glBegin(GL_QUADS);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[3 + 4]);
    glVertex3fv(pts[1 + 4]);
    glVertex3fv(pts[1]);
    glEnd();

    /* Base */
    glColor3fv(cor::WHITE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[0 + 4]);
    glVertex3fv(pts[2 + 4]);
    glVertex3fv(pts[2]);
    glEnd();

    // /*-------------------------------------*/

    glColor3fv(cor::ORANGE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[1]);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[2]);
    glEnd();

    glColor3fv(cor::RED);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0 + 4]);
    glVertex3fv(pts[1 + 4]);
    glVertex3fv(pts[3 + 4]);
    glVertex3fv(pts[2 + 4]);
    glEnd();

    glPopMatrix();
}
