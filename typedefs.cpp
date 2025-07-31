#include "typedefs.h"

// Vec2 definitions
Vec2::Vec2() : x(0.0f), y(0.0f) {}
Vec2::Vec2(float x_val, float y_val) : x(x_val), y(y_val) {}

// LineSeg definitions
LineSeg::LineSeg(const Vec2& p_start, const Vec2& p_end) : p1(p_start), p2(p_end) {}

// Polygon definitions
Polygon::Polygon() : vertCnt(0), height(0.0f), curDist(0.0f) {}
Polygon::Polygon(int count, float h, float dist)
    : vertCnt(count), height(h), curDist(dist) {}

// ScreenSpacePoly definitions
ScreenSpacePoly::ScreenSpacePoly() : distFromCamera(0.0f), planeIdInPoly(0) {}
ScreenSpacePoly::ScreenSpacePoly(float dist, int id)
    : distFromCamera(dist), planeIdInPoly(id) {}

Camera::Camera(float angle, float wave, Vec2 pos) : camAngle(angle), stepWave(wave), camPos(pos), oldCamPos(pos){}


