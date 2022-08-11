#include <stdio.h>

int main(void)
{

/* 
    int i =0;
    for(i = 1; i <= 5; i ++)
    printf("Hello MOOCs! (%d)\n", i);       // print 'MOOCS' 5 times and count them

*/



    int i = 0;
    int j = 1;

    int sum = i + j;

    while (sum <= 100)
    {
        /* code */

        i = j;
       

        j = sum;


         for(int count = 0; count < j; count++ )
        {
            printf("*");
        }
        printf("\n");

        sum = i + j;

    

    }

    printf("i = %d \nj = %d|n sum = %d\n", i,j,sum);

    return 0;
}