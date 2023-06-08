#include <stdio.h>
#include <math.h>


int main(void)
{
    float points[3][2] = {{0,10},{10,10},{5,0}}             // input points
    float m1,m2,c1,c2;
    m1 = (points[0][1] - points[1][1])/(points[0][0]-points[1][0]); // slope of AB
    m2 = (points[1][1] - points[2][1])/(points[1][0]-points[2][0]); // slope of BC

    float midpoints[2][2] = {{(points[0][0]+ points[1][0])/2 ,(points[0][1]+points[1][1])/2},
    {(points[1][0]+ points[2][0])/2 ,(points[1][1]+points[2][1])/2}}

    c1 = midpoints[0][0]+m1*midpoints[0][1];
    c2 = midpoints[1][0]+m2*midpoints[1][1];

    float x_circle, y_circle , radius;                      // Outputs, finally!

    y_circle = (c2-c1)/(m1-m2);
    x_circle = c1 - y*m1;

    radius = sqrt(pow(y_circle-points[0][1],2),pow(x_circle-points[0][0],2));



    printf("(x-%f)^2 +(y-%f)^2 = %f^2 \n",x_circle, y_circle, radius);





    
    return 0;


}