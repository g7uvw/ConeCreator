
/*
_______ _______ _       _______    _______ _______ _______ _______________________ _______
(  ____ (  ___  ( (    /(  ____ \  (  ____ (  ____ (  ____ (  ___  \__   __(  ___  (  ____ )
| (    \| (   ) |  \  ( | (    \/  | (    \| (    )| (    \| (   ) |  ) (  | (   ) | (    )|
| |     | |   | |   \ | | (__      | |     | (____)| (__   | (___) |  | |  | |   | | (____)|
| |     | |   | | (\ \) |  __)     | |     |     __|  __)  |  ___  |  | |  | |   | |     __)
| |     | |   | | | \   | (        | |     | (\ (  | (     | (   ) |  | |  | |   | | (\ (
| (____/| (___) | )  \  | (____/\  | (____/| ) \ \_| (____/| )   ( |  | |  | (___) | ) \ \__
(_______(_______|/    )_(_______/  (_______|/   \__(_______|/     \|  )_(  (_______|/   \__/

Cone Creator : A stupidly simple program that creates a 3D cone as a seris of 2D slices
               Created to scatch an itch, and to stop someone asking me to write this for them
               If this is in anyway useful to you, please use it with me best wishes.

Useage :       Compile with clang or gcc, run.
               By default it will create an 8 megabyte file called cone.bin in the current
               directory. You can change the 3D image size by changing the X, Y and Z Size
               values.
               A sequential file is written out in [XY],Z format.
*/

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

uint8_t XSize,YSize,ZSize,Radius;

int main(int argc, char *argv[])
{
    XSize = 200;
    YSize = 200;
    ZSize = 200;
    vector<uint8_t> canvas;


    canvas.resize(XSize*YSize*ZSize);
    for (uint8_t z = 0; z < ZSize; z++)
    {
        for (uint8_t x = 0; x < XSize; x++)
        {
            for (uint8_t y=0; y < YSize; y++)
            {
                Radius = (z+1)/2;
                if (((x - XSize/2) * (x - XSize/2) + (y - YSize/2) * (y - YSize/2)) <= (Radius * Radius))
                    canvas.at(z*ZSize*YSize+y*YSize+x) = 255;
                else
                    canvas.at(z*ZSize*YSize+y*YSize+x) = 0;
            }
        }
    }
    fstream file;
    file.open("cone.bin",ios::in|ios::out|ios::binary|ios::trunc);
    file.write((char*)&*(canvas.begin()),canvas.size() * sizeof(uint8_t));
    file.close();
    exit(1);
}
