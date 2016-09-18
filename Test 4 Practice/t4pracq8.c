/* Assume

struct TuitionOwed
{
    int SSN;
    float tuition
};

struct DateToday
{
    int month;
    int day;
    int year
};

*/

// Part A
struct TuitionOwed UpdateTuition (struct TuitionOwed TO1, struct DateToday DO1)
{
    struct TuitionOwed TO2;
    if (DO1.month > 8)
    {
        TO2.SSN = TO1.SSN;
        T02.tuition = TO1.tuition * 1.1
        return TO2;
    }
    else
    {
        return TO1;
    }

}

// Part B
void UpdateTuition (struct TuitionOwed TO1, struct DateToday DO1, struct TuitionOwed* TO2)
{
    (*TO2).SSN = T01.SSN;
    if (DO1.month > 8)
    {
        TO2->tuition = TO1.tuition * (1.1);
    }
    else
    {
        (*TO2).tuition = TO1.tuition;
    }
}
