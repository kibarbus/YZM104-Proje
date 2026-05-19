#include <SFML/Graphics.hpp>
#include "OyunAlani.hpp"
#include "TetrisBloklari.hpp"
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;


void ekraniguncelle(RenderWindow& window, OyunAlani& oyunalani, RectangleShape& oyunalanidiscerceve  ,int windowbaslangicdegerix, int windowbaslangicdegeriy)
{
    window.clear(Color(45,35,50));
    window.draw(oyunalanidiscerceve);
    oyunalani.oyunalaniolustur(window, windowbaslangicdegerix,windowbaslangicdegeriy);
}

int main()
{
    OyunAlani oyunalani;
    TetrisBloklari siradakiblok;
    TetrisBloklari hayaletblok;

    VideoMode kullaniciEkranBoyutu = VideoMode::getDesktopMode();//kullanıcının ekran boyutu alındı.

    RenderWindow window(kullaniciEkranBoyutu, "Tetris", Style::Fullscreen);//oyun default olarak tam ekran başlamaya ayarlandı.

    int bilgipaneligenisligi = 200;

    int oyunalanigenisligi = oyunalani.getsutunsayisi() * oyunalani.getbirimkareboyutu();
    int oyunalaniyuksekligi = oyunalani.getsatirsayisi() * oyunalani.getbirimkareboyutu();

    int anapenceregenisligi = oyunalanigenisligi + bilgipaneligenisligi;
    int anapencereyuksekligi = oyunalaniyuksekligi;

    int windowbaslangicdegerix = (window.getSize().x - anapenceregenisligi) / 2;
    int windowbaslangicdegeriy = (window.getSize().y - anapencereyuksekligi) / 2;//kullanıcının ekran boyutu alınarak oyun alanının koordinatları hesaplandı.

    bool yeniBlokGerekiyor = true;

    Clock ekranacilissuresayaci;
    float dusurdongusuzamansayaci = 0.0f;
    float blokdusmegecikmesuresi = 0.9f;
    float blokdusmeminimumgecikmesuresi = 0.2f;

    int gecicimatris [4][4];


    while (window.isOpen())
    {
        
        int yenibloknumara;

        float sonacilistangecenzaman = ekranacilissuresayaci.restart().asSeconds();//restart, pencerenin son acildigindan itibaren gecen sureyi tutar ve sifirlar, assecond ise saniye cinsinden tutar.
        dusurdongusuzamansayaci += sonacilistangecenzaman;

        Event olay;


        RectangleShape oyunalanidiscerceve(sf::Vector2f(oyunalanigenisligi + 6, oyunalaniyuksekligi + 6));
        oyunalanidiscerceve.setPosition(windowbaslangicdegerix - 3, windowbaslangicdegeriy - 3);
        oyunalanidiscerceve.setFillColor(sf::Color::Transparent);
        oyunalanidiscerceve.setOutlineThickness(10.0f);
        oyunalanidiscerceve.setOutlineColor(sf::Color(90, 80, 100)); 

        while (window.pollEvent(olay))
        {
            if (olay.type == Event::Closed)
            {
                    window.close();
            }
            if (olay.type == Event::KeyPressed) 
            {
                if (olay.key.code == Keyboard::Escape) //oyunu kapatmak için esc tuşu kısayol olarak ayarlandı.
                {
                    window.close();
                }
            }
            if (olay.type == Event::KeyPressed) 
            {
                if (olay.key.code == Keyboard::Up) 
                {
                    siradakiblok.blokdondur(oyunalani);
                    hayaletblok.blokdondur(oyunalani);
                }
                if (olay.key.code == Keyboard::Left) 
                {
                    siradakiblok.solagit(oyunalani);
                    hayaletblok.solagit(oyunalani);
                }
                if (olay.key.code == Keyboard::Right) 
                {
                    siradakiblok.sagagit(oyunalani);
                    siradakiblok.sagagit(oyunalani);
                }
                if (olay.key.code == Keyboard::Down) 
                {
                    siradakiblok.asagigit(oyunalani);
                }
                if (olay.key.code == Keyboard::Space) 
                {
                    while(siradakiblok.blokdusur(oyunalani))
                    {
                        
                    }
                }
            }
        }

        for(int u=0; u<4; u++)
        {
            for(int v=0; v<4; v++)
            {
                gecicimatris[u][v] = siradakiblok.getblokmatrisi(u,v);
            }
        }

        if (dusurdongusuzamansayaci >= blokdusmegecikmesuresi)//ekran acildiktan gecikme suresi kadar vakit gecicp gecmedigini kontrol eder.
        {

            dusurdongusuzamansayaci = 0.0f;
            
            if(!siradakiblok.blokdusur(oyunalani))
            {
                oyunalani.dusenbloksabitle(siradakiblok.getblokxdegeri(), siradakiblok.getblokydegeri(), gecicimatris, siradakiblok.getblokrengi());
                
                vector <int> silineceksatirlar = oyunalani.satirlarikontrolet();
                if(!silineceksatirlar.empty())
                {
                    Clock efektsuresi;
                    for(int m=0; m<silineceksatirlar.size(); m++)
                    {
                        int efektekleneceksatiritut = silineceksatirlar[m];
                        oyunalani.satirefekt(efektekleneceksatiritut);
                    }
                    
                    while(efektsuresi.getElapsedTime().asMilliseconds() < 600)//satir silinmeden once efekt icin bekleme suresi ayarlandi.
                    {
                        ekraniguncelle(window, oyunalani, oyunalanidiscerceve, windowbaslangicdegerix, windowbaslangicdegeriy); //satir silinmeden once efektin gorunmesi icin ekran guncellendi.
                        window.display();
                    }

                    for(int u=silineceksatirlar.size()-1; u>=0 ; u--)//asagidan yukari dogru alinan indeksleri yukaridan asagiya dogru siliyor cunku once alttakini silse usttekinin indeksi degisirdi.
                    {
                        int silineceksatiritut=silineceksatirlar[u];
                        oyunalani.satirsil(silineceksatiritut);
                    }

                }

                if (siradakiblok.oyunbittimi(siradakiblok.getblokxdegeri(), siradakiblok.getblokydegeri(), gecicimatris, oyunalani))
                {
                    window.close();
                }

                yeniBlokGerekiyor = true;
            }

        }

        ekraniguncelle(window, oyunalani, oyunalanidiscerceve, windowbaslangicdegerix, windowbaslangicdegeriy);

        if (yeniBlokGerekiyor) 
        {
            if (blokdusmegecikmesuresi > blokdusmeminimumgecikmesuresi) 
            {
                blokdusmegecikmesuresi -= blokdusmeminimumgecikmesuresi * 0.05f; //her  yeni blokta gecikme azaltildi, bloklar gittikce hizlanacak
            }

            yenibloknumara = rand() % 6;

            siradakiblok.blokolustur(yenibloknumara, oyunalani); //7 bloktan biri rastgele olusturuldu

            yeniBlokGerekiyor = false; 
        }

        hayaletblok = siradakiblok;

        hayaletblok.hayaletblokolustur(yenibloknumara, oyunalani);
        
        siradakiblok.blokciz(window, windowbaslangicdegerix, windowbaslangicdegeriy, oyunalani);
        hayaletblok.hayaletblokciz(window, windowbaslangicdegerix, windowbaslangicdegeriy, oyunalani);

        window.display();

    }
    return 0;
}