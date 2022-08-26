template <std::floating_point R> constexpr Point<R>::Point(): x(0.0), y(0.0){}
template <std::floating_point R> constexpr Point<R>::Point(Vector<R> vector): x(vector.get_x()), y(vector.get_y()){}
template <std::floating_point R> constexpr Point<R>::Point(Position<R> position): x(position.x), y(position.y){}
template <std::floating_point R> constexpr Point<R>::Point(double x, double y): x(x), y(y){}

template <std::floating_point R> 
constexpr Point<R>& Point<R>::invert(){
  double x = this->x, y = this->y;
  this->x = y, this->y = x;
  return *this;
}

template <std::floating_point R> 
constexpr bool Point<R>::operator== (const Point<R>& p2) const{
  return (x == p2.x) && (y == p2.y);
}
template <std::floating_point R> 
constexpr bool Point<R>::operator!= (const Point<R>& p2) const{
  return !(*this == p2);
}
template <std::floating_point R> 
constexpr Point<R> Point<R>::operator+ (const Point<R>& p2) const{
  return *this - Position<R>(p2);
}
template <std::floating_point R> 
constexpr Point<R> Point<R>::operator- (const Point<R>& p2) const{
  return *this - Position<R>(p2);
}
template <std::floating_point R> 
constexpr Point<R>& Point<R>::operator*= (double scalar){
  return *this = *this * scalar;
}
template <std::floating_point R> 
constexpr Point<R>& Point<R>::operator/= (double scalar){
  return *this = *this / scalar;
}
template <std::floating_point R> 
constexpr Point<R> operator* (const Point<R>& point, double scalar){
  return {point.x*scalar, point.y*scalar};
}
template <std::floating_point R> 
constexpr Point<R> operator* (double scalar, const Point<R>& point){
  return point*scalar;
}
template <std::floating_point R> 
constexpr Point<R> operator/ (const Point<R>& point, double scalar){
  return point*(1 / scalar);
}
template <std::floating_point R> 
constexpr Point<R> operator/ (double scalar, const Point<R>& point){
  return {scalar / point.x, scalar / point.y};
}
template <std::floating_point R> 
constexpr Position<R> Point<R>::operator+ (const Position<R>& p2) const{
  return {x + p2.x, y + p2.y, p2.angle};
}
template <std::floating_point R> 
constexpr Position<R> Point<R>::operator- (const Position<R>& p2) const{
  return {x - p2.x, y - p2.y, p2.angle};
}
