#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "structs.h"
#include "LDEfunctions.h"
#include "FileFunctions.h"

void menu(char *option)
{
    printf("Selecione a opção (OBS: 1, 2, 3 e 4 não são opções disponíveis, apenas 1a, 2b, etc ou 5 ou 6)\n1 - Cadastrar\n\t1a - Cadastrar novo paciente\n\t1b - Consultar paciente cadastrado\n\t1c - Mostrar lista completa\n\t1d - Atualizar dados de paciente\n\t1e - Remover paciente\n");
    printf("2 - Atendimento\n\t2a - Enfileirar paciente\n\t2b - Desenfileirar paciente\n\t2c - Mostrar fila\n");
    printf("3 - Pesquisa\n\t3a - Mostrar registros ordenados por ano de registro\n\t3b - Mostrar registros ordenados por mês de registro\n\t3c - Mostrar registros ordenados por dia de registro\n\t3d - Mostrar registros ordenados por idade do paciente\n");
    printf("4 - Carregar/ Salvar\n\t4a - Ler arquivo com dados dos pacientes\n\t4b - Salvar arquivo com dados dos pacientes\n");
    printf("5 - Sobre\n6 - Sair\nOpção: ");
    scanf("%s", option);
}

int main()
{
    FILE *file;
    if (access("patients.txt", F_OK) == 0)
    {
        file = fopen("patients.txt", "a");
    }
    else
    {
        file = fopen("patients.txt", "w");
    }
    char option[255];
    LDE *registeredPatients = inicializeLDE();
    printf("Bem vindo ao aplicativo de gerenciamento de serviços de saúde!\n");
    while (strcmp(option, "6") != 0)
    {
        menu(option);
        if (strcmp(option, "1a") == 0)
        {
            registerPatient(registeredPatients);
        }
        else if (strcmp(option, "1b") == 0)
        {
            searchPatient(registeredPatients);
        }
        else if (strcmp(option, "1c") == 0)
        {
            printLDERegisters(registeredPatients);
        }
        else if (strcmp(option, "1d") == 0)
        {
            updatePatientData(registeredPatients);
        }
        else if (strcmp(option, "1e") == 0)
        {
            deletePatient(registeredPatients);
        }
        else if (strcmp(option, "2a") == 0)
        {
            //...
        }
        else if (strcmp(option, "4b") == 0)
        {
            saveData(file, registeredPatients);
        }
        else if (strcmp(option, "6") == 0)
        {
            sleep(1);
            printf("\nObrigado por utilizar!\n\n");
            sleep(1);
        }
        else
        {
            sleep(1);
            printf("\nSELECIONE UMA OPÇÃO VÁLIDA!\n\n");
            sleep(1);
        }
    }
    fclose(file);
    free(registeredPatients);
    return 0;
}