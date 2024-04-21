typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode *next;
} SLTNode;

SLTNode *SLTNewNode(SLTDataType x);

void SLTPushBack(SLTNode **phead, SLTDataType x);
void SLTPushFront(SLTNode **phead, SLTDataType x);
void SLTPopBack(SLTNode **phead);//if only one element, head will change
void SLTPopFront(SLTNode **phead);

void SLTPrint(SLTNode *phead);
SLTNode *SLTFind(SLTNode *phead, SLTDataType x);

void SLTInsert(SLTNode **phead, SLTNode *pos, SLTDataType x); // add data infront of the position
void SLTINsertAfter(SLTNode *pos, SLTDataType x);

void SLTErase(SLTNode **phead, SLTNode *pos);
void SLTEraseAfter(SLTNode *pos);
void SLTDestroy(SLTNode **phead);
