#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "librarySytem.h"


struct  node_student*readFromStudentFiles(struct  node_student*start_student);
struct  node_book*readFromBookFiles(struct  node_book*start_book);

int main()
{


    start_b = (struct  node_book*)malloc(sizeof(struct  node_book));
    start_s=(struct  node_student*)malloc(sizeof(struct  node_student));

    // read data from files
    start_s=readFromStudentFiles(start_s);
    start_b=readFromBookFiles(start_b);
    while(1)
    {
        printf("\n\t\t\t\t Menu\n");
        printf("1-Add Book\n2-Add Member\n3-Modify Book\n4-Modify Member\n5-Delete Book\n6-Delete Member\n7-Issue Book\n8-Return Book\n9-display books\n10-dispaly students\n11-search book\n12-search student\n");
        printf("\nenter your opreation\n");
        int x ;
        scanf("%d",&x);
        switch(x)
        {
        case 1:

            system("clear");
            start_b=insert_book(start_b);
            printf("enter 1 to return to the Menu\n");
            int x;
            scanf("%d",&x);
            if(x==1);
            system("clear");

            break;
        case 2:
            system("clear");
            start_s=insert_student(start_s);
            printf("enter 1 to return to the Menu\n");
            int y;
            scanf("%d",&y);
            if(y==1);
            system("clear");

            break;
        case 3:
            system("clear");
            printf("books data not change\n");
            printf("enter 1 to return to the Menu\n");
            int z;
            scanf("%d",&z);
            if(z==1);
            system("clear");

        case 4:
            system("clear");
            start_s=update(start_s);
            printf("enter 1 to return to the Menu\n");
            int a;
            scanf("%d",&a);
            if(a==1);
            system("clear");

            break;
        case 5:
            system("clear");
            start_b=delete_book(start_b);
            printf("enter 1 to return to the Menu\n");
            int b;
            scanf("%d",&b);
            if(b==1);
            system("clear");

            break;
        case 6:
            system("clear");
            start_s=delete_student(start_s);
            printf("enter 1 to return to the Menu\n");
            int c;
            scanf("%d",&c);
            if(c==1);
            system("clear");

            break;
        case 7:
            system("clear");
            start_b=issue_book(start_b,start_s);
            printf("enter 1 to return to the Menu\n");
            int d;
            scanf("%d",&d);
            if(d==1);
            system("clear");
            break;
        case 8:
            system("clear");
            Return(start_b,start_s);
            printf("enter 1 to return to the Menu\n");
            int l;
            scanf("%d",&l);
            if(l==1);
            system("clear");
            break;
        case 9:
            system("clear");
            display_books(start_b);
            printf("enter 1 to return to the Menu\n");
            int m;
            scanf("%d",&m);
            if(m==1);
            system("clear");
            break;
        case 10:
            system("clear");
            display_students(start_s);
            printf("enter 1 to return to the Menu\n");
            int n;
            scanf("%d",&n);
            if(n==1);
            system("clear");
            break;
        case 11:
            system("clear");
            search_book(start_b);
            printf("enter 1 to return to the Menu\n");
            int o;
            scanf("%d",&o);
            if(o==1);
            system("clear");
            break;
        case 12:
            system("clear");
            search_student(start_b);
            printf("enter 1 to return to the Menu\n");
            int q;
            scanf("%d",&q);
            if(q==1);
            system("clear");
            break;
        default:
            system("clear");
            printf("wrong input\n");
            printf("enter 1 to return to the Menu\n");
            int f;
            scanf("%d",&f);
            if(f==1);
            system("clear");

        }

    }
    return 0;
}


// read the books linklist from the file
struct node_book* readFromBookFiles(struct  node_book*start_book)
{

    struct  node_book *new_node;
    char*p;
    int i=0;
    char words[5][30];
    char str[1000];
    FILE*book;
    char *bookfile;
    bookfile="books.dat";
//    printf("1-default files\n2-new files\n");
//int x;
//switch(x){
//case 1:
//
//bookfile="books.dat";
//break;
//case 2:
//printf("-enter book file ");
//scanf("%s\n",bookfile);
//break;
//}

    book=fopen(bookfile, "r");
    if(book==NULL)
    {
        printf(" book file not found ");
        return;
    }

    while (fgets(str, sizeof(str), book) != NULL)
    {
        i=0;
        p=strtok(str,",");
        while(p!=NULL)
        {
            strcpy(words[i],p);
            i++;
            p=strtok(NULL,",");
        }
        new_node = (struct  node_book*)malloc(sizeof(struct  node_book));
        new_node->accessNum=atoi(words[0]);
        strcpy(new_node->title,words[1]);
        strcpy(new_node->author,words[2]);
        strcpy(new_node->publisher,words[3]);
        new_node->cost=atoi(words[4]);
        new_node->numOfCopies=atoi(words[5]);
        new_node -> next = start_book;
        start_book = new_node;
    }
    return start_book;
}

// read the students linklist from the file
struct  node_student*readFromStudentFiles(struct  node_student*start_student)
{
    struct  node_student *new_node;
    char*p;
    int i=0;
    char words[5][30];
    char str[1000];
    FILE*student;
    char *studentfile;
    studentfile="students.dat";
    student=fopen(studentfile, "r");
    if(student==NULL)
    {
        printf(" student file not found ");
        return;
    }
    while (fgets(str, sizeof(str), student) != NULL)
    {
        i=0;
        p=strtok(str,",");
        while(p!=NULL)
        {
            strcpy(words[i],p);
            i++;
            p=strtok(NULL,",");
        }
        new_node = (struct  node_student*)malloc(sizeof(struct  node_student));
        new_node->rollNum=atoi(words[0]);
        strcpy(new_node->name,words[1]);
        strcpy(new_node->address,words[2]);
        new_node->dateOfBirth.day=atoi(strtok(words[3],"/"));
        new_node->dateOfBirth.month=atoi(strtok(NULL,"/"));
        new_node->dateOfBirth.year=atoi(strtok(NULL," "));
        new_node->numOfIssued=atoi(words[4]);
        new_node -> next = start_student;
        start_student = new_node;

}
return start_student;
    }

