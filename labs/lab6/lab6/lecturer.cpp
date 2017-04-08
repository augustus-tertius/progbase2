#include <lecturer.h>

lecturer::lecturer(){
    this->name = "";
    this->surname = "";
    this->middlen = "";
    this->age = 0;
}

lecturer::lecturer(QString name, QString surname, QString middlen, int age){
    this->age = age;
    this->name = name;
    this->surname = surname;
    this->middlen = middlen;
}

void lecturer::setName(QString name){
    this->name = name;
}

void lecturer::setSurname(QString surname){
    this->surname = surname;
}

void lecturer::setMiddlen(QString middlen){
    this->middlen = middlen;
}

void lecturer::setAge(int age){
    this->age = age;
}

QString lecturer::getName(){
    return this->name;
}

QString lecturer::getSurname(){
    return this->surname;
}

QString lecturer::getMiddlen(){
    return this->middlen;
}

int lecturer::getAge(){
    return this->age;
}
