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

char Cubinho::corY() {
    int modT, modP, modG;

    modT = (360 + (int(rotTheta) % 360)) % 360 / 90;
    modP = (360 + (int(rotPhi) % 360)) % 360 / 90;
    modG = (360 + (int(rotGamma) % 360)) % 360 / 90;

    if (modT == 0) {
        if (modG == 0) {
            return 'G';
        }
        else if (modG == 1) {
            return 'O';
        }
        else if (modG == 2) {
            return 'B';
        }
        else if (modG == 3) {
            return 'R';
        }
    }
    else if (modT == 2) {
        if (modG == 0) {
            return 'B';
        }
        else if (modG == 1) {
            return 'R';
        }
        else if (modG == 2) {
            return 'G';
        }
        else if (modG == 3) {
            return 'O';
        }
    }

    if (modT == 1) {
        if (modP == 1) {
            return 'Y';
        }
        else if (modP == 3) {
            return 'W';
        }
    }
    else if (modT == 3) {
        if (modP == 1) {
            return 'W';
        }
        else if (modP == 3) {
            return 'Y';
        }
    }

    if ((modT - 1 + modP + modG) % 4 == 0) {
        return 'O';
    }
    else if ((modT - 1 + modP + modG) % 4 == 1) {
        return 'B';
    }
    else if ((modT - 1 + modP + modG) % 4 == 2) {
        return 'R';
    }
    else if ((modT - 1 + modP + modG) % 4 == 3) {
        return 'G';
    }

    return 0;
}

char Cubinho::corX() {
    int modT, modP, modG;

    modT = (360 + (int(rotTheta) % 360)) % 360 / 90;
    modP = (360 + (int(rotPhi) % 360)) % 360 / 90;
    modG = (360 + (int(rotGamma) % 360)) % 360 / 90;

    if (modT == 0) {
        if (modP == 1) {
            return 'Y';
        }
        else if (modP == 3) {
            return 'W';
        }
    }
    else if (modT == 2) {
        if (modP == 1) {
            return 'W';
        }
        else if (modP == 3) {
            return 'Y';
        }
    }

    if (modP == 2) {
        if ((4 + modT - modG) % 4 == 0) {
            return 'R';
        }
        else if ((4 + modT - modG) % 4 == 1) {
            return 'B';
        }
        else if ((4 + modT - modG) % 4 == 2) {
            return 'O';
        }
        else if ((4 + modT - modG) % 4 == 3) {
            return 'G';
        }
    }

    if ((modT + modG) % 4 == 1) {
        return 'B';
    }
    else if ((modT + modG) % 4 == 3) {
        return 'G';
    }
    else if ((modT + modG) % 4 == 0) {
        return 'O';
    }
    else if ((modT + modG) % 4 == 2) {
        return 'R';
    }

    return 0;
}

char Cubinho::corZ() {
    int modT, modP, modG;

    modT = (360 + (int(rotTheta) % 360)) % 360 / 90;
    modP = (360 + (int(rotPhi) % 360)) % 360 / 90;
    modG = (360 + (int(rotGamma) % 360)) % 360 / 90;

    if (modP == 0) {
        return 'Y';
    }
    else if (modP == 1) {
        if (modG == 0) {
            return 'R';
        }
        else if (modG == 1) {
            return 'G';
        }
        else if (modG == 2) {
            return 'O';
        }
        else if (modG == 3) {
            return 'B';
        }
    }
    else if (modP == 2) {
        return 'W';
    }
    else if (modP == 3) {
        if (modG == 0) {
            return 'O';
        }
        else if (modG == 1) {
            return 'B';
        }
        else if (modG == 2) {
            return 'R';
        }
        else if (modG == 3) {
            return 'G';
        }
    }

    return 0;
}

char Cubinho::corXn() {
    char c = corX();

    if (c == 'R') {
        return 'O';
    }
    else if (c == 'O') {
        return 'R';
    }
    else if (c == 'W') {
        return 'Y';
    }
    else if (c == 'Y') {
        return 'W';
    }
    else if (c == 'B') {
        return 'G';
    }
    else if (c == 'G') {
        return 'B';
    }

    return 0;
}

char Cubinho::corYn() {
    char c = corY();

    if (c == 'R') {
        return 'O';
    }
    else if (c == 'O') {
        return 'R';
    }
    else if (c == 'W') {
        return 'Y';
    }
    else if (c == 'Y') {
        return 'W';
    }
    else if (c == 'B') {
        return 'G';
    }
    else if (c == 'G') {
        return 'B';
    }

    return 0;
}

char Cubinho::corZn() {
    char c = corZ();

    if (c == 'R') {
        return 'O';
    }
    else if (c == 'O') {
        return 'R';
    }
    else if (c == 'W') {
        return 'Y';
    }
    else if (c == 'Y') {
        return 'W';
    }
    else if (c == 'B') {
        return 'G';
    }
    else if (c == 'G') {
        return 'B';
    }

    return 0;
}

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
    glRotatef(rotTheta, 0, 0, 1);
    glRotatef(rotPhi, 0, 1, 0);
    glRotatef(rotGamma, 0, 0, 1);

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
