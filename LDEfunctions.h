#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "structs.h"

void insertLDEElement(LDE *l, Register *data)
{
    LDEElement *new = malloc(sizeof(LDEElement));
    new->data = data;
    new->next = NULL;
    if (l->first != NULL)
    {
        new->next = l->first;
    }
    l->first = new;
    l->len++;
}

void removeLDEElement(LDE *l, Register *data)
{
    if (l->len == 1)
    {
        l->first = NULL;
    }
    LDEElement *current = l->first;
    LDEElement *previous = NULL;
    while (current != NULL && strcmp(current->data->rg, data->rg) == 0)
    {
        previous = current;
        current = current->next;
    }
    if (current != NULL)
    {
        if (previous == NULL)
        {
            l->first = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        free(current);
        l->len--;
    }
}

LDE *inicializeLDE()
{
    LDE *l = malloc(sizeof(LDE));
    l->first = NULL;
    l->len = 0;
    return l;
}

void printLDERegisters(LDE *l)
{
    LDEElement *current = l->first;
    sleep(2);
    printf("Pacientes Cadastrados: \n\n");
    sleep(2);
    while (current != NULL)
    {
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %d/%d/%d\n\n", current->data->name, current->data->age, current->data->rg, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
        current = current->next;
    }
    sleep(2);
    printf("\n");
}

void registerPatient(LDE *list)
{
    Register *newPatient = malloc(sizeof(Register));
    printf("Informe os dados do paciente a ser cadastrado.\nNome: ");
    char temp;
    scanf("%c", &temp);
    scanf("%[^\n]s", newPatient->name);
    printf("Idade: ");
    scanf("%c", &temp);
    scanf("%d", &newPatient->age);
    printf("RG: ");
    scanf("%c", &temp);
    scanf("%[^\n]s", newPatient->rg);
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    Date *entranceDate = malloc(sizeof(Date));
    entranceDate->day = local->tm_mday;
    entranceDate->month = local->tm_mon + 1;
    entranceDate->year = local->tm_year + 1900;
    newPatient->entranceDate = entranceDate;
    insertLDEElement(list, newPatient);
    printf("\nUsuário cadastrado com sucesso!\n");
}
