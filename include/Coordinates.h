// EM168887
// Steve Gutfreund

#ifndef COORDINATES_H
#define COORDINATES_H
#include <string>
using namespace std;

/**
 * Represent x-coordinate and y-coordinate.
 */
class Coordinates {
 public:
  /**
   * Constructor, set by default to (0,0).
   */
  Coordinates();
  /**
   * Constructor.
   * @param x coordinate
   * @param y coordinate
   */
  Coordinates(int x, int y);
  /**
   * Constructor.
   * @param s string representing the coordinates
   */
  Coordinates(string s);
  /**
   * Setting the x-coordinate to x.
   * @param x int
   */
  void setX(int x);
  /**
   * Setting the y-coordinate to y.
   * @param y
   */
  void setY(int y);
  /**
   * @return x-coordinate
   */
  int getX() const;
  /**
   * @return y-coordinate
   */
  int getY() const;
  /**
   * @return string representing the coordinates
   */
  string toString() const;
  /**
   * Moves the coordinates according a given vector.
   * @param vector coordinates
   * @return new coordinates
   */
  Coordinates move(const Coordinates& vector) const;
  /**
   * Checks if the coordinates are equal to other.
   * @param other coordinates
   * @return true if equal, false otherwise
   */
  bool isEqual(Coordinates& other) const;
 private:
  int x_;
  int y_;
};

#endif //COORDINATES_H
