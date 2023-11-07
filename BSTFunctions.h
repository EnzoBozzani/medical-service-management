void inOrderAge(BSTElement *root)
{
    if (root != NULL)
    {
        inOrderAge(root->left);
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        inOrderAge(root->right);
    }
}

void inOrderDay(BSTElement *root)
{
    if (root != NULL)
    {
        inOrderDay(root->left);
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        inOrderDay(root->right);
    }
}

void inOrderMonth(BSTElement *root)
{
    if (root != NULL)
    {
        inOrderMonth(root->left);
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        inOrderMonth(root->right);
    }
}

void inOrderYear(BSTElement *root)
{
    if (root != NULL)
    {
        inOrderYear(root->left);
        printf("Nome: %s\nIdade: %d\nRG: %s\nData de entrada: %02d/%02d/%04d\n\n", root->data->name, root->data->age, root->data->rg, root->data->entranceDate->day, root->data->entranceDate->month, root->data->entranceDate->year);
        inOrderYear(root->right);
    }
}

BSTElement *createBSTElement(BST *tree, Register *data)
{
    BSTElement *newBSTElement = malloc(sizeof(BSTElement));
    newBSTElement->right = NULL;
    newBSTElement->left = NULL;
    newBSTElement->parent = NULL;
    newBSTElement->data = data;

    return newBSTElement;
}

BST *createBST()
{
    BST *tree = malloc(sizeof(BST));
    tree->root = NULL;
    tree->len = 0;

    return tree;
}

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

Register *removeBSTElement(BST *tree, BSTElement *v)
{
    Register *vData = v->data;
    BSTElement *parent = v->parent;
    if (parent == NULL)
    {
        if (v->left == NULL && v->right == NULL)
        {
            tree->root = NULL;
        }
        else if (v->left != NULL && v->right != NULL)
        {
            BSTElement *highestLeft = v->left;
            while (highestLeft->right != NULL)
            {
                highestLeft = highestLeft->right;
            }
            v->data = highestLeft->data;
            removeBSTElement(tree, highestLeft);
        }
        else
        {
            if (v->left != NULL)
            {
                tree->root = v->left;
            }
            else
            {
                tree->root = v->right;
            }
            tree->root->parent = NULL;
            free(v);
        }
    }
    else
    {
        if (v->left == NULL && v->right == NULL)
        {
            if (parent->left == v)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
            free(v);
        }
        else if (v->left != NULL && v->right != NULL)
        {
            BSTElement *highestLeft = v->left;
            while (highestLeft->right != NULL)
            {
                highestLeft = highestLeft->right;
            }
            v->data = highestLeft->data;
            removeBSTElement(tree, highestLeft);
        }
        else
        {
            BSTElement *filho = (v->left != NULL) ? v->left : v->right;
            filho->parent = parent;
            if (parent->left == v)
            {
                parent->left = filho;
            }
            else
            {
                parent->right = filho;
            }
            free(v);
        }
    }
    tree->len--;
    return vData;
}

BSTElement *searchData(BST *tree, Register *data)
{
    BSTElement *current = tree->root;
    while (current != NULL)
    {
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            if (data > current->data)
            {
                current = current->right;
            }
            else
            {
                return current;
            }
        }
    }
    return NULL;
}

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
    sleep(2);
}
