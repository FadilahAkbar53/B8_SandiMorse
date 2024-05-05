#ifndef header_H
#define header_H

// Define the structure for the tree node
typedef char info;
typedef struct Node
{
    char data;
    struct Node *leftChild;
    struct Node *rightChild;
} node;

node *createNode(info data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Alokasi gagal\n");
        exit(1);
    }
    else
    {
        newNode->data = data;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }
}

void initialmorse(node **root)
{
    *root = createNode(' ');
}

void insertLeft(node **root, info data)
{
    node *newNode = createNode(data);
    (*root)->leftChild = newNode;
}

void insertRight(node **root, info data)
{
    node *newNode = createNode(data);
    (*root)->rightChild = newNode;
}

void insertCodeMorse(node **root, info data, info codeMorse[])
{
    node *pNode = *root;
    for (int i = 0; i < strlen(codeMorse); i++)
    {
        if (codeMorse[i] == '.')
        {
            if (pNode->leftChild == NULL)
            {
                insertLeft(&pNode, ' ');
            }
            pNode = pNode->leftChild;
        }
        else if (codeMorse[i] == '-')
        {
            if (pNode->rightChild == NULL)
            {
                insertRight(&pNode, ' ');
            }
            pNode = pNode->rightChild;
        }
    }
    pNode->data = data;
}

void printTree(node *root)
{
    if (root != NULL)
    {
        printf("%c", root->data); // Cetak data dari simpul saat ini

        if (root->leftChild != NULL || root->rightChild != NULL)
        {
            printf("("); // Cetak tanda kurung pembuka jika simpul saat ini memiliki anak

            if (root->leftChild != NULL)
                printTree(root->leftChild); // Cetak anak kiri jika ada

            printf(","); // Cetak koma sebagai pemisah antara anak kiri dan kanan

            if (root->rightChild != NULL)
                printTree(root->rightChild); // Cetak anak kanan jika ada

            printf(")"); // Cetak tanda kurung penutup
        }
    }
}

void searchCodeMorse(node *root, info codeMorse[])
{
    node *pNode = root;
    for (int i = 0; i < strlen(codeMorse); i++)
    {
        if (codeMorse[i] == '.')
        {
            pNode = pNode->leftChild;
        }
        else if (codeMorse[i] == '-')
        {
            pNode = pNode->rightChild;
        }
    }
    printf("%c", pNode->data);
}

#endif /* HEADER_H */
