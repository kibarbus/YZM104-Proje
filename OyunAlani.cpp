#include "OyunAlani.hpp"
#include "TetrisBloklari.hpp"
#include <iostream>
 
using namespace sf;
using namespace std;


OyunAlani::OyunAlani()
{
    for(int i=0; i<satir; i++)
    {
        for(int j=0; j<sutun; j++)
        {
            grid[i][j] = varsayilangridrengi;
        }
    }
}

int OyunAlani::getbirimkareboyutu() const
{
    return BIRIMKAREBOYUTU;
}

int OyunAlani::getsatirsayisi() const 
{
    return satir;
}

int OyunAlani::getsutunsayisi() const 
{
    return sutun;
}

Color OyunAlani::getgriddegeri(int sutun, int satir) const
{
    return grid[satir][sutun];
}

Color OyunAlani::getvarsayilangriddegeri() const
{
    return varsayilangridrengi;
}

void OyunAlani::oyunalaniolustur(RenderWindow& pencere, int baslangicdegerix, int baslangicdegeriy)
{
    RectangleShape birimkare(Vector2f(BIRIMKAREBOYUTU-1, BIRIMKAREBOYUTU-1));//birim karelerin ayrılması için aralarında boşluk bırakıldı.
    Color varsayilangridrengi(55,45,60);

    for(int i=0; i<satir; i++)
    {
        for(int j=0; j<sutun; j++)
        {
            double x = baslangicdegerix + j * BIRIMKAREBOYUTU;
            double y = baslangicdegeriy + i * BIRIMKAREBOYUTU;

            birimkare.setPosition(x, y);
            if(grid[i][j] != varsayilangridrengi)
            {
                birimkare.setFillColor(grid[i][j]);
                birimkare.setOutlineThickness(-2.0f);
                birimkare.setOutlineColor(Color(255, 255, 255, 60));
            }
            else
            {
                birimkare.setFillColor(varsayilangridrengi);
                birimkare.setOutlineThickness(-2.0f); 
                birimkare.setOutlineColor(Color(253,250,255,10));//birim karelerin estetik durması için iç kısmında ince yarı saydam bir çerçeve çizildi.
            }
            
            pencere.draw(birimkare);
        }
    }
}

void OyunAlani::dusenbloksabitle(int blokxdegeri, int blokydegeri, int blokmatrisi[5][5], Color sabitlenecekblokrengi)
{
        for(int k=0; k<5; k++)
        {
            for(int m=0; m<5; m++)
            {
                if(blokmatrisi[k][m] == 1)
                {
                    int haritaXkoordinati = blokxdegeri + m;
                    int haritaYkoordinati = blokydegeri + k;

                    if(haritaXkoordinati >= 0 && haritaXkoordinati < getsutunsayisi() && haritaYkoordinati >= 0 && haritaYkoordinati < getsatirsayisi())
                    {
                        grid[haritaYkoordinati][haritaXkoordinati] = sabitlenecekblokrengi; //dusen blok grid uzerinde renklendirildi.grid uzerinde donduruldu. Y degerinin satirlari, X degerinin sutunlari tuttugunu unutma.
                    }//blokun dondugu birim karelerin degeri 0dan farkli hale getirildi.
                }
               
            }
        }
}

int OyunAlani::satirlarikontrolet()
{
    int satirindeksi = 0;
    for(satirindeksi; satirindeksi<satir; satirindeksi++)
    {
        bool satirdolumu = true;

        for(int j=0; j<sutun; j++)
        {
            if(grid[satirindeksi][j] == varsayilangridrengi)
            {
                satirdolumu = false;
                break;
            }
        }
        if(satirdolumu)
        {
            return satirindeksi;
        }
    }
    return -1;
}

void OyunAlani::satirefekt(int silineceksatir)
{
    for (int j = 0; j < sutun; j++) 
    {
        grid[silineceksatir][j] = varsayilangridrengi;
    }
}

void OyunAlani::satirsil(int silineceksatir)
{
    for(int i=silineceksatir; i>0; i--)
    {
        for(int j=0; j<sutun; j++)
        {
            grid[i][j] = grid[i-1][j];
        }
    }
    
    for(int k=0; k<sutun; k++)
    {
        grid[0][k] = varsayilangridrengi;
    }
}
