#include <stdio.h>

void caseConversion(char *plainText);

int main() {
  char plainText[12];
  printf("enter words\n");
  gets(plainText);
  caseConversion(plainText);
  puts(plainText);

  return 0;
}

void caseConversion(char *plainText) {
  int i = 0;
  while(plainText[i] != '\0') {
    if (plainText[i] >= 'a' && plainText[i] <= 'z') {
      plainText[i] = (plainText[i] - 32);
    }
    i++;
  }
}
