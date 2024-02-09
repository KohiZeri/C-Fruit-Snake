#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "gameObject.h"

using namespace std;

// Constants defining...
const int width = 20; // ...width of the game board
const int height = 20; // ...height of the game board

// Class representing the food in the game
class food: public GameObject{
private:
  point position; // Position of food

public:
  // Constructor with the initial position of the food
  food (int x, int y);

  // Method to draw the food on the game window
  void draw() const override;

  // Method to update the position of the food to a random location
  void update() override;

  // Getter method for the position of the food
  point getPosition() const;

};//..... End of food class

#endif