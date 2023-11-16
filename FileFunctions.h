// esse arquivo contém as funções referentes a seção 4 do menu, que está
// relacionada aos arquivos

/// @brief função que carrega dados do arquivo para a lista de registros
/// @param f arquivo a ter os dados carregados
/// @param l lista que receberá os dados
void fetchData(FILE *f, LDE *l)
{
    sleep(1);
    // caso o arquivo já exista:
    if (access("patients.txt", F_OK) == 0)
    {
        // ele é aberto para leitura
        f = fopen("patients.txt", "r");
        // são declarados os valores que serão usados para leitura do arquivo
        Register *p;
        Date *entranceDate;
        int i = 0;
        char buffer[255];
        // enquanto a linha do arquivo não for vazia:
        while (fgets(buffer, 255, f))
        {
            // é retirado o \n do final da leitura
            buffer[strcspn(buffer, "\n")] = 0;
            // de acordo com o contador, o valor lido é atribuído a um dos atributos do Registro
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
    // caso o arquivo não exista:
    else
    {
        // é informado ao usuário
        printf("\nNão há nenhum arquivo a ser salvo\n\n");
    }
    sleep(1);
}

/// @brief função que salva dados da lista para o arquivo
/// @param f arquivo que recebe os dados
/// @param l lista com os dados
void saveData(FILE *f, LDE *l)
{
    // caso exista o arquivo:
    if (access("patients.txt", F_OK) == 0)
    {
        // é exibida uma opção ao usuário:
        char yesOrNo[255];
        printf("\nATENÇÃO!!! Salvar os dados sobrescreverá os registros existentes no arquivo!\nDigite qualquer coisa e pressione ENTER para salvar dados do programa + dados no arquivo e digite NAO para sobrescrever sem salvar (apenas dados do programa)\n");
        printf("OBS: Recomendamos que escolha a opção NAO caso já tenha carregado os registros do arquivo para o programa nessa utilização, evitando que sejam salvos registros duplicados no arquivo!\nOpção: ");
        scanf("%s", yesOrNo);
        // se a opção for diferente de NAO:
        if (strcmp(yesOrNo, "NAO") != 0)
        {
            // carrega os dados do arquivo antes de salvar
            fetchData(f, l);
        }
    }
    // abre o arquivo pra escrita (apagando os dados do arquivo)
    f = fopen("patients.txt", "w");
    sleep(1);
    // caso a lista seja vazia:
    if (l->len == 0)
    {
        // é informado ao usuário
        printf("\nNenhum paciente registrado\n\n");
    }
    // caso contrário:
    else
    {
        // a lista é percorrida e todos os dados são armazenados no arquivo
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
    sleep(1);
    fclose(f);
}
