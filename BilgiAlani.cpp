#include "BilgiAlani.hpp"

using namespace sf;
using namespace std;


BilgiAlani::BilgiAlani(int xkoordinati,int ykoordinati, const OyunAlani& oyunalani)
{
    int birimkareboyutu = oyunalani.getbirimkareboyutu();

    panelgenisligi = genislik * birimkareboyutu;

    bilgialanicerceve.setSize(Vector2f(genislik*birimkareboyutu, yukseklik*birimkareboyutu));
    bilgialanicerceve.setPosition(xkoordinati, ykoordinati);
    bilgialanicerceve.setFillColor(panelrengi);
    leveltut = 1;
    skortut = 0;

    if(!font.loadFromFile("Vonique64BoldItalic.ttf"))
    {
        cout<<"Font tipi yuklenemedi."<<endl;
    }

    skor.setFont(font);
    skor.setCharacterSize(30);
    skor.setString("SKOR: 000000");
    skor.setPosition(xkoordinati+40,ykoordinati+150);
    skor.setFillColor(Color::White);

    level.setFont(font);
    level.setCharacterSize(30);
    level.setString("LEVEL: 01");
    level.setPosition(xkoordinati+40,ykoordinati+70);
    level.setFillColor(Color::White);
}

void BilgiAlani::panelikonumlandir(int xkoordinati, int ykoordinati)
{
    bilgialanicerceve.setPosition(xkoordinati, ykoordinati);
    skor.setPosition(xkoordinati+40,ykoordinati+150);
    level.setPosition(xkoordinati+41,ykoordinati+70);
}

void BilgiAlani::bilgialaniciz(RenderWindow& window)
{
    window.draw(bilgialanicerceve);
    window.draw(skor);
    window.draw(level);
}

void BilgiAlani::skorarttir(int silinensatirsayisi, float gecensure)
{

    float minimumskorarttir = 50.0f;

    float skorarttir;

    if(gecensure<30 && gecensure>0)
    {
        gecensure = gecensure / 60;
        skorarttir = minimumskorarttir * (1.0f / gecensure)/2.0f;
    }
    else
    {
        skorarttir = minimumskorarttir;
    }

    skortut += (int)(skorarttir * silinensatirsayisi * silinensatirsayisi * silinensatirsayisi);
    
    skor.setString("Skor: " + to_string(skortut));
}

void BilgiAlani::dusenbloklaskorarttir()
{
    skortut += 10;
    skor.setString("Skor: " + to_string(skortut));
}

void BilgiAlani::levelarttir()
{
    if(skortut>leveltut*1000)
    {
        leveltut++;
        level.setString("Level: " + to_string(leveltut));
    }
}

void BilgiAlani::siradakiblokonizlemesiciz(RenderWindow& window, const TetrisBloklari& sonrakiblok)
{
    
}

int BilgiAlani::getpanelgenisligi() const
{
    return panelgenisligi;
}
