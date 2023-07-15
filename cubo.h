#pragma once
#include "cubinho.h"

class Cubo{
private:
    float cx, cy, cz;
    Cubinho cubinhos[27];
    int mapa2[27];
    bool mapa[27];
    bool flagRot = false;
    float largAresta;
    float rotTemp = 0;
    int id_;
    static int proxId_;
public:
    Cubo (float _cx, float _cy, float _cz, float _largAresta);

    void tecla1();
    void tecla2();
    void tecla3();
    void tecla4();
    void tecla5();
    void tecla6();
    void tecla7();

    void verdeHorario();
    void azulHorario();
    void vermelhoHorario();
    void laranjaHorario();
    void amareloHorario();
    void brancoHorario();
    
    void verdeAntiHorario();
    void azulAntiHorario();
    void vermelhoAntiHorario();
    void laranjaAntiHorario();
    void amareloAntiHorario();
    void brancoAntiHorario();
    

    friend void giraVerdeHorario(int id);
    friend void giraAzulHorario(int id);
    friend void giraVermelhoHorario(int id);
    friend void giraLaranjaHorario(int id);
    friend void giraAmareloHorario(int id);
    friend void giraBrancoHorario(int id);

    friend void giraVerdeAntiHorario(int id);
    friend void giraAzulAntiHorario(int id);
    friend void giraVermelhoAntiHorario(int id);
    friend void giraLaranjaAntiHorario(int id);
    friend void giraAmareloAntiHorario(int id);
    friend void giraBrancoAntiHorario(int id);


    void printId();

    void displayCubo();
    

};

