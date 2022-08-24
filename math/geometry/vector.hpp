#pragma once

struct Point;
struct Position;

struct Vector{
  private:
    double x, y, magnitude, angle;

  public:
    //Constructors
      constexpr Vector();
      constexpr explicit Vector(Point p1);
      constexpr explicit Vector(Point p1, Point p2); //Can't use default argument with previous because that makes it -p2

    //Methods
      constexpr Vector& set_cartesian(Point point);
      constexpr Vector& set_cartesian(Point p2, Point p1);
      constexpr Vector& set_cartesian(double x, double y);
      constexpr Vector& set_polar(double magnitude, double angle);
      constexpr Vector& invert();
      constexpr Vector& rotate(double angle);
      static constexpr Vector make_cartesian(Point point);
      static constexpr Vector make_cartesian(Point p2, Point p1);
      static constexpr Vector make_cartesian(double x, double y);
      static constexpr Vector make_polar(double magnitude, double angle);

    //Operators
      friend constexpr Vector operator* (double, const Vector&);
      friend constexpr Vector operator/ (double, const Vector&);
      constexpr Vector operator* (double) const;
      constexpr Vector operator/ (double) const;
      constexpr bool operator== (const Vector& p2) const;
      constexpr bool operator!= (const Vector& p2) const;
      constexpr Vector operator+ (const Vector& p2) const;
      constexpr Vector operator- (const Vector& p2) const;
      constexpr Vector& operator*= (double scalar);
      constexpr Vector& operator/= (double scalar);
      constexpr double operator* (const Vector& p2) const; //Dot product

    //Getters
      constexpr double get_x() const;
      constexpr double get_y() const;
      constexpr double get_magnitude() const;
      constexpr double get_angle() const;
};