/*
ENGG1003 Assignment 1
Nick Duffy
Style: Stroustrup
*/

#include <stdio.h> // Used to take inputs from the user

/*
Write Output Function:
Opens output.txt and writes string encryptedText.
*/

int writeOutput();

/*
Read Input Function:
Opens input.txt and stores it in plainText as a string.
*/

int readInput();

/*
Rotation Encryption Function:
Returns char encryptedText and uses function literal plainText[] as to not modify original plainText.
*/

void rotationEncryption(char plainText[],char *encryptedText, int keyShift);

/*
Case Conversion Function:
Returns void and uses *plainText pointer as it is modifying string.
*/

void caseConversion(char *plainText);

int main() {
  char plainText[1024];
  char encryptedText[1024];
  int keyShift;

  /*
  Basic text-based menu, printf() used multiple times to keep code clean as opposed to one extended line.
  Spaces before ordered list to indent list making the menu a little bit nicer.
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
        case 1:
          printf("Text to be encrypted will now be read from input.txt ...\n");
          readInput(plainText);
          caseConversion(plainText);
          printf("Text found:");
          puts(plainText);
          printf("Enter enter an integer to rotate the cipher by:\n");
          scanf("%d", &keyShift);
          keyShift = (keyShift % 26);
          /*If user enters value > 25 key shift value is equivalent to if cipher made multiple rotations.
          Eg. if user enter "26" then cipher rotation is equivalent to a full rotation such that 26 = 0 and text is unchanged.
          */
          rotationEncryption(plainText, encryptedText, keyShift);
          writeOutput(encryptedText);
          printf("Encrypted text has been written to output.txt\n");
        break;
        case 2: /*rotationDecryption();*/ break;
        case 3: /*substitutionEncryption();*/ break;
        case 4: /*substitutionDecryption();*/ break;
        default: printf("Invalid input, please try again\n");
      }
  } while(menu < 1 || menu > 4);


  return 0;
}

/*
Read Input Function:
Uses C file I/O to open a text file and store text to plainText string to be encrypted by another function.
*/

int readInput(char *plainText) { // plainText as pointer as function should modify.
  FILE * fp;
  fp = fopen("input.txt", "r");
  if(fp == NULL) {
    perror("Error opening file"); // If file cannot be opened returns an error message to the user and exits program.
    return(-1);
  }
  else {
    fgets(plainText, 1024, fp); // Stores string in plainText
  }
  fclose(fp);
}

int writeOutput(char encryptedText[]) { // encryptedText as literal as it shouldn't modify string
  FILE * fp;
  fp = fopen("output.txt", "w"); //Truncates the file length to zero if it already exists, limiting double outputs.
  if(fp == NULL) {
    perror("Error opening file"); // If file cannot be opened returns an error message to the user and exits program.
    return(0);
  }
  else {
    fputs(encryptedText, fp); // writes string encryptedText to output.txt .
  }
  fclose(fp);
}

/*
Case Conversion Function:
Uses a while loop to convert lowercase to uppercase by testing each value in the string.
If the tested value is within the literal value range of lowercase ASCII characters then 32 is subtracted from it.
32 is the differncqe between the uppercase and lowercase ASCII equivalents.
Eg. 'a' = 97 and 'A' = 65 hence 97 - 32 = 65
*/

void caseConversion(char *plainText) {
  int i = 0;
  while(plainText[i] != '\0') {
    if (plainText[i] >= 'a' && plainText[i] <= 'z') {
      plainText[i] = (plainText[i] - 32);
    }
    i++;
  }
}

void rotationEncryption(char plainText[], char *encryptedText, int keyShift) {
  int i = 0;
  while(plainText[i] != '\0') {
    if(plainText[i] >= 65 && plainText[i] <= 90){
      encryptedText[i] = ((plainText[i] - 65 + keyShift) % 26 + 65);
      /*
       As 'A' has an ASCII literal value of 65 this is subtracted from the equation before the modulus operator and added back after.
       For the purpose of the modulus operator this sets A = 0, B = 1, C = ... Z = 25.
       This allows the equation to operate as outlined in the Assingment 1 document; "e(x) = (m + k)(mod 26)"
      */
    }
    else {
      encryptedText[i] = plainText[i];
    }
    i++;
  }
}

//}
