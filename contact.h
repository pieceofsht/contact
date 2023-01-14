#ifndef CONTACT
#define CONTACT

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DEFAULT_SIZE 3
#define MAX 1000
#define MAX_NAME 20
#define MAX_GENDER 6
#define MAX_TELE 12
#define MAX_ADDR 30

enum
{
    QUIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};

struct PeopleInfo
{
    char name[MAX_NAME];
    int age;
    char gender[MAX_GENDER];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

struct Contact
{
    struct PeopleInfo* data;
    int capacity; //记录最大容量
    int size; //记录已有元素个数
};

void menu();
#endif