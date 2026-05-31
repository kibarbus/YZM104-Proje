#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "OyunAlani.hpp"
#include "TetrisBloklari.hpp"
#include "BilgiAlani.hpp"
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;

void yonergeciz(RenderWindow& window, OyunAlani& oyunalani, int windowbaslangicdegeriy)
{
    Font font;
    if(!font.loadFromFile("assets/presstart.ttf"))
    {
        cout<<"Yonerge font tipi yuklenemedi."<<endl;
    }

    Text yonergeler;
    yonergeler.setFont(font);
    yonergeler.setCharacterSize(10);
    yonergeler.setFillColor(Color(180,165,200,100));
    yonergeler.setPosition(5, 10);
    //ok isaretlerinin duzgun cikmasi icin L, birden fazla satir girebilmek icin R.
    yonergeler.setString(LR"(
KONTROLLER 


P/p: Duraklat/Devam et

R/r: Yeniden baslat

←: Sola ilerlet

→: Saga ilerlet

↓: Asagi ilerlet

↑: 90 derece dondur

Space: Blok dusur

ESC: Oyunu kapat

    )"
    );
    window.draw(yonergeler);
}

void oyunduraklatildi(RenderWindow& window, OyunAlani& oyunalani, BilgiAlani& bilgipaneli, int anapenceregenisligi, int anapencereyuksekligi, int windowbaslangicdegerix, int windowbaslangicdegeriy)
{
    RectangleShape oyunpauseekrani(Vector2f(anapenceregenisligi + 5.0f, anapencereyuksekligi + 5.0f));
    oyunpauseekrani.setPosition(windowbaslangicdegerix, windowbaslangicdegeriy);
    oyunpauseekrani.setFillColor(Color(0, 0, 0, 1));

    Font pausefontu;
    if(!pausefontu.loadFromFile("Blocktopia.ttf"))
    {
        cout<<"Pause font tipi yuklenemedi."<<endl;
    }

    Text pauseyazisi ("PAUSE", pausefontu, 80);
    pauseyazisi.setFillColor(Color(255, 255, 255, 100));
    pauseyazisi.setPosition(windowbaslangicdegerix + (anapenceregenisligi / 2) - (pauseyazisi.getLocalBounds().width / 2), windowbaslangicdegeriy + (anapencereyuksekligi / 2)-20);
    
    while(window.isOpen())
    {
        window.draw(oyunpauseekrani);
        window.draw(pauseyazisi);
        window.display();
        
        Event olay;
        while (window.pollEvent(olay))
        {
            if (olay.type == Event::KeyPressed)
            {
                if(olay.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                else if (olay.key.code == Keyboard::P)
                {
                    return;
                }
            }
        }
    }
}

void ekraniguncelle(RenderWindow& window, OyunAlani& oyunalani, RectangleShape& oyunalanidiscerceve ,int windowbaslangicdegerix, int windowbaslangicdegeriy)
{
    window.clear(Color(45,35,50));
    window.draw(oyunalanidiscerceve);
    oyunalani.oyunalaniolustur(window, windowbaslangicdegerix,windowbaslangicdegeriy);
}

void oyunbittiekrani(RenderWindow& window, OyunAlani& oyunalani, BilgiAlani& bilgipaneli, int anapenceregenisligi, int anapencereyuksekligi, int windowbaslangicdegerix, int windowbaslangicdegeriy)
{
    RectangleShape oyunbittiekrani(Vector2f(anapenceregenisligi + 5.0f, anapencereyuksekligi + 5.0f));
    oyunbittiekrani.setPosition(windowbaslangicdegerix, windowbaslangicdegeriy);
    oyunbittiekrani.setFillColor(Color(0, 0, 0, 1));

    Font gameoverfontu;
    if(!gameoverfontu.loadFromFile("Blocktopia.ttf"))
    {
        cout<<"Game over font tipi yuklenemedi."<<endl;
    }

    Text tebrikleryazisi ("TEBRIKLER! YENİ REKORUNUZ:" + to_string(bilgipaneli.getrekortut()), gameoverfontu, 80);
    tebrikleryazisi.setFillColor(Color(255, 255, 255, 100));
    tebrikleryazisi.setPosition(windowbaslangicdegerix + (anapenceregenisligi / 2) - (tebrikleryazisi.getLocalBounds().width / 2), windowbaslangicdegeriy + (anapencereyuksekligi/2) - 300);

    Text rekoryazisi("REKOR:" + to_string(bilgipaneli.getrekortut()), gameoverfontu, 40);
    rekoryazisi.setFillColor(Color(255, 255, 255, 100));
    rekoryazisi.setPosition(windowbaslangicdegerix + (anapenceregenisligi / 2) - (rekoryazisi.getLocalBounds().width / 2), windowbaslangicdegeriy + (anapencereyuksekligi/2) - 300);

    Text levelyazisi("LEVEL:" + to_string(bilgipaneli.getleveltut()), gameoverfontu, 40);
    levelyazisi.setFillColor(Color(255, 255, 255, 100));
    levelyazisi.setPosition(windowbaslangicdegerix + (anapenceregenisligi / 2) - (levelyazisi.getLocalBounds().width / 2), windowbaslangicdegeriy + (anapencereyuksekligi/2) - 230);

    Text skoryazisi("SKOR:" + to_string(bilgipaneli.getskortut()), gameoverfontu, 40);
    skoryazisi.setFillColor(Color(255, 255, 255, 100));
    skoryazisi.setPosition(windowbaslangicdegerix + (anapenceregenisligi / 2) - (skoryazisi.getLocalBounds().width / 2), windowbaslangicdegeriy + (anapencereyuksekligi/2) - 160);

    Text gameoveryazisi ("GAME OVER", gameoverfontu, 80);
    gameoveryazisi.setFillColor(Color(255, 255, 255, 100));
    gameoveryazisi.setPosition(windowbaslangicdegerix + (anapenceregenisligi / 2) - (gameoveryazisi.getLocalBounds().width / 2),windowbaslangicdegeriy + (anapencereyuksekligi / 2) - 80);

    Text tekraroynamakicinspaceyazisi ("Tekrar oynamak icin space tusuna basiniz.",gameoverfontu, 30);
    tekraroynamakicinspaceyazisi.setFillColor(Color(255, 255, 255, 60));
    tekraroynamakicinspaceyazisi.setPosition(windowbaslangicdegerix + (anapenceregenisligi / 2) - (tekraroynamakicinspaceyazisi.getLocalBounds().width / 2), windowbaslangicdegeriy + (anapencereyuksekligi / 2) + 20);

    Text oyunukapatmakicinescyazisi ("Oyunu kapatmak icin esc tusuna basiniz.",gameoverfontu, 30);
    oyunukapatmakicinescyazisi.setFillColor(Color(255, 255, 255, 60));
    oyunukapatmakicinescyazisi.setPosition(windowbaslangicdegerix + (anapenceregenisligi / 2) - (oyunukapatmakicinescyazisi.getLocalBounds().width / 2), windowbaslangicdegeriy + (anapencereyuksekligi / 2) + 80);

    while(window.isOpen())
    {
        window.draw(oyunbittiekrani);
        window.draw(skoryazisi);
        window.draw(levelyazisi);
        window.draw(gameoveryazisi);
        window.draw(tekraroynamakicinspaceyazisi);
        window.draw(oyunukapatmakicinescyazisi);
        
        if(bilgipaneli.getskortut() == bilgipaneli.getrekortut())
        {
            window.draw(tebrikleryazisi);
        }
        else
        {
            window.draw(rekoryazisi);
        }

        window.display();

        Event olay;
        while (window.pollEvent(olay))
        {
            if (olay.type == Event::Closed)
            {
                window.close();
                return;
            }
            if (olay.type == Event::KeyPressed) 
            {
                if(olay.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                else if (olay.key.code == Keyboard::Space)
                {
                    oyunalani.oyunalanitemizle();
                    bilgipaneli.skortemizle();
                    bilgipaneli.leveltemizle();
                    bilgipaneli.setskoryazirengiback();
                    return;
                }
            }
        }
    }
}

int main()
{

    OyunAlani oyunalani;
    TetrisBloklari siradakiblok;
    TetrisBloklari sonrakiblok;
    TetrisBloklari hayaletblok;
    BilgiAlani bilgipaneli(0, 0, oyunalani);

    VideoMode kullaniciEkranBoyutu = VideoMode::getFullscreenModes()[0];//kullanıcının ekran boyutu alındı.

    RenderWindow window(kullaniciEkranBoyutu, "Tetris", Style::Fullscreen);//oyun default olarak tam ekran başlamaya ayarlandı.

    int oyunalanigenisligi = oyunalani.getsutunsayisi() * oyunalani.getbirimkareboyutu();
    int oyunalaniyuksekligi = oyunalani.getsatirsayisi() * oyunalani.getbirimkareboyutu();

    int bilgipaneligenisligi = bilgipaneli.getpanelgenisligi();

    int anapenceregenisligi = oyunalanigenisligi + bilgipaneligenisligi;
    int anapencereyuksekligi = oyunalaniyuksekligi;

    int windowbaslangicdegerix = ((window.getSize().x - anapenceregenisligi) / 2) - 20;
    int windowbaslangicdegeriy = (window.getSize().y - anapencereyuksekligi) / 2 ;//kullanıcının ekran boyutu alınarak oyun alanının koordinatları hesaplandı.

    int bilgipanelibaslangicdegerix = windowbaslangicdegerix + oyunalanigenisligi + 18;
    int bilgipanelibaslangicdegeriy = windowbaslangicdegeriy;


    bilgipaneli.panelikonumlandir(bilgipanelibaslangicdegerix, bilgipanelibaslangicdegeriy);
    bilgipaneli.siradakiblokonizlemekutusuciz(window, oyunalani, bilgipanelibaslangicdegerix, bilgipanelibaslangicdegeriy);


    bool yeniBlokGerekiyor = true;

    Clock ekranacilissuresayaci;
    float dusurdongusuzamansayaci = 0.0f;
    float blokdusmegecikmesuresi = 0.9f;
    float blokdusmeminimumgecikmesuresi = 0.2f;

    int gecicimatris [4][4];

    Clock satirsilmefrekansisayaci;
    float satirsilmefrekansizamansayaci = 0.0f;

    siradakiblok.blokolustur((rand() % 7), oyunalani); //7 bloktan biri rastgele olusturuldu.
    sonrakiblok.blokolustur((rand() % 7), oyunalani);

    RectangleShape bilgipanelidiscervceve(Vector2f(bilgipaneligenisligi + 6, oyunalaniyuksekligi + 6));
    RectangleShape oyunalanidiscerceve(Vector2f(oyunalanigenisligi + 6, oyunalaniyuksekligi + 6));

    Music tetrismuzigi;

    if(!tetrismuzigi.openFromFile("assets/tetrismuzigi.ogg"))
    {
        cout<<"Muzik dosyasi acilamadi."<<endl;
    }
    tetrismuzigi.setVolume(10.0f);
    tetrismuzigi.setLoop(true);
    tetrismuzigi.play();

     Music satirsilmuzigi;

    if(!satirsilmuzigi.openFromFile("assets/satirsilmemuzigi.ogg"))
    {
        cout<<"Muzik dosyasi acilamadi."<<endl;
    }
    satirsilmuzigi.setVolume(50.0f);
    satirsilmuzigi.setLoop(false);

    SoundBuffer gameoverbuffer;
    Sound gameoversesi;
    if(!gameoverbuffer.loadFromFile("assets/gameover.ogg"))
    {
        cout<<"Game over muzik dosyasi acilamadi."<<endl;
    }
    gameoversesi.setBuffer(gameoverbuffer);
    gameoversesi.setVolume(100.0f);

    SoundBuffer oyunbaslatbuffer;
    Sound oyunbaslatsesi;
    if(!oyunbaslatbuffer.loadFromFile("assets/oyunbaslat.ogg"))
    {
        cout<<"Oyun baslat muzik dosyasi acilamadi."<<endl;
    }
    oyunbaslatsesi.setBuffer(oyunbaslatbuffer);
    oyunbaslatsesi.setVolume(100.0f);

    while (window.isOpen())
    {
        float sonacilistangecenzaman = ekranacilissuresayaci.restart().asSeconds();//restart, pencerenin son acildigindan itibaren gecen sureyi tutar ve sifirlar, assecond ise saniye cinsinden tutar.
        dusurdongusuzamansayaci += sonacilistangecenzaman;

        Event olay;

        bilgipanelidiscervceve.setPosition(bilgipanelibaslangicdegerix - 3, bilgipanelibaslangicdegeriy - 3);
        bilgipanelidiscervceve.setFillColor(Color::Transparent);
        bilgipanelidiscervceve.setOutlineThickness(10.0f);
        bilgipanelidiscervceve.setOutlineColor(Color(90, 80, 100)); 

        oyunalanidiscerceve.setPosition(windowbaslangicdegerix - 3, windowbaslangicdegeriy - 3);
        oyunalanidiscerceve.setFillColor(Color::Transparent);
        oyunalanidiscerceve.setOutlineThickness(10.0f);
        oyunalanidiscerceve.setOutlineColor(Color(90, 80, 100)); 

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
                if (olay.key.code == Keyboard::P)
                {
                    tetrismuzigi.stop();
                    oyunduraklatildi(window, oyunalani, bilgipaneli, anapenceregenisligi, anapencereyuksekligi, windowbaslangicdegerix, windowbaslangicdegeriy);
                    tetrismuzigi.play();
                }
                if(olay.key.code == Keyboard::R)
                {
                    oyunalani.oyunalanitemizle();
                    bilgipaneli.skortemizle();
                    bilgipaneli.leveltemizle();
                    bilgipaneli.setskoryazirengiback();
                    blokdusmegecikmesuresi = 0.9f;
                    dusurdongusuzamansayaci = 0.0f;
                    yeniBlokGerekiyor = true;
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

                bilgipaneli.dusenbloklaskorarttir();

                int kacsatirsilindi = silineceksatirlar.size();

                if(!silineceksatirlar.empty())
                {
                    satirsilmuzigi.play();

                    float satirsilmefrekansi = satirsilmefrekansisayaci.restart().asSeconds();
                    satirsilmefrekansizamansayaci += satirsilmefrekansi;

                    bilgipaneli.skorarttir(kacsatirsilindi, satirsilmefrekansizamansayaci);
                    satirsilmefrekansizamansayaci = 0.0f;

                    Clock efektsuresi;
                    for(int m=0; m<silineceksatirlar.size(); m++)
                    {
                        int efektekleneceksatiritut = silineceksatirlar[m];
                        oyunalani.satirefekt(efektekleneceksatiritut);
                    }
                    
                    while(efektsuresi.getElapsedTime().asMilliseconds() < 800)//satir silinmeden once efekt icin bekleme suresi ayarlandi.
                    {
                        ekraniguncelle(window, oyunalani, oyunalanidiscerceve, windowbaslangicdegerix, windowbaslangicdegeriy); //satir silinmeden once efektin gorunmesi icin ekran guncellendi.
                        if(efektsuresi.getElapsedTime().asMilliseconds() < 300 || efektsuresi.getElapsedTime().asMilliseconds() > 500)
                        {
                            bilgipaneli.setskoryazirengi(Color::Transparent);
                        }
                        else
                        {
                            bilgipaneli.setskoryazirengiback();
                        }
                        bilgipaneli.bilgialaniciz(window);
                        window.draw(bilgipanelidiscervceve) ;
                        yonergeciz(window, oyunalani, windowbaslangicdegeriy);
                        bilgipaneli.siradakiblokonizlemekutusuciz(window, oyunalani, bilgipanelibaslangicdegerix, bilgipanelibaslangicdegeriy);
                        bilgipaneli.siradakiblokonizlemeciz(window, sonrakiblok, oyunalani);
                        window.display();
                    }

                    bilgipaneli.setskoryazirengiback();
                    bilgipaneli.bilgialaniciz(window);

                    for(int u=silineceksatirlar.size()-1; u>=0 ; u--)//asagidan yukari dogru alinan indeksleri yukaridan asagiya dogru siliyor cunku once alttakini silse usttekinin indeksi degisirdi.
                    {
                        int silineceksatiritut=silineceksatirlar[u];
                        oyunalani.satirsil(silineceksatiritut);
                    }

                    
                }
                yeniBlokGerekiyor = true;

                if (siradakiblok.oyunbittimi(siradakiblok.getblokxdegeri(), siradakiblok.getblokydegeri(), gecicimatris, oyunalani))
                {                    
                    tetrismuzigi.stop();
                    gameoversesi.play();
                    oyunbittiekrani(window, oyunalani, bilgipaneli, anapenceregenisligi, anapencereyuksekligi, windowbaslangicdegerix, windowbaslangicdegeriy);
                    oyunbaslatsesi.play();
                    tetrismuzigi.play();
                    blokdusmegecikmesuresi = 0.9f; //oyun yeniden basladiginda bloklarin hizli dusmesini engellemek icin sureyi basa alir.
                    dusurdongusuzamansayaci = 0.0f; 
                    yeniBlokGerekiyor = true;
                }
            }

        }

        ekraniguncelle(window, oyunalani, oyunalanidiscerceve, windowbaslangicdegerix, windowbaslangicdegeriy);

        if (yeniBlokGerekiyor) 
        {
            if (blokdusmegecikmesuresi > blokdusmeminimumgecikmesuresi) 
            {
                blokdusmegecikmesuresi -= blokdusmeminimumgecikmesuresi * 0.05f; //her  yeni blokta gecikme azaltildi, bloklar gittikce hizlanacak
            }

            siradakiblok = sonrakiblok;
            
            sonrakiblok.blokolustur((rand() % 7), oyunalani);

            yeniBlokGerekiyor = false; 
        }

        hayaletblok = siradakiblok;

        hayaletblok.hayaletblokolustur(oyunalani);
        
        siradakiblok.blokciz(window, windowbaslangicdegerix, windowbaslangicdegeriy, oyunalani);
        hayaletblok.hayaletblokciz(window, windowbaslangicdegerix, windowbaslangicdegeriy, oyunalani);

        window.draw(bilgipanelidiscervceve);

        bilgipaneli.bilgialaniciz(window);

        yonergeciz(window, oyunalani, windowbaslangicdegeriy);

        bilgipaneli.siradakiblokonizlemekutusuciz(window, oyunalani, bilgipanelibaslangicdegerix, bilgipanelibaslangicdegeriy);

        bilgipaneli.siradakiblokonizlemeciz(window, sonrakiblok, oyunalani);

        window.display();

    }
    return 0;
}