#include "monty.h"

int main()
{
    char **splited = _split("manzana banana campana", " ");
    int i = 0;
 
    for (i = 0; splited && splited[i]; i++)
        printf("%s\n", splited[i]);

    for (i = 0; splited && splited[i]; i++)
        free(splited[i]);
    free(splited);
    
    return 0;

}
