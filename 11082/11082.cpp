#include<bits/stdc++.h>

using namespace std;

void abbreviation(long long *numerator, long long *denominator)
{
    for(int i = 2; i <= (*numerator < *denominator ? *numerator : *denominator); ++i)
    {
        while(!(*numerator%i) && !(*denominator%i))
        {
            *numerator /= i;
            *denominator /= i;
        }
    }
}

int main(void)
{
    char string[11] = "";
    char *dot = NULL;
    char *ob = NULL, *cb = NULL;
    long long denominator;
    long long numerator;
    long long a, b;

    scanf("%s", string);

    // find '.'
    for(dot = string; *dot != '.' && *dot != '\0'; ++dot)
        ;
    
    // if no dot.. -> just integer??
    // `123.00000` ....?
    if(*dot == '\0')
    {
        printf("%s/1", string);
        return 0;
    }

    // find bracket
    for(ob = dot+1; *ob != '(' && *ob != '\0'; ++ob)
        ;
    
    // no bracket...
    // abc.defg --> abcdefg/1000
    if(*ob == '\0')
    {
        denominator = 1;
        for(int i =0; i < string + strlen(string) - dot - 1; ++i)
            denominator *= 10;
        
        numerator = 0;
        for(char *p = string; *p != '\0'; ++p)
            if(isdigit(*p))
                numerator = numerator*10 + (*p-'0');
        
        
        abbreviation(&numerator, &denominator);
        printf("%lld/%lld\n", numerator, denominator);
    }
    else // found bracket
    {
        // a.b(c) -> ((a.b.c) - (a.b))/('9'*len(c) + '0'*len(b))
        
        // find close bracket
        for(cb = dot+1; *cb != ')' && *cb != '\0'; ++cb)
            ;
        
        // '9'*len(c) + '0'*len(b)
        denominator = 0;
        for(char *p = ob+1; p < cb; ++p)
            denominator = denominator*10 + 9;
        
        for(char *p = dot+1; p < ob; ++p)
            denominator *= 10;
        
        // numerator a.b
        numerator = atol(string);
        for(char *p = dot+1; p < ob; ++p)
            if(isdigit(*p))
                numerator = numerator*10 + (*p - '0');
        
        // b = a.b
        b = numerator;
        
        // numerator = a.b.c
        for(char *p = ob+1; p < cb; ++p)
            if(isdigit(*p))
                numerator = numerator*10 + (*p - '0');
        
        // (a.b.c) - (a.b)
        numerator -= b;

        abbreviation(&numerator, &denominator);
        printf("%lld/%lld\n", numerator, denominator);
    }
    
    return 0;
}