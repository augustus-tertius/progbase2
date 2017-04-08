#ifndef LECTURER_H
#define LECTURER_H

#include <QString>

class lecturer
{
    QString surname;
    QString name;
    QString middlen;
    int age;

public:
    lecturer();
    lecturer(QString name, QString surname, QString middlen, int age);

    void setName(QString name);
    void setSurname(QString surname);
    void setMiddlen(QString middlen);
    void setAge(int age);

    QString getName();
    QString getSurname();
    QString getMiddlen();
    int getAge();
};

#endif // LECTURER_H
