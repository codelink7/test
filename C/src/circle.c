#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float points[3][2];                              // input points

    scanf("%f %f %f %f %f %f",&points[0][0],&points[0][1], &points[1][0], &points[1][1],& points[2][0], &points[2][1]);
    float m1,m2,c1,c2;
    float midpoints[2][2] = {{(points[0][0]+ points[1][0])/2 ,(points[0][1]+points[1][1])/2},{(points[1][0]+ points[2][0])/2 ,(points[1][1]+points[2][1])/2}};
    float x_circle, y_circle , radius;               // Outputs, finally!

    if((points[0][1] - points[1][1])/(points[0][0]-points[1][0]) ==(points[1][1] - points[2][1])/(points[1][0]-points[2][0]) )
    {
        printf("three points are collinear\n circle with infinite radius!\n");
        exit(0);
    }

   if(points[0][0]-points[1][0] == 0.0)
    {
        m2 = (points[1][1] - points[2][1])/(points[1][0]-points[2][0]);
        c2 = midpoints[1][0]+m2*midpoints[1][1];
        y_circle = midpoints[0][1];
        x_circle = c2 - y_circle*m2;


    }


     else if(points[1][0]-points[2][0] == 0.00)
    {
        m1 = (points[0][1] - points[1][1])/(points[0][0]-points[1][0]);
        c1 =  midpoints[0][0]+m1*midpoints[0][1];
        y_circle = midpoints[1][1];
        x_circle = c1 - y_circle*m1;

    }
    else {


    m1 = (points[0][1] - points[1][1])/(points[0][0]-points[1][0]);  // slope of AB
    m2 = (points[1][1] - points[2][1])/(points[1][0]-points[2][0]);  // slope of BC
    

    c1 = midpoints[0][0]+m1*midpoints[0][1];
    c2 = midpoints[1][0]+m2*midpoints[1][1];


    y_circle = (c2-c1)/(m2-m1);
    x_circle = c1 - y_circle*m1;
    }


    radius = sqrt(pow(y_circle-points[0][1],2)+pow(x_circle-points[0][0],2));
    printf("(x%+.02f)^2 +(y%+.02f)^2 = %.02f^2 \n",-x_circle, -y_circle, radius);
    printf("x^2 + yx^2 %+0.2fx %+0.2fy %+0.2f = 0\n ", -2*x_circle,-2*y_circle ,x_circle*x_circle + y_circle*y_circle - radius*radius );

    return 0;


}