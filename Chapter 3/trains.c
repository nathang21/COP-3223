// Nathan Guenther
// 8/22/13
// Approaching Train problem

#include <stdio.h>

#define MINUTES_PER_HOUR 60

int main() {

    double distance, vel1, vel2;
    double min_to_meet;
    double hr_to_meet;
    
    // Recieve imput from user.
    printf("Enter the distance separating the trains.\n");
    scanf("%lf", &distance);

    printf("What is the speed of train 1?\n");
    scanf("%lf", &vel1);

    printf("What is the speed of train 2?\n");
    scanf("%lf", &vel2);

    // Calculation of how long till trains meet.
    hr_to_meet = distance / (vel1 + vel2);
    min_to_meet = hr_to_meet* MINUTES_PER_HOUR;

    // Print out result.
    printf("It will take %.3lf minutes to meet.\n", min_to_meet);

    // Print out distances both trains travel until the meeting point.

    printf("The first train will travel %.2lf miles.\n", vel1 * hr_to_meet );
    printf("The second train will travel %.2lf miles.\n", vel2 * hr_to_meet );
system("pause");
    return 0;
}
