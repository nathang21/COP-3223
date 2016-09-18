/*
struct citizens
{
    int SSN;
    int phone;

}

struct spying
{
    int phone;
    int aqcalled;

}

struct addmostdangerous
{
    int SSN;
    int badguy;

}*/

struct addmostdangerous f (struct citizens C1, struct spying S1)
{
    struct addmostdangerous A;
    if (C1.phone == S1.phone && S1.aqcalled == 1)
    {
        A.SSN = C1.SSN;
        A.badguy = 1;
        return A;
    }
    else
    {
        A.SSN = C1.SSN;
        A.badguy = 0;
        return A;
    }
}

