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

    if(!font.loadFromFile("Blocktopia.ttf"))
    {
        cout<<"Font tipi yuklenemedi."<<endl;
    }

    ifstream rekoroku("RekorListesi.txt");
    if(!rekoroku)
    {
        rekortut=0;
    }
    else
    {
        rekoroku >> rekortut;
    }
    rekoroku.close();

    string sifirlirekor = to_string(rekortut);

    while(sifirlirekor.length() < basamaksayisi)
    {
        sifirlirekor = "0" + sifirlirekor;
    }

    rekor.setString(sifirlirekor);

    rekoryazisi.setFont(font);
    rekoryazisi.setCharacterSize(yaziboyutu);
    rekoryazisi.setString("REKOR");
    rekoryazisi.setFillColor(yazirengi);
    rekoryazisi.setOutlineThickness(-2.0f);
    rekoryazisi.setOutlineColor(yazidisrengi);

    rekor.setFont(font);
    rekor.setCharacterSize(sayiboyutu);
    rekor.setString(sifirlirekor);
    rekor.setFillColor(yazirengi);
    rekor.setOutlineThickness(-2.0f);
    rekor.setOutlineColor(yazidisrengi);

    levelyazisi.setFont(font);
    levelyazisi.setCharacterSize(yaziboyutu);
    levelyazisi.setString("LEVEL");
    levelyazisi.setFillColor(yazirengi);
    levelyazisi.setOutlineThickness(-2.0f);
    levelyazisi.setOutlineColor(yazidisrengi);

    level.setFont(font);
    level.setCharacterSize(sayiboyutu);
    level.setString("01");
    level.setFillColor(yazirengi);
    level.setOutlineThickness(-2.0f);
    level.setOutlineColor(yazidisrengi);

    skoryazisi.setFont(font);
    skoryazisi.setCharacterSize(yaziboyutu);
    skoryazisi.setString("SKOR");
    skoryazisi.setFillColor(yazirengi);
    skoryazisi.setOutlineThickness(-2.0f);
    skoryazisi.setOutlineColor(yazidisrengi);

    skor.setFont(font);
    skor.setCharacterSize(sayiboyutu);
    skor.setString("00000000");
    skor.setFillColor(yazirengi);
    skor.setOutlineThickness(-2.0f);
    skor.setOutlineColor(yazidisrengi);
}

void BilgiAlani::panelikonumlandir(int xkoordinati, int ykoordinati)
{
    bilgialanicerceve.setPosition(xkoordinati, ykoordinati);
    rekoryazisi.setPosition(xkoordinati+20,ykoordinati+20);
    rekor.setPosition(xkoordinati+20,ykoordinati+60);
    levelyazisi.setPosition(xkoordinati+20,ykoordinati+110);
    level.setPosition(xkoordinati+20,ykoordinati+150);
    skoryazisi.setPosition(xkoordinati+20,ykoordinati+200);
    skor.setPosition(xkoordinati+20,ykoordinati+240);
    siradakiblokonizlemekutusucerceve.setPosition(xkoordinati+16,ykoordinati+449);
    siradakiblokonizlemekutusu.setPosition(xkoordinati+17,ykoordinati+450);
}

void BilgiAlani::bilgialaniciz(RenderWindow& window)
{
    window.draw(bilgialanicerceve);
    window.draw(skoryazisi);
    window.draw(levelyazisi);
    window.draw(rekoryazisi);
    window.draw(skor);
    window.draw(level);
    window.draw(rekor);
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

    string sifirliskor = to_string(skortut);

    while(sifirliskor.length() < basamaksayisi)
    {
        sifirliskor = "0" + sifirliskor;
    }
    
    skor.setString(sifirliskor);
    levelarttir();

    ifstream rekoroku("RekorListesi.txt");
    if(!rekoroku)
    {
        ofstream ilkrekoruyaz("RekorListesi.txt");
        if(!ilkrekoruyaz)
        {
            cout<<"Dosya acilamadi"<<endl;
        }
        else
        {
            ilkrekoruyaz << skortut;
            ilkrekoruyaz.close();
        }
    }
    else
    {
        rekoroku >> rekortut;

        if(rekortut < skortut)
        {
            rekoroku.close();
            ofstream rekoryaz("RekorListesi.txt");
            rekoryaz << skortut;
            rekoryaz.close();
            rekortut = skortut;
        }
        else
        {
            rekoroku.close();
        }
    }

    string sifirlirekor = to_string(rekortut);

    while(sifirlirekor.length() < basamaksayisi)
    {
        sifirlirekor = "0" + sifirlirekor;
    }

    rekor.setString(sifirlirekor);
}

void BilgiAlani::dusenbloklaskorarttir()
{
    skortut += 10;
    
    string sifirliskor = to_string(skortut);

    while(sifirliskor.length() < basamaksayisi)
    {
        sifirliskor = "0" + sifirliskor;
    }
    
    skor.setString(sifirliskor);

    ifstream rekoroku("RekorListesi.txt");
    if(!rekoroku)
    {
        ofstream ilkrekoruyaz("RekorListesi.txt");
        if(!ilkrekoruyaz)
        {
            cout<<"Dosya acilamadi"<<endl;
        }
        else
        {
            ilkrekoruyaz << skortut;
            ilkrekoruyaz.close();
        }
    }
    else
    {
        rekoroku >> rekortut;

        if(rekortut < skortut)
        {
            rekoroku.close();
            ofstream rekoryaz("RekorListesi.txt");
            rekoryaz << skortut;
            rekoryaz.close();
            rekortut = skortut;
        }
        else
        {
            rekoroku.close();
        }
    }

    string sifirlirekor = to_string(rekortut);

    while(sifirlirekor.length() < basamaksayisi)
    {
        sifirlirekor = "0" + sifirlirekor;
    }

    rekor.setString(sifirlirekor);
}

void BilgiAlani::levelarttir()
{

    if(skortut>leveltut*500)
    {
        leveltut++;

        string sifirlilevel = to_string(leveltut);
    
        while(sifirlilevel.length() < 2)
        {
            sifirlilevel = "0" + sifirlilevel;
        } 

        level.setString(sifirlilevel);
    }

}

void BilgiAlani::siradakiblokonizlemekutusuciz(RenderWindow& window, OyunAlani& oyunalani, int x, int y)
{
    int birimkareboyutu = oyunalani.getbirimkareboyutu();

    RectangleShape siradakiblokonizlemekutusucerceve(Vector2f(siradakiblokonizlemekutusugenisligi*birimkareboyutu+2, siradakiblokonizlemekutusuyuksekligi*birimkareboyutu+2));
    siradakiblokonizlemekutusucerceve.setPosition(x+16,y+449);
    siradakiblokonizlemekutusucerceve.setFillColor(Color::Transparent);
    siradakiblokonizlemekutusucerceve.setOutlineThickness(-2.0f);
    siradakiblokonizlemekutusucerceve.setOutlineColor(Color(45,35,50,150));
    

    RectangleShape siradakiblokonizlemekutusu(Vector2f(siradakiblokonizlemekutusugenisligi*birimkareboyutu, siradakiblokonizlemekutusuyuksekligi*birimkareboyutu));
    siradakiblokonizlemekutusu.setPosition(x+17,y+450);
    siradakiblokonizlemekutusu.setFillColor(Color(oyunalani.getvarsayilangriddegeri()));
    siradakiblokonizlemekutusu.setOutlineThickness(-3.0f);
    siradakiblokonizlemekutusu.setOutlineColor(Color(255, 255, 255, 20));
    
    window.draw(siradakiblokonizlemekutusu);
    window.draw(siradakiblokonizlemekutusucerceve);
}

void BilgiAlani::siradakiblokonizlemeciz(RenderWindow& window, const TetrisBloklari& sonrakiblok, const OyunAlani& oyunalani)
{
    int birimkareboyutu = oyunalani.getbirimkareboyutu();

    RectangleShape sonrakiblokonizleme(Vector2f(birimkareboyutu-2,birimkareboyutu-2));

    Color sonrakiblokonizlemerengi = sonrakiblok.getblokrengi();
    sonrakiblokonizlemerengi.a = 220;
    sonrakiblokonizleme.setFillColor(sonrakiblokonizlemerengi/*  + Color(255,255,255,1) */);

    int sagx = 4;
    int solx = -1;
    int usty = -1;
    int alty = 4;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if(sonrakiblok.getblokmatrisi(i, j) == 1)
            {
                if(sagx>j) sagx=j;
                if(solx<j) solx=j;
                if(usty<i) usty=i;
                if(alty>i) alty=i;
            }
        }
    }

    float tamblokeni = (sagx - solx+1)*birimkareboyutu;
    float tamblokboyu = (alty - usty+1)*birimkareboyutu; //aralarindaki farki bulup 1 ekledigimiz icin +1 yaptik.
    
    int baslangicdegerix = siradakiblokonizlemekutusu.getPosition().x + (siradakiblokonizlemekutusugenisligi*birimkareboyutu/2) - (tamblokeni/2) - (solx*birimkareboyutu);
    int baslangicdegeriy = siradakiblokonizlemekutusu.getPosition().y + (siradakiblokonizlemekutusuyuksekligi*birimkareboyutu/2) - (tamblokboyu/2) - (usty*birimkareboyutu);

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(sonrakiblok.getblokmatrisi(i,j) == 1)
            {
                int x = baslangicdegerix + j * birimkareboyutu;
                int y = baslangicdegeriy + i * birimkareboyutu;

                sonrakiblokonizleme.setPosition(x, y);
                sonrakiblokonizleme.setOutlineThickness(-2.0f);
                sonrakiblokonizleme.setOutlineColor(Color(255, 255, 255, 40));
                window.draw(sonrakiblokonizleme);
            }
        }
    }

}

int BilgiAlani::getpanelgenisligi() const
{
    return panelgenisligi;
}
