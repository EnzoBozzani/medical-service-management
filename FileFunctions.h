void fetchData(FILE *f, LDE *l)
{
    sleep(2);
    if (access("patients.txt", F_OK) == 0)
    {
        f = fopen("patients.txt", "r");
        int i = 0;

        while (!feof(f))
        {
            Register *patient = malloc(sizeof(Register));
            fread(patient->name, sizeof(patient->name), 1, f);
            char s1[255];
            fread(s1, sizeof(s1), 1, f);
            sscanf(s1, "%d", &patient->age);
            fread(patient->rg, sizeof(patient->rg), 1, f);
            char s2[255];
            fread(s2, sizeof(s2), 1, f);
            sscanf(s2, "%d/%d/%d", &patient->entranceDate->day, &patient->entranceDate->month, &patient->entranceDate->year);
            insertLDEElement(l, patient);
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
            fprintf(f, "%s\n%d\n%s\n%d/%d/%d\n", current->data->name, current->data->age, current->data->rg, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
            current = current->next;
        }
        printf("\nDados salvos no arquivo\n\n");
    }
    sleep(2);
    fclose(f);
}
