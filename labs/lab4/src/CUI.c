#include <stdio.h>
#include <ctype.h>
#include <progbase.h>
#include <pbconsole.h>
#include <string.h>

#include <CUI.h>
#include <convert.h>
#include <storage.h>

void drawBg (void) {
  int x;
  int y;

  conReset();
  for (x = 0; x <= 40; x++) {
    for (y = 0; y <= 144; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }
}

void drawBox(struct menuBox box){
  int x;
  int y;

  drawBg();

  conSetAttr(BG_CYAN);
  for (x = box.top; x <= box.head; x++) {
    for (y = box.left; y <= box.right; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }

  conSetAttr(BG_WHITE);
  for (x = box.head; x < box.down; x++) {
    for (y = box.left; y <= box.right; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }

  conSetAttr(BG_CYAN);
  for (x = box.down; x <= box.bottom; x++) {
    for (y =  box.left; y <= box.right; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }

  for (x = box.head; x < box.down; x++) {
      conMove(x, box.right);
      putchar(' ');
      conMove(x, box.left);
      putchar(' ');
  }

  conReset();
  puts("");
}

void drawDownBox(struct menuBox box){
  int x;
  int y;

  conSetAttr(BG_CYAN);
  for (x = box.down; x <= box.bottom; x++) {
    for (y =  box.left; y <= box.right; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }
}

void pEnterOperationCode(struct menuBox box){
  conSetAttr(BG_CYAN);
  conMove(box.bottom -1,  box.left);
  printf("\t Введіть номер операції: ");
}

void printMainMenu(struct menuBox box) {

  drawBox(box);

  conSetAttr(BG_CYAN);
  conMove((box.top + box.head)/2, box.left + 17);
  printf("Лабораторна робота № 3");


  conSetAttr(BG_WHITE);
  conSetAttr(FG_BLACK);
  conMove(box.head + 1, box.left + 3);
  printf("\t 1. Видалити дані із вказаної позиції у списку \n\t \
2. Перезаписати дані у вказаній позиції на нововведені \n\t 3. Перезаписати\
 тільки обране поле даних елемента на \n\t вказаній позиції \n\t 4. Знайти всі\
 курси лекцій, у яких загальна тривалість  \n\t більша Х годин \n\t 5.\
 Представити структуру у вигляді строки");

  conMove(box.down - 3, 1);
  printf("\tНатисніть t для виклику тестового режиму \n\tНатисніть s для збереження масиву \
у файл\n\tНатисніть q для виходу");
  conReset();

  pEnterOperationCode(box);
}


int printGB(struct menuBox box){
  int x;
  int y;

  conReset();
  for (x = 0; x <= 40; x++) {
    for (y = 0; y <= 140; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }

  conSetAttr(BG_CYAN);
  for (x = box.top; x <= box.bottom; x++) {
    for (y =  box.left; y <= box.right; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }
  conMove((box.top + box.bottom)/2, box.left + 20);
  printf("That's all)");

  conReset();
  conMove(box.bottom + 2, 0);
  conShowCursor();
  return 0;
}

List* startMenu(struct menuBox box, int* quan){

  List* list = NULL;

  int exit = 1;
  drawStartMenu(box);

  while(exit) {
    char ch;
    ch = conGetChar();
    printf("%c", ch);

    if(isdigit(ch)){
        if('1' == ch) {
          int flag = 1;
          while(flag){
            conMove(box.bottom -2,  box.left);
            printf(" Введіть кількість елементів, які ви бажаєте створити: ");
            *quan = getInt();
            if(flag > 0){
              flag = 0;
            } else {
              conMove(box.bottom,  box.left);
              printf("\t Введена кількість елементів є невірною. Спробуйте ще раз.");
            }
          }

          list = List_new();

          for(int i = 0; i < *quan; i++){
            LectureCourse* lC = LectureCourse_new();
            List_add(list, lC);
            drawDownBox(box);
            conFillEl(list, i, box);
          }
          exit = 0;
        }
        if('2' == ch) {
          char FileName [50];
          int flag = 1;
          drawDownBox(box);
          drawFileInstructions(box);
          while(flag){
            conMove(box.bottom -2,  box.left);
            printf(" Введіть кількість елементів, яка має бути зчитана з файлу: ");
            *quan = getInt();
            if(flag > 0){
              flag = 0;
            } else {
              conMove(box.bottom,  box.left);
              printf("\t Введена кількість елементів є невірною. Спробуйте ще раз.");
            }
          }

          conMove(box.bottom - 1,  box.left);
          printf(" Введіть назву файлу, з якого будуть считані дані: ");
          scanf("%s", FileName);

          list = readFromFile(*quan, FileName);
          if(list == NULL) {
            conMove(box.bottom,  box.left);
            printf("\t При зчитуванні даних виникла помилка");
          }
          exit = 0;
        }
        if('0' == ch || '3' == ch || '4' == ch || '5' == ch || '6' == ch \
|| '7' == ch || '8' == ch || '9' == ch) {
          pEnterOperationCode(box);
        }
      } else {
          drawBox(box);
          drawStartMenu(box);
          conMove(box.bottom,  box.left);
          printf("\t Неправильно введений номер операції");
          pEnterOperationCode(box);
      }
    }
    return list;
}

void drawStartMenu(struct menuBox box){
  int shift = 1;

  drawDownBox(box);

  conMove(box.down + shift,  box.left);
  printf("\t Перш ніж почати працювати зі списком, його потрібно створити");
  shift += 2;

  conMove(box.down + shift,  box.left);
  printf("\t 1. Ввести список даних з консолі \n\t 2. Зчитати список з файлу");

  pEnterOperationCode(box);
}

void drawFileInstructions (struct menuBox box) {
    int x;
    int y;
    int wildth = 80;
    int length = 17;

    conSetAttr(BG_BLACK);
    for (x = box.head; x < box.head + length; x++) {
      for (y =  box.right + 5; y < box.right + 5 + wildth; y++) {
        conMove(x, y);
        putchar(' ');
      }
    }

    conMove(box.head + 1, box.right + 7);
    printf("Для правильності зчитування дані в файлі мають бути записані ");
    conMove(box.head + 2, box.right + 7);
    printf("наступним чином: ");
    conMove(box.head + 3, box.right + 7);
    printf("Строка з назвою курсу, прізвище, ім'я, по-батькові, вік викладача,");
    conMove(box.head + 4, box.right + 7);
    printf("тривалість курсу у годинах, оцінка курсу.");
    conMove(box.head + 5, box.right + 7);
    printf("Приклад оформлення:");
    conMove(box.head + 7, box.right + 7);
    printf("Випічка та кондитерське мистецтво");
    conMove(box.head + 8, box.right + 7);
    printf("Марішина Вікторія Петрівна 27 80 4.5");
    conMove(box.head + 10, box.right + 7);
    printf("Наступні стуктури описувати без пропуску рядка");
    conMove(box.head + 12, box.right + 7);
    printf("Також можна скористатися уже готовими тестовими стуктурами,");
    conMove(box.head + 13, box.right + 7);
    printf("описаними в sample.txt");
    conMove(box.head + 14, box.right + 7);
    printf("Даний файл містить 5 тестових наборів даних для структур, ");
    conMove(box.head + 15, box.right + 7);
    printf("написаних українською мовою");

    conSetAttr(BG_CYAN);
}

void conFillEl(List* list, int index, struct menuBox box){
    char str [300];

    // сделать проверку корректности ввода пользователя !

    drawDownBox(box);
    int shift = 1;
    conMove(box.down + shift,  box.left);
    printf("\tLecture course №%i", index + 1);
    shift += 2;

    void* lC = List_get(list, index);

    conMove(box.down + shift,  box.left);
    printf("\t Введіть назву курсу: ");
    fgets(str, 300, stdin);
    str[strlen(str) - 1] = '\0';
    LectureCourse_setCourseName(lC, str);
    shift++;

    conMove(box.down + shift,  box.left);
    printf("\t Введіть  прізвище викладача: ");
    fgets(str, 300, stdin);
    str[strlen(str) - 1] = '\0';
    LectureCourse_setLectSurname(lC, str);
    shift++;

    conMove(box.down + shift,  box.left);
    printf("\t Введіть ім'я викладача: ");
    fgets(str, 300, stdin);
    str[strlen(str) - 1] = '\0';
    LectureCourse_setLectName(lC, str);
    shift++;

    conMove(box.down + shift,  box.left);
    printf("\t Введіть по-батькові викладача: ");
    fgets(str, 300, stdin);
    str[strlen(str) - 1] = '\0';
    LectureCourse_setLectMiddlen(lC, str);
    shift++;

    conMove(box.down + shift,  box.left);
    printf("\t Введіть вік викладача: ");
    fgets(str, 300, stdin);
    str[strlen(str) - 1] = '\0';
    LectureCourse_setLectAge(lC, atoi(str));
    shift++;

    conMove(box.down + shift,  box.left);
    printf("\t Введіть довжину курсу: ");
    fgets(str, 300, stdin);
    str[strlen(str) - 1] = '\0';
    LectureCourse_setLength(lC, atoi(str));
    shift++;

    conMove(box.down + shift,  box.left);
    printf("\t Введіть оцінку курсу: ");
    fgets(str, 300, stdin);
    str[strlen(str) - 1] = '\0';
    LectureCourse_setRating(lC, atof(str));
    shift++;
}

int conSaveToFile(struct menuBox box, List* list, int quan){
  char FileName [50];
  int status = 0;

  drawDownBox(box);

  conMove(box.bottom - 1,  box.left);
  printf("\t Введіть назву файлу, у якому збережуться дані: ");
  scanf("%s", FileName);

  status = saveToFile(list, FileName);

  return status;
}

int conDeleteStruct(struct menuBox box, List* list, int quan){
    int delnum = 0;
    int flag = 1;

    while(flag){
      conMove(box.bottom - 1,  box.left);
      printf("\t Введіть номер структури, що буде видалена: ");
      scanf("%i", &delnum);

      if(delnum > 0 && delnum <= quan){
        flag = 0;
      } else {
        conMove(box.bottom,  box.left);
        printf("\t Структури з таким порядковим номером не існує ");
      }
    }

    LectureCourse* lC = List_get(list, delnum -1);
    LectureCourse_free(&lC);
    List_removeAt(list, delnum - 1);

    return List_getSize(list);
}

 int checkSrt(struct menuBox box, List* list){
  if(List_isEmpty(list)){
    conMove(box.bottom - 1,  box.left);
    printf(" \tНа жаль, масив структур тепер не містить жодного елемента");
    conHideCursor();
    return 1;
  } else {
    return 0;
  }
}


void conEmptyStr(struct menuBox box){
  int flag = 1;

  while(flag){
  char ch = conGetChar();
  if(isalpha(ch)){
    if('q' == ch){
      flag = 0;
    }
      } else {
        conMove(box.bottom - 1,  box.left);
        printf("\t На жаль, список структур тепер не містить жодного елемента");
        conMove(box.bottom,  box.left);
        printf("\t Операції над списком є неможливими");
        conHideCursor();
    }
  }
}

void drawParametrsList(struct menuBox box){
  int x;
  int y;
  int wildth = 60;

  conSetAttr(BG_BLACK);
  for (x = box.head; x < box.down - 1; x++) {
    for (y =  box.right + 5; y < box.right + 5 + wildth; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }

  conMove(box.head + 1, box.right + 7);
  printf("1. Назва курсу (строка)");
  conMove(box.head + 2, box.right + 7);
  printf("2. Прізвище викладача (строка)");
  conMove(box.head + 3, box.right + 7);
  printf("3. Ім'я викладача (строка)");
  conMove(box.head + 4, box.right + 7);
  printf("4. По-батькові/друге ім'я викладача (строка)");
  conMove(box.head + 5, box.right + 7);
  printf("5. Вік викладача(ціле число)");
  conMove(box.head + 6, box.right + 7);
  printf("6. Тривалість курсу у годинах (ціле число)");
  conMove(box.head + 7, box.right + 7);
  printf("7. Оцінка курсу(дробове число)");
}

void conRefillParam(struct menuBox box, List* list, int quan){
  int line = 0;
  int strNum = 0;
  char str [300];
  int flag = 1;

  while(flag){
    drawDownBox(box);
    conMove(box.bottom - 1,  box.left);
    printf("\t Оберіть зі списку параметрів той, що бажаєте змінити: ");
    line = getInt();
    if(line > 0 && line <= 7){
      flag = 0;
    } else {
      conMove(box.bottom,  box.left);
      printf("\t Невірний номер параметра ");
    }
  }

  flag = 1;

  while(flag){
    drawDownBox(box);
    conMove(box.bottom - 1,  box.left);
    printf("\t Оберіть номер структури, параметр якої бажаєте змінити: ");
    strNum = getInt();
    if(strNum > 0 && strNum <= quan){
      flag = 0;
    } else {
      conMove(box.bottom,  box.left);
      printf("\t Структури з таким порядковим номером не існує ");
    }
  }

  drawDownBox(box);
  conMove(box.bottom - 1,  box.left);
  printf(" Введіть нове значення: ");
  fgets(str, 300, stdin);
  str[strlen(str) - 1] = '\0';

  refillParam(List_get(list, strNum - 1), line, str);
}

void conRefillStruct(struct menuBox box, List* list, int quan){
  int strNum = 0;
  int flag = 1;
  drawDownBox(box);

  while(flag){
    conMove(box.bottom - 1,  box.left);
    printf("\t Оберіть номер структури, параметри якої бажаєте змінити: ");
    strNum = getInt();
    if(strNum > 0 && strNum <= quan){
      flag = 0;
    } else {
      conMove(box.bottom,  box.left);
      printf("\t Структури з таким порядковим номером не існує ");
      drawDownBox(box);
    }
  }

  conMove(box.down + 1,  box.left);
  printf("\t Введіть нові параметри для структури ");
  conFillEl(list, strNum - 1, box);
}

void conSearchStr(struct menuBox box, List* list, int quan){
  int x = 0;
  int resultsc = 0;
  LectureCourse* res [quan];
  int shift = 2;
  char str [20];
  drawDownBox(box);
  conMove(box.bottom - 1,  box.left);
  printf("\t Введіть значення Х: ");
  fgets(str, 20, stdin);
  x = atoi(str);
  drawDownBox(box);

  resultsc = searchStr(list, quan, x, res);
  conMove(box.bottom,  box.left);
  if(resultsc == 0){
    conMove(box.down + 1,  box.left);
    printf("\t Жодної структури з такими значеннями не було знайдено ");
  } else {
    conMove(box.down + 1,  box.left);
    printf("\t Курси, що мають загальну тривалість більше за %i:", x);
    for(int i = 0; i < resultsc; i++){
      conMove(box.down + shift,  box.left);
      printf("\t %s", (LectureCourse_getCourseName(res[i])));
      fflush(stdout);

      shift ++;
    }
  }
}

void conStructToStr(struct menuBox box, List* head, int quan){
  int strNum = 0;
  int flag = 1;
  char str [1000] = "";

  drawDownBox(box);
  while(flag){
    conMove(box.bottom - 1,  box.left);
    printf("\t Оберіть номер структури, яку бажаєте вивести як строку: ");
    strNum = getInt();
    if(strNum > 0 && strNum <= quan){
      flag = 0;
    } else {
      conMove(box.bottom,  box.left);
      drawDownBox(box);
      printf("\t Структури з таким порядковим номером не існує ");
    }
  }

  void* LC = List_get(head, strNum - 1);

  (void) structToStr(LC, str);

  drawDownBox(box);
  conMove(box.down + 1,  box.left + 1);
  conSetAttr(BG_BLACK);
  printf("%s", str);
  
  conSetAttr(BG_CYAN);
}

void freeAll(List* head){
  for(int i = List_getSize(head) - 1; i >= 0; i--){
    void* LC = List_get(head, i);
    if(NULL != LC){
      free(LC); 
    }
  }

  List_free(&head);
}
