#include <iostream>
#include <string>
using namespace std;


bool checkpassword(string parola){
    string correctpassword = "Parola";
    if (parola == correctpassword){
        return true;
    }else{
        return false;
    }

}


struct ticket{
    int salonno;
    int chairno;
};

bool isSalon1chairs_empty [9] = { true , true, true,true, true, true,true, true, true};
bool isSalon1_empty = true;

bool isSalon2chairs_empty [9] = {true, true, true,true, true, true,true, true, true};
bool isSalon2_empty = true;

bool isSalon3chairs_empty [9] = {true, true, true,true, true, true,true, true, true};
bool isSalon3_empty = true;

void checksalon(){
    isSalon1_empty = isSalon1chairs_empty[0] || isSalon1chairs_empty[1] || isSalon1chairs_empty[2] || isSalon1chairs_empty[3] ||
                     isSalon1chairs_empty[4] || isSalon1chairs_empty[5] || isSalon1chairs_empty[6] || isSalon1chairs_empty[7] || isSalon1chairs_empty[8];

    isSalon2_empty = isSalon2chairs_empty[0] || isSalon2chairs_empty[1] || isSalon2chairs_empty[2] || isSalon2chairs_empty[3] || isSalon2chairs_empty[4] ||
                     isSalon2chairs_empty[5] || isSalon2chairs_empty[6] || isSalon2chairs_empty[7] || isSalon2chairs_empty[8];

    isSalon3_empty = isSalon3chairs_empty[0] || isSalon3chairs_empty[1] || isSalon3chairs_empty[2] || isSalon3chairs_empty[3] ||
                     isSalon3chairs_empty[4] || isSalon3chairs_empty[5] || isSalon3chairs_empty[6] || isSalon3chairs_empty[7] || isSalon3chairs_empty[8];
}

ticket takeTicket(int salonno) {
    checksalon();
    if (salonno == 1) {
        if (isSalon1_empty) {
            for (int i = 0; i < 9; i++) {
                if (isSalon1chairs_empty[i]) {
                    isSalon1chairs_empty[i] = false;
                    return {1, i + 1};
                }
            }
        } else {
            cout << endl << endl;
            cout << "=============================" << endl;
            cout << "Salonumuz doludur!" << endl;
            cout << "=============================" << endl << endl << endl << endl;
            return {-1, -1};
        }

    } else if (salonno == 2) {
        if (isSalon2_empty) {
            for (int i = 0; i < 9; i++) {
                if (isSalon2chairs_empty[i]) {
                    isSalon2chairs_empty[i] = false;
                    return {2, i + 1};
                }

            }
        } else {
            cout << endl << endl;
            cout << "=============================" << endl;
            cout << "Salonumuz doludur!" << endl;
            cout << "=============================" << endl << endl << endl << endl;
            return {-1, -1};
        }
    } else if (salonno == 3) {
        if (isSalon3_empty) {
            for (int i = 0 ; i < 9; i++) {
                if (isSalon3chairs_empty[i]) {
                    isSalon3chairs_empty[i] = false;
                    return {3, i + 1};
                }
            }
        } else {
            cout << endl << endl;
            cout << "=============================" << endl;
            cout << "Salonumuz doludur!" << endl;
            cout << "=============================" << endl << endl << endl << endl;
            return {-1, -1};
        }

    }
    return {-1,-1};
}
void exitSalon(int salonno, int chairno){
    if(salonno == 1){
        for (int i=0;i < 9 ;i++){
            if(i == chairno - 1){
                isSalon1chairs_empty[i] = true;
            }
        }
    }
    if (salonno == 2){
        for (int i=0;i <= 9 ;i++){
            if(i == chairno - 1){
                isSalon2chairs_empty[i] = true;
            }
        }
    }
    if (salonno == 3){
        for (int i=0;i <= 9 ;i++){
            if(i == chairno - 1){
                isSalon3chairs_empty[i] = true;
            }
        }
    }
}

int HowManySalonsAreAvailable = 3;
const string movienames[3] = {"Harry Potter : Azkaban Tutsagi", "Matrix", "Sakar Sakir"};

const float price = 15.0;
void printprice(){
    cout <<endl << endl<< "=============================================" << endl;
    cout << "Odemeniz gereken tutar :" << price << "TL" << endl;
    cout << "=============================================" << endl;
}
int main(){
    int moviesalonno;
    ticket t={0,0};
    char input;
    int salonno;
    int chairno;
    do {
        cout << "Islem seciniz"<<endl;
        cout << "=============================================" << endl;
        cout << "\tFilmleri listelemek icin - l" << endl;
        cout << "\tBilet Almak icin - g"<<endl;
        cout << "\tUcret odemek icin - c"<<endl;
        cout << "\tProgrami kapatmak icin - q (Yetkili Islem):";
        cin >> input;

        cout << endl << endl;
        if(input == 'l'){
            cout << "=========================================================" << endl;
            for(int i = 0; i < HowManySalonsAreAvailable; i++){
                cout <<" * " <<movienames[i] << " - Salon " << i+1 <<endl;
            }
            cout << "=========================================================" << endl;
        }
        if (input == 'g') {
            cout << "Girmek istediginiz filmin salon numarasini seciniz:";
            cin >> moviesalonno;
            t = takeTicket(moviesalonno);
            if (t.salonno != -1) {
                cout << "=========================================================" << endl;
                cout <<"| \tSalon No : " << t.salonno << "\t \tKoltuk No: " << t.chairno << "\t\t|" << endl;
                cout << "=========================================================" << endl;
            }
        }
        if (input == 'c'){
            cout << "Salon numaranizi giriniz";
            cin >> salonno;
            cout << "Koltuk numaranizi giriniz";
            cin >> chairno;
            exitSalon(salonno,chairno);
            printprice();

        }

        if(input == 'q'){
            string parola;
            cout << "Parolayi giriniz:";
            cin >> parola;
            if(checkpassword(parola)){
                break;
            }else{
                cout << "===================================";
                cout << "\nHatali parola girdiniz";
            }
        }

        cout << endl << endl << endl << endl;
    }while (true);



    return 0;
}
