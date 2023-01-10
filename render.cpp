#include<iostream>
#include "include/render.h"
void menu() {
    
    std::cout <<"Press G for Generation\n";
    std::cout <<"Press S for menu\n";
    std::cout <<"Press X for exit \n";
        
}
void  genPass(){
    std::string encPass = "";
    std::string pool = "BP#VbK80q5pSwiEFgn@HIcNXQUtM6Ad%32fmJLvoO4jk9DxelZ$yz7TarRuC1WshY";
    int numCnt = 0;
    int specialCnt = 0;
    bool isRunning  = true;
    while(isRunning) {
    for(int i = 0; i<12;i++) {
        int num = rand() % 65;
        if(pool[num] == '#' || pool[num] == '%' || pool[num] == '$'|| pool[num] == '@') specialCnt++;
        
        if(pool[num]>=48 &&pool[num]<=57) numCnt++;
        
        encPass.push_back(pool[num]);
    
    }
    
    if(numCnt > 0 && numCnt <= 3 && specialCnt > 0 && specialCnt <= 2 && encPass.size() == 12) {
        isRunning = false;
    }
    else{
        encPass.clear();
        specialCnt = 0;
        numCnt = 0;
    }
    
    }
    std::cout << "\033[31m" <<encPass<<"\033[0m";

}

void render(const int *WIDTH,const int *HEIGHT,std::string pass){
    system("clear");
    for(int y =1; y <= *HEIGHT;y++){
        int WDTH = *WIDTH;
        if( y == 2){
            WDTH = *WIDTH -GREET.size()+1;
        }   
        if( y == 6 && pass.size()>=1) {
            WDTH = *WIDTH -12+1;
        }
        if( y==4 && pass.size()>=1) {
            if(pass[0]='g')
            WDTH = *WIDTH -31+1;
        }  
        for(int x =1; x <= WDTH; x++) {
           if (y == 1 || y == *HEIGHT || y == 3|| x == 1 || x == WDTH) 
                std::cout <<STAR;
           else if( y == 2) {
                if(x == 16) std::cout <<GREET;
                else 
                std::cout <<BLANK;
            }
            else if( y == 4 && pass.size()>=1) {
                if(x == 10) std::cout<<"COMPUTER GENREATED PASSWORD IS:";
                else 
                std::cout <<BLANK;
            }
            else if( y == 6 && pass.size()>=1){
                
                if(x == 18)
                genPass();
                else 
                std::cout<<BLANK;
            }   
            else 
                std::cout <<BLANK; 
        }

        std::cout<<"\n";
    }
        
    menu();


}