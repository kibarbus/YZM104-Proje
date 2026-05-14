#include "OyunAlani.hpp"
 
using namespace sf;
using namespace std;


OyunAlani::OyunAlani()
{

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

void OyunAlani::oyunalaniolustur(RenderWindow& pencere, int baslangicdegerix, int baslangicdegeriy)
{
    RectangleShape birimkare(Vector2f(BIRIMKAREBOYUTU-1, BIRIMKAREBOYUTU-1));

    for(int i=0; i<satir; i++)
    {
        for(int j=0; j<sutun; j++)
        {
            double x = baslangicdegerix + j * BIRIMKAREBOYUTU;
            double y = baslangicdegeriy + i * BIRIMKAREBOYUTU;

            birimkare.setPosition(x, y);
            birimkare.setFillColor(Color(55,45,60));
            birimkare.setOutlineThickness(-2.0f);
            birimkare.setOutlineColor(Color(253,250,255,10));
            pencere.draw(birimkare);
        }
    }
}
