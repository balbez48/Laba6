#include <iostream>
#include <cmath>
#pragma once

class Point2D {
public:
    double x, y;

    Point2D(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void show() {
        std::cout << "{" << x << ";" << y << "}" << std::endl;
    }
};


class Point3D : public Point2D {
public:
    double z;

    Point3D(double x, double y, double z) : Point2D(x, y) {
        this->z = z;
    }

    void show() {
        std::cout << "{" << x << ";" << y << ";" << z << "}" << std::endl;
    }

    double distance(Point3D other) {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
};