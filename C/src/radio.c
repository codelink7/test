#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BEACONS 30
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH+1];
    double x, y;
} Beacon;

typedef struct {
    double speed, dir;
} Boat;

int num_beacons;
Beacon beacons[MAX_BEACONS];

int read_beacons()
{
    if (scanf("%d", &num_beacons) != 1) return 0;
    for (int i = 0; i < num_beacons; i++) {
        if (scanf("%s %lf %lf", beacons[i].name, &beacons[i].x, &beacons[i].y) != 3)
            return 0;
    }
    return 1;
}

int get_beacon_index(char *name)
{
    for (int i = 0; i < num_beacons; i++) {
        if (strcmp(name, beacons[i].name) == 0)
            return i;
    }
    return -1;
}

void get_beacon_position(int index, double angle, Boat boat, double *dx, double *dy)
{
    double heading = boat.dir + angle;
    if (heading >= 360) heading -= 360;
    *dx = beacons[index].x - boat.speed * sin(heading * M_PI / 180.0);
    *dy = beacons[index].y - boat.speed * cos(heading * M_PI / 180.0);
}

void calculate_position(double x1, double y1, double x2, double y2, double time, Boat boat, double *x, double *y)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dist = sqrt(dx*dx + dy*dy);
    double dir = atan2(dx, dy) * 180.0 / M_PI;
    double heading = boat.dir + dir;
    if (heading >= 360) heading -= 360;
    *x = x2 + boat.speed * time * sin(heading * M_PI / 180.0);
    *y = y2 + boat.speed * time * cos(heading * M_PI / 180.0);
}

int main()
{
    int scenario = 1;
    while (read_beacons()) {
        int num_scenarios;
        if (scanf("%d", &num_scenarios) != 1) break;
        for (int i = 0; i < num_scenarios; i++) {
            double speed, dir;
            if (scanf("%lf %lf", &speed, &dir) != 2) break;
            Boat boat = { speed, dir };
            int index1;
            double angle1;
            if (scanf("%lf %s %lf", &angle1, beacons[0].name, &angle1) != 3) break;
            index1 = get_beacon_index(beacons[0].name);
            if (index1 < 0) break;
            double x1, y1;
            get_beacon_position(index1, angle1, boat, &x1, &y1);
            int index2;
            double angle2;
            if (scanf("%lf %s %lf", &angle2, beacons[0].name, &angle2) != 3) break;
            index2 = get_beacon_index(beacons[0].name);
            if (index2 < 0) break;
            double x2, y2;
            get_beacon_position(index2, angle2, boat, &x2, &y2);
            double time = angle2 - angle1;
            double x, y;
            calculate_position(x1, y1, x2, y2, time, boat, &x, &y);
            if (x < 0 || x > 100 || y < 0 || y > 100)
                printf("Scenario %d: Position cannot be determined.\n", scenario++);
            else
                printf("Scenario %d: Position is (%.2f, %.2f).\n", scenario++, x, y);
        }
    }
    return 0;
}