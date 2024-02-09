#include <iostream>
#include "food.h"

using namespace std;

food::food(int x, int y){
  position.x = x;
  position.y = y;
}

// Method to draw the food on the game window
void food::draw() const{
  cout << "○ ";
}

// Method to update the position of the food to a random location
void food::update(){
  position.x = rand() % width;
  position.y = rand() % height;
}

// Getter method for the position of the food
point food::getPosition() const{
  return position;
}