#define NLP
#ifdef NLP


typedef struct Text Text;
typedef struct Sentence Sentence;
typedef struct Word Word;

 Word*  Word_new (char symbols [100]);
 void Word_free (Word** self);
 void Word_getString(Word * self, char* buf);

 Sentence* Sentence_new (void);
 void Sentence_free(Sentence** self);
 void Sentence_add(Sentence* self, Word* wordToAdd);
 int Sentence_count(Sentence* self);
 Word* Sentence_getWord(Sentence* self, int wordInd);
 int Sentence_isLast(Sentence* self);

 Text* Text_new(void);
 void Text_freeAll(Text** self);
 void Text_add(Text* self, Sentence* sentenceToAdd);
 void Text_deleteAt(Text* self, int sentenceInd);
 Sentence* Text_getSentence(Text* self, int sentenceInd);

 #endif
