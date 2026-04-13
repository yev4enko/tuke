// standart dka autom in c lang
#include "libdka.h"

// dka
// q0-q1-q2-q3 end
// q0->a->q1->b->q2->c->q3 end
//(abc)+ automaton

int main()
{
    while (1)
    {
        
        char s[2048];
        printshit();
        scanf("%s", s);
        checkalphabet(s);
        if (dka(s))
            printf("Status: Success!\n");
        else
            printf("Status: Failed!\n");

    }
    return 0;
}
