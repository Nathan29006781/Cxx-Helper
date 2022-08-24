#pragma once

struct Point;
struct Vector;

struct Position{
  double x, y, angle;

  //Constructors
    constexpr Position();
    constexpr explicit Position(Vector vector);
    constexpr Position(Point point);
    constexpr Position(Point point, double angle);
    constexpr Position(double x, double y);
    constexpr Position(double x, double y, double angle);

    constexpr Position& invert();

  //Operators
    friend constexpr Position operator* (const Position&, double);
    friend constexpr Position operator* (double, const Position&);
    friend constexpr Position operator/ (const Position&, double);
    friend constexpr Position operator/ (double, const Position&);
    constexpr bool operator== (const Position& p2) const;
    constexpr bool operator!= (const Position& p2) const;
    constexpr Position operator+ (const Position& p2) const;
    constexpr Position operator- (const Position& p2) const;
    constexpr Position operator+ (const Point& p2) const;
    constexpr Position operator- (const Point& p2) const;
    constexpr Position& operator*= (double scalar);
    constexpr Position& operator/= (double scalar);
};
