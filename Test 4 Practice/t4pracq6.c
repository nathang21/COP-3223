/* Assume

struct gas
{
    float distance;
    float gals;
    float mpg;
};

*/

// Part A
struct gas t4pracq6A (struct gas A)
{
    A.mpg = A.distance / A.gals;
    return A.mpg;
};

// Part B
void struct gas t4pracq6B (struct gas *A)
{
    A.mpg = A.distance / A.gals;
};
