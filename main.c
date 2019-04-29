/*
ENGG1003 Assignment 1
Nick Duffy
Style: Stroustrup
High Level Operation:
The program uses a series of functions to encrypt and decrypt text from an input text file and outputs encrypted / decrypted text to an output text file.
An operation is selected from a text-based menu and the program enters a switch case for that specific operation triggering a series of functions to complete the desired task.
Text inputs (plain or encrypted text) is taken from input.txt and all outputs (decrypted/plain text or encrypted text) are written to output.txt, with the excemption of the ciper key.
Supstituiton encryption / decryption requires a 26 character cipher key, this key must be written to cipherkey.txt for the program to function.
Flow control mechanisms include the switch case previously mentioned and while loops to scan through strings and test / alter literal values.
Each function is brielfy described before they are declared and explained in detail before they are defined.
*/

#include <stdio.h> // Used to take inputs from the user

/*
Write Encrypted Function:
Opens output.txt and writes string encryptedText.
*/

int writeEncrypted(char encryptedText[]);

/*
Read Plain Function:
Opens input.txt and stores text in plainText as a string.
*/

int readPlain(char *plainText);

/*
Write Plain Function:
Opens output.txt and writes string plainText.
*/

int writeDecrypted(char plainText[]); // String as literal as function shouldn't modify original.

/*
Read Encrypted Function:
Opens input.txt and stores text in encryptedText as a string.
*/

int readEncrypted(char *encryptedText); // String as pointer as function should modify.

/*
Read Key Function:
Opens cipherkey.txt and stores value as string in cipherKey.
*/

int readKey(char cipherKey[]);

/*
Note: All file IO functions have an int return type because if a file cannot be opened the "perror" function will trigger and cause an error message to be displayed and the program will be exited with a "return 0;"
*/

/*
Rotation Encryption Function:
Returns string encryptedText and uses function literal plainText[] as to not modify original plainText.
*/

void rotationEncryption(char plainText[],char *encryptedText, int keyShift);

/*
Rotation Decryption Function:
Returns string plainText and used function literal encryptedText[] as to not modify original.
*/

void rotationDecryption(char encryptedText[], char *plainText, int keyShift);

/*
Substitution Encryption Function:
Substitutes literal values of string plainText using another string cipherKey to encrypt text.
*/

void substitutionEncryption(char plainText[], char *encryptedText, char cipherKey[]);

/*
Substitution Decryption Function:
Substitutes literal values of string encryptedText using another string cipherKey to decrypt text.
*/

void substitutionDecryption(char encryptedText[], char *plainText, char cipherKey[]);

/*
Cipher Check Function:
Tests values of cipherKey to find the postion where its match lies.
*/

int cipherCheck(char cipherKey[], char encryptedText);

/*
Case Conversion Function:
Returns void as it is modifying a string within the function and therefore does not need to return a seperate string.
Uses *plainText pointer as it is modifying string.
*/

void caseConversion(char *plainText);

int main() {
  char plainText[1024];
  char encryptedText[1024];
  int keyShift;
  char cipherKey[27]; // Cipher key is 26 characters long so string must 27 bytes to accomodate 26 chars (1 byte each) and the '/0' NULL charater.

  /*
  Basic text-based menu, printf() used multiple times to keep code clean as opposed to one extended line.
  Spaces before ordered list to indent list making the menu a little bit nicer to read.
  As seen in lecture with slight variation.
  */

  int menu; // Initialises an integer to be used by the "menu" do while loop
  do {
    printf("Please select a task:\n");
    printf(" 1. Rotation Cipher Encryption\n");
    printf(" 2. Rotation Cipher Decryption\n");
    printf(" 3. Substitution Cipher Encryption\n");
    printf(" 4. Substitution Cipher Decryption\n");
    scanf("%d", &menu); // Note: \n is not used here it creates an issue where the while condition must be false twice before exiting
      switch (menu) {
        case 1:
          printf("Text to be encrypted will now be read from input.txt ... \n");
          readPlain(plainText); // Opens input.txt and writes to plainText string.
          caseConversion(plainText);
          printf("Text found:");
          puts(plainText);
          printf("Enter enter an integer to rotate the cipher by:\n");
          scanf("%d", &keyShift);
          /*
          If user enters value > 25 key shift value is equivalent to if cipher made multiple rotations.
          Eg. If user enter "26" then cipher rotation is equivalent to a full rotation such that 26 = 0 and text is unchanged.
          */
          rotationEncryption(plainText, encryptedText, keyShift);
          writeEncrypted(encryptedText);
          printf("Encrypted text has been written to output.txt\n");
          printf("Encrypted text:");
          puts(encryptedText);
        break;
        case 2:
        printf("Text to be decrypted will now be read from input.txt ...\n");
        readEncrypted(encryptedText);
        caseConversion(encryptedText);
        printf("Text found:");
        puts(encryptedText);
        printf("Enter enter an integer to rotate the cipher by:\n");
        scanf("%d", &keyShift);
        keyShift = (keyShift % 26);
        /*As above if user enters value > 25 key shift value is equivalent to if cipher made multiple rotations.
        Eg. If user enter "26" then cipher rotation is equivalent to a full rotation such that 26 = 0 and text is unchanged.
        */
        rotationDecryption(encryptedText, plainText, keyShift);
        writeDecrypted(plainText);
        printf("Decrypted text has been written to output.txt\n");
        printf("Decrypted text:");
        puts(plainText);
        break;
        case 3:
        printf("Text to be encrypted will now be read from input.txt ... \n");
        readPlain(plainText);
        caseConversion(plainText);
        printf("Text found:");
        puts(plainText);
        printf("Cipher key will now be read from cipherkey.txt ... \n");
        readKey(cipherKey);
        printf("Cipher found:");
        puts(cipherKey);
        substitutionEncryption(plainText, encryptedText, cipherKey);
        writeEncrypted(encryptedText);
        printf("Encrypted text has been written to output.txt\n");
        printf("Encrypted text:");
        puts(encryptedText);
        break;
        case 4:
        printf("Text to be decrypted will now be read from input.txt ... \n");
        readEncrypted(encryptedText);
        caseConversion(encryptedText);
        printf("Text found:");
        puts(encryptedText);
        printf("Cipher key will now be read from cipherkey.txt ... \n");
        readKey(cipherKey);
        printf("Cipher found:");
        puts(cipherKey);
        substitutionDecryption(encryptedText, plainText, cipherKey);
        writeDecrypted(plainText);
        printf("Decrypted text has been written to output.txt\n");
        printf("Decrypted text:");
        puts(plainText);
        break;
        default: printf("Invalid input, please try again\n");
      }
  } while(menu < 1 || menu > 4); // Allows user to re-attempt menu selction should they have a temporary lapse of motor control (press the wrong button).


  return 0;
}

/*4
Read Plain Function:
Uses stdio.h to open input.txt text file and store text to plainText string to be encrypted by another function.
FILE * fp sets the file structure and fopen sets the file pointer (fp) to the desired file (input.txt)
*/

int readPlain(char *plainText) { // plainText as pointer as function should modify.
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

/*
Write Encrypted Function:
Uses stdio.h to open output.txt text file and write encryptedText string.
FILE * fp sets the file structure and fopen sets the file pointer (fp) to the desired file (output.txt)
*/

int writeEncrypted(char encryptedText[]) {  // encryptedText as literal as it shouldn't modify string
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
Read Encrypted Function:
Uses stdio.h to open input.txt text file and store text to encryptedText string to be decrypted by another function.
FILE * fp sets the file structure and fopen sets the file pointer (fp) to the desired file (input.txt)
*/

int readEncrypted(char *encryptedText) { // plainText as pointer as function should modify.
  FILE * fp;
  fp = fopen("input.txt", "r");
  if(fp == NULL) {
    perror("Error opening file"); // If file cannot be opened returns an error message to the user and exits program.
    return(-1);
  }
  else {
    fgets(encryptedText, 1024, fp); // Stores string in encryptedText
  }
  fclose(fp);
}

/*
Write Decrypted Function:
Uses stdio.h to open output.txt text file and write plainText string.
FILE * fp sets the file structure and fopen sets the file pointer (fp) to the desired file (output.txt)
*/

int writeDecrypted(char plainText[]) { // plainText as literal as it shouldn't modify string
  FILE * fp;
  fp = fopen("output.txt", "w"); //Truncates the file length to zero if it already exists, limiting double outputs.
  if(fp == NULL) {
    perror("Error opening file"); // If file cannot be opened returns an error message to the user and exits program.
    return(0);
  }
  else {
    fputs(plainText, fp); // writes string plainText to output.txt .
  }
  fclose(fp);
}

/*
Read Key Function:
Uses stdio.h functions to read text from cipherkey.txt and store as a string in cipherKey.
FILE * fp sets the file structure and fopen sets the file pointer (fp) to the desired file (cipherkey.txt)
*/

int readKey(char cipherKey[]) {
  FILE * fp;
  fp = fopen("cipherkey.txt", "r");
  if(fp == NULL) {
    perror("Error opening file"); // If file cannot be opened returns an error message to the user and exits program.
    return(0);
  }
  else {
    fgets(cipherKey, 27, fp); // fgets function scans the text file and stores as string in cipherKey.
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

/*
Rotation Encryption Function:
Based on equation e(m) = (m + k)(mod 26) from the assingment outline this function writes each charater to from plainText to encryptedText.
By using an if statment the fucntion detects uppercase ASCII characters by testing if literal value falls between the uppercase ASCII range (65 - 90).
When it detects an uppercase charater it applies the e(m) = (m + k)(mod 26) equation to them, otherwise writing to encryptedText unchanged, thus converting
only applicable characters.
*/

void rotationEncryption(char plainText[], char *encryptedText, int keyShift) {
  int i = 0;
  while(plainText[i] != '\0') {
    if(plainText[i] >= 65 && plainText[i] <= 90){
      encryptedText[i] = (((plainText[i] - 65 + keyShift) + 26) % 26 + 65);
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

/*
Rotation Decryption Function:
Based on equation d(c) = (c - k)(mod 26) from the assingment outline this function writes each charater from encryptedText to plainText.
By using an if statment the fucntion detects uppercase ASCII characters by testing if literal value falls between the uppercase ASCII range (65 - 90).
When it detects an uppercase charater it applies the d(c) = (c - k)(mod 26) equation to them, otherwise writing to plainText unchanged, thus converting
only applicable characters.
*/

void rotationDecryption(char encryptedText[], char *plainText, int keyShift) {
  int i = 0;
  while(encryptedText[i] != '\0') {
    if(encryptedText[i] >= 65 && encryptedText[i] <= 90){
      plainText[i] = (((encryptedText[i] - 65 - keyShift) + 26) % 26 + 65);
      /*
       As above 'A' has an ASCII literal value of 65 this is subtracted from the equation before the modulus operator and added back after.
       For the purpose of the modulus operator this sets A = 0, B = 1, C = ... Z = 25.
       This allows the equation to operate as outlined in the Assingment 1 document; "d(c) = (m - k)(mod 26)"
      */
    }
    else {
      plainText[i] = encryptedText[i]; // Forgot to switch the sides of this cheeky bugger and it was only decrypting up until the first space.
    }
    i++;
  }
}

/*
Substitution Encryption Function:
The substitiution encryption function works on the principle that each literal value from 'A' - 'Z' has a corresponding literal value in cipherKey[].
By creating a loop an expression cipherValue is used to find an integer for each literal value such that 'A' - 'Z' is set = 0 - 25
Hence cipherValue = 0 when plainText['A'], this is used in encryptedText[i] = cipherKey[cipherValue] so when plainText[i] is = 'A' cipherValue is equal to 0.
When cipherValue is = 0 the first value of the cipherKey is used to substitute 'A', the second value of the cipher for plainText['B'] and so on.
Any literal values outside of the uppercase ASCII range are written to encryptedText as is.
*/

void substitutionEncryption(char plainText[], char *encryptedText, char cipherKey[]) {
  int i = 0;
  while(plainText[i] != '\0') {
    int cipherValue = (plainText[i] - 'A'); // Sets 'A' = 0, 'B' = 1, 'C' = 2, ... 'Z' = 25
    if(plainText[i] >= 65 && plainText[i] <= 90){
      encryptedText[i] = cipherKey[cipherValue];
    }
    else{
      encryptedText[i] = plainText[i];
    }
    i++;
  }
}

/*
Substitution Decryption Function:
The substitiution decryption function works on the principle that each literal value from 'A' - 'Z' has a corresponding literal value in cipherKey[].
A while loop finds the literal value of each element of encryptedText and passes this value to the function cipherCheck() to test each value of cipherKey.
cipherCheck() returns an integer corresponding to the array element of cipherKey that matches with the literal value of encryptedText initially passed to the function.
When encryptedText is = 0 the corresponding literal value of cipherKey (cipherValue) is used to substitute 'A', encryptedText[] = 1 the corresponding cipherKey value (cipherValue) is used to substitute 'B' and so on.
Hence plainText can be found by taking the cipherValue of each element of encryptedText and adding 'A' as 'A' was subtracted prior to encryption in substitutionEncryption() function.
Any literal values outside of the uppercase ASCII range are written to plainText as is.
*/

void substitutionDecryption(char encryptedText[], char *plainText, char cipherKey[]) {
  int i = 0;
  while(encryptedText[i] != '\0') {
    if(encryptedText[i] >= 65 && encryptedText[i] <= 90){
      int cipherValue = cipherCheck(cipherKey, encryptedText[i]);
      plainText[i] = cipherValue + 'A'; // As 'A' was subtracted prior to encryption.
    }
    else{
      plainText[i] = encryptedText[i];
    }
    i++;
  }
}

/*
Cipher Check Function:
Uses a while loop to scan the string cipherKey.
Returns an integer corresponding to the array element of cipherKey that has a literal value equal to the value of string encryptedText passed to function.
*/

int cipherCheck(char cipherKey[], char encryptedText) {
  int i = 0;
  while(i < 25) {
    if(cipherKey[i] == encryptedText) {
      return i;
    }
    i++;
  }
}

//}
