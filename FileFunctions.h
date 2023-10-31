void saveData(FILE *f, LDE *l){
    sleep(2);
    if (l->len == 0){
        printf("\nNenhum paciente registrado\n\n");
    } else {
        LDEElement *current = l->first;
        while (current != NULL){
            fprintf(f, "Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %d/%d/%d\n\n", current->data->name, current->data->age, current->data->rg, current->data->entranceDate->day, current->data->entranceDate->month, current->data->entranceDate->year);
            current = current->next;
        }
        printf("\nDados salvos no arquivo\n\n");
    }
    sleep(2);
}
