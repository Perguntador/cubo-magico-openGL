#include "cubo.h"
#include <iostream>
#include <GL/glut.h>

#define DR 10
#define DELAY 10

using namespace std;

int j = 0;

Cubo *pCubos[10];

int Cubo::proxId_ = 0;



Cubo::Cubo (float _cx = 0.f, float _cy = 0.f, float _cz = 0.f, float _largAresta = 1.f) : id_(proxId_++) {
    pCubos[id_] = this;
    cx = _cx;
    cy = _cy;
    cz = _cz;
    largAresta = _largAresta;

    for(int i = 0; i < 27; i++){
        cubinhos[i].cz = cz + (-1+i/9%3)*largAresta;
        cubinhos[i].cy = cy + (-1+i%3)*largAresta;
        cubinhos[i].cx = cx + (-1+i/3%3)*largAresta;
        cubinhos[i].largAresta = largAresta;
        mapa[i] = true;
        mapa2[i] = i;
    }
}






void Cubo::displayCubo(){
    for (int i = 0;i < 27; i++){
        if (mapa[i])
            cubinhos[i].displayCubinhoPolar();
    }
}

void Cubo::tecla1(){
    // for (int i = 0;i < 27; i++){
    //     mapa[i] = true;
    //     // mapa[i] = !mapa[(i+1)%27];
    // }
    // cout << "j = " << j << endl;
    // mapa[j]=false;
    // j = (j+1)%27;

    // return;

    int k;
    for (int i = 0; i < 9; i++){
        // k = (i/3)*9+(i%3)+6; // lado laranha
        k = (i/3)*9+(i%3); // lado vermelho
        // k = i*3+2; // lado azul
        // k = i*3; // lado verde
        // k = i; // lado branco
        // k = i+18; // lado amarelo 
        mapa[k] = !mapa[k];
    }
    // lado branco (0,1,2,3,4,5,6,7,8)
    // lado amarelo (18,19,20,21,22,23,24,25,26)
    // lado verde (0,3,6,9,12,15,18,21,24)
    // lado azul (2,5,8,11,14,17,20,23,26)
    // lado vermelho (0,1,2,9,10,11,18,19,20)
    // lado laranha (6,7,8,15,16,17,24,25,26)


}


void Cubo::tecla2(){
    for (int i = 0;i < 27; i++){
        mapa[i] = true;
    }
}

void Cubo::tecla3(){
    for (int i = 0;i < 27; i++){
        mapa[i] = false;
    }
}

void Cubo::tecla4(){
    for (int i = 0;i < 27; i++){
        mapa[i] = !mapa[i];
    }
}

void Cubo::tecla5(){
    return;
}

void Cubo::tecla6(){
    return;
}

void Cubo::tecla7(){
    return;
}






void giraVerdeHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = i*3; // lado verde 
        cubo->cubinhos[k].rotY += DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraVerdeHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraVerdeAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = i*3; // lado verde 
        cubo->cubinhos[k].rotY -= DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraVerdeAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraAzulHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        // k = i*3; // lado verde 
        k = i*3+2; // lado azul
        cubo->cubinhos[k].rotY -= DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraAzulHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraAzulAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = i*3+2; // lado azul
        cubo->cubinhos[k].rotY += DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraAzulAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}


void giraLaranjaHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = (i/3)*9+(i%3)+6; // lado laranha
        cubo->cubinhos[k].rotX -= DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraLaranjaHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraLaranjaAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = (i/3)*9+(i%3)+6; // lado laranha
        cubo->cubinhos[k].rotX += DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraLaranjaAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraVermelhoHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = (i/3)*9+(i%3); // lado vermelho
        cubo->cubinhos[k].rotX += DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraVermelhoHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraVermelhoAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = (i/3)*9+(i%3); // lado vermelho
        cubo->cubinhos[k].rotX -= DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraVermelhoAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraBrancoHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = i; // lado branco
        cubo->cubinhos[k].rotZ += DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraBrancoHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraBrancoAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = i; // lado branco
        cubo->cubinhos[k].rotZ -= DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraBrancoAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraAmareloHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = i+18; // lado amarelo
        cubo->cubinhos[k].rotZ -= DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraAmareloHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraAmareloAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    for (int i = 0; i < 9; i++){
        k = i+18; // lado amarelo
        cubo->cubinhos[k].rotZ += DR;
    }
    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraAmareloAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::amareloHorario(){
    if (!flagRot){
        flagRot = true;
        giraAmareloHorario(id_);
    }
}

void Cubo::brancoHorario(){
    if (!flagRot){
        flagRot = true;
        giraBrancoHorario(id_);
    }
}

void Cubo::laranjaHorario(){
    if (!flagRot){
        flagRot = true;
        giraLaranjaHorario(id_);
    }
}
void Cubo::vermelhoHorario(){
    if (!flagRot){
        flagRot = true;
        giraVermelhoHorario(id_);
    }
}
void Cubo::verdeHorario(){
    if (!flagRot){
        flagRot = true;
        giraVerdeHorario(id_);
    }
}
void Cubo::azulHorario(){
    if (!flagRot){
        flagRot = true;
        giraAzulHorario(id_);
    }
}



void Cubo::amareloAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraAmareloAntiHorario(id_);
    }
}

void Cubo::brancoAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraBrancoAntiHorario(id_);
    }
}

void Cubo::laranjaAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraLaranjaAntiHorario(id_);
    }
}
void Cubo::vermelhoAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraVermelhoAntiHorario(id_);
    }
}
void Cubo::verdeAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraVerdeAntiHorario(id_);
    }
}
void Cubo::azulAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraAzulAntiHorario(id_);
    }
}






void Cubo::printId(){
    cout << "id = " << id_ << endl;
}