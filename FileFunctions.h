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
            if (i % 4 == 0)
            {
                p = malloc(sizeof(Register));
                entranceDate = malloc(sizeof(Date));
                strcpy(p->name, buffer);
            }
            else if (i % 4 == 1)
            {
                sscanf(buffer, "%d", &p->age);
            }
            else if (i % 4 == 2)
            {
                strcpy(p->rg, buffer);
            }
            else if (i % 4 == 3)
            {
                sscanf(buffer, "%02d/%02d/%04d", &entranceDate->day, &entranceDate->month, &entranceDate->year);
                p->entranceDate = entranceDate;
                insertLDEElement(l, p);
            }
            i++;
        }
        printf("\nDados de %d pacientes carregados com sucesso\n\n", i / 4);
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
        char yesOrNo[255];
        printf("\nATENÇÃO!!! Salvar os dados sobrescreverá os registros existentes no arquivo!\nDigite qualquer coisa e pressione ENTER para salvar dados do programa + dados no arquivo e digite NÃO para sobrescrever sem salvar (apenas dados do programa)\n");
        printf("OBS: Recomendamos que escolha a opção NÃO caso já tenha carregado os registros do arquivo para o programa nessa utilização, evitando que sejam salvos registros duplicados no arquivo!\nOpção: ");
        scanf("%s", yesOrNo);
        if (strcmp(yesOrNo, "NÃO") != 0)
        {
            fetchData(f, l);
        }
    }
    f = fopen("patients.txt", "w");
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
            fprintf(f, "%02d/%02d/%04d\n", current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
            current = current->next;
        }
        printf("\nDados salvos no arquivo\n\n");
    }
    sleep(2);
    fclose(f);
}
