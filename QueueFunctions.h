// esse arquivo contém as funções referentes a seção 2 do menu, que está
// relacionada às filas

/// @brief função que cria a fila
/// @return fila inicializada
Queue *createQueue()
{
    // aloca o espaço na memória
    Queue *queue = malloc(sizeof(Queue));
    // seta o head como NULL
    queue->head = NULL;
    // tail como NULL
    queue->tail = NULL;
    // quantidade como 0
    queue->len = 0;
    // retorna a fila
    return queue;
}

/// @brief função que cria o elemento da fila
/// @param data os dados do elemento
/// @return o elemento inicializado
QueueElement *createQueueElement(Register *data)
{
    // aloca o espaço na memória
    QueueElement *queueElement = malloc(sizeof(QueueElement));
    // seta os dados
    queueElement->data = data;
    // seta o próximo do elemento como NULL
    queueElement->next = NULL;
    // retorna o elemento inicializado
    return queueElement;
}

/// @brief função que faz o enfileiramento
/// @param queue fila que terá o elemento enfileirado
/// @param list lista com os registros
void enqueue(Queue *queue, LDE *list)
{
    // faz a busca por RG para ver se o cadastro existe
    LDEElement *patient = searchByRG(list);
    // se o retorno for NULL (cadastro não existe):
    if (patient == NULL)
    {
        // informado que o cadastro não existe
        printf("\nPaciente não cadastrado\n\n");
    }
    // senão:
    else
    {
        // cria o elemento da fila
        QueueElement *newQueueElement = createQueueElement(patient->data);
        // caso a fila seja vazia:
        if (queue->len == 0)
        {
            // tanto tail quanto head da fila são definidos como o novo elemento
            queue->tail = newQueueElement;
            queue->head = newQueueElement;
        }
        // senão:
        else
        {
            // próximo do tail é definido como novo elemento
            queue->tail->next = newQueueElement;
            // tail é definido como novo elemento
            queue->tail = newQueueElement;
        }
        // incrementa a quantidade
        queue->len++;
        printf("\nPaciente enfileirado!\n\n");
    }
    sleep(1);
}

/// @brief função que faz o desenfileiramento
/// @param queue fila que será feito o desenfileiramento
/// @return os dados do paciente desenfileirado
Register *dequeue(Queue *queue)
{
    // guarda o endereço do elemento que será desenfileirado
    QueueElement *address = queue->head;
    // caso a fila seja vazia:
    if (address == NULL)
    {
        // informa ao usuário e retorna NULL
        printf("\nA fila já está vazia!\n\n");
        return NULL;
    }
    // guarda dados do elemento que será desenfileirado
    Register *data = queue->head->data;
    // caso a fila tenha 1 elemento:
    if (queue->len == 1)
    {
        // head e tail definidos como NULL
        queue->head = NULL;
        queue->tail = NULL;
    }
    // senão:
    else
    {
        // head é definido como próximo do HEAD
        queue->head = queue->head->next;
    }
    // libera o endereço e decrementa a quantidade
    free(address);
    queue->len--;
    sleep(1);
    printf("\nPaciente de RG %s desenfileirado com sucesso!\n\n", data->rg);
    sleep(1);
    return data;
}

/// @brief função que imprime os elementos da fila
/// @param queue fila que terá os elementos impressos
void printQueue(Queue *queue)
{
    sleep(1);
    // caso o tamanho da fila seja 0:
    if (queue->len == 0)
    {
        // informa ao usuário
        printf("\nFila está vazia!\n\n");
    }
    // senão:
    else
    {
        // exibe a fila para o usuário
        printf("\nFila: \n\n");
        QueueElement *current = queue->head;
        int i = 1;
        while (current != NULL)
        {
            printf("%d.\nNome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", i, current->data->name, current->data->age, current->data->rg, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
            current = current->next;
            i++;
        }
    }
    sleep(1);
}