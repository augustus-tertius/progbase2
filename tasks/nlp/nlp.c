#include "nlp.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>


struct Word {
    char symbols [100];
    Word * next;
};

struct Sentence {
    Word * firstWord;
    Sentence * next;
};

struct Text {
    Sentence * firstSentence;
};



Word*  Word_new (char buf [100]) {
    Word * pWord = (Word *) malloc(sizeof(Word));
    if(NULL != pWord){
        strcpy( pWord->symbols, buf);
    }

    return pWord;
}

void Word_free (Word** self){
  free(*self);
  *self = NULL;
}

 Sentence* Sentence_new (void){
   Sentence* pSentence = (Sentence *) malloc(sizeof(Sentence));
   if(NULL != pSentence){
     pSentence->firstWord = NULL;
     pSentence->next = NULL;
   }

   return pSentence;
 }

 void  Word_getString(Word * self, char* buf){
   strcpy (buf, self->symbols);
 }

 void Sentence_free(Sentence** self){
   while((*self)->firstWord != NULL){
     Word * toBeDeleted = (*self)->firstWord;
     (*self)->firstWord = (*self)->firstWord->next;
     Word_free(&toBeDeleted);
   }
   free(*self);
   *self = NULL;
 }


 void Sentence_add(Sentence* self, Word* wordToAdd){
   if(NULL == self->firstWord){
     self->firstWord = wordToAdd;
   } else {
     Word * cur = self->firstWord;
     while(cur->next != NULL){
       cur = cur->next;
     }
     cur->next = wordToAdd;
   }
 }

  int Sentence_count(Sentence* self){
    int count = 0;
    Word * cur = self->firstWord;

    while(cur != NULL){
      cur = cur->next;
      count++;
    }

    return count;
  }

  Word* Sentence_getWord(Sentence* self, int wordInd){
    Word * cur = self->firstWord;

    for(int i = 0; i != wordInd; i++){
      cur = cur->next;
    }

    return cur;
  }

  int Sentence_isLast(Sentence* self){
    if(self->next != NULL){
      return 0;
    } else {
      return 1;
    }
  }

  Text* Text_new(void){
    Text* pText = (Text *) malloc(sizeof(Text));
    if(NULL != pText){
      pText->firstSentence = NULL;
    }

    return pText;
  }

   void Text_freeAll(Text** self){
     while((*self)->firstSentence != NULL){
       Sentence * toBeDeleted = (*self)->firstSentence;
       (*self)->firstSentence = (*self)->firstSentence->next;
       Sentence_free(&toBeDeleted);
     }

     free(*self);
     *self = NULL;
   }

   void Text_add(Text* self, Sentence* sentenceToAdd){
     if(NULL == self->firstSentence){
       self->firstSentence =  sentenceToAdd;
     } else {
       Sentence * cur = self->firstSentence;
       while(cur->next != NULL){
         cur = cur->next;
       }
       cur->next = sentenceToAdd;
     }
   }

   void Text_deleteAt(Text* self, int sentenceInd){

     if(sentenceInd == 0){
       Sentence* toBeDeleted = self->firstSentence;
       if(toBeDeleted != NULL){
         self->firstSentence = toBeDeleted->next;
       }
       Sentence_free(&toBeDeleted);

     } else {
       Sentence * cur = self->firstSentence;

       int i = 0;
       while (cur->next->next != NULL && i != sentenceInd - 1) {
             i += 1;
             cur = cur->next;
       }
       if (i != sentenceInd - 1) assert(0);
       Sentence * toBeDeleted = cur->next;
       cur->next = toBeDeleted->next;

       Sentence_free(&toBeDeleted);
     }
   }

   Sentence* Text_getSentence(Text* self, int sentenceInd){
     Sentence * cur = self->firstSentence;

     for(int i = 0; i != sentenceInd && cur != NULL; i++){
       cur = cur->next;
     }

     return cur;
   }
