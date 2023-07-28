#include "cubo.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <GL/glut.h>
#include <iostream>

#define DR 9 // divisor de 90
#define DELAY 10

#define MAX_CUBOS 10

using namespace std;

// Vetor para salvar os cubos em enviá-los para os timers que fazem as animações dos movimentos
Cubo *pCubos[MAX_CUBOS];

int Cubo::proxId_ = 0;

float grau2rad(float grau) {
    return grau / 180. * M_PI;
}

/*
eixo x: sentido do laranja
eixo y: sentido do azul
eixo z: sentido do amarelo
*/

Cubo::Cubo(float _cx, float _cy, float _cz, float _largAresta) : id_(proxId_++) {
    int k;
    float larg, rx, ry, rz;

    pCubos[id_] = this;
    cx = _cx;
    cy = _cy;
    cz = _cz;

    largAresta = _largAresta;

    for (int i = 0; i < 27; i++) {
        // coordenadas cartesianas
        cubinhos[i].cz = cz + (-1 + i / 9 % 3) * largAresta;
        cubinhos[i].cy = cy + (-1 + i % 3) * largAresta;
        cubinhos[i].cx = cx + (-1 + i / 3 % 3) * largAresta;
        cubinhos[i].largAresta = largAresta;
        mapa[i] = true;
        mapa2[i] = i;

        rotsX[i] = 0;
        rotsY[i] = 0;
        rotsZ[i] = 0;
    }

    for (int i = 0; i < 27; i++) {
        k = mapa2[i];

        if (i == 17) {
            larg = largAresta;

            rotsX[k] = 90 * 0;
            rotsY[k] = 90 * 0;
            rotsZ[k] = 90 * 1;
        }

        else if (i == 15) {
            larg = largAresta;

            rotsX[k] = 90 * 0;
            rotsY[k] = 90 * 2;
            rotsZ[k] = 90 * 1;
        }

        else if (i == 11) {
            larg = largAresta;

            rotsX[k] = 90 * 2;
            rotsY[k] = 90 * 0;
            rotsZ[k] = 90 * 1;
        }

        else if (i == 9) {
            larg = largAresta;

            rotsX[k] = 90 * 2;
            rotsY[k] = 90 * 2;
            rotsZ[k] = 90 * 1;
        }

        else if (i == 25) {
            larg = largAresta;

            rotsX[k] = 90 * 0;
            rotsY[k] = 90 * 3;
            rotsZ[k] = 90 * 0;
        }

        else if (i == 23) {
            larg = largAresta;

            rotsX[k] = 90 * 1;
            rotsY[k] = 90 * 0;
            rotsZ[k] = 90 * 0;
        }

        else if (i == 21) {
            larg = largAresta;

            rotsX[k] = 90 * 3;
            rotsY[k] = 90 * 2;
            rotsZ[k] = 90 * 0;
        }

        else if (i == 19) {
            larg = largAresta;

            rotsX[k] = 90 * 2;
            rotsY[k] = 90 * 1;
            rotsZ[k] = 90 * 0;
        }

        else if (i == 7) {
            larg = largAresta;

            rotsX[k] = 90 * 0;
            rotsY[k] = 90 * 3;
            rotsZ[k] = 90 * 2;
        }

        else if (i == 5) {
            larg = largAresta;

            rotsX[k] = 90 * 1;
            rotsY[k] = 90 * 0;
            rotsZ[k] = 90 * 2;
        }

        else if (i == 3) {
            larg = largAresta;

            rotsX[k] = 90 * 3;
            rotsY[k] = 90 * 2;
            rotsZ[k] = 90 * 2;
        }

        else if (i == 1) {
            larg = largAresta;

            rotsX[k] = 90 * 2;
            rotsY[k] = 90 * 1;
            rotsZ[k] = 90 * 2;
        }

        else if (i == 26) {
            larg = sqrt(2) * largAresta;

            rotsX[k] = 45 + 90 * 3;
            rotsY[k] = 45 + 90 * 0;
            rotsZ[k] = 45 + 90 * 0;
        }

        else if (i == 24) {
            larg = sqrt(2) * largAresta;

            rotsX[k] = 45 + 90 * 0;
            rotsY[k] = 45 + 90 * 1;
            rotsZ[k] = 45 + 90 * 0;
        }

        else if (i == 20) {
            larg = sqrt(2) * largAresta;

            rotsX[k] = 45 + 90 * 2;
            rotsY[k] = 45 + 90 * 3;
            rotsZ[k] = 45 + 90 * 0;
        }

        else if (i == 18) {
            larg = sqrt(2) * largAresta;

            rotsX[k] = 45 + 90 * 1;
            rotsY[k] = 45 + 90 * 2;
            rotsZ[k] = 45 + 90 * 0;
        }

        else if (i == 8) {
            larg = sqrt(2) * largAresta;

            rotsX[k] = 45 + 90 * 3;
            rotsY[k] = 45 + 90 * 3;
            rotsZ[k] = 45 + 90 * 1;
        }

        else if (i == 6) {
            larg = sqrt(2) * largAresta;

            rotsX[k] = 45 + 90 * 0;
            rotsY[k] = 45 + 90 * 2;
            rotsZ[k] = 45 + 90 * 1;
        }

        else if (i == 2) {
            larg = sqrt(2) * largAresta;

            rotsX[k] = 45 + 90 * 2;
            rotsY[k] = 45 + 90 * 0;
            rotsZ[k] = 45 + 90 * 1;
        }

        else if (i == 0) {
            larg = sqrt(2) * largAresta;

            rotsX[k] = 45 + 90 * 1;
            rotsY[k] = 45 + 90 * 1;
            rotsZ[k] = 45 + 90 * 1;
        }

        else {
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);

        cubinhos[k].cx = cos(rx) * larg + cx;
        cubinhos[k].cy = cos(ry) * larg + cy;
        cubinhos[k].cz = cos(rz) * larg + cz;
    }
}

void Cubo::displayCubo() {
    for (int i = 0; i < 27; i++) {
        if (mapa[i])
            cubinhos[i].displayCubinho();
    }
}

void Cubo::tecla9() {
    int k;
    k = mapa2[13];
    cubinhos[k].rotPhi += DR;
    // cout << cubinhos[k].rotPhi << endl;
}

void Cubo::tecla0() {
    int k;
    k = mapa2[13];
    cubinhos[k].rotGamma += DR;
    // cout << cubinhos[k].rotGamma << endl;
}

void Cubo::tecla1() {
    int k;
    k = mapa2[13];
    cubinhos[k].rotTheta -= DR;
    // cout << cubinhos[k].rotTheta << endl;
}

void Cubo::tecla2() {
    for (int i = 0; i < 27; i++) {
        mapa[i] = true;
    }
}

void Cubo::tecla3() {
    for (int i = 0; i < 27; i++) {
        mapa[i] = false;
    }
}

void Cubo::tecla4() {
    for (int i = 0; i < 27; i++) {
        mapa[i] = !mapa[i];
    }
}

void Cubo::tecla5() {

    int k;
    for (int i = 0; i < 9; i++) {
        // k = (i/3)*9+(i%3)+6; // lado laranja
        // k = (i/3)*9+(i%3); // lado vermelho
        k = i * 3 + 2; // lado verde
        // k = i*3; // lado azul
        // k = i; // lado branco
        // k = i+18; // lado amarelo
        k = mapa2[k];
        mapa[k] = !mapa[k];
    }

    return;
}

void Cubo::rearranjaMapa(char c) {

    int v1[9] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    int v2[9] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
    int vAux[9];
    int iAux;

    int k;

    if (c == 'Y') {
        for (int i = 0; i < 9; i++) {
            iAux = v1[i] + 18; // lado amarelo
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = i + 18; // lado amarelo
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c == 'y') {
        for (int i = 0; i < 9; i++) {
            iAux = v2[i] + 18; // lado amarelo
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = i + 18; // lado amarelo
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c == 'W') {
        for (int i = 0; i < 9; i++) {
            iAux = v2[i]; // lado branco
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = i; // lado branco
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c == 'w') {
        for (int i = 0; i < 9; i++) {
            iAux = v1[i]; // lado branco
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = i; // lado branco
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c == 'O') {
        for (int i = 0; i < 9; i++) {
            iAux = (v2[i] / 3) * 9 + (v2[i] % 3) + 6; // lado laranja
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = (i / 3) * 9 + (i % 3) + 6; // lado laranja
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c == 'o') {
        for (int i = 0; i < 9; i++) {
            iAux = (v1[i] / 3) * 9 + (v1[i] % 3) + 6; // lado laranja
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = (i / 3) * 9 + (i % 3) + 6; // lado laranja
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c == 'R') {
        for (int i = 0; i < 9; i++) {
            iAux = (v1[i] / 3) * 9 + (v1[i] % 3); // lado vermelho
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = (i / 3) * 9 + (i % 3); /// lado vermelho
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c == 'r') {
        for (int i = 0; i < 9; i++) {
            iAux = (v2[i] / 3) * 9 + (v2[i] % 3); // lado vermelho
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = (i / 3) * 9 + (i % 3); // lado vermelho
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c == 'G') {
        for (int i = 0; i < 9; i++) {
            iAux = v1[i] * 3 + 2; // lado verde
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = i * 3 + 2; // lado verde
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c == 'g') {
        for (int i = 0; i < 9; i++) {
            iAux = v2[i] * 3 + 2; // lado verde
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = i * 3 + 2; // lado verde
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c == 'B') {
        for (int i = 0; i < 9; i++) {
            iAux = v2[i] * 3; // lado azul
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = i * 3; // lado azul
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c == 'b') {
        for (int i = 0; i < 9; i++) {
            iAux = v1[i] * 3; // lado azul
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++) {
            iAux = i * 3; // lado azul
            mapa2[iAux] = vAux[i];
        }
    }

    else {
        cout << "Rearranjamento invalido\n";
    }

    return;
}

void rodaEixoX(float &rT, float &rP, float &rG, float dr) {
    int modX, modY, modZ;

    modX = (360 + (int(rT) % 360)) % 360 / 90;
    modY = (360 + (int(rP) % 360)) % 360 / 90;
    modZ = (360 + (int(rG) % 360)) % 360 / 90;

    if (modX == 3 && modZ == 0) { // azul no eixo X
        // cout << "azul1\n";
        rP += dr;
    }
    else if (modX == 1 && modZ == 2) { // azul no eixo X
        // cout << "azul2\n";
        rP -= dr;
    }
    else if (modX == 0 && modY == 0 && modZ == 3) { // azul no eixo X
        // cout << "azul3\n";
        rT = -90;
        rP += dr;
        rG = 0;
    }
    else if (modX == 2 && modY == 0 && modZ == 1) { // azul no eixo X
        // cout << "azul4\n";
        rT = -90;
        rP += dr;
        rG = 0;
    }
    else if (modX == 0 && modY == 2 && modZ == 1) { // azul no eixo X
        // cout << "azul5\n";
        rT = -90;
        rP += dr;
        rG = 0;
    }
    else if (modX == 2 && modY == 2 && modZ == 3) { // azul no eixo X
        // cout << "azul6\n";
        rT = -90;
        rP += dr;
        rG = 0;
    }

    else if (modX == 1 && modZ == 0) { // verde no eixo X
        // cout << "verde1\n";
        rP -= dr;
    }
    else if (modX == 3 && modZ == 2) { // verde no eixo X
        // cout << "verde2\n";
        rP += dr;
    }
    else if (modX == 0 && modY == 0 && modZ == 1) { // verde no eixo X
        // cout << "verde3\n";
        rT = 90;
        rP -= dr;
        rG = 0;
    }
    else if (modX == 2 && modY == 0 && modZ == 3) { // verde no eixo X
        // cout << "verde4\n";
        rT = 90;
        rP -= dr;
        rG = 0;
    }
    else if (modX == 0 && modY == 2 && modZ == 3) { // verde no eixo X
        // cout << "verde5\n";
        rT = 90;
        rP -= dr;
        rG = 0;
    }
    else if (modX == 2 && modY == 2 && modZ == 1) { // verde no eixo X
        // cout << "verde6\n";
        rT = 90;
        rP -= dr;
        rG = 0;
    }

    else if (modX == 1 && modZ == 3) { // laranja no eixo X
        // cout << "laranja1\n";
        rP -= dr;
    }

    else if (modX == 3 && modZ == 1) { // laranja no eixo X
        // cout << "laranja2\n";
        rP += dr;
    }
    else if (modX == 0 && modY == 0 && modZ == 0) {
        // cout << "laranja3\n";
        rT = +90;
        rP -= dr;
        rG = -90;
    }
    else if (modX == 2 && modY == 0 && modZ == 2) {
        // cout << "laranja4\n";
        rT = +90;
        rP -= dr;
        rG = -90;
    }
    else if (modX == 2 && modY == 2 && modZ == 0) {
        // cout << "laranja5\n";
        rT = +90;
        rP -= dr;
        rG = -90;
    }
    else if (modX == 0 && modY == 2 && modZ == 2) {
        // cout << "laranja6\n";
        rT = +90;
        rP -= dr;
        rG = -90;
    }

    else if (modX == 3 && modZ == 3) { // vermelho no eixo X
        // cout << "vermelho1\n";
        rP += dr;
    }
    else if (modX == 1 && modZ == 1) { // vermelho no eixo X
        // cout << "vermelho2\n";
        rP -= dr;
    }
    else if (modX == 2 && modY == 0 && modZ == 0) { // vermelho no eixo X
        // cout << "vermelho3\n";
        rT = -90;
        rP += dr;
        rG = -90;
    }
    else if (modX == 0 && modY == 2 && modZ == 0) { // vermelho no eixo X
        // cout << "vermelho4\n";
        rT = -90;
        rP += dr;
        rG = -90;
    }
    else if (modX == 0 && modY == 0 && modZ == 2) { // vermelho no eixo X
        // cout << "vermelho5\n";
        rT = -90;
        rP += dr;
        rG = -90;
    }
    else if (modX == 2 && modY == 2 && modZ == 2) { // vermelho no eixo X
        // cout << "vermelho6\n";
        rT = -90;
        rP += dr;
        rG = -90;
    }

    else if (modX == 2 && modY == 3) { // amarelo no eixo X
        // cout << "amarelo1\n";
        rG += dr;
    }
    else if (modX == 0 && modY == 1) { // amarelo no eixo X
        // cout << "amarelo2\n";
        rG += dr;
    }

    else if (modX == 0 && modY == 3) { // branco no eixo X
        // cout << "branco1\n";
        rG -= dr;
    }
    else if (modX == 2 && modY == 1) { // branco no eixo X
        // cout << "branco2\n";
        rG -= dr;
    }

    // cout << rT << " " << rP << " " << rG << endl;
}

void rodaEixoY(float &rT, float &rP, float &rG, float dr) {
    int modX, modY, modZ;

    modX = (360 + (int(rT) % 360)) % 360 / 90;
    modY = (360 + (int(rP) % 360)) % 360 / 90;
    modZ = (360 + (int(rG) % 360)) % 360 / 90;

    if (modX == 0 && modZ == 0) { // azul no eixo Y
        // cout << "azul1\n";
        rP -= dr;
    }
    else if (modX == 2 && modZ == 2) { // azul no eixo Y
        // cout << "azul2\n";
        rP += dr;
    }
    else if (modX == 3 && modY == 0 && modZ == 1) { // azul no eixo Y
        // cout << "azul3\n";
        rT = 0;
        rP -= dr;
        rG = 0;
    }
    else if (modX == 1 && modY == 0 && modZ == 3) { // azul no eixo Y
        // cout << "azul4\n";
        rT = 0;
        rP -= dr;
        rG = 0;
    }
    else if (modX == 1 && modY == 2 && modZ == 1) { // azul no eixo Y
        // cout << "azul5\n";
        rT = 0;
        rP -= dr;
        rG = 0;
    }
    else if (modX == 3 && modY == 2 && modZ == 3) { // azul no eixo Y
        // cout << "azul6\n";
        rT = 0;
        rP -= dr;
        rG = 0;
    }

    else if (modX == 2 && modZ == 0) { // verde no eixo Y
        // cout << "verde1\n";
        rP += dr;
    }
    else if (modX == 0 && modZ == 2) { // verde no eixo Y
        // cout << "verde2\n";
        rP -= dr;
    }
    else if (modX == 3 && modY == 0 && modZ == 3) { // verde no eixo Y
        // cout << "verde3\n";
        rT = 180;
        rP += dr;
        rG = 0;
    }
    else if (modX == 1 && modY == 0 && modZ == 1) { // verde no eixo Y
        // cout << "verde4\n";
        rT = 180;
        rP += dr;
        rG = 0;
    }
    else if (modX == 3 && modY == 2 && modZ == 1) { // verde no eixo Y
        // cout << "verde5\n";
        rT = 180;
        rP += dr;
        rG = 0;
    }
    else if (modX == 1 && modY == 2 && modZ == 3) { // verde no eixo Y
        // cout << "verde6\n";
        rT = 180;
        rP += dr;
        rG = 0;
    }

    else if (modX == 0 && modZ == 1) { // laranja no eixo Y
        // cout << "laranja1\n";
        rP -= dr;
    }
    else if (modX == 2 && modZ == 3) { // laranja no eixo Y
        // cout << "laranja2\n";
        rP += dr;
    }
    else if (modX == 1 && modY == 0 && modZ == 0) { // laranja no eixo Y
        // cout << "laranja3\n";
        rT = 0;
        rP -= dr;
        rG = 90;
    }
    else if (modX == 3 && modY == 0 && modZ == 2) { // laranja no eixo Y
        // cout << "laranja4\n";
        rT = 0;
        rP -= dr;
        rG = 90;
    }
    else if (modX == 3 && modY == 2 && modZ == 0) { // laranja no eixo Y
        // cout << "laranja5\n";
        rT = 0;
        rP -= dr;
        rG = 90;
    }
    else if (modX == 1 && modY == 2 && modZ == 2) { // laranja no eixo Y
        // cout << "laranja6\n";
        rT = 0;
        rP -= dr;
        rG = 90;
    }

    else if (modX == 2 && modZ == 1) { // vermelho no eixo Y
        // cout << "vermelho1\n";
        rP += dr;
    }
    else if (modX == 0 && modZ == 3) { // vermelho no eixo Y
        // cout << "vermelho2\n";
        rP -= dr;
    }
    else if (modX == 3 && modY == 0 && modZ == 0) { // vermelho no eixo Y
        // cout << "vermelho3\n";
        rT = 180;
        rP += dr;
        rG = 90;
    }
    else if (modX == 1 && modY == 0 && modZ == 2) { // vermelho no eixo Y
        // cout << "vermelho4\n";
        rT = 180;
        rP += dr;
        rG = 90;
    }
    else if (modX == 3 && modY == 2 && modZ == 2) { // vermelho no eixo Y
        // cout << "vermelho5\n";
        rT = 180;
        rP += dr;
        rG = 90;
    }
    else if (modX == 1 && modY == 2 && modZ == 0) { // vermelho no eixo Y
        // cout << "vermelho6\n";
        rT = 180;
        rP += dr;
        rG = 90;
    }

    else if (modX == 1 && modY == 1) { // amarelo no eixo Y
        // cout << "amarelo1\n";
        rG -= dr;
    }
    else if (modX == 3 && modY == 3) { // amarelo no eixo Y
        // cout << "amarelo2\n";
        rG -= dr;
    }

    else if (modX == 3 && modY == 1) { // branco no eixo Y
        // cout << "branco1\n";
        rG += dr;
    }
    else if (modX == 1 && modY == 3) { // branco no eixo Y
        // cout << "branco2\n";
        rG += dr;
    }

    // cout << rT << " " << rP << " " << rG << endl;
}

void rodaEixoZ(float &rT, float &rP, float &rG, float dr) {
    int modX, modY, modZ;

    modX = (360 + (int(rT) % 360)) % 360 / 90;
    modY = (360 + (int(rP) % 360)) % 360 / 90;
    modZ = (360 + (int(rG) % 360)) % 360 / 90;
    rT += dr;

    // cout << rT << " " << rP << " " << rG << endl;
}

void Cubo::teclaPonto() {
    rodaEixoY(cubinhos[13].rotTheta, cubinhos[13].rotPhi, cubinhos[13].rotGamma, DR);
}

void Cubo::tecla6() {
    float larg, rx, ry, rz;
    int k, modX, modY, modZ;

    int mods;

    for (int i = 0; i < 27; i++) {
        k = i;
        k = mapa2[k];

        modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
        modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
        modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 ||
            k == 9 || k == 11 || k == 15 || k == 17) {
            larg = largAresta;

            if (modZ == 0 && (4 + modX - modY) % 4 == 1) {
                rotsX[k] -= DR;
                rotsY[k] -= DR;
            }
            else if (modZ == 0 && (4 + modX - modY) % 4 == 3) {
                rotsX[k] += DR;
                rotsY[k] += DR;
            }
            else if (modZ == 2 && (4 + modX - modY) % 4 == 1) {
                rotsX[k] += DR;
                rotsY[k] += DR;
            }
            else if (modZ == 2 && (4 + modX - modY) % 4 == 3) {
                rotsX[k] -= DR;
                rotsY[k] -= DR;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26) {
            larg = sqrt(2) * largAresta;

            if (modZ == 1 && (modX + modY) % 4 < 2) {
                rotsX[k] += DR;
                rotsY[k] -= DR;
            }
            else if (modZ == 1 && (modX + modY) % 4 >= 2) {
                rotsX[k] -= DR;
                rotsY[k] += DR;
            }
            else if (modZ == 3 && (modX + modY) % 4 < 2) {
                rotsX[k] -= DR;
                rotsY[k] += DR;
            }
            else if (modZ == 3 && (modX + modY) % 4 >= 2) {
                rotsX[k] += DR;
                rotsY[k] -= DR;
            }

            else if (modZ == 0 && (4 + modX - modY) % 4 == 1) {
                rotsX[k] -= DR;
                rotsY[k] -= DR;
            }
            else if (modZ == 0 && (4 + modX - modY) % 4 == 3) {
                rotsX[k] += DR;
                rotsY[k] += DR;
            }
            else if (modZ == 2 && (4 + modX - modY) % 4 == 1) {
                rotsX[k] += DR;
                rotsY[k] += DR;
            }
            else if (modZ == 2 && (4 + modX - modY) % 4 == 3) {
                rotsX[k] -= DR;
                rotsY[k] -= DR;
            }
        }

        else {
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);

        cubinhos[k].cx = cos(rx) * larg + cx;
        cubinhos[k].cy = cos(ry) * larg + cy;
        cubinhos[k].cz = cos(rz) * larg + cz;
    }

    for (int i = 0; i < 9; i++) {
        k = i; // lado branco
        k = mapa2[k];
        rodaEixoZ(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, +DR);

        k = i + 18; // lado amarelo
        k = mapa2[k];
        rodaEixoZ(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, -DR);
    }

    k = mapa2[0];
    modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
    modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
    modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

    mods = modX * 100 + modY * 10 + modZ;
    if (mods != 111 && mods != 212 && mods != 221 && mods != 122) {
        rearranjaMapa('w');
        rearranjaMapa('y');
    }

    return;
}

void Cubo::tecla7() {
    float larg, rx, ry, rz;
    int k, modX, modY, modZ;

    int mods;

    for (int i = 0; i < 27; i++) {
        k = i;
        k = mapa2[k];

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 ||
            k == 9 || k == 11 || k == 15 || k == 17) {
            larg = largAresta;

            modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
            modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
            modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

            if (modY == 0 && (4 + modX - modZ) % 4 == 1) {
                rotsX[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modY == 0 && (4 + modX - modZ) % 4 == 3) {
                rotsX[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 2 && (4 + modX - modZ) % 4 == 1) {
                rotsX[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 2 && (4 + modX - modZ) % 4 == 3) {
                rotsX[k] += DR;
                rotsZ[k] += DR;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26) {
            larg = sqrt(2) * largAresta;

            modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
            modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
            modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

            if (modY == 1 && (modX + modZ) % 4 < 2) {
                rotsX[k] -= DR;
                rotsZ[k] += DR;
            }
            else if (modY == 1 && (modX + modZ) % 4 >= 2) {
                rotsX[k] += DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 3 && (modX + modZ) % 4 < 2) {
                rotsX[k] += DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 3 && (modX + modZ) % 4 >= 2) {
                rotsX[k] -= DR;
                rotsZ[k] += DR;
            }

            else if (modY == 0 && (4 + modX - modZ) % 4 == 1) {
                rotsX[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modY == 0 && (4 + modX - modZ) % 4 == 3) {
                rotsX[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 2 && (4 + modX - modZ) % 4 == 1) {
                rotsX[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 2 && (4 + modX - modZ) % 4 == 3) {
                rotsX[k] += DR;
                rotsZ[k] += DR;
            }
        }
        else {
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);

        cubinhos[k].cx = cos(rx) * larg + cx;
        cubinhos[k].cy = cos(ry) * larg + cy;
        cubinhos[k].cz = cos(rz) * larg + cz;
    }

    for (int i = 0; i < 9; i++) {
        k = i * 3 + 2; // lado verde
        k = mapa2[k];
        rodaEixoY(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, +DR);

        k = i * 3; // lado azul
        k = mapa2[k];
        rodaEixoY(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, -DR);
    }

    k = mapa2[0];
    modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
    modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
    modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

    mods = modX * 100 + modY * 10 + modZ;
    if (mods != 111 && mods != 212 && mods != 221 && mods != 122) {
        rearranjaMapa('b');
        rearranjaMapa('g');
    }

    return;
}

void Cubo::tecla8() {
    float larg, rx, ry, rz;
    int k, modX, modY, modZ;

    int mods;

    for (int i = 0; i < 27; i++) {
        k = i;
        k = mapa2[k];

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 ||
            k == 9 || k == 11 || k == 15 || k == 17) {
            larg = largAresta;

            modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
            modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
            modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

            if (modX == 0 && (4 + modY - modZ) % 4 == 1) {
                rotsY[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modX == 0 && (4 + modY - modZ) % 4 == 3) {
                rotsY[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modX == 2 && (4 + modY - modZ) % 4 == 1) {
                rotsY[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modX == 2 && (4 + modY - modZ) % 4 == 3) {
                rotsY[k] -= DR;
                rotsZ[k] -= DR;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26) {
            larg = sqrt(2) * largAresta;

            modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
            modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
            modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

            if (modX == 1 && (modY + modZ) % 4 < 2) {
                rotsY[k] += DR;
                rotsZ[k] -= DR;
            }
            else if (modX == 1 && (modY + modZ) % 4 >= 2) {
                rotsY[k] -= DR;
                rotsZ[k] += DR;
            }
            else if (modX == 3 && (modY + modZ) % 4 < 2) {
                rotsY[k] -= DR;
                rotsZ[k] += DR;
            }
            else if (modX == 3 && (modY + modZ) % 4 >= 2) {
                rotsY[k] += DR;
                rotsZ[k] -= DR;
            }

            else if (modX == 0 && (4 + modY - modZ) % 4 < 2) {
                rotsY[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modX == 0 && (4 + modY - modZ) % 4 >= 2) {
                rotsY[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modX == 2 && (4 + modY - modZ) % 4 < 2) {
                rotsY[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modX == 2 && (4 + modY - modZ) % 4 >= 2) {
                rotsY[k] -= DR;
                rotsZ[k] -= DR;
            }
        }

        else {
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);

        cubinhos[k].cx = cos(rx) * larg + cx;
        cubinhos[k].cy = cos(ry) * larg + cy;
        cubinhos[k].cz = cos(rz) * larg + cz;
    }

    for (int i = 0; i < 9; i++) {
        k = (i / 3) * 9 + (i % 3) + 6; // lado laranja
        k = mapa2[k];
        rodaEixoX(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, -DR);

        k = (i / 3) * 9 + (i % 3); // lado vermelho
        k = mapa2[k];
        rodaEixoX(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, +DR);
    }

    k = mapa2[0];
    modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
    modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
    modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

    mods = modX * 100 + modY * 10 + modZ;
    if (mods != 111 && mods != 212 && mods != 221 && mods != 122) {
        rearranjaMapa('o');
        rearranjaMapa('r');
    }

    return;
}

void Cubo::ladoXHorario(float dr, char cor) {
    float larg, rx, ry, rz;
    int k, modX, modY, modZ;

    for (int i = 0; i < 9; i++) {
        if (cor == 'o') {
            k = (i / 3) * 9 + (i % 3) + 6; // lado laranja
            k = mapa2[k];
            rodaEixoX(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, -dr);
        }
        else if (cor == 'r') {
            k = (i / 3) * 9 + (i % 3); // lado vermelho
            k = mapa2[k];
            rodaEixoX(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, +dr);
        }

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 ||
            k == 9 || k == 11 || k == 15 || k == 17) {
            larg = largAresta;

            modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
            modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
            modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

            if (modX == 0 && (4 + modY - modZ) % 4 == 1) {
                rotsY[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modX == 0 && (4 + modY - modZ) % 4 == 3) {
                rotsY[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modX == 2 && (4 + modY - modZ) % 4 == 1) {
                rotsY[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modX == 2 && (4 + modY - modZ) % 4 == 3) {
                rotsY[k] -= dr;
                rotsZ[k] -= dr;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26) {
            larg = sqrt(2) * largAresta;

            modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
            modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
            modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

            if (modX == 1 && (modY + modZ) % 4 < 2) {
                rotsY[k] += dr;
                rotsZ[k] -= dr;
            }
            else if (modX == 1 && (modY + modZ) % 4 >= 2) {
                rotsY[k] -= dr;
                rotsZ[k] += dr;
            }
            else if (modX == 3 && (modY + modZ) % 4 < 2) {
                rotsY[k] -= dr;
                rotsZ[k] += dr;
            }
            else if (modX == 3 && (modY + modZ) % 4 >= 2) {
                rotsY[k] += dr;
                rotsZ[k] -= dr;
            }

            else if (modX == 0 && (4 + modY - modZ) % 4 == 1) {
                rotsY[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modX == 0 && (4 + modY - modZ) % 4 == 3) {
                rotsY[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modX == 2 && (4 + modY - modZ) % 4 == 1) {
                rotsY[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modX == 2 && (4 + modY - modZ) % 4 == 3) {
                rotsY[k] -= dr;
                rotsZ[k] -= dr;
            }
        }

        else {
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);

        cubinhos[k].cx = cos(rx) * larg + cx;
        cubinhos[k].cy = cos(ry) * larg + cy;
        cubinhos[k].cz = cos(rz) * larg + cz;
    }

    return;
}

void Cubo::ladoYHorario(float dr, char cor) {
    float larg, rx, ry, rz;
    int k, modX, modY, modZ;

    for (int i = 0; i < 9; i++) {
        if (cor == 'b') {
            k = i * 3; // lado azul
            k = mapa2[k];
            rodaEixoY(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, -dr);
        }
        else if (cor == 'g') {
            k = i * 3 + 2; // lado verde
            k = mapa2[k];
            rodaEixoY(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, +dr);
        }

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 ||
            k == 9 || k == 11 || k == 15 || k == 17) {
            larg = largAresta;

            modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
            modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
            modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

            if (modY == 0 && (4 + modX - modZ) % 4 == 1) {
                rotsX[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modY == 0 && (4 + modX - modZ) % 4 == 3) {
                rotsX[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 2 && (4 + modX - modZ) % 4 == 1) {
                rotsX[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 2 && (4 + modX - modZ) % 4 == 3) {
                rotsX[k] += dr;
                rotsZ[k] += dr;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26) {
            larg = sqrt(2) * largAresta;

            modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
            modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
            modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

            if (modY == 1 && (modX + modZ) % 4 < 2) {
                rotsX[k] -= dr;
                rotsZ[k] += dr;
            }
            else if (modY == 1 && (modX + modZ) % 4 >= 2) {
                rotsX[k] += dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 3 && (modX + modZ) % 4 < 2) {
                rotsX[k] += dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 3 && (modX + modZ) % 4 >= 2) {
                rotsX[k] -= dr;
                rotsZ[k] += dr;
            }

            else if (modY == 0 && (4 + modX - modZ) % 4 == 1) {
                rotsX[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modY == 0 && (4 + modX - modZ) % 4 == 3) {
                rotsX[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 2 && (4 + modX - modZ) % 4 == 1) {
                rotsX[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 2 && (4 + modX - modZ) % 4 == 3) {
                rotsX[k] += dr;
                rotsZ[k] += dr;
            }
        }
        else {
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);

        cubinhos[k].cx = cos(rx) * larg + cx;
        cubinhos[k].cy = cos(ry) * larg + cy;
        cubinhos[k].cz = cos(rz) * larg + cz;
    }

    return;
}

void Cubo::ladoZHorario(float dr, char cor) {
    float larg, rx, ry, rz;
    int k, modX, modY, modZ;

    for (int i = 0; i < 9; i++) {
        if (cor == 'y') {
            k = i + 18; // lado amarelo
            k = mapa2[k];
            rodaEixoZ(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, -dr);
        }
        else if (cor == 'w') {
            k = i; // lado branco
            k = mapa2[k];
            rodaEixoZ(cubinhos[k].rotTheta, cubinhos[k].rotPhi, cubinhos[k].rotGamma, +dr);
        }

        modX = (360 + (int(rotsX[k]) % 360)) % 360 / 90;
        modY = (360 + (int(rotsY[k]) % 360)) % 360 / 90;
        modZ = (360 + (int(rotsZ[k]) % 360)) % 360 / 90;

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 ||
            k == 9 || k == 11 || k == 15 || k == 17) {
            larg = largAresta;

            if (modZ == 0 && (4 + modX - modY) % 4 == 1) {
                rotsX[k] -= dr;
                rotsY[k] -= dr;
            }
            else if (modZ == 0 && (4 + modX - modY) % 4 == 3) {
                rotsX[k] += dr;
                rotsY[k] += dr;
            }
            else if (modZ == 2 && (4 + modX - modY) % 4 == 1) {
                rotsX[k] += dr;
                rotsY[k] += dr;
            }
            else if (modZ == 2 && (4 + modX - modY) % 4 == 3) {
                rotsX[k] -= dr;
                rotsY[k] -= dr;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26) {
            larg = sqrt(2) * largAresta;

            if (modZ == 1 && (modX + modY) % 4 < 2) {
                rotsX[k] += dr;
                rotsY[k] -= dr;
            }
            else if (modZ == 1 && (modX + modY) % 4 >= 2) {
                rotsX[k] -= dr;
                rotsY[k] += dr;
            }
            else if (modZ == 3 && (modX + modY) % 4 < 2) {
                rotsX[k] -= dr;
                rotsY[k] += dr;
            }
            else if (modZ == 3 && (modX + modY) % 4 >= 2) {
                rotsX[k] += dr;
                rotsY[k] -= dr;
            }

            else if (modZ == 0 && (4 + modX - modY) % 4 == 1) {
                rotsX[k] -= dr;
                rotsY[k] -= dr;
            }
            else if (modZ == 0 && (4 + modX - modY) % 4 == 3) {
                rotsX[k] += dr;
                rotsY[k] += dr;
            }
            else if (modZ == 2 && (4 + modX - modY) % 4 == 1) {
                rotsX[k] += dr;
                rotsY[k] += dr;
            }
            else if (modZ == 2 && (4 + modX - modY) % 4 == 3) {
                rotsX[k] -= dr;
                rotsY[k] -= dr;
            }
        }

        else {
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);

        cubinhos[k].cx = cos(rx) * larg + cx;
        cubinhos[k].cy = cos(ry) * larg + cy;
        cubinhos[k].cz = cos(rz) * larg + cz;
    }

    return;
}

void giraLaranjaHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoXHorario(DR, 'o');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraLaranjaHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('o');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraLaranjaAntiHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoXHorario(-DR, 'o');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraLaranjaAntiHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('O');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::laranjaHorario() {
    if (!flagRot) {
        flagRot = true;
        giraLaranjaHorario(id_);
    }
}

void Cubo::laranjaAntiHorario() {
    if (!flagRot) {
        flagRot = true;
        giraLaranjaAntiHorario(id_);
    }
}

void giraVermelhoHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoXHorario(DR, 'r');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraVermelhoHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('r');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraVermelhoAntiHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoXHorario(-DR, 'r');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraVermelhoAntiHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('R');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::vermelhoHorario() {
    if (!flagRot) {
        flagRot = true;
        giraVermelhoHorario(id_);
    }
}

void Cubo::vermelhoAntiHorario() {
    if (!flagRot) {
        flagRot = true;
        giraVermelhoAntiHorario(id_);
    }
}

void giraAzulHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoYHorario(DR, 'b');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraAzulHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('b');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraAzulAntiHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoYHorario(-DR, 'b');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraAzulAntiHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('B');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::azulHorario() {
    if (!flagRot) {
        flagRot = true;
        giraAzulHorario(id_);
    }
}

void Cubo::azulAntiHorario() {
    if (!flagRot) {
        flagRot = true;
        giraAzulAntiHorario(id_);
    }
}

void giraVerdeHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoYHorario(DR, 'g');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraVerdeHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('g');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraVerdeAntiHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoYHorario(-DR, 'g');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraVerdeAntiHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('G');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::verdeHorario() {
    if (!flagRot) {
        flagRot = true;
        giraVerdeHorario(id_);
    }
}

void Cubo::verdeAntiHorario() {
    if (!flagRot) {
        flagRot = true;
        giraVerdeAntiHorario(id_);
    }
}

void giraAmareloHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoZHorario(DR, 'y');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraAmareloHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('y');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraAmareloAntiHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoZHorario(-DR, 'y');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraAmareloAntiHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('Y');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::amareloHorario() {
    if (!flagRot) {
        flagRot = true;
        giraAmareloHorario(id_);
    }
}

void Cubo::amareloAntiHorario() {
    if (!flagRot) {
        flagRot = true;
        giraAmareloAntiHorario(id_);
    }
}

void giraBrancoHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoZHorario(DR, 'w');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraBrancoHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('w');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraBrancoAntiHorario(int id) {
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoZHorario(-DR, 'w');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY, giraBrancoAntiHorario, id);
    else {
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('W');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::brancoHorario() {
    if (!flagRot) {
        flagRot = true;
        giraBrancoHorario(id_);
    }
}

void Cubo::brancoAntiHorario() {
    if (!flagRot) {
        flagRot = true;
        giraBrancoAntiHorario(id_);
    }
}

void Cubo::printId() {
    cout << "id = " << id_ << endl;
}