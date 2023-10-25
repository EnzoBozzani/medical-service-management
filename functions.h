void menu(char *option)
{
    printf("Bem vindo ao aplicativo de gerenciamento de serviços de saúde!\n");
    printf("Selecione a opção (OBS: 1, 2, 3 e 4 não são opções disponíveis, apenas 1a, 2b, etc ou 5)\n1 - Cadastrar\n\t1a - Cadastrar novo paciente\n\t1b - Consultar paciente cadastrado\n\t1c - Mostrar lista completa\n\t1d - Atualizar dados de paciente\n\t1e - Remover paciente\n");
    printf("2 - Atendimento\n\t2a - Enfileirar paciente\n\t2b - Desenfileirar paciente\n\t2c - Mostrar fila\n");
    printf("3 - Pesquisa\n\t3a - Mostrar registros ordenados por ano de registro\n\t3b - Mostrar registros ordenados por mês de registro\n\t3c - Mostrar registros ordenados por dia de registro\n\t3d - Mostrar registros ordenados por idade do paciente\n");
    printf("4 - Carregar/ Salvar\n\t4a - Ler arquivo com dados dos pacientes\n\t4b - Salvar arquivo com dados dos pacientes\n");
    printf("5 - Sobre\nOpção: ");
    scanf("%s", option);
}