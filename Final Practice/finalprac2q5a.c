#include <stdio.h>

struct foo{
        int num;
        char* word;
        struct foo *ptr;
};

int* t;
void func1(struct foo);
void func2(struct foo*);
void func3(struct foo);

int main() {
        struct foo a;
        a.num = 5;
        
       // a.word = "whichword";
       // printf("char2=%c\n", a.word );
       
        a.word[0]='r';
        a.word[1]='d';
        a.word[2]='\0';
        
        //strcpy(a.word,"whoseword");
        //a.word[3]='D';
    
        printf("char3=%s\n", a.word );
        
        a.word[0]='y';
        a.word[1]='o';
        a.word[2]='r';
        a.word[3]='w';
        a.word[4]='o';
        a.word[5]='r';
        a.word[6]='d';
        a.word[7]='\0';
       // a.word[2]='p';
        
        printf("char4=%s\n", a.word );
       // a.word = "myword";
        //printf("char2=%c\n", a.word[2] );
        printf("char2=%s\n", a.word );
        //a.word[2]='p';
        func1(a);
        printf("1 %d %s\n\n\n", a.num, a.word);

        a.num = 100;
        a.word = "secondword";
        func2(&a);
        printf("2 %d %s\n", a.num, a.word);

        a.ptr = &a;
        a.num = 50;
        a.word = "mylastword";
        func3(a);
        printf("4 %d %s\n", a.num, a.word);
system ("pause");}

void func1(struct foo a)
{       //a.word="whose";

         //strcpy(a.word, "whatever");
         printf("str=%s\n", a.word);
         //a.word="whense";
         //strcpy(a.word, "whenwhyever");
         printf("str=%s\n", a.word);
        while(*(a.word) != '\0')
           {
                putchar(*(a.word));
                a.word++;
           }
        putchar('\n');
       
         strcpy(a.word, "whatever");
        
        if(a.num % 10 != 0)
           { a.num *= 2; }
        a.word--;
        strcpy(a.word, "whatever");
                a.word[0]='Q';
       // a.word[1]='\0';
        
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

