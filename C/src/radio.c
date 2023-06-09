#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EPSILON 1E-7

typedef struct Point
{
    double x, y;
} Point;

typedef struct Line
{
    double a, b, c;
} Line;

typedef struct Boat
{
    double course, speed;
} Boat;

typedef struct Reading
{
    char name[20];
    double time, angle;
} Reading;

Point beacons[100];
Reading reading1, reading2;
Boat mine;

double getAngle(double angle)
{
    if (angle <= 90.0 + EPSILON)
        return (90.0 - angle);
    else if (angle <= 270.0 + EPSILON)
        return -(angle - 90.0);
    else
        return 180.0 - (angle - 270.0);
}

Line getLine(Reading data)
{
    Line lr;
    double angle = getAngle(mine.course + data.angle);

    if (fabs(fabs(angle) - 90.0) <= EPSILON)
    {
        lr.a = 1.0;
        lr.b = 0.0;
        lr.c = -beacons[atoi(data.name+1)-1].x;
    }
    else
    {
        lr.a = -tan(angle * PI / 180.0);
        lr.b = 1.0;
        lr.c = -(lr.a * beacons[atoi(data.name+1)-1].x + lr.b * beacons[atoi(data.name+1)-1].y);
    }

    return lr;
}

void calculate()
{
    double traveled = (reading2.time - reading1.time) * mine.speed;
    Line line1 = getLine(reading1), line2 = getLine(reading2);
    double boatAngle = mine.course * PI / 180.0;
    double x1 = line1.c * line2.b - line1.b * line2.c -
        line1.b * line2.b * traveled * cos(boatAngle) -
        line1.b * line2.a * traveled * sin(boatAngle);
    x1 = x1 / (line1.b * line2.a - line1.a * line2.b);
    double y1 = line1.c * line2.a - line1.a * line2.c -
        line1.a * line2.a * traveled * sin(boatAngle) -
        line1.a * line2.b * traveled * cos(boatAngle);
    y1 = y1 / (line1.a * line2.b - line1.b * line2.a);

    printf(": Position is (%.2lf, %.2lf)\n", (x1 + traveled * sin(boatAngle)), (y1 + traveled * cos(boatAngle)));
}

int main()
{
    int counter, cases = 0;

    while (scanf("%d", &counter) == 1)
    {
        memset(beacons, 0, sizeof(beacons));

        for (int i = 1; i <= counter; i++)
        {
            char name[20];
            double x, y;
            scanf("%s %lf %lf", name, &x, &y);
            Point location = { x, y };
            beacons[atoi(name+1)-1] = location;
        }

        scanf("%d", &counter);

        for (int i = 1; i <= counter; i++)
        {
            scanf("%lf %lf", &mine.course, &mine.speed);
            scanf("%lf %s %lf", &reading1.time, reading1.name, &reading1.angle);
            scanf("%lf %s %lf", &reading2.time, reading2.name, &reading2.angle);

            printf("Scenario %d", ++cases);

            if (fabs(reading1.angle - reading2.angle) <= EPSILON ||
                fabs(fabs(reading1.angle - reading2.angle) - 180.0) <= EPSILON)
            {
                printf(": Position cannot be determined\n");
                continue;
            }

            calculate();
        }
    }

    return 0;
}