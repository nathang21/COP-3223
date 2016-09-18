/*
struct StudentInfo
{
    int studentID;
    float GPA;
}

struct ProbationStudentInfo
{
    int studentID;
    float GPA;
    char probational;
}

Note

PBV __ (Pass by Value)
PBR *& (Pass by Reference) (& is for when you call in main, * for functions)



*/

// Part A
CompareForScholarships (struct StudentInfo A, struct StudentInfo B, int *flag)
{
    if (A.GPA == B.GPA)
    {
        *flag = 0;
        return A;
    }
    else
    {
        *flag = 1;
        if (A.GPA > B.GOA)
            return A;
        else
            return B;
    }
}

// Part B
void ProbationCheck (struct StudentInfo A, struct ProbationStudentInfo *B;)
{
    (*B).studentID = A.studentID;
    (*B).GPA = A.GPA;
    if (A.GPA < 2.0)
    {
        (*B).probational = 'y';
    }
    else
        (*B).probational = 'n';
}
