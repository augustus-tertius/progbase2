#include "designer.h"
#include <QString>

designer::designer()
{
    this->age = 0;
    this->score = 0;
}

designer::designer(QString name, int age, double score){
    this->name = name;
    this->age = age;
    this->score = score;
}

QString designer::getName(){
    return this->name;
}

int designer::getAge(){
    return this->age;
}

double designer::getScore(){
    return this->score;
}
