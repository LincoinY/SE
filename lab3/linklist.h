typedef struct DataNode
{
    char *cmd;
    char *desc;
    void (*hander)();
    struct DataNode *next;
}tDataNode;

tDataNode *FindCmd(tDataNode *head,char *cmd);
int ShowAllCmd(tDataNode *head);
