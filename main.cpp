

#include "TXLib.h"

 struct Mario
 {
    int x;
    int y;
    int w;
    int h;
    HDC image;
    HDC image_jump;



    void draw()
    {
       txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_WHITE);
    }
};





int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

Mario mario = { 100, 250, 100, 80, txLoadImage("Mарина_2.bmp"), txLoadImage("Mарина_2.bmp")};



   while (!GetAsyncKeyState(VK_ESCAPE))
   {
    txClear();
    txBegin();

    mario.draw();

    if (GetAsyncKeyState(VK_RIGHT))
    {
     mario.x += 5;
    }

    if (GetAsyncKeyState(VK_SPACE))
    {
      mario.image = mario.image_jump;
      mario.y -= 20;
    }

    mario.y += 5;

    if(mario.y > 400)
    {
     mario.y = 400;
    }




    txEnd();
    txSleep(30);
   }









    txDisableAutoPause();
    return 0;
    }
