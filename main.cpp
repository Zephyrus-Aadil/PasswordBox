#include<iostream>
#include "include/render.h" 

const int WIDTH = 50;
const int HEIGHT =10;

int main() {
    srand(time(NULL));
    render(&WIDTH,&HEIGHT,"");
    bool isRunning = true;
    std::string tempPass ="";

    while(isRunning){
        std::string  ch;
        std::cin >>ch;
      
      if(ch[0] == 'G' || ch[0] == 'g') {
        std::cout <<"Pressed G\n";

        render(&WIDTH,&HEIGHT,"G");
      }
      else if( ch[0] == 'X' ||ch[0]==  'x'){
        std::cout <<"Exit\n";
        system("clear");
        isRunning = false;
      }
      else if( ch[0] == 'S' || ch[0] == 's') {
        render(&WIDTH,&HEIGHT,"");
      }
      else {
    
            std::cout <<"Pressed Wrong Key\n";
            menu();
      }
      
    }
}