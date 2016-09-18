/* struct complex_numb
{
    float real;
    float imaginary;
};

*/


// Part A
struct complex_numb Add_Complex (struct complex_numb C1, struct complex_numb C2)
{
    C1.real = C1.real + C2.real;
    C1.imaginary = C1.imaginary + C2.imaginary;
    return C1;
}

// Part B
void Copy_Complex (struct complex_numb *C1, struct complex_numb C2)
{
    C1->real = C2.real;
    C1->imaginary = C2.imaginary;
}
