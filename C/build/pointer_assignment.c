#include <stdio.h>
#include <math.h>


float s_x(float*, unsigned int);             /* sum of Xn*/
float s_xy(float*, float*, unsigned int);      /* sum of Xn*Yn*/
float s_x2(float*, unsigned int);            /* sum of x^2*/



int main()
{

    unsigned int num_points;

    printf("Hello, This is a program to calculate the best fit line equation. \n");
    printf("Please enter the number of points\n");
    scanf("%d",&num_points);


    float X[num_points];  
    float Y[num_points];

    for(int i = 0; i<=num_points-1; i++)
    {
        printf("Enter the number of X\n");
        
        scanf("%f", &X[i]);
        printf("Enter the number of Y\n");
        
        scanf("%f", &Y[i]);

    }
    
    
    float x_avg = s_x(X,num_points)/num_points;
    float y_avg = s_x(Y, num_points)/num_points;

    float b = (num_points*s_xy(X,Y, num_points) - s_x(X,num_points)*s_x(Y, num_points))/(num_points*s_x2(X,num_points) - pow(s_x(X,num_points),2.0)); 
    float a = y_avg - b*x_avg;

    
    printf("the equation of the best fit is: y = %f + %fx \n ", a,b);

    printf("mean of X-values = %f\n mean of y-values = %f\n" , x_avg , y_avg);

    return 0;
}


float s_x(float *X, unsigned int num_points)
{

    int i = 0;
    float result = 0;
    float *ptr = NULL;

    for(i = 0; i < num_points-1; i++)
    {   ptr = X +i;
        result += *ptr;
    }

    return result;
}


float s_xy(float *X, float *Y, unsigned int num_points)
{
    float result = 0;

    int i;

    float *ptrx = NULL;
    float *ptry = NULL;

    
    for(i = 0; i <num_points-1; i++)
    {
        ptrx = X + i;
        ptry = Y + i;
        result += *ptrx * *ptry;
    }
    return result;

}

float s_x2(float *X, unsigned int num_points)
{

    float result = 0;
    int i;
    float *ptr = NULL;

    
    for(i = 0; i <num_points-1; i++)
    {
        ptr = X + i;
        result += *ptr * *ptr;
    }
    return result;

}