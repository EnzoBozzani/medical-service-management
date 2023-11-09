// esse arquivo contém as funções referentes a seção 3 do menu, que está
// relacionada às árvores binárias de busca

/// @brief função que imprime os registros na árvore em ordem de idade
/// @param root nó a partir do qual é feita a impressão
void inOrderAge(BSTElement *root)
{
    if (root != NULL)
    {
        inOrderAge(root->left);
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        inOrderAge(root->right);
    }
}

/// @brief função que imprime os registros na árvore em ordem de dia de registro
/// @param root nó a partir do qual é feita a impressão
void inOrderDay(BSTElement *root)
{
    if (root != NULL)
    {
        inOrderDay(root->left);
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        inOrderDay(root->right);
    }
}

/// @brief função que imprime os registros na árvore em ordem de mês de registro
/// @param root nó a partir do qual é feita a impressão
void inOrderMonth(BSTElement *root)
{
    if (root != NULL)
    {
        inOrderMonth(root->left);
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        inOrderMonth(root->right);
    }
}

/// @brief função que imprime os registros na árvore em ordem de ano de registro
/// @param root nó a partir do qual é feita a impressão
void inOrderYear(BSTElement *root)
{
    if (root != NULL)
    {
        inOrderYear(root->left);
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        inOrderYear(root->right);
    }
}

/// @brief cria elemento da árvore binária de busca
/// @param tree árvore que terá o elemento criado
/// @param data dados do elemento
/// @return elemento inicializado
BSTElement *createBSTElement(BST *tree, Register *data)
{
    BSTElement *newBSTElement = malloc(sizeof(BSTElement));
    newBSTElement->right = NULL;
    newBSTElement->left = NULL;
    newBSTElement->parent = NULL;
    newBSTElement->data = data;

    return newBSTElement;
}

/// @brief cria árvore binária de busca
/// @return árvore inicializada
BST *createBST()
{
    BST *tree = malloc(sizeof(BST));
    tree->root = NULL;
    tree->len = 0;

    return tree;
}

/// @brief insere o elemento na árvore de maneira ordenada quanto à idade do paciente
/// @param tree árvore a ter o elemento inserido
/// @param data dados do elemento a ser inserido
void insertBSTElementByAge(BST *tree, Register *data)
{
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
            if (data->age < current->data->age)
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
        if (data->age < previous->data->age)
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

/// @brief insere o elemento na árvore de maneira ordenada quanto ao dia de registro
/// @param tree árvore a ter o elemento inserido
/// @param data dados do elemento a ser inserido
void insertBSTElementByDay(BST *tree, Register *data)
{
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
    sleep(2);
    BST *tree = createBST();
    LDEElement *current = list->first;
    if (current == NULL)
    {
        printf("\nNenhum paciente registrado\n\n");
    }
    else
    {
        printf("\nPacientes ordenados por %s: \n\n", param);
        while (current != NULL)
        {
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
        BSTElement *root = tree->root;
        if (strcmp(param, "idade") == 0)
        {
            inOrderAge(root);
        }
        else if (strcmp(param, "dia de registro") == 0)
        {
            inOrderDay(root);
        }
        else if (strcmp(param, "mês de registro") == 0)
        {
            inOrderMonth(root);
        }
        else if (strcmp(param, "ano de registro") == 0)
        {
            inOrderYear(root);
        }
    }
    free(tree);
    sleep(2);
}
