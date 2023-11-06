void fetchData(FILE *f, LDE *l)
{
    sleep(2);
    if (access("patients.txt", F_OK) == 0)
    {
        f = fopen("patients.txt", "r");
        Register *p = malloc(sizeof(Register));
        int i = 0;
        while (!feof(f))
        {
            fgets(p->name, sizeof(p->name), f);
            char age[255];
            fgets(age, sizeof(age), f);
            p->age = atoi(age);
            fgets(p->rg, sizeof(p->rg), f);
            char value[255];
            fgets(value, sizeof(value), f);
            p->entranceDate->day = atoi(value);
            fgets(value, sizeof(value), f);
            p->entranceDate->month = atoi(value);
            fgets(value, sizeof(value), f);
            p->entranceDate->year = atoi(value);
            if (feof(f))
            {
                break;
            }
            insertLDEElement(l, p);
            i++;
        }
        printf("\nDados de %d pacientes carregados com sucesso\n\n", i);
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
