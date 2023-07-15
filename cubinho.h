#pragma once

class Cubinho{
private:
    float cx, cy, cz;
    float rotX = 0;
    float rotY = 0;
    float rotZ = 0;
    float largAresta;
public:
    Cubinho(float _cx = 0.f, float _cy = 0.f, float _cz = 0.f, float _largAresta = 1.f){
        cx = _cx;
        cy = _cy;
        cz = _cz;
        largAresta = _largAresta;
    }
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

    void setRX(float _rotX){
        rotX = _rotX;
    }
    void setRY(float _rotY){
        rotY = _rotY;
    }
    void setRZ(float _rotZ){
        rotZ = _rotZ;
    }



    void displayCubinhoPolar();
    void displayCubinho();

};

