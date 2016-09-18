
#include <stdio.h>
#include <math.h>

int main(void) {
    
    int a, b, c;
    double disc, root1, root2;
    
    printf("Enter A, B, and C for the quadratic\n");
    printf("Please keep the values positive to obtain proper roots\n");
    scanf("%d%d%d", &a, &b, &c);
    
    disc = (pow(b,2) -4*a*c);
    
    root1 = (-b + sqrt(disc))/(2*a);
    root2 = (-b - sqrt(disc))/(2*a);
    
    printf("The roots are %.2lf and %.2lf\n", root1, root2);

system("pause");
return 0;
}
