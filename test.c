#include"contact.c"

int main()
{
    int input;
    struct Contact con;
    InitContact(&con);
    do
    {
        menu();
        printf("请选择操作:>");
        scanf("%d",&input);
        switch (input)
        {
            case ADD:
            AddContact(&con);
            break;
            case DEL:
            DelContact(&con);
            break;
            case SEARCH:
            SearchContact(&con);
            break;
            case MODIFY:
            ModifyContact(&con);
            break;
            case SHOW:
            ShowContact(&con);
            break;
            case SORT:
            SortContact(&con);
            break;
            case QUIT:
            printf("退出通讯录");
            break;
            default:
            printf("输入错误");
            break;
        }
    } while (input);
    
}
