#include "cubo.h"
#include <iostream>
#include <GL/glut.h>

namespace cor{
    float RED[3] = {1,0,0};
    float BLUE[3] = {0,0,1};
    float GREEN[3] = {0,1,0};
    float WHITE[3] = {1,1,1};
    float YELLOW[3] = {1,1,0};
    float ORANGE[3] = {1,0.5,0};
}


void displayContornoCubo(float pts[8][3]){
    // glColor3f(1,1,1);
    glColor3f(0,0,0);

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[1]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[2]);
    glVertex3fv(pts[2+4]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[3]);
    glEnd();

    /*-------------------------------------*/

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[1]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[2+4]);
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
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[2+4]);
    glEnd();


}


void Cubo::displayCubo(){
    float pts[8][3];
    float d = largAresta / 2.f;
    int i;
    for (i=0;i<8;i++){
        if (i<4){
            pts[i][0] = cx + d;
        }
        else {
            pts[i][0] = cx - d;
        }
        if ((i/2)%2){
            pts[i][1] = cy + d;
        }
        else{
            pts[i][1] = cy - d;
        }
        if (i%2){
            pts[i][2] = cz + d;
        }
        else{
            pts[i][2] = cz - d;
        }
    }

    displayContornoCubo(pts);

    glColor3fv(cor::GREEN);
    glBegin(GL_QUADS);
    glVertex3fv(pts[2]);
    glVertex3fv(pts[2+4]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[3]);
    glEnd();

    glColor3fv(cor::BLUE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[1]);
    glEnd();

    // /*-------------------------------------*/

    /* Topo */
    glColor3fv(cor::YELLOW);
    glBegin(GL_QUADS);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[1]);
    glEnd();

    /* Base */
    glColor3fv(cor::WHITE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[2+4]);
    glVertex3fv(pts[2]);
    glEnd();

    // /*-------------------------------------*/

    glColor3fv(cor::RED);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[1]);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[2]);
    glEnd();
    
    glColor3fv(cor::ORANGE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[2+4]);
    glEnd();

}
