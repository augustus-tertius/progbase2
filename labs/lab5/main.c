#include <progbase.h>
#include <pbconsole.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <CUI.h>

int main(void){


    struct menuBox box = {4, 32, 4, 70, 7, 20};
    int exit = 1;
    int quan = 0;

    drawBox(box);
    void* list = startMenu(box, &quan);
    printMainMenu(box);

    while(exit) {
      char ch;
      ch = conGetChar();
      //printf("%c", ch);

      int check = checkSrt(box, list);
      if(check){
        conEmptyStr(box);
        freeAll(list);
        exit = printGB(box);
      }

      if(isalpha(ch)){
        if('q' == ch){
          freeAll(list);
          exit = printGB(box);
          break;
        }
        if('t' == ch){
          drawDownBox(box);
          //tests();
          conMove(box.down + 1,  box.left);
          printf("\t Нічого не відбулося, отже все працює");
          pEnterOperationCode(box);
        }
        if('s' == ch){
          int status = conSaveToFile(box, list, quan);
            if(status){
              printMainMenu(box);
              conMove(box.bottom,  box.left);
              printf("\t Зміни успішно збережені ");
            } else {
              conMove(box.bottom,  box.left);
              printf("\t На жаль, при збереженні файлу виникла помилка ");
            }
            pEnterOperationCode(box);
        }
      } else if(isdigit(ch)){
          if('1' == ch) {
            quan = conDeleteStruct(box, list, quan);
            printMainMenu(box);
            int check = checkSrt(box, list);
            if(check){
              conEmptyStr(box);
              freeAll(list);
              exit = printGB(box);
            } else {
              pEnterOperationCode(box);
            }
          }
          if('2' == ch) {
            drawParametrsList(box);
            conRefillStruct(box, list, quan);
            drawDownBox(box);
            pEnterOperationCode(box);
          }
          if('3' == ch){
            drawParametrsList(box);
            conRefillParam(box, list, quan);
            drawDownBox(box);
            pEnterOperationCode(box);
          }
          if('4' == ch){
            conSearchStr(box, list, quan);
            pEnterOperationCode(box);
          }
          if('5' == ch){
            conStructToStr(box, list, quan);
            pEnterOperationCode(box);
          }
        } else {
          drawBox(box);
          printMainMenu(box);
          conMove(box.bottom, box.left);
          printf("\t Неправильно введений номер операції");
          pEnterOperationCode(box);
        }
      }

  return 0;
}
