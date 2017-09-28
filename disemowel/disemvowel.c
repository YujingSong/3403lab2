#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include "disemvowel.h"

int check_vowel(char c);

char* disemvowel(char* str) {
  int i,j = 0;
  int counter = 1;
  char* t;
  for(i = 0; str[i] != '\0'; i++) {
    if(check_vowel(str[i]) == 0) {    
      counter++;
    }
  }
  
  t = (char *) calloc(counter, sizeof(char));

  for(i = 0; str[i] != '\0'; i++) {
    if(check_vowel(str[i]) == 0) {    
      t[j] = str[i];
      j++;
    }
  }

  t[j] = '\0';

  return t;
}

int check_vowel(char c){
  switch(c) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      return 1;
    default:
      return 0;
  }
}
