#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "TetrisBloklari.hpp"
#include "OyunAlani.hpp"

using namespace sf;
using namespace std;

class BilgiAlani
{

public:

    BilgiAlani(int xkoordinati,int ykoordinati, const OyunAlani& oyunalani);

    void panelikonumlandir(int xkoordinati, int ykoordinati);
    void bilgialaniciz(RenderWindow& window);

    void skorarttir(int silinensatirsayisi, float gecensure);
    void dusenbloklaskorarttir();
    void levelarttir();

    void siradakiblokonizlemekutusuciz(RenderWindow& window, OyunAlani& oyunalani, int x, int y);
    void siradakiblokonizlemeciz(RenderWindow& window, const TetrisBloklari& sonrakiblok, const OyunAlani& oyunalani);

    int getpanelgenisligi() const;


private:
    static const int genislik = 7;
    static const int yukseklik = 20;

    static const int siradakiblokonizlemekutusugenisligi = 6;
    static const int siradakiblokonizlemekutusuyuksekligi = 6;


    int skortut;
    int leveltut;

    int panelgenisligi;

    RectangleShape bilgialanicerceve;
    RectangleShape siradakiblokonizlemekutusu;
    RectangleShape siradakiblokonizlemekutusucerceve;

    Font font;
    Text skoryazisi;
    Text skor;
    Text levelyazisi;
    Text level;

    Color panelrengi = Color(255,255,255,60);
};