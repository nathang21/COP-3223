#include <stdio.h>

struct foo{
        int num;
        char* word;
        struct foo *ptr;
};

void func2(struct foo*);
void func3(struct foo*);
void func4(struct foo);

int main() {
        struct foo a;
        a.num = 100;
        a.word = "secondword";
        func2(&a);
        printf("2 %d %s\n", a.num, a.word);

        a.ptr = &a;
        a.num = 50;
        a.word = "mylastword";
        func3(&a);
        printf("4 %d %s\n", a.num, a.word);
        
        a.ptr = &a;
        a.num = 50;
        a.word = "mypastword";
        func4(a);
        printf("6 %d %s\n", a.num, a.word);
system ("pause");}



void func2(struct foo *a)
{
        while(*(a->word) != '\0')
           {
                putchar(*(a->word));
                a->word++;
           }
        putchar('\n');
        if(a->num % 10 != 0)
           { a->num *= 2; }
        a->word--;
        printf("num is %d\n", (*a).num);
}

void func3(struct foo *a)
{
        if( (*a).num ==  a->ptr->num)
          { (*a).num = (* ((*a).ptr)).num +1; }
        else
          { a->num = 200; }

        a->word = "wordsix";
        a->ptr->word = "wordseven";
        
        printf("7th is  %d %s\n", (*a).num, (* ((*a).ptr)).word);
}

void func4(struct foo a)
{
        if( (a).num ==  a.ptr->num)
          { (a).num = (* (a.ptr)).num +1; }
        else
          { a.num = 200; }

        a.word = "wordsix";
        a.ptr->ptr = &a;
        printf("8th is  %d %s\n", (a).num, (*((*(a.ptr)).ptr)).word);
        a.ptr->ptr->word = "wordseven";
        
        printf("9th is  %d %s\n", (a).num, (*((*(a.ptr)).ptr)).word);
}

