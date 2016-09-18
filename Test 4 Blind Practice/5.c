/*

struct Payment
{
    int SSN;
    float fine;
};

*/

int struct IncreaseFine (struct Payment A, struct Payment B, struct Payment *C;)

{
    if (A.SSN == B.SSN)
    {
        (*C) = A.fine + B.fine;
        (*C).SSN = A.SSN;
        (*C) = (*C) * 2;
         return 1;
    }
    else
    {
        return 0;
    }
}
