#pragma once
#include "cubinho.h"

class Cubo {
  private:
    float cx, cy, cz;
    float rotsX[27];
    float rotsY[27];
    float rotsZ[27];
    Cubinho cubinhos[27];
    int mapa2[27];
    bool mapa[27];
    bool flagRot = false;
    float largAresta;
    float rotTemp = 0;
    int id_;
    static int proxId_;

    void ladoXHorario(float dr, char cor);
    void ladoYHorario(float dr, char cor);
    void ladoZHorario(float dr, char cor);

  public:
    Cubo(float _cx = 0.0f, float _cy = 0.0f, float _cz = 0.0f, float _largAresta = 1.0f);

    void displayCubo();

    void tecla1();
    void tecla2();
    void tecla3();
    void tecla4();
    void tecla5();
    void tecla6();
    void tecla7();
    void tecla8();
    void tecla9();
    void tecla0();
    void teclaPonto();

    void rearranjaMapa(char c);

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

    bool espera() { return flagRot; }

    void salvar();
    void carregar();

    void printId();
};
