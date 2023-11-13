// esse arquivo contém as funções referentes a seção 1 do menu, que está
// relacionada às listas dinâmicas

/// @brief função que realiza a inserção de um elemento no início da LDE
/// @param l lista que deve inserir o elemento
/// @param data dados do elemento a ser inserido
void insertLDEElement(LDE *l, Register *data)
{
    // aloca espaço na memória para o novo elemento
    LDEElement *new = malloc(sizeof(LDEElement));
    // define os dados dele
    new->data = data;
    // define o próximo dele na lista como sendo NULL
    new->next = NULL;
    // caso a lista não seja vazia:
    if (l->first != NULL)
    {
        // define que o próximo do novo elemento é o atual primeiro da lista
        new->next = l->first;
    }
    // define que o primeiro da lista é o novo elemento
    l->first = new;
    // incrementa a quantidade da lista
    l->len++;
}

/// @brief função que realiza a busca por RG
/// @param list lista que deve ser feita a busca
/// @return NULL caso não exista nenhum registro com o RG ou retornando o elemento da LDE referente ao RG
LDEElement *searchByRG(LDE *list)
{
    // é pedido ao usuário o RG a ser buscado
    char rg[255];
    printf("Qual o RG do paciente? ");
    scanf("%s", rg);
    // o elemento atual (que será usado para percorrer a lista) é definido como o primeiro da lista
    LDEElement *current = list->first;
    sleep(1);
    // enquanto o atual for diferente de nulo:
    while (current != NULL)
    {
        // caso o RG informado seja igual ao RG do elemento atual
        if (strcmp(current->data->rg, rg) == 0)
        {
            // quebra o loop
            break;
        }
        // senão:
        else
        {
            // atual é definido como próximo do atual
            current = current->next;
        }
    }

    // por fim, é retornado o valor de atual (ou NULL ou o elemento que o RG bata)
    return current;
}

/// @brief função que remove o elemento da lista
/// @param l lista que terá o elemento removido
/// @param data dados do paciente a ser removido
void removeLDEElement(LDE *l, Register *data)
{
    // caso a lista tenha apenas um elemento:
    if (l->len == 1)
    {
        // o primeiro da lista é definido como NULL
        l->first = NULL;
    }
    // o elemento atual (que será usado para percorrer a lista) é definido como o primeiro da lista
    LDEElement *current = l->first;
    // o elemento anterior é definido como NULL
    LDEElement *previous = NULL;
    // enquanto atual for diferente de NULL e o RG do atual não bater com o RG do elemento a ser removido:
    while (current != NULL && strcmp(current->data->rg, data->rg) != 0)
    {
        // anterior é definido como atual
        previous = current;
        // atual é definido como próximo do atual
        current = current->next;
    }
    // caso atual seja diferente de NULL:
    if (current != NULL)
    {
        // caso anterior seja NULL:
        if (previous == NULL)
        {
            // primeiro da lista é definido como próximo do atual
            l->first = current->next;
        }
        // senão:
        else
        {
            // próximo do anterior é definido como próximo do atual
            previous->next = current->next;
        }
        // o espaço na memória é liberado
        free(current);
        // decrementada a quantidade da lista
        l->len--;
    }
}

/// @brief função que inicializa a lista
/// @return a lista inicializada
LDE *inicializeLDE()
{
    // aloca a memória
    LDE *l = malloc(sizeof(LDE));
    // seta o ponteiro para o primeiro como NULL
    l->first = NULL;
    // seta a quantidade como 0
    l->len = 0;
    // retorna a lista
    return l;
}

/// @brief função que imprime todos os registros na LDE
/// @param l lista que terá os registros impressos
void printLDERegisters(LDE *l)
{
    // o elemento atual (que será usado para percorrer a lista) é definido como o primeiro da lista
    LDEElement *current = l->first;
    sleep(1);
    printf("\nPacientes Cadastrados: \n\n");
    // enquanto atual for diferente de NULL:
    while (current != NULL)
    {
        // imprime as informações
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", current->data->name, current->data->age, current->data->rg, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
        // atual é definido como próximo do atual
        current = current->next;
    }
    sleep(1);
}

/// @brief função que faz o registro de um paciente, lendo os dados e inserindo o elemento na lista
/// @param list lista na qual será inserido o elemento
void registerPatient(LDE *list)
{
    // aloca o espaço na memória
    Register *newPatient = malloc(sizeof(Register));
    // recebe todos os dados informados pelo usuário
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
    // pega o dia, mês e ano do momento que o registro é feito e define como a data de registro
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    Date *entranceDate = malloc(sizeof(Date));
    entranceDate->day = local->tm_mday;
    entranceDate->month = local->tm_mon + 1;
    entranceDate->year = local->tm_year + 1900;
    newPatient->entranceDate = entranceDate;
    // chama a função que insere o paciente na lista, passando como dado as informações lidas do usuário
    insertLDEElement(list, newPatient);
    sleep(1);
    printf("\nUsuário cadastrado com sucesso!\n\n");
    sleep(1);
}

/// @brief função que faz a busca de um paciente específico
/// @param list lista que a busca deve ser feita
void searchPatient(LDE *list)
{
    // chama a função de busca por RG
    LDEElement *current = searchByRG(list);
    // caso o retorno seja NULL:
    if (current == NULL)
    {
        // informa que nenhum registro foi encontrado
        printf("\nNenhum registro encontrado\n\n");
    }
    // senão:
    else
    {
        // imprime as informações do paciente
        printf("\nDados do paciente: \n\tNome: %s\n\tRG: %s\n\tIdade: %d\n\tEntrada: %02d/%02d/%04d\n\n", current->data->name, current->data->rg, current->data->age, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
    }
    sleep(1);
}

/// @brief função que atualiza os dados de um paciente
/// @param list lista que possui os pacientes
void updatePatientData(LDE *list)
{
    // chama a função de busca por RG
    LDEElement *current = searchByRG(list);
    // caso o retorno seja NULL:
    if (current == NULL)
    {
        // informa que nenhum registro foi encontrado
        printf("\nNenhum registro encontrado\n\n");
    }
    // senão:
    else
    {
        // imprime as informações do paciente
        printf("\nDados atuais do paciente: \n\tNome: %s\n\tRG: %s\n\tIdade: %d\n\tEntrada: %02d/%02d/%04d\n\n", current->data->name, current->data->rg, current->data->age, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
        sleep(1);
        // pede os novos dados do paciente e os atualiza
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
    sleep(1);
}

/// @brief função que realiza a remoção do registro de um paciente
/// @param list lista que deve ser removido o paciente
void deletePatient(LDE *list)
{
    // chama a função de busca por RG
    LDEElement *current = searchByRG(list);
    // caso o retorno seja NULL:
    if (current == NULL)
    {
        // informa que nenhum registro foi encontrado
        printf("\nNenhum registro encontrado\n\n");
    }
    // senão:
    else
    {
        // remove o elemento da lista
        removeLDEElement(list, current->data);
        printf("\nRegistro do paciente deletado\n\n");
    }
    sleep(1);
}
