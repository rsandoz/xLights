/***************************************************************
 * Name:      RenderCircles
 * Purpose:   Extends RGB effects with Circle effects
 * Author:    Frank Reichstein (phar_hp@yahoo.com)
 * Created:   2013-07-28
 * Copyright: 2013 by Frank Reichstein
 * License:
     This file is part of xLights.

    xLights is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    xLights is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with xLights.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************/
#include <cmath>
#include "RgbEffects.h"

#define PI_DOUBLE M_PI * 2
#define PI_THIRD M_PI/3

float RgbEffects::getAngle(float difX, float difY)
{
    float angle;
    // returns as radians (360 degrees equals 2*PI)
    // for our other function it would be easier to return in degrees, but as atanf returns the angle in radians we just leave it like that

    // avoding ziro division
    // (little bit of a hack, and not a good programming style, but whateva...)
    if(difX == 0)
        difX += 0.0001f;

    if(difY == 0)
        difY += 0.0001f;


    if ( difX >= 0 && difY >= 0 )
    {
        angle = atanf( difX / difY );
    }
    else if (difX >= 0 && difY <= 0)
    {
        angle = M_PI_2 + atanf(-difY / difX);
    }
    else if(difX <= 0 && difY <= 0)
    {
        angle = M_PI + atanf(difX / difY);
    }
    else if (difX <= 0 && difY >= 0)
    {
        angle = M_PI_2 + M_PI + atanf(difY / -difX);
    }
    return angle;
}

void RgbEffects::RenderCircles(int number,int radius, bool bounce, bool collide, bool random,
                               bool radial, bool radial_3D, int start_x, int start_y, bool plasma)
{
     wxImage::HSVValue hsv;
     palette.GetHSV(0, hsv);
     double pos=0.0;
     int x,y;

     float angle;

     int xp, yp;
     wxColor color;

     if (bounce)/* temp means direction... */
        angle = -(float)PI_DOUBLE * (float)state/20.0f;
     else
        angle = (float)PI_DOUBLE * (float)state/20.0f;

     float dx,dy, diff, dysq;
     float curAngle;

     for (yp = 0; yp < BufferHt; yp++)
     {
         dy = yp - BufferHt/2.0;
         dysq = dy*dy;
         for (xp = 0; xp < BufferWi; xp++)
         {
             dx = xp - BufferWi/2.0;
             diff = sqrtf(dx*dx+dysq);

             curAngle = getAngle(dx , dy);
             getColorForAngle(curAngle+angle+(diff/400.0*M_PI), color);
             SetPixel(xp,yp, color);
         }
     }


    /* Expirement with drawing spirals
     for (;pos<=1.0; pos += .001)
     {
         x = int(cos(pos*radius*M_PI *2) * number*10 *(1-pos)) + BufferWi/2;
         y = int(sin(pos*radius*M_PI *2) * number*10 *(1-pos)) + BufferHt/2;
         SetPixel(x,y,hsv);
     }
     */

/*
    int ii=0;
    int colorIdx;
    size_t colorCnt=GetColorCount();
    wxImage::HSVValue hsv;
    float spd;
    float angle;
    static int numBalls = 0;
    RgbBalls *effectObjects;
    static bool metaType=false;

    if(plasma)
    {
        effectObjects = metaballs;
    }
    else
    {
        effectObjects = balls;
    }

    if (radial)
    {
        RenderRadial(start_x, start_y, radius, colorCnt, number, radial_3D);
        return; //radial is the easiest case so just get out.
    }

    if ( 0 == state || radius != effectObjects[ii]._radius || number != numBalls || metaType != plasma)
    {
        numBalls = number;
        for(ii=0; ii<number; ii++)
        {
            start_x = rand()%(BufferWi);
            start_y = rand()%(BufferHt);
            colorIdx = ii%colorCnt;
            palette.GetHSV(colorIdx, hsv);
            spd = rand()%3 + 1;
            angle = rand()%2?rand()%90:-rand()%90;
            effectObjects[ii].Reset((float) start_x, (float) start_y, spd, angle, (float)radius, hsv);
        }
        metaType=plasma;
    }
    else
    {
        RenderCirclesUpdate(number, effectObjects);
    }

    if (bounce)
    {
        //update position in case something hit a wall
        for(ii = 0; ii < number; ii++)
        {
            effectObjects[ii].Bounce(BufferWi,BufferHt);
        }
    }
    if(collide)
    {
        //update position if two balls collided
    }

    if (plasma)
    {
        RenderMetaBalls(numBalls);
    }
    else
    {
        for (ii=0; ii<number; ii++)
        {
            hsv = balls[ii].hsvcolor;
            for(int r = balls[ii]._radius; r >= 0; r--)
            {
                if(!bounce && !collide)
                {
                    DrawCircle(balls[ii]._x, balls[ii]._y, r, hsv);
                }
                else
                {
                    DrawCircleClipped(balls[ii]._x, balls[ii]._y, r, hsv);
                }
            }
        }
    }
    */
}

void RgbEffects::RenderCirclesUpdate(int ballCnt, RgbBalls* effObjs)
{
    int ii;
    for (ii=0; ii <ballCnt; ii++)
    {
        effObjs[ii].updatePosition((float)speed/4.0, BufferWi, BufferHt);
    }
}

void RgbEffects::RenderRadial(int x, int y,int thickness, int colorCnt,int number,bool radial_3D)
{
    wxImage::HSVValue hsv;
    int ii,n;
    int colorIdx;
    int barht = BufferHt/(thickness+1);
    if(barht<1) barht=1;
    int maxRadius = state>BufferHt?BufferHt: state/2 + thickness;
    int blockHt   = colorCnt*barht;
    int f_offset  = state/4 % (blockHt+1);

//  int curEffStartPer, curEffEndPer, nextEffTimePeriod;

    barht = barht>0?barht:1;
    palette.GetHSV(0,hsv);
    for( ii = maxRadius ; ii >= 0;  ii--)
    {
        n=ii-f_offset+blockHt;
        colorIdx = (n)%blockHt/barht;
        palette.GetHSV(colorIdx,hsv);

        if(radial_3D)
        {
            hsv.hue = 1.0*(ii+state)/(maxRadius/number);
            if(hsv.hue>1.0) hsv.hue=hsv.hue-(long)hsv.hue;
            hsv.saturation=1.0;
            hsv.value=1.0;
        }
        DrawCircle(x, y, ii, hsv);
    }
}



void RgbEffects::RenderMetaBalls(int numBalls)
{
    int row, col, ii;
    float sum, val;
    wxImage::HSVValue hsv, temp;

    for(row=0;row<BufferHt;row++)
    {
        for(col=0;col<BufferWi;col++)
        {
            sum = 0;
            hsv.hue=0.0;
            hsv.saturation=0.0;
            hsv.value=0.0;

            for (ii=0; ii<numBalls; ii++)
            {
                val =  metaballs[ii].Equation((float)col,(float)row);
                sum+= val;
                temp = metaballs[ii].hsvcolor;
                if(val > 0.30)
                {
                    temp.value=val>1.0?1.0:val;
                    hsv = Get2ColorAdditive(hsv, temp);
                }
            }
            if(sum >= 0.90)
            {
                SetPixel(col,row, hsv);
            }
        }
    }
}

void RgbEffects::getColorForAngle(float angle, wxColor &color)
{
    // returns the color for a given angle (angle can be from 0 to DOUBLE_PI, (360.0 degrees in radians))
    size_t colorCnt=GetColorCount();
    int green, red, blue;
    green = red = blue = 0;

    // make sure angle is between 0 and DOUBLE_PI
    while (angle < 0)
        angle = angle + PI_DOUBLE;

    // I'd go for number 3 (but I didn't test it, you're free to do so)
    if (angle > PI_DOUBLE)
        angle -= (int)(angle / PI_DOUBLE) * PI_DOUBLE;


    // this calculates one of the three color parts (one if always ziro, the other one is always 255)
    // (255.0/60.0) is about 4
    int z = 4 * ((int)(angle / M_PI * 180.0f)%60);


    if (angle < PI_THIRD)
    {
        red = 255;
        green = z;
    }
    else if (angle < PI_THIRD * 2.0)
    {
        red = 255 - z;
        green = 255;
    }
    else if (angle < PI_THIRD * 3.0)
    {
        green = 255;
        blue = z;
    }
    else if (angle < PI_THIRD * 4.0)
    {
        green = 255 - z;
        blue = 255;
    }
    else if (angle < PI_THIRD * 5.0)
    {
        red = z;
        blue = 255;
    }
    else
    {
        red = 255;
        blue = 255 - z;
    }
    color.Set(red, green, blue);
}

