#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "storage.h"

void deleteSentences (Text* text);

int main (void) {
    char readFilename [] = "text.txt";
    char writeFilename [] = "out.txt";

    Text* text = fileToText(readFilename);

    deleteSentences (text);

    writeToFile(writeFilename, text);

    Text_freeAll(&text);
    return 0;
}

void deleteSentences (Text* text){
  int i = 0;
  Sentence* cur = Text_getSentence(text, i);

  while(Sentence_isLast(cur) == 0 ){
    if(Sentence_count(cur) < 5){
      Text_deleteAt(text, i);
      i--;
    }
    i++;
    cur = Text_getSentence(text, i);
  }
}
