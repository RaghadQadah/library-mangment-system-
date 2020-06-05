//time struct use in issue and return opreation
struct node_time
{
    int day ;
    int month;
    int year ;
};

struct node_book
{
    int accessNum;
    char title[30] ;
    char author[30];
    char publisher[30];
    int cost;
    int numOfCopies;
    int available;
    struct node_book*next;
    struct student_book*next_student;//pointer to point in students(struct) who issued a certain book
};
struct node_student
{
    int rollNum;
    char name[30] ;
    char address[30];
    struct node_time dateOfBirth;
    int numOfIssued;
    struct node_student*next;
};
struct student_book
{
    char name[30];
    int std_rollNum;
    struct node_time ReturnDate;
    struct student_book*next_s;
};



struct node_book *insert_book(struct  node_book*start);
struct node_student *insert_student(struct  node_student*start);
struct node_book *delete_book(struct  node_book*start);
struct node_student *delete_student(struct  node_student *start);
struct node_student* uptade(struct  node_student *start);
void search_book(struct  node_book *start);
void search_student(struct node_book*start);
void display_books(struct  node_book*start);
void display_students(struct  node_student*start);
struct node_book *issue_book(struct  node_book*start, struct node_student*start_student );
void Return(struct node_book*start_b,struct node_student*start_student);
struct node_book *start_b=NULL;
struct node_student*start_s=NULL;
struct student_book*start_bs=NULL;

//insert in from the begning of book node for less timing
struct node_book *insert_book(struct  node_book*start)
{
    struct  node_book *new_node;
    new_node = (struct  node_book*)malloc(sizeof(struct  node_book));
    printf(" Enter the book info \n 1-access number \n 2-title  \n 3-author  \n 4-publisher \n 5-cost\n 6-numberOfcopies\n ");
    scanf("%d\n%s\n%s\n%s\n%d\n%d",&new_node -> accessNum, &new_node -> title,&new_node -> author,&new_node -> publisher,&new_node -> cost,&new_node ->numOfCopies );
    new_node -> next = start;
    start = new_node;
    return start;

}
//insert in from the begning of student node for less timing
struct node_student *insert_student(struct  node_student*start)
{
    struct node_student *new_node;
    char a,b;
    new_node = (struct node_student*)malloc(sizeof(struct node_student));
    printf(" Enter the student info \n 1-roll num \n 2-name  \n 3-address  \n 4-date of birth (day/month/year)\n  ");
    scanf("%d\n%[^\n]%s\n%d%c%d%c%d",&new_node -> rollNum, &new_node -> name,&new_node -> address,&new_node -> dateOfBirth.day,&a,&new_node->dateOfBirth.month,&b,&new_node->dateOfBirth.year);
    new_node -> next = start;
    start = new_node;


    return start;
}

//delete book by enter accession number
struct node_book *delete_book(struct  node_book*start)
{

    struct node_book* ptr,*before,*new_node;
    int num;
    new_node = (struct node_book*)malloc(sizeof(struct node_book));
    printf("enter the access number of the book\n ");
    scanf("%d",&num);
    ptr = start;
    before = start;
    if( ptr ->accessNum  == num)
    {
        start = start -> next;
        free(ptr);
        printf("deleted\n");
        return start;
    }
    else
    {
        while( ptr!=NULL)
        {


            if( ptr->accessNum==num)
            {
                before->next=ptr->next;
                free(ptr);
                printf("deleted\n");
                break;
            }
            before=ptr;
            ptr=ptr->next;
        }
// iterated on all of books and not exist
        if(ptr==NULL)
        {
            printf("not exist\n ");
        }
    }

    return start;
}
//delete student data by roll number
struct node_student *delete_student(struct  node_student *start)
{

    struct node_student * ptr,*before,*new_node;
    int num;
    new_node = (struct node_student*)malloc(sizeof(struct node_student));
    printf("enter the roll number of student \n");
    scanf("%d",&num);
    ptr = start;
    before=ptr;
    while (ptr !=NULL)
    {

        if(ptr->rollNum==num)
        {
            //check if no issued book for thw student first
            if(ptr->numOfIssued==0)
            {
                before->next=ptr->next;
                free(ptr);
                printf("deleted\n");
            }
            else
            {
                printf("invalid delete untill return all issued book \n");


            }
            //stop searching
            break;
        }
        before=ptr;
        ptr=ptr->next;


    }

    if(ptr==NULL)
    {
        printf("not exist \n ");
    }


    return start;
}


//function to uptade data of student like adress ..... by entering rollnumber
struct node_student* update(struct  node_student *start)
{
    struct node_student*ptr;
    struct student_book*s_ptr;
    ptr=start;
    int num;
    printf("enter the roll number of the student \n ");
    scanf("%d",&num);
    while(ptr!=NULL&&ptr->rollNum!=num)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("not exist\n");
    }
    else
    {
        printf(" Enter the student info to be uptade \n 1-roll num \n 2-name  \n 3-address  \n 4-date of birth \n  ");
        scanf("%d\n%[^\n]%s\n%d",&ptr -> rollNum, &ptr -> name,&ptr -> address,&ptr -> dateOfBirth);
    }

    return start;
}

// display all book in the library
void display_books(struct  node_book*start)
{
    struct node_book* ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        printf("\n\nascces number: %d\n title:%s\nauthor:%s\n publisher:%s\ncost:%d\nnumber of copies:%d\n", ptr -> accessNum,  ptr->  title, ptr->  author, ptr ->  publisher, ptr -> cost,ptr->numOfCopies);
        ptr=ptr->next;

    }
}
//display all student nodes
void display_students(struct  node_student*start)
{
    struct node_student*ptr;
    ptr=start;
    char a='/';
    // printf("roll numbre:\t name \t adrees\t date of birth\t numer of issued book\n");
    while(ptr->next!=NULL)
    {
        printf("roll number:%d \n name:%s \n adress:%s \n date of birth %d%c%d%c%d \n issued book:%d\n\n",ptr->rollNum,ptr->name,ptr->address,ptr->dateOfBirth.day,a,ptr->dateOfBirth.month,a,ptr->dateOfBirth.year,ptr->numOfIssued);
        ptr=ptr->next;
    }
}


//search for particular book
void search_book(struct  node_book *start)
{
    struct  node_book*ptr;
    ptr=start;
    int x;
    char s[30];
    char a[30];
    int num;
    printf("1-search by accessNum\n 2-search by author \n 3-search by title\n 4-search by title and author \n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        printf("enter the access number\n");
        scanf("%d",&num);
        while(ptr!=NULL&&ptr->accessNum!=num)
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("not exist\n ");

        }
        else
        {
            printf("exist\n");

        }
        break;

    case 2:
        printf("enter the author\n");
        scanf("%s",s);
        while(ptr!=NULL&&(strcmp(ptr->author,s)!=0))
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("not exist\n ");

        }
        else
        {
            printf("exist\n");

        }
        break;
    case 3:
        printf("enter the title\n");
        scanf("%s",s);
        while(ptr!=NULL&&(strcmp(ptr->title,s)!=0))
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("not exist\n ");

        }
        else
        {
            printf("exist\n");

        }
        break;
    case 4:
        printf("enter the title\n");
        scanf("%s",s);
        printf("enter the author\n");
        scanf("%s",a);
        while (ptr!=NULL&&(strcmp(ptr->title,s)!=0)&&(strcmp(ptr->author,s)!=0))
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("not exist\n");
        }
        else
        {
            printf(" exist\n ");
        }


        break ;
    default:
        printf("Wrong input");
    }

    // if book exiat print info
    if(ptr!=NULL)
    {

        printf("\n\nascces number: %d\n title:%s\nauthor:%s\n publisher:%s\ncost:%d\nnumber of copies:%d\n", ptr -> accessNum,  ptr->  title, ptr->  author, ptr ->  publisher, ptr -> cost,ptr->numOfCopies);
    }

}

//search for particular student who possess the particular book
void search_student(struct node_book*start)
{
    struct student_book*student_ptr;
    struct node_book*ptr;
    ptr=start;
    int num;
    printf("enter access number of book\n");
    scanf("%d",&num);
    while(ptr!=NULL&&ptr->accessNum!=num)
    {
        ptr=ptr->next;

    }

    if(ptr != NULL && ptr->accessNum==num)
    {
        if(ptr->next_student!=NULL)
        {
            student_ptr=ptr->next_student;
            while(student_ptr!=NULL)
            {
                printf("name: %s\n roll number:%d \n",student_ptr->name,student_ptr->std_rollNum);
                student_ptr=student_ptr->next_s;
            }
        }
        else
        {
            printf("no student possesses for this book\n ");

        }
    }
    else
    {
        printf("book does not exist \n");

    }
}

// issue book for student by adding new start_book node
struct node_book * issue_book(struct node_book *start_book,struct node_student*start_student)
{
    char a;
    char b;
    struct node_book *book_ptr;
    struct node_student*ptr;
    struct student_book*student_ptr,*newnode,*countptr;
    newnode=(struct student_book*)malloc(sizeof(struct student_book));
    book_ptr=start_book;
    student_ptr=newnode;
    ptr=start_student;
    int countIssued=0;
    int num;
    printf("enter book access number\n");
    scanf("%d",&num);
    // handle thw not found book and null check
    // find the book
    while(book_ptr!=NULL&&book_ptr->accessNum!=num)
    {
        book_ptr=book_ptr->next;
    }
    if(book_ptr==NULL)
    {
        printf("book not found\n");
        return;
    }
    else
    {

        countptr=book_ptr->next_student;
        //null check
        while(countptr!=NULL&&countptr->next_s!=NULL)
        {
            countptr=countptr->next_s;
            countIssued++;
            //   printf("%d",countIssued);
        }

        if(book_ptr->numOfCopies>countIssued)
        {

            printf("enter data about student\n 1-student roll number \n 2-student name \n 3-date of return\n day/month/year\n ");
            scanf("%d\n%[^\n]%d%c%d%c%d",&newnode->std_rollNum,&newnode->name,&newnode->ReturnDate.day,&a,&newnode->ReturnDate.month,&b,&newnode->ReturnDate.year);
            while(ptr->next!=NULL&&ptr->rollNum!=newnode->std_rollNum)
            {
                ptr=ptr->next;
            }
            if(ptr!=NULL&&ptr->rollNum==newnode->std_rollNum)
            {
                ptr->numOfIssued= ptr->numOfIssued+1;

            }

            if( book_ptr->next_student==NULL)
            {
                book_ptr->next_student=newnode;
                newnode->next_s=NULL;
            }
            else
            {
                while(student_ptr->next_s!=NULL)
                {
                    student_ptr=student_ptr->next_s;
                }
                student_ptr->next_s=newnode;
                newnode->next_s=NULL;
            }
        }
        else
        {
            printf("book not available\n");
        }
    }
    return start_book;
}


//returns issued book with sepcifide time
void Return(struct node_book*start_b,struct node_student*start_student)
{

    struct node_time currentDate;
    int acessnum ;
    int rollnum;
    char a,b;
    struct node_book*book_ptr;
    struct student_book*ptr,*preptr;
    struct node_student*student_ptr;
    student_ptr=start_s;
    printf("enter access number of book \n ");
    scanf("%d",&acessnum );
    book_ptr=start_b;
    while(book_ptr!=NULL&&book_ptr->accessNum !=acessnum )
    {
        book_ptr=book_ptr->next;
    }
    printf("enter roll number of student \n");
    scanf("%d",&rollnum);
    ptr=book_ptr->next_student;
    while(ptr!=NULL&&ptr->std_rollNum!=rollnum)
    {
        preptr=ptr;
        ptr=ptr->next_s;
    }

    while(student_ptr->next!=NULL&&student_ptr->rollNum!=ptr->std_rollNum)
    {
        student_ptr=student_ptr->next;
    }
    if(student_ptr!=NULL&&student_ptr->rollNum==ptr->std_rollNum)
    {
        student_ptr->numOfIssued= student_ptr->numOfIssued-1;

    }


    if(ptr->std_rollNum==rollnum)
    {
        printf("enter the current date\n day/month/year\n");
        scanf("%d%c%d%c%d",&currentDate.day,&a,&currentDate.month,&b,&currentDate.year);
        if(currentDate.year>ptr->ReturnDate.year)
        {
            printf("\nlate return ,you should pay money\n");
        }
        else if(currentDate.year==ptr->ReturnDate.year&&currentDate.month>ptr->ReturnDate.month)
        {
            printf("\nlate return ,you should pay money\n");
        }
        else if(currentDate.year==ptr->ReturnDate.year&&currentDate.month==ptr->ReturnDate.month&&currentDate.day>ptr->ReturnDate.day)
        {
            printf("\nlate return ,you should pay money\n");
        }


        if(ptr==NULL)
        {
            printf("not exist\n ");
        }
        else
        {

            preptr->next_s=ptr->next_s;
            free(ptr);
            printf("book returned \n ");
        }

    }


}






