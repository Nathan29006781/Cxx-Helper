template <std::floating_point R> constexpr Position<R>::Position(): x(0.0), y(0.0), angle(0.0){}
template <std::floating_point R> constexpr Position<R>::Position(Vector<R> vector): x(vector.get_x()), y(vector.get_y()), angle(0.0){}
template <std::floating_point R> constexpr Position<R>::Position(Point<R> point): x(point.x), y(point.y), angle(0.0){}
template <std::floating_point R> constexpr Position<R>::Position(Point<R> point, double angle): x(point.x), y(point.y), angle(angle){}
template <std::floating_point R> constexpr Position<R>::Position(double x, double y): x(x), y(y), angle(0.0){}
template <std::floating_point R> constexpr Position<R>::Position(double x, double y, double angle): x(x), y(y), angle(angle){}


template <std::floating_point R> 
constexpr Position<R>& Position<R>::invert(){
  double x = this->x, y = this->y;
  this->x = y, this->y = x;
  angle = M_PI_2 - angle;
  return *this;
}

template <std::floating_point R> 
constexpr Position<R> operator* (const Position<R>& position, double scalar){
  return {position.x*scalar, position.y*scalar, position.angle*scalar};
}
template <std::floating_point R> 
constexpr Position<R> operator* (double scalar, const Position<R>& position){
  return position*scalar;
}
template <std::floating_point R> 
constexpr Position<R> operator/ (const Position<R>& position, double scalar){
  return position * (1 / scalar);
}
template <std::floating_point R> 
constexpr Position<R> operator/ (double scalar, const Position<R>& position){
  return {position.x / scalar, position.y / scalar, position.angle / scalar};
}
template <std::floating_point R> 
constexpr bool Position<R>::operator== (const Position<R>& p2) const{
  return (x == p2.x) && (y == p2.y) && (angle == p2.angle);
}
template <std::floating_point R> 
constexpr bool Position<R>::operator!= (const Position<R>& p2) const{
  return !(*this == p2);
}
template <std::floating_point R> 
constexpr Position<R> Position<R>::operator+ (const Position<R>& p2) const{
  return {x + p2.x, y + p2.y, angle + p2.angle};
}
template <std::floating_point R> 
constexpr Position<R> Position<R>::operator- (const Position<R>& p2) const{
  return {x - p2.x, y - p2.y, angle - p2.angle};
}
template <std::floating_point R> 
constexpr Position<R> Position<R>::operator+ (const Point<R>& p2) const{
  return *this + Position<R>(p2);
}
template <std::floating_point R> 
constexpr Position<R> Position<R>::operator- (const Point<R>& p2) const{
  return *this + Position<R>(p2);
}
template <std::floating_point R> 
constexpr Position<R>& Position<R>::operator*= (double scalar){
  return *this = *this * scalar;
}
template <std::floating_point R> 
constexpr Position<R>& Position<R>::operator/= (double scalar){
  return *this = *this / scalar;
}