#include "TetrisBloklari.hpp"
#include "OyunAlani.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class OyunAlani;

const int bloktipi [7][4][4]=
{
    //kucuk t blok
    {{1,1,1,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}}, //1
    //j blok
    {{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}}, //2
    //l blok
    {{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}}, //3
    //s blok
    {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},//4
    //z blok
    {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}}, //5
    //2'li kare blok
    {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}, //6
    //4'lu yatay blok
    {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},}, //7
};

TetrisBloklari::TetrisBloklari()
{
    blokxdegeri = 6;
    blokydegeri = 0;
}

void TetrisBloklari::blokolustur(int bloknumarasi, const OyunAlani& oyunalani)
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            blokmatrisi[i][j] = bloktipi[bloknumarasi][i][j];
        }
    }
    int donusyonu = rand() % 5; //donmemis hallerinin gelme ihtimalinin daha fazla olmasi icin randomda ilk halini 2 kez ihtimal aldirdim.
    for(int z=0; z<donusyonu; z++)
    {
        blokdondur(oyunalani); 
    }

    blokxdegeri = 6;
    blokydegeri = 0;

    switch(bloknumarasi) 
    {
        case 0:  blokrengi = Color(255, 150, 196);   break; // kucuk t blok
        case 1:  blokrengi = Color(186, 215, 255);   break; // j blok
        case 2:  blokrengi = Color(230, 223, 186);   break; // l blok
        case 3:  blokrengi = Color(186, 255, 211);   break; // s blok
        case 4:  blokrengi = Color(221, 155, 231);   break; // z blok
        case 5:  blokrengi = Color(188, 158, 130);   break; // 2'li kare blok
        case 6:  blokrengi = Color(204, 200, 255);   break; // 4'lu yatay blok
        
        default:                                        break;
    }
}

void TetrisBloklari::hayaletblokolustur(const OyunAlani& oyunalani)
{
    /* for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            blokmatrisi[i][j] = bloktipi[hayaletbloknumarasi][i][j];
        }
    } */

    /* this->hayaletbloknumarasi = hayaletbloknumarasi;

    switch(hayaletbloknumarasi) 
    {
        case 0:  blokrengi = Color(255, 240, 245, 30);   break; // kucuk t blok
        case 1:  blokrengi = Color(240, 248, 255, 30);   break; // j blok
        case 2:  blokrengi = Color(255, 253, 240, 30);   break; // l blok
        case 3:  blokrengi = Color(240, 255, 245, 30);   break; // s blok
        case 4:  blokrengi = Color(253, 242, 255, 30);   break; // z blok
        case 5:  blokrengi = Color(250, 245, 240, 30);   break; // 2'li kare blok
        case 6:  blokrengi = Color(242, 255, 255, 30);   break; // 4'lu yatay blok
        
        default:                                        break;
    } */

    while(blokdusur(oyunalani))
    {
        
    }

}

void TetrisBloklari::blokciz(RenderWindow& pencere, int windowbaslangicdegerix, int windowbaslangicdegeriy, const OyunAlani& oyunalani)
{
    int blokbirimkareboyutu = oyunalani.getbirimkareboyutu();
    
    RectangleShape blokbirimkare(Vector2f(blokbirimkareboyutu-2, blokbirimkareboyutu-2));

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(blokmatrisi[i][j] == 1)
            {
                int x = windowbaslangicdegerix + (blokxdegeri + j) * blokbirimkareboyutu;
                int y = windowbaslangicdegeriy + (blokydegeri + i) * blokbirimkareboyutu;

                blokbirimkare.setPosition(x, y);
                blokbirimkare.setFillColor(blokrengi);
                blokbirimkare.setOutlineThickness(-2.0f);
                blokbirimkare.setOutlineColor(Color(255, 255, 255, 60));
                pencere.draw(blokbirimkare);
            }
        }
    }
}

void TetrisBloklari::hayaletblokciz(RenderWindow& pencere, int windowbaslangicdegerix, int windowbaslangicdegeriy, const OyunAlani& oyunalani)
{
    int blokbirimkareboyutu = oyunalani.getbirimkareboyutu();
    
    RectangleShape blokbirimkare(Vector2f(blokbirimkareboyutu-2, blokbirimkareboyutu-2));

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(blokmatrisi[i][j] == 1)
            {
                int x = windowbaslangicdegerix + (blokxdegeri + j) * blokbirimkareboyutu;
                int y = windowbaslangicdegeriy + (blokydegeri + i) * blokbirimkareboyutu;

                blokrengi.a = 40;//blok renkleri şeffaflaştırıldı.

                blokbirimkare.setPosition(x, y);
                blokbirimkare.setFillColor(blokrengi);
                blokbirimkare.setOutlineThickness(-1.0f);
                blokbirimkare.setOutlineColor(Color(255, 255, 255, 1));
                pencere.draw(blokbirimkare);
            }
        }
    }
}

void TetrisBloklari::sagagit(const OyunAlani& oyunalani)
{
    if(bisonrakikarebosmu(blokxdegeri + 1 , blokydegeri , blokmatrisi, oyunalani))
    {
        blokxdegeri++;
    }
}

void TetrisBloklari::solagit(const OyunAlani& oyunalani)
{
    if(bisonrakikarebosmu(blokxdegeri - 1 , blokydegeri , blokmatrisi, oyunalani))
    {
        blokxdegeri--;
    }
}

void TetrisBloklari::asagigit(const OyunAlani& oyunalani)
{
    if(bisonrakikarebosmu(blokxdegeri , blokydegeri + 1 , blokmatrisi, oyunalani))
    {
        blokydegeri++;
    }
}

void TetrisBloklari::blokdondur(const OyunAlani& oyunalani)
{
    int eskimatris[4][4];
    for(int k=0; k<4; k++)
    {
        for(int m=0; m<4; m++)
        {
            eskimatris[k][m] = blokmatrisi[k][m];
        }
    }

    int tempmatris[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            tempmatris[j][3-i] = blokmatrisi[i][j];//indis 0dan başladigi icin 3-i
        }
    }
    
    int ilkdolusatir = 4, ilkdolusutun = 4;
    for(int i=0; i<4; i++) 
    {
        for(int j=0; j<4; j++) 
        {
            if(tempmatris[i][j] == 1) 
            {
                if(i < ilkdolusatir) 
                {
                    ilkdolusatir = i;
                }
                if(j < ilkdolusutun) 
                {
                    ilkdolusutun = j;
                }
            }
        }
    }

    for(int k=0; k<4; k++)
    {
        for(int m=0; m<4; m++)
        {
            blokmatrisi[k-ilkdolusatir][m-ilkdolusutun] = tempmatris[k][m];
        }
    }

    if(!bisonrakikarebosmu(blokxdegeri, blokydegeri, blokmatrisi, oyunalani))
    {
        for(int k=0; k<4; k++)
        {
            for(int m=0; m<4; m++)
            {
                blokmatrisi[k][m] = eskimatris[k][m];
            }
        }
    }
}

bool TetrisBloklari::blokdusur(const OyunAlani& oyunalani)
{
    if(bisonrakikarebosmu(blokxdegeri, blokydegeri + 1, blokmatrisi, oyunalani))
    {
        blokydegeri++;
        return true;
    }
    return false;
}

bool TetrisBloklari::bisonrakikarebosmu(int siradakix, int siradakiy, int matris[4][4], const OyunAlani& oyunalani)
{
    for (int i=0; i<4; i++) 
    {
        for (int j=0; j<4; j++) 
        {
            int siradakixkoordinati;
            int siradakiykoordinati;
            if (matris[i][j] == 1) 
            {
                siradakixkoordinati = siradakix + j;
                siradakiykoordinati = siradakiy + i;

                if(siradakixkoordinati >= oyunalani.getsutunsayisi() || siradakixkoordinati<0 || siradakiykoordinati >= oyunalani.getsatirsayisi())
                {
                    return false; 
                }

                if (siradakiykoordinati>=0) 
                {
                    if (oyunalani.getgriddegeri(siradakixkoordinati, siradakiykoordinati) != oyunalani.getvarsayilangriddegeri()) 
                    {
                        return false; 
                    }
                }
            }
        }
    }
    return true;
}

bool TetrisBloklari::oyunbittimi(int oyunbittimix, int oyunbittimiy, int matris[4][4], const OyunAlani& oyunalani)
{
    for (int i=0; i<4; i++) 
    {
        for (int j=0; j<4; j++) 
        {
            int oyunbittimikontroly;

            if (matris[i][j] == 1) 
            {
                oyunbittimikontroly = oyunbittimiy + i;

                if(oyunbittimikontroly <= 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int TetrisBloklari::getblokmatrisi(int i, int j) const
{
    return blokmatrisi[i][j];
}

int TetrisBloklari::getblokxdegeri() const
{
    return blokxdegeri;
}

int TetrisBloklari::getblokydegeri() const
{
    return blokydegeri;
}

Color TetrisBloklari::getblokrengi() const
{
    return blokrengi; 
}

