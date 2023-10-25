#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"
#include "structs.h"

int main()
{
    char option[255];
    menu(option);
    if (strcmp(option, "1a") == 0)
    {
        // função que realiza o cadastro de pacientes na fila
    }
    else if (strcmp(option, "1b") == 0)
    {
        // função que realiza a consulta de paciente cadastrado
    }
    else if (strcmp(option, "1c") == 0)
    {
        // função que mostra a lista de pacientes cadastrados
    }
    else if (strcmp(option, "1d") == 0)
    {
        // função que atualiza os dados de algum paciente
    }
    else if (strcmp(option, "1e") == 0)
    {
        // função que remove o paciente
    }
    // e por ai vai
    else
    {
        sleep(1);
        printf("\nSELECIONE UMA OPÇÃO VÁLIDA!\n\n");
        sleep(1);
        main();
    }
    return 0;
}