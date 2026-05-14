#include <SFML/Graphics.hpp>
#include "OyunAlani.hpp"
using namespace sf;
using namespace std;

int main()
{
    OyunAlani oyunalani;

    VideoMode kullaniciEkranBoyutu = VideoMode::getDesktopMode();//kullanıcının ekran boyutu alındı.

    RenderWindow window(kullaniciEkranBoyutu, "Tetris", Style::Fullscreen);//oyun default olarak tam ekran başlamaya ayarlandı.

    int bilgipaneligenisligi = 200;

    int oyunalanigenisligi = oyunalani.getsutunsayisi() * oyunalani.getbirimkareboyutu();
    int oyunalaniyuksekligi = oyunalani.getsatirsayisi() * oyunalani.getbirimkareboyutu();

    int anapenceregenisligi = oyunalanigenisligi + bilgipaneligenisligi;
    int anapencereyuksekligi = oyunalaniyuksekligi;

    int windowbaslangicdegerix = (window.getSize().x - anapenceregenisligi) / 2;
    int windowbaslangicdegeriy = (window.getSize().y - anapencereyuksekligi) / 2;//kullanıcının ekran boyutu alınarak oyun alanının koordinatları hesaplandı.

    while (window.isOpen())
    {
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
        }

        window.clear(Color(45,35,50));//ekran temizlendi ve arka plan rengi ayarlandı.


        RectangleShape oyunalanidiscerceve(sf::Vector2f(oyunalanigenisligi + 6, oyunalaniyuksekligi + 6));
        oyunalanidiscerceve.setPosition(windowbaslangicdegerix - 3, windowbaslangicdegeriy - 3);
        oyunalanidiscerceve.setFillColor(sf::Color::Transparent);
        oyunalanidiscerceve.setOutlineThickness(10.0f);
        oyunalanidiscerceve.setOutlineColor(sf::Color(90, 80, 100)); 
        window.draw(oyunalanidiscerceve);//birim karelerin etrafına çerçeve çizildi.


        oyunalani.oyunalaniolustur(window, windowbaslangicdegerix, windowbaslangicdegeriy);

        window.display();

    }
    return 0;
}