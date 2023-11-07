typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char name[255];
    int age;
    char rg[255];
    Date *entranceDate;
} Register;

typedef struct LDEElement
{
    Register *data;
    struct LDEElement *next;
} LDEElement;

typedef struct LDE
{
    int len;
    LDEElement *first;
} LDE;

typedef struct QueueElement
{
    Register *data;
    struct QueueElement *next;
} QueueElement;

typedef struct Queue
{
    QueueElement *head;
    QueueElement *tail;
    int len;
} Queue;

typedef struct BSTElement
{
    Register *data;
    struct BSTElement *parent;
    struct BSTElement *left;
    struct BSTElement *right;
} BSTElement;

typedef struct
{
    BSTElement *root;
    int len;
} BST;
