#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct student // declaration of structure
{
    int roll;
    char name[25];
    int mark;
} s;

void search_rec();
void update_rec();
void delete_rec();
void display_rec();
void sort_rec();
void merge_rec();

// create function for searching student record
void search_rec(s *pt, int n, int ts)
{
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if ((pt + i)->roll == ts)
        {
            printf("Roll No: %d  ", (pt + i)->roll);
            printf("Name : %s  ", (pt + i)->name);
            printf("Marks : %d  \n", (pt + i)->mark);
            ct++;
        }
    }
    if (ct == 0)
    {
        printf("This record is not found \n");
    }
}

// create function for updating student record
void update_rec(s *pt, int n, int tu)
{
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if ((pt + i)->roll == tu)
        {
            printf("\nNew Roll No:  ");
            scanf("%d", &(pt + i)->roll);
            printf("New Name : ");
            scanf("%s", (pt + i)->name);
            printf("New Marks :");
            scanf("%d", &(pt + i)->mark);
            ct++;
        }
    }
    if (ct == 1)
    {
        printf("\nData Updated successfully\n");
    }
    else
    {
        printf("\nThis Record is not found\n");
    }
}

// create function for deleting student record
void delete_rec(s *pt, int n, int td)
{
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if ((pt + i)->roll == td)
        {
            (pt + i)->roll = (pt + i + 1)->roll;
            strcpy((pt + i)->name, (pt + i + 1)->name);
            (pt + i)->mark = (pt + i + 1)->mark;
            ct++;
        }
    }
    if (ct == 1)
    {
        printf("\nData Deleted successfully ");
    }
    else
    {
        printf("\nRecord not found");
    }
    free(pt);
}

// create function for display student record

void display_rec(s *pt, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nRoll No. %d\t Name: %s\t Marks: %d\n", (pt + i)->roll,
               (pt + i)->name, (pt + i)->mark);
    }
}

// create function for sorting student record
void sort_rec(s *pt, int n)
{
    int t_r, t_m;
    char t_n[20];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((pt + i)->mark > (pt + i - 1)->mark)
            {
                t_r = (pt + i)->roll;
                (pt + i)->roll = (pt + j)->roll;
                (pt + j)->roll = t_r;

                t_m = (pt + i)->mark;
                (pt + i)->mark = (pt + j)->mark;
                (pt + j)->mark = t_m;

                strcpy(t_n, (pt + i)->name);
                strcpy((pt + i)->name, (pt + j)->name);
                strcpy((pt + j)->name, t_n);
            }
        }
    }
    printf("\n Data sorted successfully\n");
    printf("\n Below data is sorted according to marks\n");
    display_rec(pt, n);
}

// create function for merging student record
void merge_rec(s *pt, s *pt2, int n, int m_n)
{
    for (int i = n + 1, j = 0; i <= (n + m_n), j < m_n; i++, j++)
    {
        (pt + i)->roll = (pt2 + j)->roll;
        strcpy((pt + i)->name, (pt2 + j)->name);
        (pt + i)->mark = (pt2 + j)->mark;
    }
    free(pt2);
    printf("\nData Merge Successfully");
}

void main()
{
    int n;
    printf("Enter Total Number of Students: ");
    scanf("%d", &n);
    s *pt;
    pt = (s *)malloc(n * (sizeof(s)));

    printf("\nFirst You have to create Student record ");
    printf("\nSo Enter 1 for creating students record :  ");
    int t;
    scanf("%d", &t);
    if (t == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("\nEnter Roll No. of Student %d: ", i + 1);
            scanf("%d", &(pt + i)->roll);
            printf("Enter Name of Student %d: ", i + 1);
            scanf("%s", (pt + i)->name);
            printf("Enter Marks of Student %d: ", i + 1);
            scanf("%d", &(pt + i)->mark);
        }
    }
    else
    {
        printf("Please choose proper input \n");
    }

    int choice;

    // Do all the operations using switch cases

    while (1)
    {
        printf("\nchose operation number which you want to perform :  ");
        printf("\n 1.Search  2.Update  3.Delete");
        printf("\n 4.Display 5.Sort 6.Merge 7.exit\n");
        printf("\n Choose any one option above them : ");
        scanf("%d", &choice);
        printf("\n--------------------------------------------------");

        switch (choice)
        {

        case 1:
            printf("\nEnter Roll number which you want to search : ");
            int ts; // temp_search for searching as searching variable.
            scanf("%d", &ts);
            search_rec(pt, n, ts);
            break;

        case 2:
            printf("\nEnter Roll number which you want to update : ");
            int tu; // temp_update for update as a updating variable
            scanf("%d", &tu);
            update_rec(pt, n, tu);
            break;

        case 3:
            printf("\nEnter Roll number which you want to delete : ");
            int td; // temp_delete for delete as a deleting variable
            scanf("%d", &td);
            delete_rec(pt, n, td);
            break;

        case 4:
            display_rec(pt, n);
            break;

        case 5:
            sort_rec(pt, n);
            break;

        case 6:
            printf("\nEnter total number of student which you want to merge :");
            int m_n; // store Extra student number whose are merge
            scanf("%d", &m_n);
            s *pt2; // declare second pointer for storing merging students record
            pt2 = (s *)malloc(m_n * (sizeof(s)));
            for (int i = 0; i < m_n; i++)
            {
                printf("Enter Roll No. : ");
                scanf("%d", &(pt2 + i)->roll);
                printf("Enter Name : ");
                scanf("%s", (pt2 + i)->name);
                printf("Enter Marks : ");
                scanf("%d", &(pt2 + i)->mark);
            }
            pt = (s *)realloc(pt, (n + m_n) * sizeof(s));
            merge_rec(pt, pt2, n, m_n);
            n = n + m_n;
            break;

        case 7:
            exit(0);
        default:

            break;
        }
    }
}