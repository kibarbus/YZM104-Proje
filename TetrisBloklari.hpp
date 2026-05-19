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

    void blokolustur(int bloknumarasi, const OyunAlani& oyunalani);
    void hayaletblokolustur(int bloknumarasi, const OyunAlani& oyunalani);
    void blokciz(RenderWindow& pencere, int windowbaslangicdegerix, int windowbaslangicdegeriy, const OyunAlani& oyunalani);
    void hayaletblokciz(RenderWindow& pencere, int windowbaslangicdegerix, int windowbaslangicdegeriy, const OyunAlani& oyunalani);
    void sagagit(const OyunAlani& oyunalani);
    void solagit(const OyunAlani& oyunalani);
    void asagigit(const OyunAlani& oyunalani);
    void blokdondur(const OyunAlani& oyunalani);

    bool blokdusur(const OyunAlani& oyunalani);

    bool bisonrakikarebosmu(int siradakix, int siradakiy, int matris[4][4], const OyunAlani& oyunalani);

    bool oyunbittimi(int oyunbittimix, int oyunbittimiy, int matris[4][4], const OyunAlani& oyunalani);

    int getblokmatrisi(int i, int j) const;
    int getblokxdegeri() const;
    int getblokydegeri() const;
    Color getblokrengi() const;


private:
    int blokmatrisi[4][4]; //bloklarin seklini tutacak matris olusturuldu.
    int hayaletblokmatrisi[4][4];
    int bloknumarasi;
    int hayaletbloknumarasi;
    int blokxdegeri,blokydegeri;
    Color blokrengi;


};