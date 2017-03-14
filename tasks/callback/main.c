#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct Startup {
    char name [200];
    int investitions;
} Startup;

void task1(void);
void task2(void);

void printTask1(void);
void printWordsArr(char arr [][100], int length);
int isConsonant(char ch);
int compareConsQuan(const void* w1, const void* w2);

void printTask2(void);
void printStartupsArr(Startup arr[], int length);
int compareInvestitions(const void* s1, const void* s2);

void printTask3(void);
void printIntArr(int arr [], int length);
void Array_foreach(int arr[], int len, void (*action)(int, int));
void Array_foreachReversed(int arr[], int len, void (*action)(int, int));
void action(int index, int value);

int main (void){

    task1();
    task2();

    printTask3();

    int arr [] = {3, 8, 6, 12, 37, 9, 32, -4, -7, 123};
    int len = sizeof(arr)/sizeof(int);
    printIntArr(arr, len);

    Array_foreach(arr, len, action);
    puts("");
    Array_foreachReversed(arr, len, action);
    puts("");

    return 0;
}

void task1(void){
    char arr [][100] = {"no", "cat", "coding", "aoa", "dich"};
    int length = sizeof(arr)/(sizeof(char)*100);

    printTask1();

    printWordsArr(arr, length);

    qsort(arr, length, (sizeof(char)*100), compareConsQuan);
    printWordsArr(arr, length);
}

void task2(void){
    Startup arr[] = {{"Magic hat", 0}, {"Home for homeless", 30000}, {"Cooking robot", 14347}, 
    {"Memories recorder", 30001} , {"New facebook", 3}};
    int length = sizeof(arr)/sizeof(Startup);

    printTask2();

    printStartupsArr(arr, length);
    qsort(arr, length, sizeof(Startup), compareInvestitions);
    printStartupsArr(arr, length);
}

void printTask1(void){
    printf("\n\tПункт 1. Сортування простих типів\n");
    printf("Використовуючи стандартну функцію qsort() і callback-функції, \
виконати сортування масиву слів у порядку спадання кількості приголосних букв.\n");
}

void printWordsArr(char arr [][100], int length){
    for(int i = 0; i < length; i++){
        printf("%s, ", arr[i]);
    }
    puts("");
}

int isConsonant(char ch){
    if(isalpha(ch)){
        if(ch == 'A' || ch == 'E' || ch == 'O' || ch == 'I' || ch == 'U' || ch == 'Y') {
	     	return 0;
	    } else if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u' || ch == 'y'){
            return 0;
        } else return 1;
    }
    return 0;
}
	
int compareConsQuan(const void* w1, const void* w2){
    int q1 = 0;
    int q2 = 0;

    for(int i = 0; i < strlen((char*)w1); i++){
        if(isConsonant(((char*)w1)[i])){
            q1++;
        }
    }

    for(int i = 0; i < strlen((char*)w2); i++){
        if(isConsonant(((char*)w2)[i])){
            q2++;
        }
    }
    
    return q2 - q1;
}


void printTask2(void){
    printf("\n\tПункт 2. Сортування складених типів\n");
    printf("Описати структуру Стартап і за допомогою qsort(), \
виконати сортування масиву елементів Стартап у порядку спадання кількісті інвестицій.\n");
}

void printStartupsArr(Startup arr[], int length){
    for(int i = 0; i < length; i++){
        printf("| %s, %i |", arr[i].name, arr[i].investitions);
    }
    puts("");
}

int compareInvestitions(const void* s1, const void* s2){
    return ((Startup *)s2)->investitions - ((Startup *)s1)->investitions;
}


void printTask3(void){
    printf("\n\tПункт 3. Створення функцій, що приймають callback\n");
    printf("Створити функцію, яка проходиться по масиву arr у прямому порядку і для \
кожного значення викликає callback-функцію action із двома аргументами: поточне значення \
у масиві та індекс поточного елемента масиву.\n");
    printf("Створити функцію, яка проходиться по масиву arr у зворотньому порядку і для \
кожного значення викликає callback-функцію action із двома аргументами: поточне значення у \
масиві та індекс поточного елемента масиву.\n");
    printf("У функції main() створити і вивести тестовий масив цілих чисел та викликати\
 функції Array_foreach() та Array_foreachReversed на тестовому масиві чисел із callback-функціями, \
 що виводять у консоль індекс і значення елементів із парними значеннями.\n\n");
}

void printIntArr(int arr [], int length){
    printf("\n");

    for(int i = 0; i < length; i++){
        printf("%i  ", arr[i]);
    }
    printf("\n\n");
}

void Array_foreach(int arr[], int len, void (*action)(int, int)){
    for(int i = 0; i < len; i++){
        action(i, arr[i]);
    }
}

void Array_foreachReversed(int arr[], int len, void (*action)(int, int)){
    for(int i = len - 1; i >= 0; i--){
        action(i, arr[i]);
    }
}

void action(int index, int value){
    if(value % 2 == 0){
        printf("arr[%i] = %i  ", index, value);
    }
}