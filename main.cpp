#include <SFML/Graphics.hpp>
#include "OyunAlani.hpp"
#include "TetrisBloklari.hpp"

using namespace sf;
using namespace std;

int main()
{
    OyunAlani oyunalani;
    TetrisBloklari siradakiblok;

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
    float blokdusmeminimumgecikmesuresi = 0.1f;

    int gecicimatris [5][5];


    while (window.isOpen())
    {
        float sonacilistangecenzaman = ekranacilissuresayaci.restart().asSeconds();//restart, pencerenin son acildigindan itibaren gecen sureyi tutar ve sifirlar, assecond ise saniye cinsinden tutar.
        dusurdongusuzamansayaci += sonacilistangecenzaman;

        Event olay;

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
                    siradakiblok.blokdondur();
                }
                if (olay.key.code == Keyboard::Left) 
                {
                    siradakiblok.solagit(oyunalani);
                }
                if (olay.key.code == Keyboard::Right) 
                {
                    siradakiblok.sagagit(oyunalani);
                }
                if (olay.key.code == Keyboard::Down) 
                {
                    siradakiblok.asagigit(oyunalani);
                }
            }
        }

        for(int u=0; u<5; u++)
        {
            for(int v=0; v<5; v++)
            {
                gecicimatris[u][v] = siradakiblok.getblokmatrisi(u,v);
            }
        }

        if (dusurdongusuzamansayaci >= blokdusmegecikmesuresi)//ekran acildiktan gecikme suresi kadar vakit gecicp gecmedigini kontrol eder.
        {
            if(!siradakiblok.blokdusur(oyunalani))
            {
                oyunalani.dusenbloksabitle(siradakiblok.getblokxdegeri(), siradakiblok.getblokydegeri(), gecicimatris, siradakiblok.getblokrengi());
                
                yeniBlokGerekiyor = true;

                oyunalani.satirlarikontrolet();
            }

            dusurdongusuzamansayaci = 0.0f;
        }

        window.clear(Color(45,35,50));//ekran temizlendi ve arka plan rengi ayarlandı.


        RectangleShape oyunalanidiscerceve(sf::Vector2f(oyunalanigenisligi + 6, oyunalaniyuksekligi + 6));
        oyunalanidiscerceve.setPosition(windowbaslangicdegerix - 3, windowbaslangicdegeriy - 3);
        oyunalanidiscerceve.setFillColor(sf::Color::Transparent);
        oyunalanidiscerceve.setOutlineThickness(10.0f);
        oyunalanidiscerceve.setOutlineColor(sf::Color(90, 80, 100)); 
        window.draw(oyunalanidiscerceve);//birim karelerin etrafına çerçeve çizildi.


        oyunalani.oyunalaniolustur(window, windowbaslangicdegerix, windowbaslangicdegeriy);

        if (yeniBlokGerekiyor) 
        {
            if (blokdusmegecikmesuresi > blokdusmeminimumgecikmesuresi) 
            {
                blokdusmegecikmesuresi -= blokdusmeminimumgecikmesuresi * 0.1f; //her  yeni blokta gecikme azaltildi, bloklar gittikce hizlanacak
            }
            siradakiblok.blokolustur(rand() % 14); 
            yeniBlokGerekiyor = false; 
        }
        
        siradakiblok.blokciz(window, windowbaslangicdegerix, windowbaslangicdegeriy, oyunalani);

        window.display();

    }
    return 0;
}