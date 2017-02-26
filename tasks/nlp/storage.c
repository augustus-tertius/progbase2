#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "storage.h"


Text* fileToText(char filename [100]){

  FILE * fr = fopen(filename, "r");
  assert(fr != NULL);

  char buf [200] = "\0";
  Text* text = Text_new();
  Sentence* curSentence = Sentence_new();
  Text_add(text, curSentence);

  while(!feof(fr)){
    fscanf(fr,"%s", buf);
    char lastCh;
    int length = 0;

    for(; buf[length] != '\0'; length++){
      lastCh = buf[length];
    }

    if(isalnum(lastCh)){
      Word* wordToAdd = Word_new(buf);
      Sentence_add(curSentence, wordToAdd);

    } else if(lastCh == '.' || lastCh == '?' || lastCh == '!'){
      buf[length - 1] = '\0';

      if(strcmp(buf, "")){
        Word* wordToAdd = Word_new(buf);
        Sentence_add(curSentence, wordToAdd);
      }

      curSentence = Sentence_new();
      Text_add(text, curSentence);
      buf[0] = '\0';
    } else if(lastCh == ',' || lastCh == ':' || lastCh == ';') {
      buf[length - 1] = '\0';

      Word* wordToAdd = Word_new(buf);
      Sentence_add(curSentence, wordToAdd);
    }
  }


  fclose(fr);

  return text;
}

int writeToFile(char filename [100], Text * text){
  FILE * fw = fopen(filename, "w");
  if(fw == NULL){
    return 1;
  }

  int sentenceInd = 0;
  Sentence* curSentence = Text_getSentence(text, sentenceInd);;

  while(curSentence != NULL){
    int wordInd = 0;
    Word* curWord = Sentence_getWord(curSentence, wordInd);
    while(curWord != NULL){
      char buf [200] = "\0";
      Word_getString(curWord, buf);
      fprintf(fw, "%s, ", buf);

      wordInd++;
      curWord = Sentence_getWord(curSentence, wordInd);
    }

    fprintf(fw, "\n");

    sentenceInd++;
    curSentence = Text_getSentence(text, sentenceInd);
  }


  fclose(fw);
  return 0;
}
