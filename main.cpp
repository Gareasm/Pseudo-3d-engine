#include <iostream>
#include <cstdint>
#include <SFML/Graphics.hpp>
#include "typedefs.h"
#include <math.h>
#include <string.h>

#define screenW 1000
#define screenH 1000
#define MOV_SPEED 100
#define ROT_SPEED 3
#define SHOULD_RASTERIZE 1
//decrease for better resolution; increase for performance
#define RASTER_RESOLUTION 5
#define RASTER_NUM_VERTS 4
const int MAX_VISIBLE_PLANES_CAPACITY = 200;
const int MAX_POLYGONS_PER_PLANE_CAPACITY = 20;


int screenSpaceVisiblePlanes;
ScreenSpacePoly screenSpacePolys[MAX_POLYS][MAX_VERTS];
Camera cam;
Polygon polys[MAX_POLYS];

void Init()
{
    // Camera position
    cam.camAngle = 0.0;
    cam.camPos.x = 500.0;
    cam.camPos.y = -200.0;

    // Wall at grid position (0, 0)
    polys[0].vert[0].x = 0.00;
    polys[0].vert[0].y = 0.00;
    polys[0].vert[1].x = 100.00;
    polys[0].vert[1].y = 0.00;
    polys[0].vert[2].x = 100.00;
    polys[0].vert[2].y = 100.00;
    polys[0].vert[3].x = 0.00;
    polys[0].vert[3].y = 100.00;
    polys[0].vert[4].x = 0.00;
    polys[0].vert[4].y = 0.00;
    polys[0].height = 50000;
    polys[0].vertCnt = 5;

    // Wall at grid position (1, 0)
    polys[1].vert[0].x = 100.00;
    polys[1].vert[0].y = 0.00;
    polys[1].vert[1].x = 200.00;
    polys[1].vert[1].y = 0.00;
    polys[1].vert[2].x = 200.00;
    polys[1].vert[2].y = 100.00;
    polys[1].vert[3].x = 100.00;
    polys[1].vert[3].y = 100.00;
    polys[1].vert[4].x = 100.00;
    polys[1].vert[4].y = 0.00;
    polys[1].height = 50000;
    polys[1].vertCnt = 5;

    // Wall at grid position (2, 0)
    polys[2].vert[0].x = 200.00;
    polys[2].vert[0].y = 0.00;
    polys[2].vert[1].x = 300.00;
    polys[2].vert[1].y = 0.00;
    polys[2].vert[2].x = 300.00;
    polys[2].vert[2].y = 100.00;
    polys[2].vert[3].x = 200.00;
    polys[2].vert[3].y = 100.00;
    polys[2].vert[4].x = 200.00;
    polys[2].vert[4].y = 0.00;
    polys[2].height = 50000;
    polys[2].vertCnt = 5;

    // Wall at grid position (3, 0)
    polys[3].vert[0].x = 300.00;
    polys[3].vert[0].y = 0.00;
    polys[3].vert[1].x = 400.00;
    polys[3].vert[1].y = 0.00;
    polys[3].vert[2].x = 400.00;
    polys[3].vert[2].y = 100.00;
    polys[3].vert[3].x = 300.00;
    polys[3].vert[3].y = 100.00;
    polys[3].vert[4].x = 300.00;
    polys[3].vert[4].y = 0.00;
    polys[3].height = 50000;
    polys[3].vertCnt = 5;

    // Wall at grid position (4, 0)
    polys[4].vert[0].x = 400.00;
    polys[4].vert[0].y = 0.00;
    polys[4].vert[1].x = 500.00;
    polys[4].vert[1].y = 0.00;
    polys[4].vert[2].x = 500.00;
    polys[4].vert[2].y = 100.00;
    polys[4].vert[3].x = 400.00;
    polys[4].vert[3].y = 100.00;
    polys[4].vert[4].x = 400.00;
    polys[4].vert[4].y = 0.00;
    polys[4].height = 50000;
    polys[4].vertCnt = 5;

    // Wall at grid position (5, 0)
    polys[5].vert[0].x = 500.00;
    polys[5].vert[0].y = 0.00;
    polys[5].vert[1].x = 600.00;
    polys[5].vert[1].y = 0.00;
    polys[5].vert[2].x = 600.00;
    polys[5].vert[2].y = 100.00;
    polys[5].vert[3].x = 500.00;
    polys[5].vert[3].y = 100.00;
    polys[5].vert[4].x = 500.00;
    polys[5].vert[4].y = 0.00;
    polys[5].height = 50000;
    polys[5].vertCnt = 5;

    // Wall at grid position (6, 0)
    polys[6].vert[0].x = 600.00;
    polys[6].vert[0].y = 0.00;
    polys[6].vert[1].x = 700.00;
    polys[6].vert[1].y = 0.00;
    polys[6].vert[2].x = 700.00;
    polys[6].vert[2].y = 100.00;
    polys[6].vert[3].x = 600.00;
    polys[6].vert[3].y = 100.00;
    polys[6].vert[4].x = 600.00;
    polys[6].vert[4].y = 0.00;
    polys[6].height = 50000;
    polys[6].vertCnt = 5;

    // Wall at grid position (7, 0)
    polys[7].vert[0].x = 700.00;
    polys[7].vert[0].y = 0.00;
    polys[7].vert[1].x = 800.00;
    polys[7].vert[1].y = 0.00;
    polys[7].vert[2].x = 800.00;
    polys[7].vert[2].y = 100.00;
    polys[7].vert[3].x = 700.00;
    polys[7].vert[3].y = 100.00;
    polys[7].vert[4].x = 700.00;
    polys[7].vert[4].y = 0.00;
    polys[7].height = 50000;
    polys[7].vertCnt = 5;

    // Wall at grid position (8, 0)
    polys[8].vert[0].x = 800.00;
    polys[8].vert[0].y = 0.00;
    polys[8].vert[1].x = 900.00;
    polys[8].vert[1].y = 0.00;
    polys[8].vert[2].x = 900.00;
    polys[8].vert[2].y = 100.00;
    polys[8].vert[3].x = 800.00;
    polys[8].vert[3].y = 100.00;
    polys[8].vert[4].x = 800.00;
    polys[8].vert[4].y = 0.00;
    polys[8].height = 50000;
    polys[8].vertCnt = 5;

    // Wall at grid position (9, 0)
    polys[9].vert[0].x = 900.00;
    polys[9].vert[0].y = 0.00;
    polys[9].vert[1].x = 1000.00;
    polys[9].vert[1].y = 0.00;
    polys[9].vert[2].x = 1000.00;
    polys[9].vert[2].y = 100.00;
    polys[9].vert[3].x = 900.00;
    polys[9].vert[3].y = 100.00;
    polys[9].vert[4].x = 900.00;
    polys[9].vert[4].y = 0.00;
    polys[9].height = 50000;
    polys[9].vertCnt = 5;

    // Wall at grid position (3, 3)
    polys[10].vert[0].x = 300.00;
    polys[10].vert[0].y = 300.00;
    polys[10].vert[1].x = 400.00;
    polys[10].vert[1].y = 300.00;
    polys[10].vert[2].x = 400.00;
    polys[10].vert[2].y = 400.00;
    polys[10].vert[3].x = 300.00;
    polys[10].vert[3].y = 400.00;
    polys[10].vert[4].x = 300.00;
    polys[10].vert[4].y = 300.00;
    polys[10].height = 50000;
    polys[10].vertCnt = 5;

    // Wall at grid position (4, 3)
    polys[11].vert[0].x = 400.00;
    polys[11].vert[0].y = 300.00;
    polys[11].vert[1].x = 500.00;
    polys[11].vert[1].y = 300.00;
    polys[11].vert[2].x = 500.00;
    polys[11].vert[2].y = 400.00;
    polys[11].vert[3].x = 400.00;
    polys[11].vert[3].y = 400.00;
    polys[11].vert[4].x = 400.00;
    polys[11].vert[4].y = 300.00;
    polys[11].height = 50000;
    polys[11].vertCnt = 5;

    // Wall at grid position (5, 3)
    polys[12].vert[0].x = 500.00;
    polys[12].vert[0].y = 300.00;
    polys[12].vert[1].x = 600.00;
    polys[12].vert[1].y = 300.00;
    polys[12].vert[2].x = 600.00;
    polys[12].vert[2].y = 400.00;
    polys[12].vert[3].x = 500.00;
    polys[12].vert[3].y = 400.00;
    polys[12].vert[4].x = 500.00;
    polys[12].vert[4].y = 300.00;
    polys[12].height = 50000;
    polys[12].vertCnt = 5;

    // Wall at grid position (6, 3)
    polys[13].vert[0].x = 600.00;
    polys[13].vert[0].y = 300.00;
    polys[13].vert[1].x = 700.00;
    polys[13].vert[1].y = 300.00;
    polys[13].vert[2].x = 700.00;
    polys[13].vert[2].y = 400.00;
    polys[13].vert[3].x = 600.00;
    polys[13].vert[3].y = 400.00;
    polys[13].vert[4].x = 600.00;
    polys[13].vert[4].y = 300.00;
    polys[13].height = 50000;
    polys[13].vertCnt = 5;

    // Wall at grid position (3, 6)
    polys[14].vert[0].x = 300.00;
    polys[14].vert[0].y = 600.00;
    polys[14].vert[1].x = 400.00;
    polys[14].vert[1].y = 600.00;
    polys[14].vert[2].x = 400.00;
    polys[14].vert[2].y = 700.00;
    polys[14].vert[3].x = 300.00;
    polys[14].vert[3].y = 700.00;
    polys[14].vert[4].x = 300.00;
    polys[14].vert[4].y = 600.00;
    polys[14].height = 50000;
    polys[14].vertCnt = 5;

    // Wall at grid position (4, 6)
    polys[15].vert[0].x = 400.00;
    polys[15].vert[0].y = 600.00;
    polys[15].vert[1].x = 500.00;
    polys[15].vert[1].y = 600.00;
    polys[15].vert[2].x = 500.00;
    polys[15].vert[2].y = 700.00;
    polys[15].vert[3].x = 400.00;
    polys[15].vert[3].y = 700.00;
    polys[15].vert[4].x = 400.00;
    polys[15].vert[4].y = 600.00;
    polys[15].height = 50000;
    polys[15].vertCnt = 5;

    // Wall at grid position (5, 6)
    polys[16].vert[0].x = 500.00;
    polys[16].vert[0].y = 600.00;
    polys[16].vert[1].x = 600.00;
    polys[16].vert[1].y = 600.00;
    polys[16].vert[2].x = 600.00;
    polys[16].vert[2].y = 700.00;
    polys[16].vert[3].x = 500.00;
    polys[16].vert[3].y = 700.00;
    polys[16].vert[4].x = 500.00;
    polys[16].vert[4].y = 600.00;
    polys[16].height = 50000;
    polys[16].vertCnt = 5;

    // Wall at grid position (6, 6)
    polys[17].vert[0].x = 600.00;
    polys[17].vert[0].y = 600.00;
    polys[17].vert[1].x = 700.00;
    polys[17].vert[1].y = 600.00;
    polys[17].vert[2].x = 700.00;
    polys[17].vert[2].y = 700.00;
    polys[17].vert[3].x = 600.00;
    polys[17].vert[3].y = 700.00;
    polys[17].vert[4].x = 600.00;
    polys[17].vert[4].y = 600.00;
    polys[17].height = 50000;
    polys[17].vertCnt = 5;

    // Wall at grid position (0, 9)
    polys[18].vert[0].x = 0.00;
    polys[18].vert[0].y = 900.00;
    polys[18].vert[1].x = 100.00;
    polys[18].vert[1].y = 900.00;
    polys[18].vert[2].x = 100.00;
    polys[18].vert[2].y = 1000.00;
    polys[18].vert[3].x = 0.00;
    polys[18].vert[3].y = 1000.00;
    polys[18].vert[4].x = 0.00;
    polys[18].vert[4].y = 900.00;
    polys[18].height = 50000;
    polys[18].vertCnt = 5;

    // Wall at grid position (1, 9)
    polys[19].vert[0].x = 100.00;
    polys[19].vert[0].y = 900.00;
    polys[19].vert[1].x = 200.00;
    polys[19].vert[1].y = 900.00;
    polys[19].vert[2].x = 200.00;
    polys[19].vert[2].y = 1000.00;
    polys[19].vert[3].x = 100.00;
    polys[19].vert[3].y = 1000.00;
    polys[19].vert[4].x = 100.00;
    polys[19].vert[4].y = 900.00;
    polys[19].height = 50000;
    polys[19].vertCnt = 5;

    // Wall at grid position (2, 9)
    polys[20].vert[0].x = 200.00;
    polys[20].vert[0].y = 900.00;
    polys[20].vert[1].x = 300.00;
    polys[20].vert[1].y = 900.00;
    polys[20].vert[2].x = 300.00;
    polys[20].vert[2].y = 1000.00;
    polys[20].vert[3].x = 200.00;
    polys[20].vert[3].y = 1000.00;
    polys[20].vert[4].x = 200.00;
    polys[20].vert[4].y = 900.00;
    polys[20].height = 50000;
    polys[20].vertCnt = 5;

    // Wall at grid position (3, 9)
    polys[21].vert[0].x = 300.00;
    polys[21].vert[0].y = 900.00;
    polys[21].vert[1].x = 400.00;
    polys[21].vert[1].y = 900.00;
    polys[21].vert[2].x = 400.00;
    polys[21].vert[2].y = 1000.00;
    polys[21].vert[3].x = 300.00;
    polys[21].vert[3].y = 1000.00;
    polys[21].vert[4].x = 300.00;
    polys[21].vert[4].y = 900.00;
    polys[21].height = 50000;
    polys[21].vertCnt = 5;

    // Wall at grid position (4, 9)
    polys[22].vert[0].x = 400.00;
    polys[22].vert[0].y = 900.00;
    polys[22].vert[1].x = 500.00;
    polys[22].vert[1].y = 900.00;
    polys[22].vert[2].x = 500.00;
    polys[22].vert[2].y = 1000.00;
    polys[22].vert[3].x = 400.00;
    polys[22].vert[3].y = 1000.00;
    polys[22].vert[4].x = 400.00;
    polys[22].vert[4].y = 900.00;
    polys[22].height = 50000;
    polys[22].vertCnt = 5;

    // Wall at grid position (5, 9)
    polys[23].vert[0].x = 500.00;
    polys[23].vert[0].y = 900.00;
    polys[23].vert[1].x = 600.00;
    polys[23].vert[1].y = 900.00;
    polys[23].vert[2].x = 600.00;
    polys[23].vert[2].y = 1000.00;
    polys[23].vert[3].x = 500.00;
    polys[23].vert[3].y = 1000.00;
    polys[23].vert[4].x = 500.00;
    polys[23].vert[4].y = 900.00;
    polys[23].height = 50000;
    polys[23].vertCnt = 5;

    // Wall at grid position (6, 9)
    polys[24].vert[0].x = 600.00;
    polys[24].vert[0].y = 900.00;
    polys[24].vert[1].x = 700.00;
    polys[24].vert[1].y = 900.00;
    polys[24].vert[2].x = 700.00;
    polys[24].vert[2].y = 1000.00;
    polys[24].vert[3].x = 600.00;
    polys[24].vert[3].y = 1000.00;
    polys[24].vert[4].x = 600.00;
    polys[24].vert[4].y = 900.00;
    polys[24].height = 50000;
    polys[24].vertCnt = 5;

    // Wall at grid position (7, 9)
    polys[25].vert[0].x = 700.00;
    polys[25].vert[0].y = 900.00;
    polys[25].vert[1].x = 800.00;
    polys[25].vert[1].y = 900.00;
    polys[25].vert[2].x = 800.00;
    polys[25].vert[2].y = 1000.00;
    polys[25].vert[3].x = 700.00;
    polys[25].vert[3].y = 1000.00;
    polys[25].vert[4].x = 700.00;
    polys[25].vert[4].y = 900.00;
    polys[25].height = 50000;
    polys[25].vertCnt = 5;

    // Wall at grid position (8, 9)
    polys[26].vert[0].x = 800.00;
    polys[26].vert[0].y = 900.00;
    polys[26].vert[1].x = 900.00;
    polys[26].vert[1].y = 900.00;
    polys[26].vert[2].x = 900.00;
    polys[26].vert[2].y = 1000.00;
    polys[26].vert[3].x = 800.00;
    polys[26].vert[3].y = 1000.00;
    polys[26].vert[4].x = 800.00;
    polys[26].vert[4].y = 900.00;
    polys[26].height = 50000;
    polys[26].vertCnt = 5;

    // Wall at grid position (9, 9)
    polys[27].vert[0].x = 900.00;
    polys[27].vert[0].y = 900.00;
    polys[27].vert[1].x = 1000.00;
    polys[27].vert[1].y = 900.00;
    polys[27].vert[2].x = 1000.00;
    polys[27].vert[2].y = 1000.00;
    polys[27].vert[3].x = 900.00;
    polys[27].vert[3].y = 1000.00;
    polys[27].vert[4].x = 900.00;
    polys[27].vert[4].y = 900.00;
    polys[27].height = 50000;
    polys[27].vertCnt = 5;

    // Total polygons created: 28
    // Camera: (500, -200), Winding: CW
    // Note: Your near-plane clipping is set to 5.0f units
    // Objects closer than 5 units to camera will be clipped
}

void InitSafe()
{

    cam.camAngle = 0.42;

    cam.camPos.x = 451.96;

    cam.camPos.y = 209.24;



    polys[0].vert[0].x = 141.00;

    polys[0].vert[0].y = 84.00;

    polys[0].vert[1].x = 496.00;

    polys[0].vert[1].y = 81.00;

    polys[0].vert[2].x = 553.00;

    polys[0].vert[2].y = 136.00;

    polys[0].vert[3].x = 135.00;

    polys[0].vert[3].y = 132.00;

    polys[0].vert[4].x = 141.00;

    polys[0].vert[4].y = 84.00;

    polys[0].height = 50000;

    polys[0].vertCnt = 5;

    polys[1].vert[0].x = 133.00;

    polys[1].vert[0].y = 441.00;

    polys[1].vert[1].x = 576.00;

    polys[1].vert[1].y = 438.00;

    polys[1].vert[2].x = 519.00;

    polys[1].vert[2].y = 493.00;

    polys[1].vert[3].x = 123.00;

    polys[1].vert[3].y = 497.00;

    polys[1].vert[4].x = 133.00;

    polys[1].vert[4].y = 441.00;

    polys[1].height = 50000;

    polys[1].vertCnt = 5;

    polys[2].vert[0].x = 691.00;

    polys[2].vert[0].y = 165.00;

    polys[2].vert[1].x = 736.00;

    polys[2].vert[1].y = 183.00;

    polys[2].vert[2].x = 737.00;

    polys[2].vert[2].y = 229.00;

    polys[2].vert[3].x = 697.00;

    polys[2].vert[3].y = 247.00;

    polys[2].vert[4].x = 656.00;

    polys[2].vert[4].y = 222.00;

    polys[2].vert[5].x = 653.00;

    polys[2].vert[5].y = 183.00;

    polys[2].vert[6].x = 691.00;

    polys[2].vert[6].y = 165.00;

    polys[2].height = 10000;

    polys[2].vertCnt = 7;

    polys[3].vert[0].x = 698.00;

    polys[3].vert[0].y = 330.00;

    polys[3].vert[1].x = 741.00;

    polys[3].vert[1].y = 350.00;

    polys[3].vert[2].x = 740.00;

    polys[3].vert[2].y = 392.00;

    polys[3].vert[3].x = 699.00;

    polys[3].vert[3].y = 414.00;

    polys[3].vert[4].x = 654.00;

    polys[3].vert[4].y = 384.00;

    polys[3].vert[5].x = 652.00;

    polys[3].vert[5].y = 348.00;

    polys[3].vert[6].x = 698.00;

    polys[3].vert[6].y = 330.00;

    polys[3].height = 10000;

    polys[3].vertCnt = 7;

    polys[4].vert[0].x = 419.00;

    polys[4].vert[0].y = 311.00;

    polys[4].vert[1].x = 461.00;

    polys[4].vert[1].y = 311.00;

    polys[4].vert[2].x = 404.00;

    polys[4].vert[2].y = 397.00;

    polys[4].vert[3].x = 346.00;

    polys[4].vert[3].y = 395.00;

    polys[4].vert[4].x = 348.00;

    polys[4].vert[4].y = 337.00;

    polys[4].vert[5].x = 419.00;

    polys[4].vert[5].y = 311.00;

    polys[4].height = 50000;

    polys[4].vertCnt = 6;

    polys[5].vert[0].x = 897.00;

    polys[5].vert[0].y = 98.00;

    polys[5].vert[1].x = 1079.00;

    polys[5].vert[1].y = 294.00;

    polys[5].vert[2].x = 1028.00;

    polys[5].vert[2].y = 297.00;

    polys[5].vert[3].x = 851.00;

    polys[5].vert[3].y = 96.00;

    polys[5].vert[4].x = 897.00;

    polys[5].vert[4].y = 98.00;

    polys[5].height = 10000;

    polys[5].vertCnt = 5;

    polys[6].vert[0].x = 1025.00;

    polys[6].vert[0].y = 294.00;

    polys[6].vert[1].x = 1080.00;

    polys[6].vert[1].y = 292.00;

    polys[6].vert[2].x = 1149.00;

    polys[6].vert[2].y = 485.00;

    polys[6].vert[3].x = 1072.00;

    polys[6].vert[3].y = 485.00;

    polys[6].vert[4].x = 1025.00;

    polys[6].vert[4].y = 294.00;

    polys[6].height = 1000;

    polys[6].vertCnt = 5;

    polys[7].vert[0].x = 1070.00;

    polys[7].vert[0].y = 483.00;

    polys[7].vert[1].x = 1148.00;

    polys[7].vert[1].y = 484.00;

    polys[7].vert[2].x = 913.00;

    polys[7].vert[2].y = 717.00;

    polys[7].vert[3].x = 847.00;

    polys[7].vert[3].y = 718.00;

    polys[7].vert[4].x = 1070.00;

    polys[7].vert[4].y = 483.00;

    polys[7].height = 1000;

    polys[7].vertCnt = 5;

    polys[8].vert[0].x = 690.00;

    polys[8].vert[0].y = 658.00;

    polys[8].vert[1].x = 807.00;

    polys[8].vert[1].y = 789.00;

    polys[8].vert[2].x = 564.00;

    polys[8].vert[2].y = 789.00;

    polys[8].vert[3].x = 690.00;

    polys[8].vert[3].y = 658.00;

    polys[8].height = 10000;

    polys[8].vertCnt = 4;

    polys[9].vert[0].x = 1306.00;

    polys[9].vert[0].y = 598.00;

    polys[9].vert[1].x = 1366.00;

    polys[9].vert[1].y = 624.00;

    polys[9].vert[2].x = 1369.00;

    polys[9].vert[2].y = 678.00;

    polys[9].vert[3].x = 1306.00;

    polys[9].vert[3].y = 713.00;

    polys[9].vert[4].x = 1245.00;

    polys[9].vert[4].y = 673.00;

    polys[9].vert[5].x = 1242.00;

    polys[9].vert[5].y = 623.00;

    polys[9].vert[6].x = 1306.00;

    polys[9].vert[6].y = 598.00;

    polys[9].height = 50000;

    polys[9].vertCnt = 7;
}
void safeInit()
{

    cam.camAngle = 0.42;

    cam.camPos.x = 451.96;

    cam.camPos.y = 209.24;



    polys[0].vert[0].x = 141.00;

    polys[0].vert[0].y = 84.00;

    polys[0].vert[1].x = 496.00;

    polys[0].vert[1].y = 81.00;

    polys[0].vert[2].x = 553.00;

    polys[0].vert[2].y = 136.00;

    polys[0].vert[3].x = 135.00;

    polys[0].vert[3].y = 132.00;

    polys[0].vert[4].x = 141.00;

    polys[0].vert[4].y = 84.00;

    polys[0].height = 50000;

    polys[0].vertCnt = 5;

    polys[1].vert[0].x = 133.00;

    polys[1].vert[0].y = 441.00;

    polys[1].vert[1].x = 576.00;

    polys[1].vert[1].y = 438.00;

    polys[1].vert[2].x = 519.00;

    polys[1].vert[2].y = 493.00;

    polys[1].vert[3].x = 123.00;

    polys[1].vert[3].y = 497.00;

    polys[1].vert[4].x = 133.00;

    polys[1].vert[4].y = 441.00;

    polys[1].height = 50000;

    polys[1].vertCnt = 5;

    polys[2].vert[0].x = 691.00;

    polys[2].vert[0].y = 165.00;

    polys[2].vert[1].x = 736.00;

    polys[2].vert[1].y = 183.00;

    polys[2].vert[2].x = 737.00;

    polys[2].vert[2].y = 229.00;

    polys[2].vert[3].x = 697.00;

    polys[2].vert[3].y = 247.00;

    polys[2].vert[4].x = 656.00;

    polys[2].vert[4].y = 222.00;

    polys[2].vert[5].x = 653.00;

    polys[2].vert[5].y = 183.00;

    polys[2].vert[6].x = 691.00;

    polys[2].vert[6].y = 165.00;

    polys[2].height = 10000;

    polys[2].vertCnt = 7;

    polys[3].vert[0].x = 698.00;

    polys[3].vert[0].y = 330.00;

    polys[3].vert[1].x = 741.00;

    polys[3].vert[1].y = 350.00;

    polys[3].vert[2].x = 740.00;

    polys[3].vert[2].y = 392.00;

    polys[3].vert[3].x = 699.00;

    polys[3].vert[3].y = 414.00;

    polys[3].vert[4].x = 654.00;

    polys[3].vert[4].y = 384.00;

    polys[3].vert[5].x = 652.00;

    polys[3].vert[5].y = 348.00;

    polys[3].vert[6].x = 698.00;

    polys[3].vert[6].y = 330.00;

    polys[3].height = 10000;

    polys[3].vertCnt = 7;

    polys[4].vert[0].x = 419.00;

    polys[4].vert[0].y = 311.00;

    polys[4].vert[1].x = 461.00;

    polys[4].vert[1].y = 311.00;

    polys[4].vert[2].x = 404.00;

    polys[4].vert[2].y = 397.00;

    polys[4].vert[3].x = 346.00;

    polys[4].vert[3].y = 395.00;

    polys[4].vert[4].x = 348.00;

    polys[4].vert[4].y = 337.00;

    polys[4].vert[5].x = 419.00;

    polys[4].vert[5].y = 311.00;

    polys[4].height = 50000;

    polys[4].vertCnt = 6;

    polys[5].vert[0].x = 897.00;

    polys[5].vert[0].y = 98.00;

    polys[5].vert[1].x = 1079.00;

    polys[5].vert[1].y = 294.00;

    polys[5].vert[2].x = 1028.00;

    polys[5].vert[2].y = 297.00;

    polys[5].vert[3].x = 851.00;

    polys[5].vert[3].y = 96.00;

    polys[5].vert[4].x = 897.00;

    polys[5].vert[4].y = 98.00;

    polys[5].height = 10000;

    polys[5].vertCnt = 5;

    polys[6].vert[0].x = 1025.00;

    polys[6].vert[0].y = 294.00;

    polys[6].vert[1].x = 1080.00;

    polys[6].vert[1].y = 292.00;

    polys[6].vert[2].x = 1149.00;

    polys[6].vert[2].y = 485.00;

    polys[6].vert[3].x = 1072.00;

    polys[6].vert[3].y = 485.00;

    polys[6].vert[4].x = 1025.00;

    polys[6].vert[4].y = 294.00;

    polys[6].height = 1000;

    polys[6].vertCnt = 5;

    polys[7].vert[0].x = 1070.00;

    polys[7].vert[0].y = 483.00;

    polys[7].vert[1].x = 1148.00;

    polys[7].vert[1].y = 484.00;

    polys[7].vert[2].x = 913.00;

    polys[7].vert[2].y = 717.00;

    polys[7].vert[3].x = 847.00;

    polys[7].vert[3].y = 718.00;

    polys[7].vert[4].x = 1070.00;

    polys[7].vert[4].y = 483.00;

    polys[7].height = 1000;

    polys[7].vertCnt = 5;

    polys[8].vert[0].x = 690.00;

    polys[8].vert[0].y = 658.00;

    polys[8].vert[1].x = 807.00;

    polys[8].vert[1].y = 789.00;

    polys[8].vert[2].x = 564.00;

    polys[8].vert[2].y = 789.00;

    polys[8].vert[3].x = 690.00;

    polys[8].vert[3].y = 658.00;

    polys[8].height = 10000;

    polys[8].vertCnt = 4;

    polys[9].vert[0].x = 1306.00;

    polys[9].vert[0].y = 598.00;

    polys[9].vert[1].x = 1366.00;

    polys[9].vert[1].y = 624.00;

    polys[9].vert[2].x = 1369.00;

    polys[9].vert[2].y = 678.00;

    polys[9].vert[3].x = 1306.00;

    polys[9].vert[3].y = 713.00;

    polys[9].vert[4].x = 1245.00;

    polys[9].vert[4].y = 673.00;

    polys[9].vert[5].x = 1242.00;

    polys[9].vert[5].y = 623.00;

    polys[9].vert[6].x = 1306.00;

    polys[9].vert[6].y = 598.00;

    polys[9].height = 50000;

    polys[9].vertCnt = 7;

}
void PutPixel(float x, float y, std::uint8_t r, std::uint8_t g, std::uint8_t b,sf::RenderWindow &window ) {
    if (x > screenW || y > screenH) {
        return;
    }
    if (x < 0  || y < 0) {
        return;
    }
    sf::Vertex pixel(sf::Vector2f(x, y), sf::Color(r, g, b, 255));
    window.draw(&pixel, 1, sf::Points);

}
void DrawLine(int x0, int y0, int x1, int y1, sf::RenderWindow& window) {
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(x0, y0);
    line[1].position = sf::Vector2f(x1, y1);
    line[0].color = sf::Color::White;
    line[1].color = sf::Color::White;
    window.draw(line);

}
void DrawLineM(int x0, int y0, int x1, int y1, sf::RenderWindow& window)
{
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    for (;;)
    {
        PutPixel(x0, y0, 255, 255, 255, window);

        if (x0 == x1 && y0 == y1)
            break;

        e2 = err;

        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}
float Cross2dPoints(float x1, float y1, float x2, float y2)
{

    return x1 * y2 - y1 * x2;

}
Vec2 Intersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    // Helper lambda to compute 2D cross product of two vectors
    auto cross2D = [](float a1, float a2, float b1, float b2) -> float {
        return a1 * b2 - a2 * b1;
    };

    Vec2 p;

    float A = cross2D(x1, y1, x2, y2);
    float B = cross2D(x3, y3, x4, y4);
    float denominator = cross2D(x1 - x2, y1 - y2, x3 - x4, y3 - y4);

    // Avoid division by zero (parallel lines)
    constexpr float epsilon = 1e-6f;
    if (std::abs(denominator) < epsilon) {
        // Return invalid point or handle differently
        return { NAN, NAN };
    }

    p.x = cross2D(A, x1 - x2, B, x3 - x4) / denominator;
    p.y = cross2D(A, y1 - y2, B, y3 - y4) / denominator;

    return p;
}
int IsFrontFace(const Vec2& camera, Vec2 pointA, Vec2 pointB)
{
    // Translate points relative to the camera
    pointA.x -= camera.x;
    pointA.y -= camera.y;
    pointB.x -= camera.x;
    pointB.y -= camera.y;

    // 2D cross product to determine facing
    int crossProduct = static_cast<int>(pointA.x * pointB.y - pointA.y * pointB.x);

    if (crossProduct > 0)
        return 1;

    if (crossProduct < 0)
        return -1;

    return 0;
}
void CameraTranslate(double deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        cam.camPos.x += MOV_SPEED * std::cos(cam.camAngle) * deltaTime;
        cam.camPos.y += MOV_SPEED * std::sin(cam.camAngle) * deltaTime;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cam.camPos.x -= MOV_SPEED * std::cos(cam.camAngle) * deltaTime;
        cam.camPos.y -= MOV_SPEED * std::sin(cam.camAngle) * deltaTime;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        cam.camAngle -= ROT_SPEED * deltaTime;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        cam.camAngle += ROT_SPEED * deltaTime;
    }
}
//todo rast
int PointInPoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
    int i, j, isPointInside = 0;
    for (i = 0, j = nvert-1; i < nvert; j = i++)
    {
        int isSameCoordinates = 0;
        if ((verty[i]>testy) == (verty[j]>testy))
            isSameCoordinates = 1;
        if (isSameCoordinates == 0 &&
            (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]))
        {
            isPointInside = !isPointInside;
        }
    }
    return isPointInside;
}
void ClearRasterBuffer()
{
    for (int polyIdx = 0; polyIdx < MAX_POLYS; polyIdx++)
    {
        for (int i = 0; i < polys[polyIdx].vertCnt; i++)
        {
            for (int vn = 0; vn < RASTER_NUM_VERTS; vn++)
            {
                screenSpacePolys[polyIdx][i].vert[vn].x = 0;
                screenSpacePolys[polyIdx][i].vert[vn].y = 0;
            }
        }
    }
}
void Rasterize(sf::RenderWindow &window)
{
    float vx[4];
    float vy[4];

    // Pixel buffer to prevent overdraw
    std::uint8_t pixelBuff[screenH][screenW];
    memset(pixelBuff, 0, sizeof(pixelBuff));

    // Process each polygon that has visible edges
    for (int polyIdx = 0; polyIdx < MAX_POLYS; polyIdx++) {
        const auto& poly = polys[polyIdx];

        // Look for valid edges in this polygon
        for (int edgeIdx = 0; edgeIdx < poly.vertCnt - 1; edgeIdx++) {
            // Check if this edge has valid screen space data
            if (screenSpacePolys[polyIdx][edgeIdx].vert[0].x == 0 &&
                screenSpacePolys[polyIdx][edgeIdx].vert[0].y == 0) {
                continue; // Skip invalid/unset edges
                }

            // Extract the quad vertices for this edge
            for (int nextv = 0; nextv < RASTER_NUM_VERTS; nextv++) {
                vx[nextv] = screenSpacePolys[polyIdx][edgeIdx].vert[nextv].x;
                vy[nextv] = screenSpacePolys[polyIdx][edgeIdx].vert[nextv].y;
            }

            // Rasterize this quad
            for (int y = 0; y < screenH; y += RASTER_RESOLUTION) {
                for (int x = 0; x < screenW; x += 1) {
                    // Skip if pixel already drawn
                    if (pixelBuff[y][x] == 1)
                        continue;

                    // Check if point is inside polygon
                    if (PointInPoly(RASTER_NUM_VERTS, vx, vy, x, y) == 1) {
                        PutPixel(x, y, 100, 255, 0, window);
                        pixelBuff[y][x] = 1;
                    }
                }
            }
        }
    }
}

void Renderdb(sf::RenderWindow& window) {

    ClearRasterBuffer();
    for (int polyIdx = 0; polyIdx < MAX_POLYS; ++polyIdx) {
        const auto& poly = polys[polyIdx];
        bool polyHasVisibleEdges = false;

        for (int i = 0; i < poly.vertCnt - 1; ++i) {
            Vec2 p1 = poly.vert[i];
            Vec2 p2 = poly.vert[i + 1];
            float height = -poly.height;



            // World space to camera space
            float dx1 = p1.x - cam.camPos.x;
            float dy1 = p1.y - cam.camPos.y;
            float dx2 = p2.x - cam.camPos.x;
            float dy2 = p2.y - cam.camPos.y;

            float z1 = dx1 * std::cos(cam.camAngle) + dy1 * std::sin(cam.camAngle);
            float z2 = dx2 * std::cos(cam.camAngle) + dy2 * std::sin(cam.camAngle);

            dx1 = dx1 * std::sin(cam.camAngle) - dy1 * std::cos(cam.camAngle);
            dx2 = dx2 * std::sin(cam.camAngle) - dy2 * std::cos(cam.camAngle);

            // Near-plane clipping logic
            if (z1 > 0 || z2 > 0) {
                Vec2 i1 = Intersection(dx1, z1, dx2, z2, -0.0001f, 0.0001f, -20.0f, 5.0f);
                Vec2 i2 = Intersection(dx1, z1, dx2, z2,  0.0001f, 0.0001f,  20.0f, 5.0f);

                if (z1 <= 0) {
                    if (i1.y > 0) {
                        dx1 = i1.x;
                        z1 = i1.y;
                    } else {
                        dx1 = i2.x;
                        z1 = i2.y;
                    }
                }

                if (z2 <= 0) {
                    if (i1.y > 0) {
                        dx2 = i1.x;
                        z2 = i1.y;
                    } else {
                        dx2 = i2.x;
                        z2 = i2.y;
                    }
                }
            } else {
                continue;
            }

            // Perspective projection
            const float widthRatio = screenW / 2.0f;
            const float heightRatio = (screenW * screenH) / 60.0f;
            const float centerH = screenH / 2.0f;
            const float centerW = screenW / 2.0f;

            float projX1 = -dx1 * widthRatio / z1;
            float projX2 = -dx2 * widthRatio / z2;

            float y1a = (height - heightRatio) / z1;
            float y1b = heightRatio / z1;
            float y2a = (height - heightRatio) / z2;
            float y2b = heightRatio / z2;

            // Render vertical wall edges
            DrawLine(centerW + projX1, centerH + y1a, centerW + projX2, centerH + y2a, window);
            DrawLine(centerW + projX1, centerH + y1b, centerW + projX2, centerH + y2b, window);

            // Render top and bottom edges
            DrawLine(centerW + projX1, centerH + y1a, centerW + projX1, centerH + y1b, window);
            DrawLine(centerW + projX2, centerH + y2a, centerW + projX2, centerH + y2b, window);



        }

        // Only increment visible planes counter once per polygon that has visible edges

    }

    if (SHOULD_RASTERIZE == 1)
        Rasterize(window);
}
void Render(sf::RenderWindow& window) {
    if (SHOULD_RASTERIZE == 1)
    {
        ClearRasterBuffer();
        screenSpaceVisiblePlanes = 0;
    }

    for (int polyIdx = 0; polyIdx < MAX_POLYS; ++polyIdx) {
        const auto& poly = polys[polyIdx];
        bool polyHasVisibleEdges = false;

        for (int i = 0; i < poly.vertCnt - 1; ++i) {
            Vec2 p1 = poly.vert[i];
            Vec2 p2 = poly.vert[i + 1];
            float height = -poly.height;

            if (IsFrontFace(cam.camPos , p1, p2) > 0)
                continue;

            // World space to camera space
            float dx1 = p1.x - cam.camPos.x;
            float dy1 = p1.y - cam.camPos.y;
            float dx2 = p2.x - cam.camPos.x;
            float dy2 = p2.y - cam.camPos.y;

            float z1 = dx1 * std::cos(cam.camAngle) + dy1 * std::sin(cam.camAngle);
            float z2 = dx2 * std::cos(cam.camAngle) + dy2 * std::sin(cam.camAngle);

            dx1 = dx1 * std::sin(cam.camAngle) - dy1 * std::cos(cam.camAngle);
            dx2 = dx2 * std::sin(cam.camAngle) - dy2 * std::cos(cam.camAngle);

            // Near-plane clipping logic
            if (z1 > 0 || z2 > 0) {
                Vec2 i1 = Intersection(dx1, z1, dx2, z2, -0.0001f, 0.0001f, -20.0f, 0.1f);
                Vec2 i2 = Intersection(dx1, z1, dx2, z2,  0.0001f, 0.0001f,  20.0f, 0.1f);

                if (z1 <= 0) {
                    if (i1.y > 0) {
                        dx1 = i1.x;
                        z1 = i1.y;
                    } else {
                        dx1 = i2.x;
                        z1 = i2.y;
                    }
                }

                if (z2 <= 0) {
                    if (i1.y > 0) {
                        dx2 = i1.x;
                        z2 = i1.y;
                    } else {
                        dx2 = i2.x;
                        z2 = i2.y;
                    }
                }
            } else {
                continue;
            }

            // Perspective projection
            const float widthRatio = screenW / 2.0f;
            const float heightRatio = (screenW * screenH) / 60.0f;
            const float centerH = screenH / 2.0f;
            const float centerW = screenW / 2.0f;

            float projX1 = -dx1 * widthRatio / z1;
            float projX2 = -dx2 * widthRatio / z2;

            float y1a = (height - heightRatio) / z1;
            float y1b = heightRatio / z1;
            float y2a = (height - heightRatio) / z2;
            float y2b = heightRatio / z2;

            // Render vertical wall edges
            DrawLine(centerW + projX1, centerH + y1a, centerW + projX2, centerH + y2a, window);
            DrawLine(centerW + projX1, centerH + y1b, centerW + projX2, centerH + y2b, window);

            // Render top and bottom edges
            DrawLine(centerW + projX1, centerH + y1a, centerW + projX1, centerH + y1b, window);
            DrawLine(centerW + projX2, centerH + y2a, centerW + projX2, centerH + y2b, window);

            if (SHOULD_RASTERIZE == 1)
            {
                // FIXED: Use polyIdx as first index, i as second index
                screenSpacePolys[polyIdx][i].vert[0].x = centerW + projX2;
                screenSpacePolys[polyIdx][i].vert[0].y = centerH + y2a;
                screenSpacePolys[polyIdx][i].vert[1].x = centerW + projX1;
                screenSpacePolys[polyIdx][i].vert[1].y = centerH + y1a;
                screenSpacePolys[polyIdx][i].vert[2].x = centerW + projX1;
                screenSpacePolys[polyIdx][i].vert[2].y = centerH + y1b;
                screenSpacePolys[polyIdx][i].vert[3].x = centerW + projX2;
                screenSpacePolys[polyIdx][i].vert[3].y = centerH + y2b;

                screenSpacePolys[polyIdx][i].planeIdInPoly = i;

                if (!polyHasVisibleEdges) {
                    polyHasVisibleEdges = true;
                }
            }
        }

        // Only increment visible planes counter once per polygon that has visible edges
        if (SHOULD_RASTERIZE == 1 && polyHasVisibleEdges) {
            screenSpaceVisiblePlanes++;
        }
    }

    if (SHOULD_RASTERIZE == 1)
        Rasterize(window);
}




int main() {
    Init();
    bool dbRend = false;
    double deltaTime;
    sf::Clock clk;
    sf::RenderWindow window(sf::VideoMode(screenW, screenH), "Pseudo 3D");
    window.setFramerateLimit(60);
    // Main loop
    while (window.isOpen()){
        window.clear();
        double start = clk.getElapsedTime().asMilliseconds();
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            dbRend = !dbRend;
        }
        if(dbRend) {
          Renderdb(window);
        }
        else {
            Render(window);
        }
        CameraTranslate(deltaTime);


        window.display();

        double end = clk.getElapsedTime().asMilliseconds();
        deltaTime = (end - start) / 1000.0;
    }


    return 0;
}
