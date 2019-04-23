/*
ENGG1003 Assignment 1
Nick Duffy
Style: Stroustrup
*/

#include <stdio.h> // Used to take inputs from the user

int main()
{
  /*
  Basic GUI, printf() used multiple times to keep code clean as opposed to one extended line.
  Spaces before ordered list to indent list making GUI a little bit nicer.
  */
int menu; // Initialises an integer to be used by the menu do while loop
  do {
    printf("Please select a task:\n");
    printf(" 1. Rotation Cipher Encryption\n");
    printf(" 2. Rotation Cipher Decryption\n");
    printf(" 3. Substitution Cipher Encryption\n");
    printf(" 4. Substitution Cipher Decryption\n");
    scanf("%d", &menu); // \n is not used here it creates an issue where the while condition must be false twice before exiting
      switch (menu) {
        case 1: /*rotationEncryption();*/ break;
        case 2: /*rotationDecryption();*/ break;
        case 3: /*substitutionEncryption();*/ break;
        case 4: /*substitutionDecryption();*/ break;
        default: printf("Invalid input, please try again\n");
      }
  } while(menu < 1 || menu > 4);


  return 0;
}
