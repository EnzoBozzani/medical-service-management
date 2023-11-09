// importação das bibliotecas que serão utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "structs.h"
#include "LDEfunctions.h"
#include "QueueFunctions.h"
#include "BSTFunctions.h"
#include "FileFunctions.h"

/// @brief função que imprime o menu
/// @param option opção a ser lida
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
    // declara o arquivo, a string de opção, a lista e a fila
    FILE *file;
    char option[255];
    LDE *registeredPatients = inicializeLDE();
    Queue *queue = createQueue();
    printf("Bem vindo ao aplicativo de gerenciamento de serviços de saúde!\n");
    // enquanto a opção for diferente de 6:
    while (strcmp(option, "6") != 0)
    {
        // chama o menu e entra em uma das condições dependendo da opção
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
            enqueue(queue, registeredPatients);
        }
        else if (strcmp(option, "2b") == 0)
        {
            dequeue(queue);
        }
        else if (strcmp(option, "2c") == 0)
        {
            printQueue(queue);
        }
        else if (strcmp(option, "3a") == 0)
        {
            showOrderedByParam(registeredPatients, "ano de registro");
        }
        else if (strcmp(option, "3b") == 0)
        {
            showOrderedByParam(registeredPatients, "mês de registro");
        }
        else if (strcmp(option, "3c") == 0)
        {
            showOrderedByParam(registeredPatients, "dia de registro");
        }
        else if (strcmp(option, "3d") == 0)
        {
            showOrderedByParam(registeredPatients, "idade");
        }
        else if (strcmp(option, "4a") == 0)
        {
            fetchData(file, registeredPatients);
        }
        else if (strcmp(option, "4b") == 0)
        {
            saveData(file, registeredPatients);
        }
        else if (strcmp(option, "5") == 0)
        {
            printf("\nEsse sistema foi desenvolvido por Enzo Bozzani, do 4º Semestre de Ciência da Computação, como projeto final da disciplina de Estrutura de Dados (CC4652).");
            printf("\nO sistema começou a ser desenvolvido no dia 25/10/2023 e teve seu desenvolvimento finalizado no dia 09/11/2023.");
            printf("\nÉ possível acessar a documentação, os commits e todo o código fonte no repositório do GitHub: https://github.com/EnzoBozzani/medical-service-management");
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
    // libera a memória
    free(registeredPatients);
    free(queue);
    return 0;
}