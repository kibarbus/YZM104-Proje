#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class OyunAlani
{

public:
    OyunAlani();

    int getbirimkareboyutu() const;
    int getsatirsayisi() const; 
    int getsutunsayisi() const;

    Color getgriddegeri(int sutun, int satir) const;
    
    Color getvarsayilangriddegeri() const;

    void oyunalaniolustur(RenderWindow& pencere, int baslangicdegerix, int baslangicdegeriy);

    void dusenbloksabitle(int blokxdegeri, int blokydegeri, int blokmatrisi[5][5], Color sabitlenecekblokrengi);

    vector <int> satirlarikontrolet();

    void satirsil(int silineceksatir);

    void satirefekt(int silineceksatir);

private:
    static const int BIRIMKAREBOYUTU = 37;
    static const int satir = 20;
    static const int sutun = 15;

    Color grid [satir][sutun]; //birim karelerin içinin değeri default olarak 0 atandı. sonrasinda boyayabilmek icin color olarak degistirildi.
    Color varsayilangridrengi = Color(55,45,60);
    
};
