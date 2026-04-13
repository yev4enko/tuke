#include "libdka.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool dka(char s[])
{
    int state = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (state == 0 && s[i] == 'a')
        {
            state = 1;
        }
        else if (state == 1 && s[i] == 'b')
        {
            state = 2;
        }
        else if (state == 2 && s[i] == 'c')
        {
            state = 0;
        }
        else
        {
            return false;
        }
    }

    return (state == 0);
}

void checkalphabet(char s[])
{

    char alphabet[] = {'a', 'b', 'c'};
    for (int i = 0; s[i] != '\0'; i++)
    {
        bool state = 1;
        for (int j = 0; alphabet[j] != '\0'; j++)
        {
            if (s[i] == alphabet[j])
            {
                state = 1;
                break;
            }
            else
            {
                state = 0;
            }
        }
        if (!state)
        {
            printf("Alphabet error found at char: {'%c'}; positon: [%d]\n", s[i], i + 1);
        }
    }

    printf("\n");
}

void printshit()
{
    printf("Assigned lib: {a,b,c} | (abc)+ automaton\n");
    printf("q0->a->q1->b->q2->c->q3 end\n");
}