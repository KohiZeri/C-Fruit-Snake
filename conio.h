#ifndef CONIO_H
#define CONIO_H

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <limits>

int ungetch(int ch){
  return ungetc(ch, stdin);
}

int getch_echo(bool echo = true){
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~ICANON;
  if (echo){
    newt.c_lflag &= ECHO;
  }else{
    newt.c_lflag &= ~ECHO;
  }
  
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

int getch(){
  return getch_echo(false);
}

int kbhit(){
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if (ch != EOF){
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}

#endif