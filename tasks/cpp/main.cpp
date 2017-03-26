#include <iostream>
#include <vector>
#include <iostream>
#include "include/Ball.h"

using namespace std;

void createBall (vector<Ball * > & vec){
    string name;
    double rad;
    bool isHollow;

    cout << "Enter name of the sphere: "<<endl;
    cin >> name;
    cout<<"Enter radius: "<<endl;
    cin >> rad;
    cout << "Is it hollow?: "<<endl;
    cin >> isHollow;

    vec.push_back(new Ball(name, rad, isHollow));
}

void printVec (vector<Ball *> & vec){
    for(auto it = begin(vec); it != end(vec); it++){
        Ball * cur = *it.base();
        cur->toString();
        cout << "V =" << cur->getVolume() << endl << endl;
    }
}

void findBall (vector<Ball *> & vec){
    double volume;
    cout << "Please, enter your V: ";
    cin >> volume;

    for(auto it = begin(vec);it != end(vec); it++){
        Ball * cur = *it.base();

       if(cur->getVolume() < volume){
           cur->toString();
           cout << "V =" << cur->getVolume() << endl;
       }
    }
}

void printTasks(void){
    cout << endl << endl;
    cout << "______________________________________________________" << endl;
    cout << "1. Вивести вміст списку із полями об'єктів у консоль." << endl;
    cout << "2. Додати до списку новий елемент." << endl;
    cout << "3. Вивести всі кулі, об'єм яких менший за введене V." << endl;
    cout << "[q] - Вийти з циклу і завершити роботу програми. " << endl;
    cout << "______________________________________________________" << endl;
    cout << endl << endl;
    cout << "Введіть код дії: ";
}

void printErr(void) {
    cout << "Введено невірний символ" << endl << endl;
}

int main() {
    vector<Ball *> vec;
    int exit = 0;


    while(!exit){
        printTasks();

        char ch = '0';
        cin >> ch;

        switch(ch){
            case '1':
                printVec(vec);
                break;

            case '2':
                createBall(vec);
                break;

            case '3':
                findBall(vec);
                break;

            case 'q':
                exit = true;
                break;

            default:
                printErr();
                break;


        }

    }
    for(auto it = begin(vec); it != end(vec); it++){
        Ball * rec = *it.base();
        delete rec;
    }
    vec.clear();
    return 0;
}