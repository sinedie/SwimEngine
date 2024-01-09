#ifndef VECTOR2D_H
#define VECTOR2D_H

template <typename T> class Vector2D {
public:
  T x, y;

  Vector2D(){};
  Vector2D(T x, T y) {
    this->x = x;
    this->y = y;
  }

  Vector2D<T> operator+(Vector2D<T> const &vector) {
    return Vector2D<T>(x + vector.x, y + vector.y);
  }
  Vector2D<T> operator-(Vector2D<T> const &vector) {
    return Vector2D<T>(x - vector.x, y - vector.y);
  }
  Vector2D<T> operator/(float number) {
    return Vector2D<T>(x / number, y / number);
  }
  Vector2D<T> operator*(float number) {
    return Vector2D<T>(x * number, y * number);
  }

  void operator+=(Vector2D<T> const &vector) {
    x += vector.x;
    y += vector.y;
  }
  void operator-=(Vector2D<T> const &vector) {
    x -= vector.x;
    y -= vector.y;
  }
  void operator*=(float number) {
    x *= number;
    y *= number;
  }
  void operator/=(float number) {
    x /= number;
    y /= number;
  }

  float magnitude() { return sqrt(pow(x, 2) + pow(y, 2)); }
  Vector2D<T> normalize() {
    float norma = magnitude();
    if (norma != 0) {
      return Vector2D<T>(x / norma, y / norma);
    }
    return Vector2D<T>();
  };
};

#endif