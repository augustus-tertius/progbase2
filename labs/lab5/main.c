#include <progbase.h>
#include <pbconsole.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <CUI.h>




int main(void){

    int exit = 1;
    int quan = 0;

    drawBox();
    void* list = startMenu(&quan);
    printMainMenu();

    while(exit) {
      char ch;
      ch = conGetChar();

      int check = checkSrt(list);
      if(check){
        conEmptyStr();
        freeAll(list);
        exit = printGB();
      }

      if(isalpha(ch)){
        if('q' == ch){
          freeAll(list);
          exit = printGB();
          break;
        }
        if('s' == ch){
          int status = conSaveToFile(list, quan);
            if(status){
              printMainMenu();
              printMessage("Зміни успішно збережені");
            } else {
              printMessage("На жаль, при збереженні файлу виникла помилка");
            }
            pEnterOperationCode();
        }
      } else if(isdigit(ch)){
          if('1' == ch) {
            quan = conDeleteStruct(list, quan);
            printMainMenu();
            int check = checkSrt(list);
            if(check){
              conEmptyStr();
              freeAll(list);
              exit = printGB();
            } else {
              pEnterOperationCode();
            }
          }
          if('2' == ch) {
            drawParametrsList();
            conRefillStruct(list, quan);
            drawDownBox();
            pEnterOperationCode();
          }
          if('3' == ch){
            drawParametrsList();
            conRefillParam(list, quan);
            drawDownBox();
            pEnterOperationCode();
          }
          if('4' == ch){
            conSearchStr(list, quan);
            pEnterOperationCode();
          }
          if('5' == ch){
            conStructToStr(list, quan);
            pEnterOperationCode();
          }
        } else {
          drawBox();
          printMainMenu();
          printMessage("Неправильно введений номер операції");
          pEnterOperationCode();
        }
      }

  return 0;
}
