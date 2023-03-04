#include <stdio.h>

int power (int base, int exp)
{

	int result = 1;
	if(exp > 0)
	{
		while(exp!=0)
		{
			result = base * result;
			exp--;
		}

		return result;

	}

	

	else
		return 0;


}




int main(void)
{

	int input = 0;
	int num = 0;
	int Digit_num;
	int Flag = 0;

	

	printf("enter number \n");

	scanf("%d", &input);

	num = input;
	
	for(Digit_num = 0; num >0; Digit_num++)
	{
		num = num/10;
	}
	num = input;
	int Array[Digit_num];
	int Digit = Digit_num;

	printf("number of digits = %d \n", Digit_num);


	for(int i = 0;Digit_num>=1; Digit_num-- && i++)
	{
		if(Digit_num == 1)
		{
			Array[i] = num;
			break;
		}

		Array[i] = num/power(10,Digit_num-1);
		num = num%power(10,Digit_num-1);

		
				

	}
		for(int i = 0; i<Digit; i++)
		{

			printf("%d\n", Array[i]);
		}


	for(int i = 0; i <(Digit-1)/2; i++)
	{
		if(Array[i] != Array[Digit-1-i])
		{
			Flag = 1;
		}
		
	}

	if(Flag == 1)
	{
		printf("Number is not palindrome\n");


	}

	else
		printf("Number is palindrome\n");

	
	


    
   return 0;
      
    
    
}
