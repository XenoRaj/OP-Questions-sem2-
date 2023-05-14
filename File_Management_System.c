#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct File_Manager
{
    struct File_Manager **dirs;
    int num;
    char *name;
};

struct File_Manager *Creator()
{
    struct File_Manager *Directory = (struct File_Manager *)malloc(sizeof(struct File_Manager));
    Directory->num = 0;
    Directory->dirs = (struct File_Manager **)malloc(21 * sizeof(struct File_Manager *));
    Directory->dirs[0] = NULL;
    Directory->name = (char *)malloc(25 * sizeof(char));
    Directory->name = "root";
    return Directory;
}

struct File_Manager *Finder(struct File_Manager *Directory, char name[], int flag)
{
    struct File_Manager *Dir = NULL;

    for (int i = 1; i <= Directory->num; i++)
    {
        if (strcmp(Directory->dirs[i]->name, name) == 0)
        {
            Dir = Directory->dirs[i];
            return Dir;
        }
    }
    return Dir;
}

void mkdir(struct File_Manager *Directory)
{
    char *name = (char *)malloc(25 * sizeof(char));
    scanf("%s", name);
    int flag = 0;
    struct File_Manager *Dir = Finder(Directory, name, flag);
    if (Dir == NULL)
    {
        struct File_Manager *NewDir = Creator();
        NewDir->name = name;
        Directory->num++;
        Directory->dirs[Directory->num] = NewDir;
        NewDir->dirs[0] = Directory;
    }
    else
    {
        printf("-1\n");
    }
}

void pwd(struct File_Manager *Directory)
{
    if (Directory->dirs[0] == NULL)
    {
        printf("root");
        return;
    }
    pwd(Directory->dirs[0]);
    printf("/");
    printf("%s", Directory->name);
}

void ls(struct File_Manager *Directory)
{
    char **names = (char **)malloc(Directory->num * sizeof(char *));
    for (int i = 1; i <= Directory->num; i++)
    {
        if (Directory->dirs[i] != NULL)
        {
            names[i - 1] = (char *)malloc(100 * sizeof(char));
            names[i - 1] = Directory->dirs[i]->name;
        }
    }

    char *temp = (char *)malloc(100 * sizeof(char));

    int n = Directory->num;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (strcmp(names[j - 1], names[j]) == 1)
            {
                temp = names[j - 1];
                names[j - 1] = names[j];
                names[j] = temp;
            }
        }
    }

    for (int i = 0; i < Directory->num; i++)
    {
        printf("%s ", names[i]);
    }
}

struct File_Manager *cdparent(struct File_Manager *CurrDir)
{

    if (CurrDir->dirs[0] != NULL)
    {
        return CurrDir->dirs[0];
    }
    printf("-1\n");
    return CurrDir;
}

struct File_Manager *cd(char name[], struct File_Manager *CurrDir)
{
    int flag = 0;
    struct File_Manager *Dir = Finder(CurrDir, name, flag);
    if (Dir == NULL)
    {
        printf("-1\n");
        return CurrDir;
    }
    else
    {
        return Dir;
    }
}

struct File_Manager *rem(struct File_Manager *RootDir, char name[])
{

    struct File_Manager *Dir;
    for (int i = 1; i <= RootDir->num; i++)
    {
        if (!(strcmp(RootDir->dirs[i]->name, name)))
        {

            for (; i < RootDir->num; i++)
            {
                RootDir->dirs[i] = RootDir->dirs[i + 1];
            }
            RootDir->num--;
        }
    }
    return RootDir;
}

int main()
{
    int Q, n;
    scanf("%d", &Q);
    struct File_Manager *RootDir = Creator();
    struct File_Manager *CurrDir = RootDir;
    for (; Q > 0; Q--)
    {
        scanf("%d", &n);
        // char *op = (char *)malloc(20 * sizeof(char));
        char op[25];
        scanf("%s", op);
        if (n == 1)
        {
            if (!(strcmp(op, "pwd")))
            {
                pwd(CurrDir);
                printf("\n");
            }
            if (!(strcmp(op, "ls")))
            {
                ls(CurrDir);
                printf("\n");
            }
        }
        if (n == 2)
        {

            if (!(strcmp(op, "mkdir")))
            {
                mkdir(CurrDir);
            }
            if (!(strcmp(op, "cd")))
            {
                char name[25];
                scanf("%s", name);

                if (!(strcmp(name, "..")))
                {
                    CurrDir = cdparent(CurrDir);
                }
                else
                {
                    CurrDir = cd(name, CurrDir);
                }
            }
        }
        if (n == 3)
        {
            if (!(strcmp(op, "rm")))
            {
                char *name = (char *)malloc(25 * sizeof(char));
                scanf("%s", name);
                if (!(strcmp(name, "-r")))
                {
                    scanf("%s", name);
                    int flag = 0;
                    struct File_Manager *Dir = Finder(CurrDir, name, flag);
                    if (Dir == NULL)
                    {
                        printf("-1\n");
                    }
                    else
                    {
                        CurrDir = rem(CurrDir, name);
                    }
                }
            }
        }
    }
    return 0;
}