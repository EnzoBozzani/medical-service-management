// esse arquivo contém as funções referentes a seção 3 do menu, que está
// relacionada às árvores binárias de busca

/// @brief função que imprime os registros na árvore em ordem de idade
/// @param root nó a partir do qual é feita a impressão
void inOrder(BSTElement *root)
{
    // se a raiz for diferente de NULL:
    if (root != NULL)
    {
        // chama a função novamente, passando o filho esquerdo
        inOrder(root->left);
        // printa os dados
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        // chama a função novamente, passando o filho direito
        inOrder(root->right);
    }
}

/// @brief cria elemento da árvore binária de busca
/// @param tree árvore que terá o elemento criado
/// @param data dados do elemento
/// @return elemento inicializado
BSTElement *createBSTElement(BST *tree, Register *data)
{
    // aloca espaço na memória
    BSTElement *newBSTElement = malloc(sizeof(BSTElement));
    // seta os filhos e o pai como NULL
    newBSTElement->right = NULL;
    newBSTElement->left = NULL;
    newBSTElement->parent = NULL;
    // seta os dados
    newBSTElement->data = data;
    // retorna o elemento inicializado
    return newBSTElement;
}

/// @brief cria árvore binária de busca
/// @return árvore inicializada
BST *createBST()
{
    // aloca espaço na memória
    BST *tree = malloc(sizeof(BST));
    // seta a raiz como NULL
    tree->root = NULL;
    // o tamanho como 0
    tree->len = 0;
    // retorna a árvore
    return tree;
}

/// @brief insere o elemento na árvore de maneira ordenada quanto à idade do paciente
/// @param tree árvore a ter o elemento inserido
/// @param data dados do elemento a ser inserido
void insertBSTElementByAge(BST *tree, Register *data)
{
    // cria o elemento da árvore
    BSTElement *newBSTElement = createBSTElement(tree, data);
    // se a raiz for NULL (árvore vazia):
    if (tree->root == NULL)
    {
        // a raiz é o novo elemento
        tree->root = newBSTElement;
    }
    // caso contrário:
    else
    {
        // o elemento atual (que será usado para percorrer a árvore) é definido como a raiz
        BSTElement *current = tree->root;
        // o anterior é setado como NULL
        BSTElement *previous = NULL;
        // enquanto o atual for diferente de NULL:
        while (current != NULL)
        {
            // se a idade do novo elemento for menor que a idade do atual:
            if (data->age < current->data->age)
            {
                // anterior é definido como atual
                previous = current;
                // atual é definido como filho esquerdo do mesmo
                current = current->left;
            }
            // caso contrário:
            else
            {
                // anterior é definido como atual
                previous = current;
                // atual é definido como filho direito do mesmo
                current = current->right;
            }
        }
        // se a idade do novo elemento for menor que a idade do anterior:
        if (data->age < previous->data->age)
        {
            // filho esquerdo do anterior é definido como novo elemento
            previous->left = newBSTElement;
        }
        // caso contrário:
        else
        {
            // filho direito é definido como novo elemento
            previous->right = newBSTElement;
        }
        // pai do novo elemento é definido como anterior
        newBSTElement->parent = previous;
    }
    // quantidade é incrementada
    tree->len++;
}

/// @brief insere o elemento na árvore de maneira ordenada quanto ao dia de registro
/// @param tree árvore a ter o elemento inserido
/// @param data dados do elemento a ser inserido
void insertBSTElementByDay(BST *tree, Register *data)
{
    // mesmo procedimento da outra função de inserção, porém o parâmetro de ordenação é o dia de entrada
    BSTElement *newBSTElement = createBSTElement(tree, data);
    if (tree->root == NULL)
    {
        tree->root = newBSTElement;
    }
    else
    {
        BSTElement *current = tree->root;
        BSTElement *previous = NULL;
        while (current != NULL)
        {
            if (data->entranceDate->day < current->data->entranceDate->day)
            {
                previous = current;
                current = current->left;
            }
            else
            {
                previous = current;
                current = current->right;
            }
        }
        if (data->entranceDate->day < previous->data->entranceDate->day)
        {
            previous->left = newBSTElement;
        }
        else
        {
            previous->right = newBSTElement;
        }
        newBSTElement->parent = previous;
    }
    tree->len++;
}

/// @brief insere o elemento na árvore de maneira ordenada quanto ao mês de registro
/// @param tree árvore a ter o elemento inserido
/// @param data dados do elemento a ser inserido
void insertBSTElementByMonth(BST *tree, Register *data)
{
    // mesmo procedimento da outra função de inserção, porém o parâmetro de ordenação é o mês de entrada
    BSTElement *newBSTElement = createBSTElement(tree, data);
    if (tree->root == NULL)
    {
        tree->root = newBSTElement;
    }
    else
    {
        BSTElement *current = tree->root;
        BSTElement *previous = NULL;
        while (current != NULL)
        {
            if (data->entranceDate->month < current->data->entranceDate->month)
            {
                previous = current;
                current = current->left;
            }
            else
            {
                previous = current;
                current = current->right;
            }
        }
        if (data->entranceDate->month < previous->data->entranceDate->month)
        {
            previous->left = newBSTElement;
        }
        else
        {
            previous->right = newBSTElement;
        }
        newBSTElement->parent = previous;
    }
    tree->len++;
}

/// @brief insere o elemento na árvore de maneira ordenada quanto ao ano de registro
/// @param tree árvore a ter o elemento inserido
/// @param data dados do elemento a ser inserido
void insertBSTElementByYear(BST *tree, Register *data)
{
    // mesmo procedimento da outra função de inserção, porém o parâmetro de ordenação é o ano de entrada
    BSTElement *newBSTElement = createBSTElement(tree, data);
    if (tree->root == NULL)
    {
        tree->root = newBSTElement;
    }
    else
    {
        BSTElement *current = tree->root;
        BSTElement *previous = NULL;
        while (current != NULL)
        {
            if (data->entranceDate->year < current->data->entranceDate->year)
            {
                previous = current;
                current = current->left;
            }
            else
            {
                previous = current;
                current = current->right;
            }
        }
        if (data->entranceDate->year < previous->data->entranceDate->year)
        {
            previous->left = newBSTElement;
        }
        else
        {
            previous->right = newBSTElement;
        }
        newBSTElement->parent = previous;
    }
    tree->len++;
}

/// @brief exibe os registros de uma lista de maneira ordenada de acordo com o parâmetro passado
/// @param list lista com os registros
/// @param param parâmetro de ordenação (idade, dia ou mês ou ano de registro)
void showOrderedByParam(LDE *list, char *param)
{
    sleep(1);
    // cria a árvore
    BST *tree = createBST();
    // define como atual o primeiro elemento da lista
    LDEElement *current = list->first;
    // se atual for diferente de NULL (lista vazia):
    if (current == NULL)
    {
        // é informado que nenhum paciente foi registrado
        printf("\nNenhum paciente registrado\n\n");
    }
    // caso contrário:
    else
    {
        printf("\nPacientes ordenados por %s: \n\n", param);
        // lista é percorrida:
        while (current != NULL)
        {
            // chamando a função de inserção de acordo com o parâmetro passado
            if (strcmp(param, "idade") == 0)
            {
                insertBSTElementByAge(tree, current->data);
            }
            else if (strcmp(param, "dia de registro") == 0)
            {
                insertBSTElementByDay(tree, current->data);
            }
            else if (strcmp(param, "mês de registro") == 0)
            {
                insertBSTElementByMonth(tree, current->data);
            }
            else if (strcmp(param, "ano de registro") == 0)
            {
                insertBSTElementByYear(tree, current->data);
            }
            current = current->next;
        }
        // com a árvore com todos elementos da lista
        BSTElement *root = tree->root;
        // é chamada a função que exibe os elementos da árvore em ordem
        inOrder(root);
    }
    free(tree);
    sleep(1);
}
