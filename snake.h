#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include "gameObject.h"

using namespace std;

// Class representing the snake in game
class snake: public GameObject{
private:
  // Members of the snake class
  vector<point> body; // Vector to store the body segments of the snake
  char direction; // Current direction of the snake

public:
  // Constructor with the initial position of the snake's head
  snake(int startX, int startY);

  // Method to draw the snake on the game window
  void draw() const override;

  // Method to change the direction of the snake
  void changeDirection(char newDirection);

  char getDirection();

  // Method to update the position of the snake based on its direction
  void update() override;

  // Getter methods for the coordinates of the snake's head
  int getX() const;
  int getY() const;

};//..... End of snake class

#endif