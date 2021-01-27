#include <iostream>
#include <fstream>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>

using namespace std;

struct yem{
    int x;
    int y;
};
long score = 1;
yem y1;
void create_yem(){


        srand(time(NULL));
        y1.x = rand() % 39;
        y1.y = rand() % 20;
    }
void sleepcp(int milliseconds){


    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}
void print_coordinates(int x, int y){

            char character = 'o';
            system("cls");
            cout << "__________________________________________"<<endl;
            if(x == y1.x && y == y1.y){
                    cout << "|\tYemi Basariyla Aldiniz" << "\t \t  |" << endl;
                create_yem();
                score *=2;
            }else{
            for(int a=0; a < 20;a++) {
                if(a==y1.y){
                if(a==y1.y && a != y) {
                    cout << "|";
                    for (int i = 0; i < 41; i++) {

                        if (i == y1.x) {
                            cout << "x";
                        } else {
                            cout << " ";
                        }
                    }
                    cout << "|" << endl;
                }else if (a == y1.y && a == y){

                    cout << "|";
                    for (int i = 0; i < 40; i++) {
                        if(i == x){
                            cout << character;
                        }
                        if (i == y1.x) {
                            cout << "x";
                        } else {
                            cout << " ";
                        }
                    }
                    cout << "|" << endl;
                }
                else{
                    cout << "|";
                    for (int i = 0; i < 41; i++) {
                         cout << " ";
                        }
                    cout << "|" << endl;
                    }
                }else{
                    if(a==y) {
                    cout << "|";
                    for (int i = 0; i < 41; i++) {

                        if (i == x) {
                            cout << character;
                        } else {
                            cout << " ";
                        }
                    }
                    cout << "|" << endl;
                }else{
                    cout << "|";
                    for (int i = 0; i < 41; i++) {
                         cout << " ";
                        }
                    cout << "|" << endl;
                    }


                }
            }
}
                cout << "|_________________________________________|"<<endl;
                cout << "Score:" << score << endl;
}


int get_key_statement(){
   static int x = 20;
   static int y = 10;
if (GetAsyncKeyState(VK_RIGHT)) {
            x++;
            if(x>39){
                x=0;
            }
            print_coordinates(x,y);
            }
        if (GetAsyncKeyState(VK_LEFT)) {
            x--;
            if(x<0){
                x=39;
            }
            print_coordinates(x,y);
        }
        if (GetAsyncKeyState(VK_UP)) {
            y--;
            if(y<=0){
                y=19;
            }
            print_coordinates(x,y);
            }
            if (GetAsyncKeyState(VK_DOWN)) {
            y++;
            if(y>=20){
                y=0;
            }
            print_coordinates(x,y);
            }
        sleepcp(300);
     if(GetAsyncKeyState(VK_ESCAPE)){
         return -1;
        }
}



int main(){
    create_yem();

    while(true) {
        int exit = get_key_statement();
        if(exit == -1){
            break;
        }

    }
    system("cls");
    cout << "Tekrar bekleriz!!" << endl;
    cout << "Skorunuz :" << score;
    sleep(2);
    return 0;
}
