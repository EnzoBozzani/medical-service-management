Queue *createQueue()
{
    Queue *queue = malloc(sizeof(queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->len = 0;
    return queue;
}

QueueElement *createQueueElement(Register *data)
{
    QueueElement *queueElement = malloc(sizeof(QueueElement));
    queueElement->data = data;
    queueElement->next = NULL;
    return queueElement;
}

void enqueue(Queue *queue, LDE *list)
{
    LDEElement *patient = searchByRG(list);
    if (patient == NULL)
    {
        printf("\nEsse paciente não está cadastrado\n\n");
    }
    else
    {
        QueueElement *newQueueElement = createQueueElement(patient->data);
        if (queue->len == 0)
        {
            queue->tail = newQueueElement;
            queue->head = newQueueElement;
            queue->len++;
        } else {
            queue->tail->next = newQueueElement;
            queue->tail = newQueueElement;
            queue->len++;
        }
        printf("\nPaciente enfileirado!\n\n");
    }
    sleep(2);
}

Register* dequeue(Queue *queue)
{
    QueueElement *address = queue->head;
    Register *data = queue->head->data;
    if (queue->len == 1)
    {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
    }
    free(address);
    queue->len--;
    sleep(2);
    printf("\nPaciente de RG %s desenfileirado com sucesso!\n\n", data->rg);
    sleep(2);
    return data;
}

void printQueue(Queue *queue)
{
    sleep(2);
    if (queue->len == 0){
        printf("\nFila está vazia!\n\n");
    } else {
        printf("\nFila: \n\n");
        QueueElement *current = queue->head;
        int i = 0;
        while (current != NULL)
        {
            printf("%d\n\tNome: %s\n\tIdade: %d\n\tRG: %s\n\tData de entrada: %d/%d/%d\n\n", i, current->data->name, current->data->age, current->data->rg, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
            current = current->next;
            i++;
        }
    }
    sleep(2);
}