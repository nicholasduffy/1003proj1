/*
ENGG1003 Assignment 1
Nick Duffy
Style: Stroustrup
*/

#include <stdio.h> // Used to take inputs from the user

/*
Function Definition
*/
void rotationEncryption();
int main()
{
  /*
  Basic GUI, printf() used multiple times to keep code clean as opposed to one extended line.
  Spaces before ordered list to indent list making GUI a little bit nicer.
  As seen in lecture with slight variation.
  */
int menu; // Initialises an integer to be used by the menu do while loop
  do {
    printf("Please select a task:\n");
    printf(" 1. Rotation Cipher Encryption\n");
    printf(" 2. Rotation Cipher Decryption\n");
    printf(" 3. Substitution Cipher Encryption\n");
    printf(" 4. Substitution Cipher Decryption\n");
    scanf("%d", &menu); // Note: \n is not used here it creates an issue where the while condition must be false twice before exiting
      switch (menu) {
        case 1: rotationEncryption(); break;
        case 2: /*rotationDecryption();*/ break;
        case 3: /*substitutionEncryption();*/ break;
        case 4: /*substitutionDecryption();*/ break;
        default: printf("Invalid input, please try again\n");
      }
  } while(menu < 1 || menu > 4);


  return 0;
}

void rotationEncryption() {
  int keyShift;
  char plainText[1024];
  scanf("Enter text to be encrypted\n", plainText);
}
