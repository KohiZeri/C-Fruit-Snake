#include <iostream>
#include <vector>
#include "snake.h"

using namespace std;

// Constructor with the initial position of the snake's head
snake::snake(int startX, int startY): direction('R'){
  body.push_back(point(startX , startY));
}

// Method to draw the snake on the game window
void snake::draw() const{
    cout << "● ";
}

// Method to change the direction of the snake
void snake::changeDirection(char newDirection){
  direction = newDirection;
}

char snake::getDirection(){
  return direction;
}

// Method to update the position of the snake based on its direction
void snake::update(){
  cout << "Current Direction" << direction << endl;
  switch(direction){
    case 'L':
      body[0].x--;
      break;
    case 'R':
      body[0].x++;
      break;
    case 'U':
      body[0].y--;
      break;
    case 'D':
      body[0].y++;
      break;
  }
}

// Getter methods for the coordinates of the snake's head
int snake::getX() const {return body[0].x;}
int snake::getY() const {return body[0].y;}