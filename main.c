/*
ENGG1003 Assignment 1
Nick Duffy
Style: Stroustrup
*/

#include <stdio.h> // Used to take inputs from the user

/*
Function Definition
*/
//onst char* rotationEncryption(char plainText, int keyShift);
int main()
{
  /*
  Basic text-based menu, printf() used multiple times to keep code clean as opposed to one extended line.
  Spaces before ordered list to indent list making the menu a little bit nicer.
  As seen in lecture with slight variation.
  */
int menu; // Initialises an integer to be used by the menu do while loop
int keyShift;
char plainText[1024];
char encryptedText[1024];
  do {
    printf("Please select a task:\n");
    printf(" 1. Rotation Cipher Encryption\n");
    printf(" 2. Rotation Cipher Decryption\n");
    printf(" 3. Substitution Cipher Encryption\n");
    printf(" 4. Substitution Cipher Decryption\n");
    scanf("%d", &menu); // Note: \n is not used here it creates an issue where the while condition must be false twice before exiting
      switch (menu) {
        case 1:
          printf("Enter text to be encrypted:\n");
          scanf("%s", plainText); // Stores string in plainText
          printf("Enter enter an integer to rotate the cipher by:\n");
          scanf("%d\n", keyShift);
          keyShift = (keyShift % 26);
          /*If user enters value > 25 key shift value is equivalent to if cipher made multiple rotations.
          Eg. if user enter "26" then cipher rotation is equivalent to a full rotation such that 26 = 0 and text is unchanged.
          *
          rotationEncryption(plainText, keyShift);
          printf("The encrypted text is: %s\n", encryptedText);
          */
        break;
        case 2: /*rotationDecryption();*/ break;
        case 3: /*substitutionEncryption();*/ break;
        case 4: /*substitutionDecryption();*/ break;
        default: printf("Invalid input, please try again\n");
      }
  } while(menu < 1 || menu > 4);


  return 0;
}

//void rotationEncryption() {
  /*
  This while loop converts lowercase to uppercase by testing each value in the string.
  If the tested value is within the value range of lowercase ASCII characters then 32 is subtracted from it.
  32 is the differncqe between the uppercase and lowercase ASCII equivalents.
  Eg. 'a' = 97 and 'A' = 65 hence 97 - 32 = 65

  while (plainText[i] != '/0') {
    if (plainText[i] >= 97 && plainText[i] <= 122) {
      plainText[i] = (plainText[i] - 32)
    }
  }

  store in array
  create for loop
  if ascii value is capital run formula
  else if ascii value is lowercase convert then run formula
  else plain[i] = encrypted[i]
  */

//}
