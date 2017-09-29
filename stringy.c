// Kristin Lin
// Systems pd10
// Work 04: Demonstringing Code
// 2017-09-29

#include <string.h>
#include <stdio.h>

// char *strcpy(char *dest, const char *src);
// char *strncpy(char *dest, const char *src, size_t n);

/*---------------DESC.--------------------
strcpy : copies a string from src to dest into buffer; returns dest

strncpy : same as above BUT copies into buffer up to N BYTES [note: may not include NULL; but if less than n, will fill rest of bytes with NULL]
helpful for making sure not to overflow buffer and unused bytes are zeroed out (information leak)
-----------------------------------------*/

//string counter; counts until null is reached
int length(const char * point) {
  const char *i;
  for (i = point; *i; i++); 
  return i - point;
}


//look at each of these variables, esp the memory after NULL in second
int printState(char * sec, char * first, int length) {
  printf("original is: %s\n", first);
  printf("result prints as: %s\n", sec);
  printf("slot of last character: %c\n", sec[length-1]);
  printf("Slot after last character (NULL): %c\n", sec[length]);
  printf("Slot after NULL: %c\n", sec[length+1]);
  printf("-----------------------\n");
}

int main() {

  char * orig = "Hey! This is an awesome demo, and you should enjoy it!";
  char one[200];

  printf("ORIGINAL STATE: \n");
  printf("original is: %s\n", orig);
  printf("result prints as: %s\n", one);
  printf("-----------------------\n");

  //copies with NULL, but not zeroed
  printf("STRCPY EX.1: \n");
  strcpy(one, orig);
  printState(one, orig, length(orig));

  //copies with NULL, extended
  char two[1];
  printf("STRCPY EX.2:\n");
  strcpy(two, orig);
  printState(two, orig, length(orig));
  
  //copies and zeroed
  char three[200];
  printf("STRNCPY EX.1: \n");
  strncpy(three, orig, length(orig));
  printState(three, orig, length(orig));

  //copies, but overflows
  char four[50];
  printf("STRNCPY EX.2: \n");
  strncpy(four, orig, length(orig));
  printState(four, orig, length(orig));
}
