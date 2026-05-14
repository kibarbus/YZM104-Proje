#include "TetrisBloklari.hpp"
#include "OyunAlani.hpp"

using namespace sf;
using namespace std;

const int bloktipi [14][5][5]=
{
    //buyuk t blok
    {{1,1,1,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //1
    //kucuk t blok
    {{1,1,1,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //2
    //sol yan l blok
    {{1,1,1,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //3
    //sag yan l blok
    {{1,1,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //4
    //z blok
    {{1,1,0,0,0},{0,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //5
    //2'li kare blok
    {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //6
    //3'lu kare blok
    {{1,1,1,0,0},{1,1,1,0,0},{1,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //7
    //5'li yatay blok
    {{1,1,1,1,1},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //8
    //4'lu yatay blok
    {{1,1,1,1,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //9
    //3'lu yatay blok
    {{1,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //10
    //2'li yatay blok
    {{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //11
    //tek blok
    {{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //12
    //n blok
    {{0,0,1,0,0},{1,1,1,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //13
    //sapan blok
    {{1,1,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0}}, //14
};

TetrisBloklari::TetrisBloklari()
{
    blokxdegeri = 6;
    blokydegeri = 0;
}

void TetrisBloklari::blokolustur(int bloknumarasi)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            blokmatrisi[i][j] = bloktipi[bloknumarasi][i][j];
        }
    }
    int donusyonu = rand() % 5;
    for(int z=0; z<donusyonu; z++)
    {
        blokdondur(); 
    }
    
    blokxdegeri = 6;
    blokydegeri = 0;

    switch(bloknumarasi) 
    {
        case 0:  blokrengi = Color(255, 179, 186);      break; // buyuk t blok
        case 1:  blokrengi = Color(255, 223, 186);      break; // kucuk t blok
        case 2:  blokrengi = Color(255, 255, 186);      break; // sol yan l blok
        case 3:  blokrengi = Color(186, 255, 201);      break; // sag yan l blok
        case 4:  blokrengi = Color(188, 158, 130);      break; // z blok
        case 5:  blokrengi = Color(221, 160, 221);      break; // 2'li kare blok
        case 6:  blokrengi = Color(204, 204, 255);      break; // 3'lu kare blok
        case 7:  blokrengi = Color(255, 204, 229);      break; // 4'lu yatay blok
        case 8:  blokrengi = Color(204, 255, 255);      break; // 5'li yatay blok
        case 9:  blokrengi = Color(224, 224, 224);      break; // 4'lu yatay blok
        case 10: blokrengi = Color(255, 218, 185);      break; // 3'lu yatay blok
        case 11: blokrengi = Color(186, 225, 255);      break; // tek blok
        case 12: blokrengi = Color(176, 224, 230);      break; // n blok
        case 13: blokrengi = Color(152, 251, 152);      break; // sapan blok
        
        default:                                        break;
    }
}

void TetrisBloklari::blokciz(RenderWindow& pencere, int windowbaslangicdegerix, int windowbaslangicdegeriy)
{
    OyunAlani tempoyunalani;
    int blokbirimkareboyutu = tempoyunalani.getbirimkareboyutu();
    
    RectangleShape blokbirimkare(Vector2f(blokbirimkareboyutu-2, blokbirimkareboyutu-2));

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
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

void TetrisBloklari::sagagit()
{

}

void TetrisBloklari::solagit()
{

}

void TetrisBloklari::blokdondur()
{
    
}

void TetrisBloklari::blokdusur()
{
    
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

