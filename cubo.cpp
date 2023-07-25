#include "cubo.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <GL/glut.h>

#define DR 10
#define DELAY 10
// #define PI 3.141592
#define PI M_PI
using namespace std;

int j = 0;

Cubo *pCubos[10];

int Cubo::proxId_ = 0;


float grau2rad(float grau){
    return grau/180.*PI;
}

/*
eixo x: sentido do laranja
eixo y: sentido do azul
eixo z: sentido do amarelo
*/


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
        // mapa[i] = true;
        mapa[i] = false;
        mapa2[i] = i;

        rotsX[i] = 0;
        rotsY[i] = 0;
        rotsZ[i] = 0;

    }




    int k;
    float larg, rx, ry, rz;

    j=0;
    for (int i = 0; i < 27; i++){
        // k = i*3+1;
        // k = (i/3)*9+(i%3)+3;
        // k=i+9;

        k=i;
        k = mapa2[k];
        // if (i==13 || i == j){
        // if (i==13 || i == 0 || i == 2 || i == 6 || i == 8 || i == 18 || i == 20 || i == 24 || i == 26){
        // if (i==13 || i == 1 || i == 3 || i == 5 || i == 7 || i == 19 || i == 21 || i == 23 || i == 25){
        // if (i==13 || i == 9 || i == 11 || i == 15 || i == 17){
        // if (i==13 || i == 1 || i == 3 || i == 5 || i == 7 || i == 19 || i == 21 || i == 23 || i == 25 || i == 9 || i == 11 || i == 15 || i == 17){
        if (i==13 || i == j){
            // mapa[k]=true;
        }

        if (i == 17){
            larg = largAresta;

            rotsX[k] = 90*0;
            rotsY[k] = 90*0;
            rotsZ[k] = 90*1;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 15){
            larg = largAresta;

            rotsX[k] = 90*0;
            rotsY[k] = 90*2;
            rotsZ[k] = 90*1;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 11){
            larg = largAresta;

            rotsX[k] = 90*2;
            rotsY[k] = 90*0;
            rotsZ[k] = 90*1;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 9){
            larg = largAresta;

            rotsX[k] = 90*2;
            rotsY[k] = 90*2;
            rotsZ[k] = 90*1;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 25){
            larg = largAresta;

            rotsX[k] = 90*0;
            rotsY[k] = 90*3;
            rotsZ[k] = 90*0;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 23){
            larg = largAresta;

            rotsX[k] = 90*1;
            rotsY[k] = 90*0;
            rotsZ[k] = 90*0;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 21){
            larg = largAresta;

            rotsX[k] = 90*3;
            rotsY[k] = 90*2;
            rotsZ[k] = 90*0;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 19){
            larg = largAresta;

            rotsX[k] = 90*2;
            rotsY[k] = 90*1;
            rotsZ[k] = 90*0;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 7){
            larg = largAresta;

            rotsX[k] = 90*0;
            rotsY[k] = 90*3;
            rotsZ[k] = 90*2;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 5){
            larg = largAresta;

            rotsX[k] = 90*1;
            rotsY[k] = 90*0;
            rotsZ[k] = 90*2;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 3){
            larg = largAresta;

            rotsX[k] = 90*3;
            rotsY[k] = 90*2;
            rotsZ[k] = 90*2;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 1){
            larg = largAresta;

            rotsX[k] = 90*2;
            rotsY[k] = 90*1;
            rotsZ[k] = 90*2;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 26){
            larg = sqrt(largAresta*2);

            rotsX[k] = 45+90*3;
            rotsY[k] = 45+90*0;
            rotsZ[k] = 45+90*0;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }


        if (i == 24){
            larg = sqrt(largAresta*2);

            rotsX[k] = 45+90*0;
            rotsY[k] = 45+90*1;
            rotsZ[k] = 45+90*0;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }


        if (i == 20){
            larg = sqrt(largAresta*2);

            rotsX[k] = 45+90*2;
            rotsY[k] = 45+90*3;
            rotsZ[k] = 45+90*0;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }


        if (i == 18){
            larg = sqrt(largAresta*2);

            rotsX[k] = 45+90*1;
            rotsY[k] = 45+90*2;
            rotsZ[k] = 45+90*0;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

        if (i == 8){
            larg = sqrt(largAresta*2);

            rotsX[k] = 45+90*3;
            rotsY[k] = 45+90*3;
            rotsZ[k] = 45+90*1;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }


        if (i == 6){
            larg = sqrt(largAresta*2);

            rotsX[k] = 45+90*0;
            rotsY[k] = 45+90*2;
            rotsZ[k] = 45+90*1;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }


        if (i == 2){
            larg = sqrt(largAresta*2);

            rotsX[k] = 45+90*2;
            rotsY[k] = 45+90*0;
            rotsZ[k] = 45+90*1;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }




        if (i == 0){
            larg = sqrt(largAresta*2);

            rotsX[k] = 45+90*1;
            rotsY[k] = 45+90*1;
            rotsZ[k] = 45+90*1;

            rx = grau2rad(rotsX[k]);
            ry = grau2rad(rotsY[k]);
            rz = grau2rad(rotsZ[k]);
            
            cubinhos[k].cx =  cos(rx)*larg;
            cubinhos[k].cy =  cos(ry)*larg;
            cubinhos[k].cz =  cos(rz)*larg;
        }

    }



/*
eixo x: sentido do laranja
eixo y: sentido do azul
eixo z: sentido do amarelo
*/


    /*
        if (i==4){
                // cubinhos[k].rotX -= DR;
                continue;
            }
            else if (i%2){
                larg = largAresta;
            }
            else{
                larg = sqrt(largAresta*2);
            }
    // */

    for (int i = 0; i < 9; i++){
        // k = (i/3)*9+(i%3)+6; // lado laranja
        // k = (i/3)*9+(i%3); // lado vermelho
        // k = i*3+2; // lado azul
        // k = i*3; // lado verde
        // k = i; // lado branco
        // k = i+18; // lado amarelo 

        // k = i*3+1;
        // k = (i/3)*9+(i%3)+3;
        // k=i+9;

        k = i+18;

        k = mapa2[k];
        // mapa[k] = true;
    }
    mapa[13]=true;


}






void Cubo::displayCubo(){
    for (int i = 0;i < 27; i++){
        if (mapa[i])
            cubinhos[i].displayCubinhoPolar2();
    }
}

void Cubo::tecla9(){

    int k;
    float larg, rx, ry, rz;

    k = mapa2[13];
    cubinhos[k].rotY+=DR;
    cout << cubinhos[k].rotY << endl;

}
void Cubo::tecla0(){

    int k;
    float larg, rx, ry, rz;

    k = mapa2[13];
    cubinhos[k].rotZ+=DR;
    cout << cubinhos[k].rotZ << endl;


}

void Cubo::tecla1(){

    int k;
    float larg, rx, ry, rz;

    k = mapa2[13];
    cubinhos[k].rotX-=DR;
    cout << cubinhos[k].rotX << endl;



    return;
    for (int i = 0;i < 27; i++){
        // mapa[i] = false;
        mapa[i] = true;
    }
    cout << "j = " << j << endl;
    k=mapa2[j];
    // mapa[k]=true;
    mapa[k]=false;
    j = (j+1)%27;

    return;

    // int k;
    for (int i = 0; i < 9; i++){
        // k = (i/3)*9+(i%3)+6; // lado laranja
        k = (i/3)*9+(i%3); // lado vermelho
        // k = i*3+2; // lado azul
        // k = i*3; // lado verde
        // k = i; // lado branco
        // k = i+18; // lado amarelo 

        k = mapa2[k];
        mapa[k] = !mapa[k];
    }
    // lado branco (0,1,2,3,4,5,6,7,8)
    // lado amarelo (18,19,20,21,22,23,24,25,26)
    // lado verde (0,3,6,9,12,15,18,21,24)){
        
    // lado azul (2,5,8,11,14,17,20,23,26)
    // lado vermelho (0,1,2,9,10,11,18,19,20)
    // lado laranja (6,7,8,15,16,17,24,25,26)


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

    int k;
    for (int i = 0; i < 9; i++){
        // k = (i/3)*9+(i%3)+6; // lado laranja
        // k = (i/3)*9+(i%3); // lado vermelho
        // k = i*3+2; // lado azul
        // k = i*3; // lado verde
        k = i; // lado branco
        // k = i+18; // lado amarelo
        k = mapa2[k];
        mapa[k] = !mapa[k];
    }

    
    return;
}

void Cubo::rearranjaMapa(char c){

    int v1[9] = {2,5,8,1,4,7,0,3,6};
    int v2[9] = {6,3,0,7,4,1,8,5,2};
    int vAux[9];
    int iAux;

    int k;

    if (c=='Y'){
        for (int i = 0; i < 9; i++){
            iAux = v1[i]+18; // lado amarelo
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = i+18; // lado amarelo
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c=='y'){
        for (int i = 0; i < 9; i++){
            iAux = v2[i]+18; // lado amarelo
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = i+18; // lado amarelo
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c=='W'){
        for (int i = 0; i < 9; i++){
            iAux = v2[i]; // lado branco
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = i; // lado branco
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c=='w'){
        // cout << "branco\n";
        for (int i = 0; i < 9; i++){
            iAux = v1[i]; // lado branco
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = i; // lado branco
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c=='O'){
        for (int i = 0; i < 9; i++){
            iAux = (v2[i]/3)*9+(v2[i]%3)+6; // lado laranja
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = (i/3)*9+(i%3)+6; // lado laranja
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c=='o'){
        for (int i = 0; i < 9; i++){
            iAux = (v1[i]/3)*9+(v1[i]%3)+6; // lado laranja
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = (i/3)*9+(i%3)+6; // lado laranja
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c=='R'){
        for (int i = 0; i < 9; i++){
        // k = (i/3)*9+(i%3); // lado vermelho
            iAux = (v1[i]/3)*9+(v1[i]%3); // lado vermelho
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = (i/3)*9+(i%3); /// lado vermelho
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c=='r'){
        for (int i = 0; i < 9; i++){
            iAux = (v2[i]/3)*9+(v2[i]%3); // lado vermelho
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = (i/3)*9+(i%3); // lado vermelho
            mapa2[iAux] = vAux[i];
        }
    }

    else if (c=='B'){
        for (int i = 0; i < 9; i++){
            iAux = v1[i]*3+2; // lado azul
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = i*3+2; // lado azul
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c=='b'){
        for (int i = 0; i < 9; i++){
            iAux = v2[i]*3+2; // lado azul
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = i*3+2; // lado azul
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c=='G'){
        for (int i = 0; i < 9; i++){
            iAux = v2[i]*3; // lado verde
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = i*3; // lado verde
            mapa2[iAux] = vAux[i];
        }
    }
    else if (c=='g'){
        for (int i = 0; i < 9; i++){
            iAux = v1[i]*3; // lado verde
            vAux[i] = mapa2[iAux];
        }
        for (int i = 0; i < 9; i++){
            iAux = i*3; // lado verde
            mapa2[iAux] = vAux[i];
        }
    }
    else{
        cout<<"Rearranjamento invalido\n";
    }


    // cout << "Rearranja\n";
    /*
    0-2
    1-5
    2-8
    3-1
    4-4
    5-7
    6-0
    7-3
    8-6
    */
    /*
    for (int i = 0; i < 27; i++){
        mapa[i] = true;
    }
    k = 0;
    k = mapa2[k];
    mapa[k] = false;
    */
    return;
}

void aumentaX(float &rx, float &ry, float &rz, float dr){
    int modX, modY, modZ;

    modX = (360+(int(rx)%360))%360 / 90;
    modY = (360+(int(ry)%360))%360 / 90;
    modZ = (360+(int(rz)%360))%360 / 90;

    if (modX==3&&modZ==0){ // azul no X
        cout << "azul1\n";
        ry+=dr;
    }
    else if (modX==1&&modZ==2){ // azul no X
        cout << "azul2\n";
        ry-=dr;
    }
    else if (modX==0&&modY==0&&modZ==3){ // azul no X
        cout << "azul3\n";
        rx=-90;
        ry+=dr;
        rz=0;
    }
    else if (modX==2&&modY==0&&modZ==1){ // azul no X
        cout << "azul4\n";
        rx=-90;
        ry+=dr;
        rz=0;
    }
    else if (modX==0&&modY==2&&modZ==1){ // azul no X
        cout << "azul5\n";
        rx=-90;
        ry+=dr;
        rz=0;
    }
    else if (modX==2&&modY==2&&modZ==3){ // azul no X
        cout << "azul6\n";
        rx=-90;
        ry+=dr;
        rz=0;
    }

    else if(modX==1&&modZ==0){ // verde no X
        cout << "verde1\n";
        ry-=dr;
    }
    else if(modX==3&&modZ==2){ // verde no X
        cout << "verde2\n";
        ry+=dr;
    }
    else if(modX==0&&modY==0&&modZ==1){ // verde no X
        cout << "verde3\n";
        rx=90;
        ry-=dr;
        rz=0;
    }
    else if(modX==2&&modY==0&&modZ==3){ // verde no X
        cout << "verde4\n";
        rx=90;
        ry-=dr;
        rz=0;
    }
    else if(modX==0&&modY==2&&modZ==3){ // verde no X
        cout << "verde5\n";
        rx=90;
        ry-=dr;
        rz=0;
    }
    else if(modX==2&&modY==2&&modZ==1){ // verde no X
        cout << "verde6\n";
        rx=90;
        ry-=dr;
        rz=0;
    }

    else if(modX==1&&modZ==3){ // laranja no X
        cout << "laranja1\n";
        ry-=dr;
    }

    else if(modX==3 && modZ==1){ // laranja no X
        cout << "laranja2\n";
        ry += dr;
    }
    else if (modX==0&&modY==0&&modZ==0){
        cout << "laranja3\n";
        rx = +90;
        ry -= dr;
        rz = -90;
        
    }
    else if (modX==2&&modY==0&&modZ==2){
        cout << "laranja4\n";
        rx = +90;
        ry -= dr;
        rz = -90;
    }
    else if (modX==2&&modY==2&&modZ==0){
        cout << "laranja5\n";
        rx = +90;
        ry -= dr;
        rz = -90;
    }
    else if (modX==0&&modY==2&&modZ==2){
        cout << "laranja6\n";
        rx = +90;
        ry -= dr;
        rz = -90;
    }

    else if(modX==3&&modZ==3){ // vermelho no X
        cout << "vermelho1\n";
        ry+=dr;
    }
    else if(modX==1&&modZ==1){ // vermelho no X
        cout << "vermelho2\n";
        ry-=dr;
    }
    else if(modX==2&&modY==0&&modZ==0){ // vermelho no X
        cout << "vermelho3\n";
        rx=-90;
        ry+=dr;
        rz=-90;
    }
    else if(modX==0&&modY==2&&modZ==0){ // vermelho no X
        cout << "vermelho4\n";
        rx=-90;
        ry+=dr;
        rz=-90;
    }
    else if(modX==0&&modY==0&&modZ==2){ // vermelho no X
        cout << "vermelho5\n";
        rx=-90;
        ry+=dr;
        rz=-90;
    }
    else if(modX==2&&modY==2&&modZ==2){ // vermelho no X
        cout << "vermelho6\n";
        rx=-90;
        ry+=dr;
        rz=-90;
    }


    else if(modX==2&&modY==3){ // amarelo no X
        cout << "amarelo1\n";
        rz+=dr;
    }
    else if(modX==0&&modY==1){ // amarelo no X
        cout << "amarelo2\n";
        rz+=dr;
    }

    else if(modX==0&&modY==3){ // branco no X
        cout << "branco1\n";
        rz-=dr;
    }
    else if(modX==2&&modY==1){ // branco no X
        cout << "branco2\n";
        rz-=dr;
    }

    cout << rx << " " << ry << " " << rz << endl;
}

void aumentaY(float &rx, float &ry, float &rz, float dr){
    int modX, modY, modZ;

    modX = (360+(int(rx)%360))%360 / 90;
    modY = (360+(int(ry)%360))%360 / 90;
    modZ = (360+(int(rz)%360))%360 / 90;

    if (modX==0&&modZ==0){ // azul no Y
        cout << "azul1\n";
        ry-=dr;
    }
    else if (modX==2&&modZ==2){ // azul no Y
        cout << "azul2\n";
        ry+=dr;
    }
    else if (modX==3&&modY==0&&modZ==1){ // azul no Y
        cout << "azul3\n";
        rx=0;
        ry-=dr;
        rz=0;
    }
    else if (modX==1&&modY==0&&modZ==3){ // azul no Y
        cout << "azul4\n";
        rx=0;
        ry-=dr;
        rz=0;
    }
    else if (modX==1&&modY==2&&modZ==1){ // azul no Y
        cout << "azul5\n";
        rx=0;
        ry-=dr;
        rz=0;
    }
    else if (modX==3&&modY==2&&modZ==3){ // azul no Y
        cout << "azul6\n";
        rx=0;
        ry-=dr;
        rz=0;
    }
    

    else if (modX==2&&modZ==0){ // verde no Y
        cout << "verde1\n";
        ry+=dr;
    }
    else if (modX==0&&modZ==2){ // verde no Y
        cout << "verde2\n";
        ry-=dr;
    }
    else if (modX==3&&modY==0&&modZ==3){ // verde no Y
        cout << "verde3\n";
        rx=180;
        ry+=dr;
        rz=0;
    }
    else if (modX==1&&modY==0&&modZ==1){ // verde no Y
        cout << "verde4\n";
        rx=180;
        ry+=dr;
        rz=0;
    }
    else if (modX==3&&modY==2&&modZ==1){ // verde no Y
        cout << "verde5\n";
        rx=180;
        ry+=dr;
        rz=0;
    }
    else if (modX==1&&modY==2&&modZ==3){ // verde no Y
        cout << "verde6\n";
        rx=180;
        ry+=dr;
        rz=0;
    }

    else if (modX==0&&modZ==1){ // laranja no Y
        cout << "laranja1\n";
        ry-=dr;
    }
    else if (modX==2&&modZ==3){ // laranja no Y
        cout << "laranja2\n";
        ry+=dr;
    }
    else if (modX==1&&modY==0&&modZ==0){ // laranja no Y
        cout << "laranja3\n";
        rx=0;
        ry-=dr;
        rz=90;
    }
    else if (modX==3&&modY==0&&modZ==2){ // laranja no Y
        cout << "laranja4\n";
        rx=0;
        ry-=dr;
        rz=90;
    }
    else if (modX==3&&modY==2&&modZ==0){ // laranja no Y
        cout << "laranja5\n";
        rx=0;
        ry-=dr;
        rz=90;
    }
    else if (modX==1&&modY==2&&modZ==2){ // laranja no Y
        cout << "laranja6\n";
        rx=0;
        ry-=dr;
        rz=90;
    }

    else if (modX==2&&modZ==1){ // vermelho no Y
        cout << "vermelho1\n";
        ry+=dr;
    }
    else if (modX==0&&modZ==3){ // vermelho no Y
        cout << "vermelho2\n";
        ry-=dr;
    }
    else if (modX==3&&modY==0&&modZ==0){ // vermelho no Y
        cout << "vermelho3\n";
        rx=180;
        ry+=dr;
        rz=90;
    }
    else if (modX==1&&modY==0&&modZ==2){ // vermelho no Y
        cout << "vermelho4\n";
        rx=180;
        ry+=dr;
        rz=90;
    }
    else if (modX==3&&modY==2&&modZ==2){ // vermelho no Y
        cout << "vermelho5\n";
        rx=180;
        ry+=dr;
        rz=90;
    }
    else if (modX==1&&modY==2&&modZ==0){ // vermelho no Y
        cout << "vermelho6\n";
        rx=180;
        ry+=dr;
        rz=90;
    }

    else if (modX==1&&modY==1){ // amarelo no Y
        cout << "amarelo1\n";
        rz-=dr;
    }
    else if (modX==3&&modY==3){ // amarelo no Y
        cout << "amarelo2\n";
        rz-=dr;
    }

    else if (modX==3&&modY==1){ // branco no Y
        cout << "branco1\n";
        rz+=dr;
    }
    else if (modX==1&&modY==3){ // branco no Y
        cout << "branco2\n";
        rz+=dr;
    }

    cout << rx << " " << ry << " " << rz << endl;

}

void aumentaZ(float &rx, float &ry, float &rz, float dr){
    int modX, modY, modZ;

    modX = (360+(int(rx)%360))%360 / 90;
    modY = (360+(int(ry)%360))%360 / 90;
    modZ = (360+(int(rz)%360))%360 / 90;
    rx+=dr;

    // cout << rx << " " << ry << " " << rz << endl;

}


void Cubo::teclaPonto(){
    aumentaY(cubinhos[13].rotX,cubinhos[13].rotY,cubinhos[13].rotZ,DR);
}


void Cubo::tecla6(){

    float larg;
    float rx, ry, rz;

    int k;
    int modX, modY, modZ;
    int mods;

    for (int i = 0; i < 27; i++){
        k=i;
        k = mapa2[k];

        if (i==j){
            cout << "rotX=" << (360+(int(rotsX[k])%360))%360<<endl;
            cout << "rotY=" << (360+(int(rotsY[k])%360))%360<<endl;
            cout << "rotZ=" << (360+(int(rotsZ[k])%360))%360<<endl<<endl;
        }

        modX = (360+(int(rotsX[k])%360))%360 / 90;
        modY = (360+(int(rotsY[k])%360))%360 / 90;
        modZ = (360+(int(rotsZ[k])%360))%360 / 90;

        if (i==j)
            cout << modX<<modY<<modZ<<endl;

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 || k == 9 || k == 11 || k == 15 || k == 17){
            larg = largAresta;

            if (modZ == 0 && (4+modX-modY)%4==1){
                rotsX[k] -= DR;
                rotsY[k] -= DR;
            }
            else if (modZ == 0 && (4+modX-modY)%4==3){
                rotsX[k] += DR;
                rotsY[k] += DR;
            }
            else if (modZ == 2 && (4+modX-modY)%4==1){
                rotsX[k] += DR;
                rotsY[k] += DR;
            }
            else if (modZ == 2 && (4+modX-modY)%4==3){
                rotsX[k] -= DR;
                rotsY[k] -= DR;
            }

        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26){
        
            larg = sqrt(largAresta*2);

            
            if (modZ == 1 && (modX+modY)%4==0){
                rotsX[k] += DR;
                rotsY[k] -= DR;
            }
            else if (modZ == 1 && (modX+modY)%4==2){
                rotsX[k] -= DR;
                rotsY[k] += DR;
            }
            else if (modZ == 3 && (modX+modY)%4==0){
                rotsX[k] -= DR;
                rotsY[k] += DR;
            }
            else if (modZ == 3 && (modX+modY)%4==2){
                rotsX[k] += DR;
                rotsY[k] -= DR;
            }

            else if (modZ == 0 && (4+modX-modY)%4==1){
                rotsX[k] -= DR;
                rotsY[k] -= DR;
            }
            else if (modZ == 0 && (4+modX-modY)%4==3){
                rotsX[k] += DR;
                rotsY[k] += DR;
            }
            else if (modZ == 2 && (4+modX-modY)%4==1){
                rotsX[k] += DR;
                rotsY[k] += DR;
            }
            else if (modZ == 2 && (4+modX-modY)%4==3){
                rotsX[k] -= DR;
                rotsY[k] -= DR;
            }
        }

        else{
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);
        
        cubinhos[k].cx =  cos(rx)*larg;
        cubinhos[k].cy =  cos(ry)*larg;
        cubinhos[k].cz =  cos(rz)*larg;
        
    }
    cout << endl;
    for (int i = 0; i < 9; i++){
        k = i; // lado branco
        k = mapa2[k];
        aumentaZ(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,+DR);
        
        k = i+18; // lado amarelo
        k = mapa2[k];
        aumentaZ(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,-DR);
    }

    k=mapa2[0];
    modX = (360+(int(rotsX[k])%360))%360 / 90;
    modY = (360+(int(rotsY[k])%360))%360 / 90;
    modZ = (360+(int(rotsZ[k])%360))%360 / 90;

    mods=modX*100+modY*10+modZ;
    if (mods!=111&&mods!=212&&mods!=221&&mods!=122){
        rearranjaMapa('w');
        rearranjaMapa('y');
    }

    return;
}


void Cubo::tecla7(){
    int k;
    float larg, rx, ry, rz;
    int mods;
    int modX, modY, modZ;
    
    for (int i = 0; i < 27; i++){
        k=i;
        k = mapa2[k];

        if (k==j){
            cout << "rotX=" << (360+(int(rotsX[k])%360))%360<<endl;
            cout << "rotY=" << (360+(int(rotsY[k])%360))%360<<endl;
            cout << "rotZ=" << (360+(int(rotsZ[k])%360))%360<<endl<<endl;
        }
        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 || k == 9 || k == 11 || k == 15 || k == 17){
            larg = largAresta;

            modX = (360+(int(rotsX[k])%360))%360 / 90;
            modY = (360+(int(rotsY[k])%360))%360 / 90;
            modZ = (360+(int(rotsZ[k])%360))%360 / 90;

            if (k==j)
                cout << modX<<modY<<modZ<<endl;

            if (modY == 0 && (4+modX-modZ)%4==1){
                rotsX[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modY == 0 && (4+modX-modZ)%4==3){
                rotsX[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 2 && (4+modX-modZ)%4==1){
                rotsX[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 2 && (4+modX-modZ)%4==3){
                rotsX[k] += DR;
                rotsZ[k] += DR;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26){
            larg = sqrt(largAresta*2);

            modX = (360+(int(rotsX[k])%360))%360 / 90;
            modY = (360+(int(rotsY[k])%360))%360 / 90;
            modZ = (360+(int(rotsZ[k])%360))%360 / 90;
            if (k==j)
                cout << modX<<modY<<modZ<<endl;

            if (modY == 1 && (modX+modZ)%4==0){
                rotsX[k] -= DR;
                rotsZ[k] += DR;
            }
            else if (modY == 1 && (modX+modZ)%4==2){
                rotsX[k] += DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 3 && (modX+modZ)%4==0){
                rotsX[k] += DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 3 && (modX+modZ)%4==2){
                rotsX[k] -= DR;
                rotsZ[k] += DR;
            }

            else if (modY == 0 && (4+modX-modZ)%4==1){
                rotsX[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modY == 0 && (4+modX-modZ)%4==3){
                rotsX[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 2 && (4+modX-modZ)%4==1){
                rotsX[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modY == 2 && (4+modX-modZ)%4==3){
                rotsX[k] += DR;
                rotsZ[k] += DR;
            }
        }
        else{
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);
        
        cubinhos[k].cx =  cos(rx)*larg;
        cubinhos[k].cy =  cos(ry)*larg;
        cubinhos[k].cz =  cos(rz)*larg;

    }

    for (int i = 0; i < 9; i++){
        k = i*3+2; // lado azul
        k = mapa2[k];
        aumentaY(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,+DR);
        
        k = i*3; // lado verde
        k = mapa2[k];
        aumentaY(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,-DR);
    }

    k=mapa2[0];
    modX = (360+(int(rotsX[k])%360))%360 / 90;
    modY = (360+(int(rotsY[k])%360))%360 / 90;
    modZ = (360+(int(rotsZ[k])%360))%360 / 90;

    mods=modX*100+modY*10+modZ;
    if (mods!=111&&mods!=212&&mods!=221&&mods!=122){
        rearranjaMapa('b');
        rearranjaMapa('g');
    }

    return;
}


void Cubo::tecla8(){
    int k;
    float larg, rx, ry, rz;
    int mods;
    int modX, modY, modZ;

    for (int i = 0; i < 27; i++){
        k=i;
        k = mapa2[k];

        if (i==j){
            cout << "rotX=" << (360+(int(rotsX[k])%360))%360<<endl;
            cout << "rotY=" << (360+(int(rotsY[k])%360))%360<<endl;
            cout << "rotZ=" << (360+(int(rotsZ[k])%360))%360<<endl<<endl;
        }

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 || k == 9 || k == 11 || k == 15 || k == 17){
            larg = largAresta;

            modX = (360+(int(rotsX[k])%360))%360 / 90;
            modY = (360+(int(rotsY[k])%360))%360 / 90;
            modZ = (360+(int(rotsZ[k])%360))%360 / 90;

            if (i==j)
                cout << modX<<modY<<modZ<<endl;

            if (modX == 0 && (4+modY-modZ)%4==1){
                rotsY[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modX == 0 && (4+modY-modZ)%4==3){
                rotsY[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modX == 2 && (4+modY-modZ)%4==1){
                rotsY[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modX == 2 && (4+modY-modZ)%4==3){
                rotsY[k] -= DR;
                rotsZ[k] -= DR;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26){
            larg = sqrt(largAresta*2);

            modX = (360+(int(rotsX[k])%360))%360 / 90;
            modY = (360+(int(rotsY[k])%360))%360 / 90;
            modZ = (360+(int(rotsZ[k])%360))%360 / 90;
            if (k==j)
                cout << modX<<modY<<modZ<<endl;

            if (modX == 1 && (modY+modZ)%4==0){
                rotsY[k] += DR;
                rotsZ[k] -= DR;
            }
            else if (modX == 1 && (modY+modZ)%4==2){
                rotsY[k] -= DR;
                rotsZ[k] += DR;
            }
            else if (modX == 3 && (modY+modZ)%4==0){
                rotsY[k] -= DR;
                rotsZ[k] += DR;
            }
            else if (modX == 3 && (modY+modZ)%4==2){
                rotsY[k] += DR;
                rotsZ[k] -= DR;
            }

            else if (modX == 0 && (4+modY-modZ)%4==1){
                rotsY[k] -= DR;
                rotsZ[k] -= DR;
            }
            else if (modX == 0 && (4+modY-modZ)%4==3){
                rotsY[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modX == 2 && (4+modY-modZ)%4==1){
                rotsY[k] += DR;
                rotsZ[k] += DR;
            }
            else if (modX == 2 && (4+modY-modZ)%4==3){
                rotsY[k] -= DR;
                rotsZ[k] -= DR;
            }
        }

        else{
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);
        
        cubinhos[k].cx =  cos(rx)*larg;
        cubinhos[k].cy =  cos(ry)*larg;
        cubinhos[k].cz =  cos(rz)*larg;
    }

    for (int i = 0; i < 9; i++){
        k = (i/3)*9+(i%3)+6; // lado laranja
        k = mapa2[k];
        aumentaX(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,-DR);
        
        k = (i/3)*9+(i%3); // lado vermelho
        k = mapa2[k];
        aumentaX(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,+DR);
    }

    k=mapa2[0];
    modX = (360+(int(rotsX[k])%360))%360 / 90;
    modY = (360+(int(rotsY[k])%360))%360 / 90;
    modZ = (360+(int(rotsZ[k])%360))%360 / 90;

    mods=modX*100+modY*10+modZ;
    if (mods!=111&&mods!=212&&mods!=221&&mods!=122){
        rearranjaMapa('o');
        rearranjaMapa('r');
    }
    
    return;
}



void Cubo::ladoXHorario(float dr, char cor){
    int k;
    float larg, rx, ry, rz;
    int mods;
    int modX, modY, modZ;

    // for (int i = 0; i < 27; i++){
    for (int i = 0; i < 9; i++){
        if (cor == 'o'){
            k = (i/3)*9+(i%3)+6; // lado laranja
        }
        else if (cor == 'r'){
            k = (i/3)*9+(i%3); // lado vermelho
        }
        // k=i;
        k = mapa2[k];

        if (i==j){
            cout << "rotX=" << (360+(int(rotsX[k])%360))%360<<endl;
            cout << "rotY=" << (360+(int(rotsY[k])%360))%360<<endl;
            cout << "rotZ=" << (360+(int(rotsZ[k])%360))%360<<endl<<endl;
        }

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 || k == 9 || k == 11 || k == 15 || k == 17){
            larg = largAresta;

            modX = (360+(int(rotsX[k])%360))%360 / 90;
            modY = (360+(int(rotsY[k])%360))%360 / 90;
            modZ = (360+(int(rotsZ[k])%360))%360 / 90;

            if (i==j)
                cout << modX<<modY<<modZ<<endl;

            if (modX == 0 && (4+modY-modZ)%4==1){
                rotsY[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modX == 0 && (4+modY-modZ)%4==3){
                rotsY[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modX == 2 && (4+modY-modZ)%4==1){
                rotsY[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modX == 2 && (4+modY-modZ)%4==3){
                rotsY[k] -= dr;
                rotsZ[k] -= dr;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26){
            larg = sqrt(largAresta*2);

            modX = (360+(int(rotsX[k])%360))%360 / 90;
            modY = (360+(int(rotsY[k])%360))%360 / 90;
            modZ = (360+(int(rotsZ[k])%360))%360 / 90;
            if (k==j)
                cout << modX<<modY<<modZ<<endl;

            if (modX == 1 && (modY+modZ)%4==0){
                rotsY[k] += dr;
                rotsZ[k] -= dr;
            }
            else if (modX == 1 && (modY+modZ)%4==2){
                rotsY[k] -= dr;
                rotsZ[k] += dr;
            }
            else if (modX == 3 && (modY+modZ)%4==0){
                rotsY[k] -= dr;
                rotsZ[k] += dr;
            }
            else if (modX == 3 && (modY+modZ)%4==2){
                rotsY[k] += dr;
                rotsZ[k] -= dr;
            }

            else if (modX == 0 && (4+modY-modZ)%4==1){
                rotsY[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modX == 0 && (4+modY-modZ)%4==3){
                rotsY[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modX == 2 && (4+modY-modZ)%4==1){
                rotsY[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modX == 2 && (4+modY-modZ)%4==3){
                rotsY[k] -= dr;
                rotsZ[k] -= dr;
            }
        }

        else{
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);
        
        cubinhos[k].cx =  cos(rx)*larg;
        cubinhos[k].cy =  cos(ry)*larg;
        cubinhos[k].cz =  cos(rz)*larg;
    }

    for (int i = 0; i < 9; i++){
        if (cor == 'o'){
            k = (i/3)*9+(i%3)+6; // lado laranja
            k = mapa2[k];
            aumentaX(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,-dr);
        }
        else if (cor == 'r'){
            k = (i/3)*9+(i%3); // lado vermelho
            k = mapa2[k];
            aumentaX(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,+dr);
        }
    }

    return;
}


void Cubo::ladoYHorario(float dr, char cor){
    int k;
    float larg, rx, ry, rz;
    int mods;
    int modX, modY, modZ;
    
    // for (int i = 0; i < 27; i++){
    for (int i = 0; i < 9; i++){
        if (cor == 'b'){        
            k = i*3+2; // lado azul
        }
        else if (cor == 'g'){
            k = i*3; // lado verde
        }
        // k=i;
        k = mapa2[k];

        if (k==j){
            cout << "rotX=" << (360+(int(rotsX[k])%360))%360<<endl;
            cout << "rotY=" << (360+(int(rotsY[k])%360))%360<<endl;
            cout << "rotZ=" << (360+(int(rotsZ[k])%360))%360<<endl<<endl;
        }
        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 || k == 9 || k == 11 || k == 15 || k == 17){
            larg = largAresta;

            modX = (360+(int(rotsX[k])%360))%360 / 90;
            modY = (360+(int(rotsY[k])%360))%360 / 90;
            modZ = (360+(int(rotsZ[k])%360))%360 / 90;

            if (k==j)
                cout << modX<<modY<<modZ<<endl;

            if (modY == 0 && (4+modX-modZ)%4==1){
                rotsX[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modY == 0 && (4+modX-modZ)%4==3){
                rotsX[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 2 && (4+modX-modZ)%4==1){
                rotsX[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 2 && (4+modX-modZ)%4==3){
                rotsX[k] += dr;
                rotsZ[k] += dr;
            }
        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26){
            larg = sqrt(largAresta*2);

            modX = (360+(int(rotsX[k])%360))%360 / 90;
            modY = (360+(int(rotsY[k])%360))%360 / 90;
            modZ = (360+(int(rotsZ[k])%360))%360 / 90;
            if (k==j)
                cout << modX<<modY<<modZ<<endl;

            if (modY == 1 && (modX+modZ)%4==0){
                rotsX[k] -= dr;
                rotsZ[k] += dr;
            }
            else if (modY == 1 && (modX+modZ)%4==2){
                rotsX[k] += dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 3 && (modX+modZ)%4==0){
                rotsX[k] += dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 3 && (modX+modZ)%4==2){
                rotsX[k] -= dr;
                rotsZ[k] += dr;
            }

            else if (modY == 0 && (4+modX-modZ)%4==1){
                rotsX[k] += dr;
                rotsZ[k] += dr;
            }
            else if (modY == 0 && (4+modX-modZ)%4==3){
                rotsX[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 2 && (4+modX-modZ)%4==1){
                rotsX[k] -= dr;
                rotsZ[k] -= dr;
            }
            else if (modY == 2 && (4+modX-modZ)%4==3){
                rotsX[k] += dr;
                rotsZ[k] += dr;
            }
        }
        else{
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);
        
        cubinhos[k].cx =  cos(rx)*larg;
        cubinhos[k].cy =  cos(ry)*larg;
        cubinhos[k].cz =  cos(rz)*larg;

    }

    for (int i = 0; i < 9; i++){
        if (cor == 'b'){        
            k = i*3+2; // lado azul
            k = mapa2[k];
            aumentaY(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,+dr);
        }
        else if (cor == 'g'){
            k = i*3; // lado verde
            k = mapa2[k];
            aumentaY(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,-dr);
        }
    }


    return;
}



void Cubo::ladoZHorario(float dr, char cor){
    float larg;
    float rx, ry, rz;

    int k;
    int modX, modY, modZ;
    int mods;

    // for (int i = 0; i < 27; i++){
    for (int i = 0; i < 9; i++){
        if (cor == 'y'){        
            k = i+18; // lado amarelo
        }
        else if (cor == 'w'){
            k = i; // lado branco
        }
        // k=i;
        k = mapa2[k];

        if (i==j){
            cout << "rotX=" << (360+(int(rotsX[k])%360))%360<<endl;
            cout << "rotY=" << (360+(int(rotsY[k])%360))%360<<endl;
            cout << "rotZ=" << (360+(int(rotsZ[k])%360))%360<<endl<<endl;
        }

        modX = (360+(int(rotsX[k])%360))%360 / 90;
        modY = (360+(int(rotsY[k])%360))%360 / 90;
        modZ = (360+(int(rotsZ[k])%360))%360 / 90;

        if (i==j)
            cout << modX<<modY<<modZ<<endl;

        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 19 || k == 21 || k == 23 || k == 25 || k == 9 || k == 11 || k == 15 || k == 17){
            larg = largAresta;

            if (modZ == 0 && (4+modX-modY)%4==1){
                rotsX[k] -= dr;
                rotsY[k] -= dr;
            }
            else if (modZ == 0 && (4+modX-modY)%4==3){
                rotsX[k] += dr;
                rotsY[k] += dr;
            }
            else if (modZ == 2 && (4+modX-modY)%4==1){
                rotsX[k] += dr;
                rotsY[k] += dr;
            }
            else if (modZ == 2 && (4+modX-modY)%4==3){
                rotsX[k] -= dr;
                rotsY[k] -= dr;
            }

        }

        else if (k == 0 || k == 2 || k == 6 || k == 8 || k == 18 || k == 20 || k == 24 || k == 26){
        
            larg = sqrt(largAresta*2);

            
            if (modZ == 1 && (modX+modY)%4==0){
                rotsX[k] += dr;
                rotsY[k] -= dr;
            }
            else if (modZ == 1 && (modX+modY)%4==2){
                rotsX[k] -= dr;
                rotsY[k] += dr;
            }
            else if (modZ == 3 && (modX+modY)%4==0){
                rotsX[k] -= dr;
                rotsY[k] += dr;
            }
            else if (modZ == 3 && (modX+modY)%4==2){
                rotsX[k] += dr;
                rotsY[k] -= dr;
            }

            else if (modZ == 0 && (4+modX-modY)%4==1){
                rotsX[k] -= dr;
                rotsY[k] -= dr;
            }
            else if (modZ == 0 && (4+modX-modY)%4==3){
                rotsX[k] += dr;
                rotsY[k] += dr;
            }
            else if (modZ == 2 && (4+modX-modY)%4==1){
                rotsX[k] += dr;
                rotsY[k] += dr;
            }
            else if (modZ == 2 && (4+modX-modY)%4==3){
                rotsX[k] -= dr;
                rotsY[k] -= dr;
            }
        }

        else{
            continue;
        }

        rx = grau2rad(rotsX[k]);
        ry = grau2rad(rotsY[k]);
        rz = grau2rad(rotsZ[k]);
        
        cubinhos[k].cx =  cos(rx)*larg;
        cubinhos[k].cy =  cos(ry)*larg;
        cubinhos[k].cz =  cos(rz)*larg;
        
    }
    cout << endl;
    for (int i = 0; i < 9; i++){
        if (cor == 'y'){        
            k = i+18; // lado amarelo
            k = mapa2[k];
            aumentaZ(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,-dr);
        }
        else if (cor == 'w'){
            k = i; // lado branco
            k = mapa2[k];
            aumentaZ(cubinhos[k].rotX,cubinhos[k].rotY,cubinhos[k].rotZ,+dr);
        }
    }

    k=mapa2[0];
    modX = (360+(int(rotsX[k])%360))%360 / 90;
    modY = (360+(int(rotsY[k])%360))%360 / 90;
    modZ = (360+(int(rotsZ[k])%360))%360 / 90;

    mods=modX*100+modY*10+modZ;
    if (mods!=111&&mods!=212&&mods!=221&&mods!=122){
        rearranjaMapa('w');
        rearranjaMapa('y');
    }

    return;
}







void giraLaranjaHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoXHorario(DR, 'o');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraLaranjaHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('o');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraLaranjaAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoXHorario(-DR, 'o');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraLaranjaAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('O');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::laranjaHorario(){
    if (!flagRot){
        flagRot = true;
        giraLaranjaHorario(id_);
    }
}

void Cubo::laranjaAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraLaranjaAntiHorario(id_);
    }
}










void giraVermelhoHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoXHorario(DR, 'r');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraVermelhoHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('r');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraVermelhoAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoXHorario(-DR, 'r');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraVermelhoAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('R');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::vermelhoHorario(){
    if (!flagRot){
        flagRot = true;
        giraVermelhoHorario(id_);
    }
}

void Cubo::vermelhoAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraVermelhoAntiHorario(id_);
    }
}







void giraAzulHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoYHorario(DR, 'b');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraAzulHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('b');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraAzulAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoYHorario(-DR, 'b');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraAzulAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('B');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::azulHorario(){
    if (!flagRot){
        flagRot = true;
        giraAzulHorario(id_);
    }
}

void Cubo::azulAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraAzulAntiHorario(id_);
    }
}











void giraVerdeHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoYHorario(DR, 'g');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraVerdeHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('g');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraVerdeAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoYHorario(-DR, 'g');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraVerdeAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('G');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::verdeHorario(){
    if (!flagRot){
        flagRot = true;
        giraVerdeHorario(id_);
    }
}

void Cubo::verdeAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraVerdeAntiHorario(id_);
    }
}












void giraAmareloHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoZHorario(DR, 'y');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraAmareloHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('y');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraAmareloAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoZHorario(-DR, 'y');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraAmareloAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('Y');
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

void Cubo::amareloAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraAmareloAntiHorario(id_);
    }
}








void giraBrancoHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoZHorario(DR, 'w');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraBrancoHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('w');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void giraBrancoAntiHorario(int id){
    Cubo *cubo = pCubos[id];
    int k;
    cubo->rotTemp += DR;
    cubo->ladoZHorario(-DR, 'w');

    if (cubo->rotTemp < 90)
        glutTimerFunc(DELAY,giraBrancoAntiHorario,id);
    else{
        cubo->rotTemp = 0;
        cubo->rearranjaMapa('W');
        cubo->flagRot = false;
    }
    glutPostRedisplay();
}

void Cubo::brancoHorario(){
    if (!flagRot){
        flagRot = true;
        giraBrancoHorario(id_);
    }
}

void Cubo::brancoAntiHorario(){
    if (!flagRot){
        flagRot = true;
        giraBrancoAntiHorario(id_);
    }
}










void Cubo::printId(){
    cout << "id = " << id_ << endl;
}