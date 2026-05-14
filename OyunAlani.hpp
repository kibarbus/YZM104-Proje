#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class OyunAlani
{

public:
    OyunAlani();

    int getbirimkareboyutu() const;
    int getsatirsayisi() const; 
    int getsutunsayisi() const;

    void oyunalaniolustur(RenderWindow& pencere, int baslangicdegerix, int baslangicdegeriy);


private:
    static const int BIRIMKAREBOYUTU = 37;
    static const int satir = 20;
    static const int sutun = 15;

    int izgara [satir][sutun] = {0}; //birim karelerin içinin değeri default olarak 0 atandı.

};
