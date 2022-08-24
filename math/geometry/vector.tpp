constexpr Vector::Vector(): x(0.0), y(0.0), magnitude(0.0), angle(0.0) {};

constexpr Vector::Vector(Point p1):
x(0.0), y(0.0), magnitude(0.0), angle(0.0){ //Initializing to 0, becuase constexpr needs to see the initialization
  set_cartesian(p1);
}

constexpr Vector::Vector(Point p1, Point p2):
x(0.0), y(0.0), magnitude(0.0), angle(0.0){ //Initializing to 0, becuase constexpr needs to see the initialization
  set_cartesian(p2-p1);
}


constexpr Vector& Vector::set_cartesian(Point point){
  return set_cartesian(point.x, point.y);
}

constexpr Vector& Vector::set_cartesian(Point p2, Point p1){
  return set_cartesian(p2-p1);
}

constexpr Vector& Vector::set_cartesian(double x, double y){
  this->x = x;
  this->y = y;
  magnitude = sqrt(pow(x, 2) + pow(y, 2));
  angle = atan2(y, x);
  return *this;
}

constexpr Vector& Vector::set_polar(double magnitude, double angle){
  this->magnitude = magnitude;
  this->angle = angle;
  x = magnitude * cos(angle);
  y = magnitude * sin(angle);
  return *this;
}

constexpr Vector& Vector::invert(){
  return set_cartesian(y, x);
}

constexpr Vector& Vector::rotate(double angle){
  return set_polar(magnitude, this->angle + angle);
}

constexpr Vector Vector::make_cartesian(Point point){
  return make_cartesian(point.x, point.y);
}

constexpr Vector Vector::make_cartesian(Point p1, Point p2){
  return make_cartesian(p2-p1);
}

constexpr Vector Vector::make_cartesian(double x, double y){
  Vector vector;
  vector.set_cartesian(x, y);
  return vector;
}

constexpr Vector Vector::make_polar(double magnitude, double angle){
  Vector vector;
  vector.set_polar(magnitude, angle);
  return vector;
}

constexpr double Vector::get_x() const{
  return x;
}
constexpr double Vector::get_y() const{
  return y;
}
constexpr double Vector::get_magnitude() const{
  return magnitude;
}
constexpr double Vector::get_angle() const{
  return angle;
}


constexpr Vector Vector::operator* (double scalar) const{
  return make_polar(magnitude * scalar, angle);
}
constexpr Vector operator* (double scalar, const Vector& vector){
  return vector*scalar;
}
constexpr Vector Vector::operator/ (double scalar) const{
  return *this * (1 / scalar);
}
constexpr Vector operator/ (double scalar, const Vector& vector){
  return Vector::make_polar(vector.magnitude / scalar, vector.angle);
}
constexpr bool Vector::operator== (const Vector& p2) const{
  return (x == p2.x) && (y == p2.y) && (magnitude == p2.magnitude) && (angle == p2.angle);
}
constexpr bool Vector::operator!= (const Vector& p2) const{
  return !(*this == p2);
}
constexpr Vector Vector::operator+ (const Vector& p2) const{
  return make_polar(x + p2.x, y + p2.y);
}
constexpr Vector Vector::operator- (const Vector& p2) const{
  return make_polar(x - p2.x, y - p2.y);
}
constexpr Vector& Vector::operator*= (double scalar){
  return set_polar(magnitude * scalar, angle);
}
constexpr Vector& Vector::operator/= (double scalar){
  return set_polar(magnitude / scalar, angle);
}
constexpr double Vector::operator* (const Vector& p2) const{
  return x*p2.x+y*p2.y;
}
