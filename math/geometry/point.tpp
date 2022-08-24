constexpr Point::Point(): x(0.0), y(0.0){}
constexpr Point::Point(Vector vector): x(vector.get_x()), y(vector.get_y()){}
constexpr Point::Point(Position position): x(position.x), y(position.y){}
constexpr Point::Point(double x, double y): x(x), y(y){}

constexpr Point& Point::invert(){
  double x = this->x, y = this->y;
  this->x = y, this->y = x;
  return *this;
}

constexpr bool Point::operator== (const Point& p2) const{
  return (x == p2.x) && (y == p2.y);
}
constexpr bool Point::operator!= (const Point& p2) const{
  return !(*this == p2);
}
constexpr Point Point::operator+ (const Point& p2) const{
  return *this - Position(p2);
}
constexpr Point Point::operator- (const Point& p2) const{
  return *this - Position(p2);
}
constexpr Point& Point::operator*= (double scalar){
  return *this = *this * scalar;
}
constexpr Point& Point::operator/= (double scalar){
  return *this = *this / scalar;
}
constexpr Point operator* (const Point& point, double scalar){
  return {point.x*scalar, point.y*scalar};
}
constexpr Point operator* (double scalar, const Point& point){
  return point*scalar;
}
constexpr Point operator/ (const Point& point, double scalar){
  return point*(1 / scalar);
}
constexpr Point operator/ (double scalar, const Point& point){
  return {scalar / point.x, scalar / point.y};
}
constexpr Position Point::operator+ (const Position& p2) const{
  return {x + p2.x, y + p2.y, p2.angle};
}
constexpr Position Point::operator- (const Position& p2) const{
  return {x - p2.x, y - p2.y, p2.angle};
}
