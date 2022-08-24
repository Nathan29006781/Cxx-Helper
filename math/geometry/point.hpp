#pragma once

struct Position;
struct Vector;

struct Point{
  double x, y;
  
  //Constructors
    constexpr Point();
    constexpr explicit Point(Vector vector);
    constexpr Point(Position position);
    constexpr Point(double x, double y);

  //Methods
    constexpr Point& invert();
  
  //Operators
    friend constexpr Point operator* (const Point&, double);
    friend constexpr Point operator* (double, const Point&);
    friend constexpr Point operator/ (const Point&, double);
    friend constexpr Point operator/ (double, const Point&);
    constexpr bool operator== (const Point& p2) const;
    constexpr bool operator!= (const Point& p2) const;
    constexpr Point operator+ (const Point& p2) const;
    constexpr Point operator- (const Point& p2) const;
    constexpr Position operator+ (const Position& p2) const;
    constexpr Position operator- (const Position& p2) const;
    constexpr Point& operator*= (double scalar);
    constexpr Point& operator/= (double scalar);
};
