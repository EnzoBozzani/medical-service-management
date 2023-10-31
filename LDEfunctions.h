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

LDEElement *searchByRG(LDE *list)
{
    char rg[255];
    printf("Qual o RG do paciente? ");
    scanf("%s", rg);
    LDEElement *current = list->first;
    sleep(1);
    while (current != NULL)
    {
        if (strcmp(current->data->rg, rg) == 0)
        {
            break;
        }
        else
        {
            current = current->next;
        }
    }

    return current;
}

void removeLDEElement(LDE *l, Register *data)
{
    if (l->len == 1)
    {
        l->first = NULL;
    }
    LDEElement *current = l->first;
    LDEElement *previous = NULL;
    while (current != NULL && strcmp(current->data->rg, data->rg) != 0)
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
    printf("\nPacientes Cadastrados: \n\n");
    sleep(2);
    while (current != NULL)
    {
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %d/%d/%d\n\n", current->data->name, current->data->age, current->data->rg, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
        current = current->next;
    }
    sleep(2);
}

void registerPatient(LDE *list)
{
    Register *newPatient = malloc(sizeof(Register));
    printf("\nInforme os dados do paciente a ser cadastrado.\nNome: ");
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
    sleep(2);
    printf("\nUsuário cadastrado com sucesso!\n\n");
    sleep(1);
}

void searchPatient(LDE *list)
{
    LDEElement *current = searchByRG(list);
    if (current == NULL)
    {
        printf("\nNenhum registro encontrado\n\n");
    }
    else
    {
        printf("\nDados do paciente: \n\tNome: %s\n\tRG: %s\n\tIdade: %d\n\tEntrada: %d/%d/%d\n\n", current->data->name, current->data->rg, current->data->age, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
    }
    sleep(2);
}

void updatePatientData(LDE *list)
{
    LDEElement *current = searchByRG(list);
    if (current == NULL)
    {
        printf("\nNenhum registro encontrado\n\n");
    }
    else
    {
        printf("\nDados atuais do paciente: \n\tNome: %s\n\tRG: %s\n\tIdade: %d\n\tEntrada: %d/%d/%d\n\n", current->data->name, current->data->rg, current->data->age, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
        sleep(2);
        printf("Informe os dados do paciente a ser atualizado.\nNome: ");
        char temp;
        scanf("%c", &temp);
        scanf("%[^\n]s", current->data->name);
        printf("Idade: ");
        scanf("%c", &temp);
        scanf("%d", &current->data->age);
        printf("RG: ");
        scanf("%c", &temp);
        scanf("%[^\n]s", current->data->rg);
        printf("\nUsuário atualizado com sucesso!\n\n");
    }
    sleep(2);
}

void deletePatient(LDE *list)
{
    LDEElement *current = searchByRG(list);
    if (current == NULL)
    {
        printf("\nNenhum registro encontrado\n\n");
    }
    else
    {
        removeLDEElement(list, current->data);
        printf("\nRegistro do paciente deletado\n\n");
    }
    sleep(2);
}
