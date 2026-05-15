#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class OyunAlani;

class TetrisBloklari
{
public:
    TetrisBloklari();

    void blokolustur(int bloknumarasi);
    void blokciz(RenderWindow& pencere, int windowbaslangicdegerix, int windowbaslangicdegeriy, const OyunAlani& oyunalani);
    void sagagit(const OyunAlani& oyunalani);
    void solagit(const OyunAlani& oyunalani);
    void asagigit(const OyunAlani& oyunalani);
    void blokdondur();

    bool blokdusur(const OyunAlani& oyunalani);

    bool bisonrakikarebosmu(int siradakix, int siradakiy, int matris[5][5], const OyunAlani& oyunalani);

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