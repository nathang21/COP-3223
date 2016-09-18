// Part A
struct ProbationStudentInfo CompareForScholarships (struct StudentInfo A, struct StudentInfo B, int *flag)
{
    if (A.GPA == B.GPA)
    {
        *flag = 0
        return A;
    }
    else
    {
        *flag = 1;
        if (A.GPA > B.GPA)
            return A;
        return B;
    }

};

// Part B
void ProbationCheck (struct StudentInfo A, struct ProbationntInfo *B)
{
    B->studentID = A.studentID;
    B->GPA = A.GPA;
    if (A.GPA < 2)
        B->probational = 'y';
    else
        B->probational = 'n';
}
