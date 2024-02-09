#include <iostream>
#include <cstdlib>
#include "conio.h" // including conio.h file
#include "snake.h"
#include "food.h"
#include "gameManager.h"

// Constructor with the default values for the snake and random values for the food
gameManager::gameManager(int x, int y): score(0), level(1), body(10,10), fruit(x,y){}

// Method to draw the game window
void gameManager::drawGame() {
  gameOver = false;

  // Draw top boarder
  for (int i = 0; i < width + 1; i++){
    cout << "##";
  }
  cout << endl;

  // Draw the game board
  for (int j = 0; j < height; j++){
    for (int k = 0; k < width; k++){
      // Initialize variables
      bool print = false;
      bool head = false;

      // Draw left boarder
      if (k == 0){
        cout << "#";
      }

      // Draw the snake head
      if (j == body.getY() && k == body.getX()){
        body.draw();
        print = true;
        head = true;
      }

      // Draw the food
      if(j == fruit.getPosition().y && k == fruit.getPosition().x){
        if (!head){
          fruit.draw();
        }
        print = true;
      }
      else{

        // Draw the snake's body
        for (int m = 1; m <= nTail; m++){
          if (tailX[m] == k && tailY[m] == j){
            cout << "● ";
            print = true;
          }
        }

        // If no game object is present draw an empty space
        if (!print){
          cout << "  ";
        }
      }

      // Draw right boarder
      if (k == width - 1){
        cout << "# ";
      }
    }
    cout << endl;
  }

  // Draw bottom boarder
  for (int l = 0; l < width + 1; l++){
    cout << "##";
  }
  cout << endl;

  // Display score and level
  cout << "Score: " << score << endl;
  cout << "Level: " << level << endl;
}

  // Method to update the game state
void gameManager::update(){

  // Check if the snake has collided with the boarder
  if (body.getX() >= width || body.getX() < 0 || body.getY() >= height || body.getY() < 0){
    gameOver = true;
  }

  // Check if the snake has collided with itself
  for (int n = 0; n < nTail; n++){
    if (tailX[n] == body.getX() && tailY[n] == body.getY()){
      gameOver = true;
    }
  }

  // Check if the snake has eaten the food
  if (body.getX() == fruit.getPosition().x && body.getY() == fruit.getPosition().y){
    score+=10;
    level++;
    nTail++;
    fruit.update();
  }

  // Update the snakes body position
  tailX[0] = body.getX();
  tailY[0] = body.getY();
  for (int i = nTail; i > 0; i--){
    tailX[i] = tailX[i-1];
    tailY[i] = tailY[i-1];
  }
}

  // Method to handle user input
void gameManager::handleInput(){
  while(true){
    char key = getch();
    if (key == 100 && (body.getDirection() != 'L' || nTail == 0)){ // ASCII number for 'd'
      body.changeDirection('R');
      break;
    }else if(key == 97 && (body.getDirection() != 'R' || nTail == 0)){ // ASCII number for 'a'
      body.changeDirection('L');
      break;
    }else if (key == 119 && (body.getDirection() != 'D' || nTail == 0)){ // ASCII number for 'w'
      body.changeDirection('U');
      break;
    }else if (key == 115 && (body.getDirection() != 'U' || nTail == 0)){ // ASCII number for 's'
      body.changeDirection('D');
      break;
    }else if (key == 120){ // ASCII number for 'x'
      gameOver = true;
      break;
    }
  }
    // else{
    //   ungetch(key);
    // }
  // }
}


void menu(){
  // Constructor for the class gameManager
  gameManager gm = gameManager();

  // Initialize variables
  string word;
  bool gameOver;

  // Storing variable
  gameOver = false;

  // Tittle screen printout
  cout << "__________WELCOME TO C++ SNAKE GAME__________" << endl;
  cout << endl;
  cout << "INSTRUCTIONS:" << endl;
  cout << "1. Use the keys 'w', 'a', 's', 'd' to move the snake." << endl;
  cout << "2. Eat the fruit to grow the snake." << endl;
  cout << "3. Avoid hitting the walls or the snake's body." << endl;
  cout << "4. The game ends when the snake hits the wall or its own body." << endl;
  cout << "5. Your score is calculated based on how many fruits you eat." << endl;
  cout << endl;

  // Prompt user to enter play to start the game
  cout << "Enter 'play' to start the game." << endl;
  cout << "Note: If you want to exit the game, press x." << endl;
  cin >> word;

  // If the user enters 'play', the game starts
  if (word == "play"){

    // Main game loop
    while(!gameOver){

      void(system("clear")); // clears the screen
      
      // Calling functions in class gameManager
      gm.drawGame();
      gm.handleInput();
      gm.update();
      gm.body.update();
      usleep(100000);
      
      gameOver = gm.gameOver;
    }
  }else{ // Error trap
    cout << "Invalid Choice, please get out your disturbing me.";
    return;
  }

  void(system("clear")); // clears the screen

  // Ending message
  cout << "Game Over! Wow ur trash, here's your final score: " << gm.score << endl;
  return;
}