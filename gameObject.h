#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <cstdlib>

using namespace std;

// Class representing a point in 2D space 
class point {
public: 
  int x; 
  int y;

  // Constructor with default values
  point(int x = 0, int y = 0): x(x), y(y) {}

};//..... End of class point

// Abstract class representing a game object with draw and update methods
class GameObject {
public:
  virtual void draw() const = 0;
  virtual void update() = 0;
  virtual ~GameObject() = default;
};//..... End of GameObject class

#endif