#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "declaration.h"

int main()
{
    char *title="Adressse IP et reseau";
    int number_of_character=0;
    
    head(title);
    head_of_body();
    
    number_of_character=strlen(getenv("QUERY_STRING"));
    last_test(number_of_character);    
    
    foot_of_body();
    return (0);
}
