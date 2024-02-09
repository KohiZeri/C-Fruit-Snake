#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include "food.h"
#include "snake.h"

using namespace std;

// Class representing the gameManager
class gameManager {
public:
  // Members of the gameManager class
  int score;
  int level;
  bool gameOver;
  snake body;
  food fruit;
  int tailX[100], tailY[100];
  int nTail = 0;
  int dir;

  // Constructor with the default values for the snake and random values for the food
  gameManager(int x = rand() % width,
int y = rand() % height);

  // Method to draw the game window
  void drawGame();

  // Method to update the game state
  void update();

  // Method to handle user input
  void handleInput();

};//.....end of gameManager class

void menu();

#endif