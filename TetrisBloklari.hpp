#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class TetrisBloklari
{
public:
    TetrisBloklari();

    void blokolustur(int bloknumarasi);
    void blokciz(RenderWindow& pencere, int windowbaslangicdegerix, int windowbaslangicdegeriy);
    void sagagit();
    void solagit();
    void blokdondur();
    void blokdusur();

    int getblokmatrisi(int i, int j) const;
    int getblokxdegeri() const;
    int getblokydegeri() const;
    Color getblokrengi() const;


private:
    int blokmatrisi[5][5]; //bloklarin seklini tutacak matris olusturuldu.
    int bloknumarasi;
    int blokxdegeri,blokydegeri;
    Color blokrengi;


};