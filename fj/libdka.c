#include "libdka.h"

bool dka(char s[])
{

    int state = 0;

    for (int i = 0; s[i]; i++)
    {
        switch (state)
        {
        case 0:
            if (s[i] == 'a')
                state = 1;
            else
                return false;
            break;

        case 1:
            if (s[i] == 'b')
                state = 2;
            else
                return false;
            break;

        case 2:
            if (s[i] == 'c')
                state = 0;
            else
                return false;
            break;
        }
    }

    return state == 0;
}

void checkalphabet(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {

        if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c')
        {
            //  printf("||Alphabet error found at char: ");
            // errored chars
            printf("^");

            //  printf("char: {'%c'}; pos: [%d]\n", s[i], i + 1);
        }
        else printf(" ");
    }

    printf("\n");
}

void printshit()
{
    printf("Assigned lib: {a,b,c} | (abc)+ automaton\n");
    printf("q0->a->q1->b->q2->c->q3 end; Lib errors will be marked with ('^') sign\n");
}