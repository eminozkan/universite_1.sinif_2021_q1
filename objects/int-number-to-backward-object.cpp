#include <iostream>
#include <cmath>
using namespace std;

class intnumber {
private:
    int number;
    int backward_number;
    int digitsnumber=0;

    void calcdigits() {
        for (int i = number; i > 10; i /= 10) {
            digitsnumber++;
        }
    }

    void backward_intnumber(){
        int result=0;
        for(int i = digitsnumber; i >= 0; i--){
            backward_number = number % 10;
            result += backward_number * pow(10, i) ;
            number /=10;
        }
        backward_number = result;
    }
public:
    void setNumber(int value){
        number = value;
    }
    int getNumber(){
        return number;
    }
    int getBackwardNumber(){
        calcdigits();
        backward_intnumber();
        return backward_number;
    }

};

int main(){
    int number = 423105;
    intnumber number1;
    number1.setNumber(number);
    cout << number1.getNumber() << endl;
    cout << number1.getBackwardNumber() << endl;


    return 0;
}
