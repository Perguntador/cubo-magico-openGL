#pragma once

class Cubo{
private:
    float cx, cy, cz;
    float largAresta;
public:
    Cubo(float _cx = 0.f, float _cy = 0.f, float _cz = 0.f, float _largAresta = 1.f){
        cx = _cx;
        cy = _cy;
        cz = _cz;
        largAresta = _largAresta;
    }
    void displayCubo();
    void setCX(float _cx){
        cx = _cx;
    }
    void setCY(float _cy){
        cy = _cy;
    }
    void setCZ(float _cz){
        cz = _cz;
    }
    void setCentro(float _cx, float _cy, float _cz){
        cx = _cx;
        cy = _cy;
        cz = _cz;
    }

    void setAresta(float _largAresta){
        largAresta = _largAresta;
    }

};

