#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    
char input[14];
char isbn[11];

int i = 0;
int sum = 0;
int check = 0;


printf("Enter the input number: ");
scanf("%s", &input);

    for(int i = 0, j; input[i] != '\0'; i++) {
        while(!isdigit(input[i]) && !(input[i] == '\0')) {
            for (j = i; input[j] != '\0'; ++j) {

            // if jth element of line is not a number,
            // assign the value of (j+1)th element to the jth element
            input[j] = input[j + 1];
         }
        }
    }
    

    for(i = 0; i<10; i++)
    {
        isbn[i] = input[i];
    }
    

   
    // Check if the input is valid
    if (strlen(isbn) != 10) {
        printf("Invalid ISBN number.\n");
        return 0;
    }

    // Calculate the sum of the digits
    for (i = 0; i < 9; i++) {
        sum += (isbn[i] - '0') * (i + 1);
    }

    // Calculate the check digit
    check = sum % 11;
    if (check == 10) {
        if (isbn[9] == 'X') {
            printf("Valid ISBN number.\n");
        } else {
            printf("Invalid ISBN number.\n");
        }
    } else {
        if (isbn[9] == (check + '0')) {
            printf("Valid ISBN number.\n");
        } else {
            printf("Invalid ISBN number.\n");
        }
    }

     
    return 0;
}
