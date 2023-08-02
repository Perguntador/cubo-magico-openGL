#pragma once

class Cubinho {
  private:
    float cx, cy, cz;
    float rotTheta = 0;
    float rotPhi = 0;
    float rotGamma = 0;
    float largAresta;

  public:
    Cubinho(float _cx = 0.f, float _cy = 0.f, float _cz = 0.f, float _largAresta = 1.f) {
        cx = _cx;
        cy = _cy;
        cz = _cz;
        largAresta = _largAresta;
    }

    void setAresta(float _largAresta) { largAresta = _largAresta; }
    void setCX(float _cx) { cx = _cx; }
    void setCY(float _cy) { cy = _cy; }
    void setCZ(float _cz) { cz = _cz; }

    void setCentro(float _cx, float _cy, float _cz) {
        cx = _cx;
        cy = _cy;
        cz = _cz;
    }

    void setTheta(float _rotTheta) { rotTheta = _rotTheta; }
    void setPhi(float _rotPhi) { rotPhi = _rotPhi; }
    void setGamma(float _rotGamma) { rotGamma = _rotGamma; }

    void displayCubinho();

    char corX();
    char corY();
    char corZ();
    char corXn();
    char corYn();
    char corZn();

    friend class Cubo;
};
