#include"contact.h"

void menu()
{
    printf("****************************\n");
    printf("***  1.Add       2.Del   ***\n");
    printf("***  3.Search    4.Modify***\n");
    printf("***  5.Show      6.Sort  ***\n");
    printf("***  0.Quit              ***\n");
    printf("****************************\n");
}

void InitContact(struct Contact* ps)
{
    ps->data=calloc(sizeof(struct PeopleInfo),DEFAULT_SIZE);
    if (ps==NULL)
    {
        return;
    }
    ps->size=0;
    ps->capacity=DEFAULT_SIZE;
}

int CheckCapacity(struct Contact* ps)
{
    if (ps->size==ps->capacity)
    {
        struct PeopleInfo* ptr=realloc(ps->data,((ps->capacity)+2)*sizeof(struct PeopleInfo));
        if (ptr!=NULL)
        {
            ps->data=ptr;
            ps->capacity+=2;
            printf("扩容成功\n");
            return 1;
        }
        else
        {
        printf("扩容失败\n");
        return 0;
        }
    }
    return 1;
}


void AddContact(struct Contact* ps)
{
    
        if(CheckCapacity(ps))
        {
        printf("请输入姓名:>");
        scanf("%s",ps->data[ps->size].name);
        printf("请输入年龄:>");
        scanf("%d",&(ps->data[ps->size].age));
        printf("请输入性别:>");
        scanf("%s",ps->data[ps->size].gender);
        printf("请输入电话:>");
        scanf("%s",ps->data[ps->size].tele);
        printf("请输入住址:>");
        scanf("%s",ps->data[ps->size].addr);
        ps->size++;
        printf("输入成功\n");
        }

}

void ShowContact(struct Contact* ps)
{
    int i;
    if(ps->size==0)
    {
        printf("列表为空\n");
    }
    else
    {
        printf("%-20s\t%-3s\t%-6s\t%-12s\t%-30s\n","姓名","年龄","性别","电话","住址");
        for(i=0;i<ps->size;i++)
        {
            printf("%-20s\t%-3d\t%-6s\t%-12s\t%-30s\n",
            ps->data[i].name,
            ps->data[i].age,
            ps->data[i].gender,
            ps->data[i].tele,
            ps->data[i].addr
            );
        }
    }
}

int FindByName(struct Contact* ps,char name[MAX_NAME])
{
    int i;
    for(i=0;i<ps->size;i++)
    {
        if(strcmp(ps->data[i].name,name)==0)
        {
            return i;
        }
    }
    return -1;
}

void DelContact(struct Contact* ps)
{
    int i;
    char name[MAX_NAME];
    printf("请输入要删除人姓名:>");
    scanf("%s",name);
    int j=FindByName(ps,name);
    if(j==-1)
    {
        printf("要删除的人不存在\n");
    }
    else
    {
        for(i=j;i<ps->size-1;i++)
        {
            ps->data[i]=ps->data[i+1];
        }
        ps->size--;
        printf("删除成功\n");
    }
}

void SearchContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的姓名:>");
    scanf("%s",name);
    int i=FindByName(ps,name);
    if(i==-1)
    {
        printf("要查找的人不存在\n");
    }
    else
    {
        printf("%-20s\t%-3s\t%-6s\t%-12s\t%-30s\n","姓名","年龄","性别","电话","住址");
        printf("%-20s\t%-3d\t%-6s\t%-12s\t%-30s\n",
            ps->data[i].name,
            ps->data[i].age,
            ps->data[i].gender,
            ps->data[i].tele,
            ps->data[i].addr);
    }
}

void ModifyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要修改人的姓名:>");
    scanf("%s",name);
    int i=FindByName(ps,name);
    if(i==-1)
    {
        printf("要查找的人不存在\n");
    }
    else
    {
        printf("请输入姓名:>");
        scanf("%s",ps->data[i].name);
        printf("请输入年龄:>");
        scanf("%d",&(ps->data[i].age));
        printf("请输入性别:>");
        scanf("%s",ps->data[i].gender);
        printf("请输入电话:>");
        scanf("%s",ps->data[i].tele);
        printf("请输入住址:>");
        scanf("%s",ps->data[i].addr);
        printf("修改成功\n");
    }
}

void swapstr(char a[30],char b[30])
{
    char temp[30]="";
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

void SortContact(struct Contact* ps)
{
    int i,j;
    if(ps->size<2)
    {
        printf("不需要排序\n");
    }
    else
    {
        for(i=ps->size-1;i>0;i--)
        {
            for(j=0;j<i;j++)
            {
                if(strcmp(ps->data[j].name,ps->data[j+1].name)>0)
                {
                     struct PeopleInfo temp;
                     temp=ps->data[j];
                     ps->data[j]=ps->data[j+1];
                     ps->data[j+1]=temp;
                     
                }
            }
        }
        printf("排序成功\n");
    }
}