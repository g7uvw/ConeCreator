
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
#include "tomhead.h"
using namespace std;

unsigned int XSize,XCentre,YCentre,YSize,ZSize,Radius;
#define CurrentVoxel z*ZSize*YSize+y*YSize+x

int main()
{
    XSize = 600;
    YSize = 600;
    ZSize = 600;
    XCentre = XSize/2;
    YCentre = YSize/2;

    vector<uint8_t> canvas;
    canvas.resize(XSize*YSize*ZSize);

    thead TomHead;
    TomHead.xsize = XSize;
    TomHead.ysize = YSize;
    TomHead.zsize = ZSize;
    //TomHead.owner = "DM";
    //TomHead.comment = "A Computed Cone";


    for (unsigned int z = 2; z < ZSize; z++)
    {
        cout<<"Slice : " <<z<<endl;
        for (unsigned int y = 0; y < YSize; y++)
        {
            for (unsigned int x=0; x < XSize; x++)
            {
                Radius = z/2;

                if (((x - XCentre) * (x - XCentre)) + ((y - YCentre) * (y - YCentre)) <= (Radius * Radius))
                {
                    canvas.at(CurrentVoxel) = 254;
                    cout << "X = " << x <<endl;
                    cout << "Y = " << y <<endl;
                }
                else
                    canvas.at(CurrentVoxel) = 0;
            }
        }
    }
    cout << "Xcentre : " <<XCentre<<endl;
    cout << "Ycentre : " <<YCentre<<endl;
    fstream file;
    file.open("cone.tom",ios::in|ios::out|ios::binary|ios::trunc);
    file.write((char *) &TomHead, sizeof(struct thead));

    //for(unsigned long i=0;i<canvas.size();i++)
    //{
    //    file<<canvas[i];
    //}

    file.write((char*)&*(canvas.begin()),canvas.size() * sizeof(uint8_t));
    file.close();
    exit(1);
}
