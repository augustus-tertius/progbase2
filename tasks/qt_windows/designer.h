#ifndef DESIGNER_H
#define DESIGNER_H

#include <QString>

class designer
{
    QString name;
    int age;
    double score;


public:
    designer();
    designer(QString name, int age, double score);
    QString getName();
    int getAge();
    double getScore();
};

#endif // DESIGNER_H
