#include "cubinho.h"
#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

namespace cor{
    float RED[3] = {1,0,0};
    float BLUE[3] = {0,0,1};
    float GREEN[3] = {0,1,0};
    float WHITE[3] = {1,1,1};
    float YELLOW[3] = {1,1,0};
    float ORANGE[3] = {1,0.5,0};
}


void displayContornoCubinho(float pts[8][3]){
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


void Cubinho::displayCubinho(){
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

    displayContornoCubinho(pts);

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

    glColor3fv(cor::ORANGE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[1]);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[2]);
    glEnd();
    
    glColor3fv(cor::RED);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[2+4]);
    glEnd();

}




void Cubinho::displayCubinhoPolar2(){
    int i;
    float pts[8][3];
    float d = largAresta / 2.f;
    float raioc = cbrt(cx*cy*cz);
    float dr = d*sqrt(2);
    float dx, dy, dz;
    float rx, ry, rz;
    // dx = dr * cos(rotX);
    // dz = - dr * cos(rotX);


    // cout << "Raio: "<< raioc << endl;

    // rotX += 1;

    // pts[0]

    // dx = dr*cos(rotX);

    // dx = dr*cos

    dx = d;
    dy = d;
    dz = d;

    glPushMatrix();
    // cout << "aqui\n";

    rx = (360+(int(rotX)%360))%360/360.f;
    ry = (360+(int(rotY)%360))%360/360.f;
    rz = (360+(int(rotZ)%360))%360/360.f;
    // cout << rx << "\n";
    // cout << ry << "\n";
    // cout << rz << "\n\n\n";
    // glRotatef(90.f,rx,ry,rz);
    // glRotatef()


    glTranslatef(cx, cy, cz);
    // glRotatef(rotX,1,0,0);
    glRotatef(rotX,0,0,1);
    glRotatef(rotY,0,1,0);
    glRotatef(rotZ,0,0,1);
    

    pts[0][0] = dx;
    pts[0][1] = dy;
    pts[1][0] = dx;
    pts[1][1] = dy;
    pts[2][0] = dx;
    pts[2][1] = - dy;
    pts[3][0] = dx;
    pts[3][1] = - dy;

    pts[4][0] = - dx;
    pts[4][1] = dy;
    pts[5][0] = - dx;
    pts[5][1] = dy;
    pts[6][0] = - dx;
    pts[6][1] = - dy;
    pts[7][0] = - dx;
    pts[7][1] = - dy;

    for (i=0;i<8;i++){
        // if (i<4){
        //     pts[i][0] = cx + dx;
        // }
        // else {
        //     pts[i][0] = cx - dx;
        // }




        // if ((i/2)%2){
        //     pts[i][1] = cy + dy;
        // }
        // else{
        //     pts[i][1] = cy - dy;
        // }
        if (i%2){
            pts[i][2] = dz;
        }
        else{
            pts[i][2] = - dz;
        }
    }

    displayContornoCubinho(pts);

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

    glColor3fv(cor::ORANGE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[1]);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[2]);
    glEnd();
    
    glColor3fv(cor::RED);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[2+4]);
    glEnd();

    glPopMatrix();

}




void Cubinho::displayCubinhoPolar(){
    int i;
    float pts[8][3];
    float d = largAresta / 2.f;
    float raioc = cbrt(cx*cy*cz);
    float dr = d*sqrt(2);
    float dx, dy, dz;
    dx = dr * cos(rotX);
    dy = d;
    // dz = - dr * cos(rotX);
    dz = d;


    // cout << "Raio: "<< raioc << endl;

    // rotX += 1;

    // pts[0]

    // dx = dr*cos(rotX);

    // dx = dr*cos

    dx = d;

    glPushMatrix();
    // cout << "aqui\n";

    glRotatef(rotX,1,0,0);
    glRotatef(rotY,0,1,0);
    glRotatef(rotZ,0,0,1);

    pts[0][0] = cx + dx;
    pts[0][1] = cy + dy;
    pts[1][0] = cx + dx;
    pts[1][1] = cy + dy;
    pts[2][0] = cx + dx;
    pts[2][1] = cy - dy;
    pts[3][0] = cx + dx;
    pts[3][1] = cy - dy;

    pts[4][0] = cx - dx;
    pts[4][1] = cy + dy;
    pts[5][0] = cx - dx;
    pts[5][1] = cy + dy;
    pts[6][0] = cx - dx;
    pts[6][1] = cy - dy;
    pts[7][0] = cx - dx;
    pts[7][1] = cy - dy;

    for (i=0;i<8;i++){
        // if (i<4){
        //     pts[i][0] = cx + dx;
        // }
        // else {
        //     pts[i][0] = cx - dx;
        // }




        // if ((i/2)%2){
        //     pts[i][1] = cy + dy;
        // }
        // else{
        //     pts[i][1] = cy - dy;
        // }
        if (i%2){
            pts[i][2] = cz + dz;
        }
        else{
            pts[i][2] = cz - dz;
        }
    }

    displayContornoCubinho(pts);

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

    glColor3fv(cor::ORANGE);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0]);
    glVertex3fv(pts[1]);
    glVertex3fv(pts[3]);
    glVertex3fv(pts[2]);
    glEnd();
    
    glColor3fv(cor::RED);
    glBegin(GL_QUADS);
    glVertex3fv(pts[0+4]);
    glVertex3fv(pts[1+4]);
    glVertex3fv(pts[3+4]);
    glVertex3fv(pts[2+4]);
    glEnd();

    glPopMatrix();

}