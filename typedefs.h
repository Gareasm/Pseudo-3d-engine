#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#pragma once

#include <array> // For std::array

// Using constexpr for compile-time constants
constexpr int MAX_POLYS = 100;
constexpr int MAX_VERTS = 8;

// Vec2 struct
struct Vec2 {
    float x;
    float y;

    // Default constructor
    Vec2();

    // Constructor with initializers
    Vec2(float x_val, float y_val);
};

// LineSeg struct
struct LineSeg {
    Vec2 p1;
    Vec2 p2;

    // Default constructor
    LineSeg() = default;

    // Constructor with initializers
    LineSeg(const Vec2& p_start, const Vec2& p_end);
};

// Polygon struct
struct Polygon {
    std::array<Vec2, MAX_VERTS> vert;
    int vertCnt;
    float height;
    float curDist;

    // Default constructor
    Polygon();

    // Constructor with initializers
    Polygon(int count, float h, float dist);
};

// ScreenSpacePoly struct
struct ScreenSpacePoly {
    std::array<Vec2, 4> vert;
    float distFromCamera;
    int planeIdInPoly;

    // Default constructor
    ScreenSpacePoly();

    // Constructor with initializers
    ScreenSpacePoly(float dist, int id);
};
struct Camera{
    float camAngle;
    float stepWave;
    Vec2 camPos;
    Vec2 oldCamPos;
    Camera(float angle = 0.0f, float wave = 0.0f, Vec2 pos = Vec2(0.0f, 0.0f));
};

#endif //TYPEDEFS_H
