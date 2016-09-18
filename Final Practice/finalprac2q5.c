#include <stdio.h>

struct foo{
        int num;
        char *word;
        struct foo *ptr;
};
void func1(struct foo);
void func2(struct foo*);
void func3(struct foo);

int main() {
        struct foo a;
        a.num = 5;
        a.word = "myword";
        func1(a);
        printf("1 %d %s\n", a.num, a.word);

        a.num = 100;
        a.word = "secondword";
        func2(&a);
        printf("2 %d %s\n", a.num, a.word);

        a.ptr = &a;
        a.num = 50;
        a.word = "mylastword";
        func3(a);
        printf("4 %d %s\n", a.num, a.word);
}

void func1(struct foo a)
{
        while(*(a.word) != '\0')
           {
                putchar(*(a.word));
                a.word++;
           }
        putchar('\n');
        if(a.num % 10 != 0)
           { a.num *= 2; }
        a.word--;
        printf("num is %d\n", a.num);
}

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

void func3(struct foo a)
{
        if(a.num > a.ptr->num)
          { a.num = 500; }
        else
          { a.num = a.ptr->num + 1; }

        a.word = "myotherword";
        a.ptr->word = "yetanotherword";
        printf("3  %d %s\n", a.num, a.word);
}

