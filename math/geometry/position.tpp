constexpr Position::Position(): x(0.0), y(0.0), angle(0.0){}
constexpr Position::Position(Vector vector): x(vector.get_x()), y(vector.get_y()), angle(0.0){}
constexpr Position::Position(Point point): x(point.x), y(point.y), angle(0.0){}
constexpr Position::Position(Point point, double angle): x(point.x), y(point.y), angle(angle){}
constexpr Position::Position(double x, double y): x(x), y(y), angle(0.0){}
constexpr Position::Position(double x, double y, double angle): x(x), y(y), angle(angle){}


constexpr Position& Position::invert(){
  double x = this->x, y = this->y;
  this->x = y, this->y = x;
  angle = M_PI_2 - angle;
  return *this;
}

constexpr Position operator* (const Position& position, double scalar){
  return {position.x*scalar, position.y*scalar, position.angle*scalar};
}
constexpr Position operator* (double scalar, const Position& position){
  return position*scalar;
}
constexpr Position operator/ (const Position& position, double scalar){
  return position * (1 / scalar);
}
constexpr Position operator/ (double scalar, const Position& position){
  return {position.x / scalar, position.y / scalar, position.angle / scalar};
}
constexpr bool Position::operator== (const Position& p2) const{
  return (x == p2.x) && (y == p2.y) && (angle == p2.angle);
}
constexpr bool Position::operator!= (const Position& p2) const{
  return !(*this == p2);
}
constexpr Position Position::operator+ (const Position& p2) const{
  return {x + p2.x, y + p2.y, angle + p2.angle};
}
constexpr Position Position::operator- (const Position& p2) const{
  return {x - p2.x, y - p2.y, angle - p2.angle};
}
constexpr Position Position::operator+ (const Point& p2) const{
  return *this + Position(p2);
}
constexpr Position Position::operator- (const Point& p2) const{
  return *this + Position(p2);
}
constexpr Position& Position::operator*= (double scalar){
  return *this = *this * scalar;
}
constexpr Position& Position::operator/= (double scalar){
  return *this = *this / scalar;
}