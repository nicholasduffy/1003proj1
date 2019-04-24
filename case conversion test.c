#include <stdio.h>

int main() {
  char plainText[1024];
  printf("enter words\n");
  scanf("%s\n", plainText );
  int i = 0;
  while (plainText[i] != '0') {
    if (plainText[i] >= 97 && plainText[i] <= 122) {
      plainText[i] = (plainText[i] - 32);
    }
    i++;
  }
printf("%s\n", plainText);
  return 0;
}
