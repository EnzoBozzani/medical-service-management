void fetchData(FILE *f, LDE *l)
{
    sleep(2);
    if (access("patients.txt", F_OK) == 0)
    {
        f = fopen("patients.txt", "r");
        Register *p;
        Date *entranceDate;
        int i = 0;
        char buffer[255];
        while (fgets(buffer, 255, f))
        {
            buffer[strcspn(buffer, "\n")] = 0;
            if (i % 6 == 0)
            {
                p = malloc(sizeof(Register));
                entranceDate = malloc(sizeof(Date));
                strcpy(p->name, buffer);
            }
            else if (i % 6 == 1)
            {
                p->age = atoi(buffer);
            }
            else if (i % 6 == 2)
            {
                strcpy(p->rg, buffer);
            }
            else if (i % 6 == 3)
            {
                entranceDate->day = atoi(buffer);
            }
            else if (i % 6 == 4)
            {
                entranceDate->month = atoi(buffer);
            }
            else if (i % 6 == 5)
            {
                entranceDate->year = atoi(buffer);
                p->entranceDate = entranceDate;
                insertLDEElement(l, p);
            }
            i++;
        }
        printf("\nDados de %d pacientes carregados com sucesso\n\n", i / 6);
        fclose(f);
    }
    else
    {
        printf("\nNão há nenhum arquivo a ser salvo\n\n");
    }
    sleep(2);
}

void saveData(FILE *f, LDE *l)
{
    if (access("patients.txt", F_OK) == 0)
    {
        f = fopen("patients.txt", "a");
    }
    else
    {
        f = fopen("patients.txt", "w");
    }
    sleep(2);
    if (l->len == 0)
    {
        printf("\nNenhum paciente registrado\n\n");
    }
    else
    {
        LDEElement *current = l->first;
        while (current != NULL)
        {
            fprintf(f, "%s\n", current->data->name);
            fprintf(f, "%d\n", current->data->age);
            fprintf(f, "%s\n", current->data->rg);
            fprintf(f, "%d\n", current->data->entranceDate->day);
            fprintf(f, "%d\n", current->data->entranceDate->month);
            fprintf(f, "%d\n", current->data->entranceDate->year);
            current = current->next;
        }
        printf("\nDados salvos no arquivo\n\n");
    }
    sleep(2);
    fclose(f);
}
