#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "TetrisBloklari.hpp"
#include "OyunAlani.hpp"

using namespace sf;
using namespace std;

class BilgiAlani
{

public:

    void sifirliyazdir(int sayitut, Text& sayi);

    BilgiAlani(int xkoordinati,int ykoordinati, const OyunAlani& oyunalani);

    void panelikonumlandir(int xkoordinati, int ykoordinati);
    void bilgialaniciz(RenderWindow& window);

    void skorarttir(int silinensatirsayisi, float gecensure);
    void dusenbloklaskorarttir();
    void levelarttir();

    void skortemizle();
    void leveltemizle();

    void siradakiblokonizlemekutusuciz(RenderWindow& window, OyunAlani& oyunalani, int x, int y);
    void siradakiblokonizlemeciz(RenderWindow& window, const TetrisBloklari& sonrakiblok, const OyunAlani& oyunalani);

    int getpanelgenisligi() const;

    void setskoryazirengi(Color renk); 
    void setskoryazirengiback();  

private:
    static const int genislik = 7;
    static const int yukseklik = 20;

    static const int siradakiblokonizlemekutusugenisligi = 6;
    static const int siradakiblokonizlemekutusuyuksekligi = 6;

    int basamaksayisi = 8;
    int yaziboyutu = 45;
    int sayiboyutu = 55;

    int skortut;
    int leveltut;
    int rekortut;

    int panelgenisligi;

    RectangleShape bilgialanicerceve;
    RectangleShape siradakiblokonizlemekutusu;
    RectangleShape siradakiblokonizlemekutusucerceve;

    Font font;
    Text skoryazisi;
    Text skor;
    Text levelyazisi;
    Text level;
    Text rekoryazisi;
    Text rekor;
    
    Color panelrengi = Color(255,255,255,60);

    Color yazirengi = Color(45,35,50,150);

    Color yazidisrengi = Color(255,255,255,100);

    Color yazidisrenkyenile = yazidisrengi;
    
    Color rekoruastinrengi = Color(70,65,120,150);

    SoundBuffer levelartmabuffer;
    Sound levelartmasesi;

    SoundBuffer satirsilmebuffer;
    Sound satirsilmesesi;

    SoundBuffer blokdusmesesibuffer;
    Sound blokdusmesesi;

    SoundBuffer rekorugectinsesibuffer;
    Sound rekorugectinsesi;
};