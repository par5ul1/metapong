#pragma once
#import <cmath>

template <typename T>
struct Vector2 {
    T x;
    T y;
};

template <typename T>
struct Vector3 {
    T x;
    T y;
    T z;
};

template <typename T>
float magnitude(Vector2<T> vector) {
    return sqrt(vector.x * vector.x + vector.y * vector.y);
};
