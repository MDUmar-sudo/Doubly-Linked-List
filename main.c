#include <stdio.h>
#include <stdlib.h>
#define rep(y,x) for(int i=y;i<x;i++)

typedef struct Node dll;
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

dll*head=NULL;


//Creating initial LinkedList

void createNode(){
    dll *temp,*ptr;

    temp = (dll *)malloc(sizeof(dll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{   ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
        ptr->next=temp;
        temp->prev=ptr;
    }
}

//Displaying the LinkedList

void display(){
    dll *ptr;
    int node_no=1;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        ptr = head;
        printf("\n");
        rep(0,30) printf("-");
        printf("\nDISPLAYING THE LINKED LIST\n");
        rep(0,30) printf("-");
        printf("\n[ NULL<--");
        while(ptr!=NULL){
        if(ptr->next==NULL){
            printf("(Data:%d||Node:%d)-->",ptr->data,node_no++);
        }
        else{
            printf("(Data:%d||Node:%d)<---->",ptr->data,node_no++);
        }
        ptr = ptr->next;
        }
        printf("NULL ]\n");
    }

}

/*
Insertion functions starts
*/

//Insertion at the beginning of the linked list
void insertAtBegin(){
    dll *temp;
    temp = (dll *)malloc(sizeof(dll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }
    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        head->prev=temp;
        temp->next=head;
        head=temp;
    }
}

//Insertion at the end of the linked list
void insertAtEnd(){
    dll *temp,*ptr;
    temp = (dll *)malloc(sizeof(dll));

    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp->prev=ptr;
    ptr->next=temp;
    }

}

//Insertion at a given position in the linked list
void insertAtPosition(){
    dll *temp,*ptr;
    temp = (dll *)malloc(sizeof(dll));
    ptr=head;

    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }

    int pos;
    printf("\nENTER POSITION FOR NODE INSERTION: ");
    scanf("%d",&pos);

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(pos==1){
        head->prev=temp;
        temp->next=head;
        head=temp;
    }
    else{
        int i=1;
        while(i!=pos-1){
            if(ptr->next==NULL){
              printf("\nPOSITION NOT FOUND!!\n");
              return;
            }
            ptr=ptr->next;
            i++;
        }
        temp->next=ptr->next;
        ptr->next->prev=temp;
        ptr->next=temp;
        temp->prev=ptr;
    }

}

//Insertion after a specified node in the linked list
void insertAfterNode(){
    dll *temp,*ptr;
    temp = (dll *)malloc(sizeof(dll));


    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        ptr=head;
        int nd;
        printf("\nENTER NODE VALUE FOR NODE INSERTION: ");
        scanf("%d",&nd);

        printf("\nENTER NODE DATA: ");
        scanf("%d",&temp->data);
        temp->prev=NULL;
        temp->next=NULL;
        while(ptr->data!=nd){
            if(ptr->next==NULL){
              printf("\nNODE NOT FOUND!!\n");
              return;
            }
            ptr=ptr->next;
        }
        if(ptr->next==NULL){
            temp->next=NULL;
            ptr->next=temp;
            temp->prev=ptr;
        }
        else{
                temp->next=ptr->next;
                ptr->next->prev=temp;
                ptr->next=temp;
                temp->prev=ptr;

        }
    }
}

/*
Insertion functions ends
*/


/*
Deletion functions starts
*/

//Deletion of node at the beginning of the linked list
void deleteAtFirst(){
    dll *ptr;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else if(head->next==NULL){
        ptr=head;
        head=NULL;
        free(ptr);
        printf("DELETION COMPLETE");
    }
    else{
        ptr=head;
        head=ptr->next;
        head->prev=NULL;
        free(ptr);
        printf("DELETION COMPLETE");
    }
}

//Deletion of node at the end of the linked list
void deleteAtLast(){
    dll *ptr;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else if(head->next==NULL){
        ptr=head;
        head=NULL;
        printf("DELETION COMPLETE");
        free(ptr);

    }

    else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;

        }
        ptr->prev->next=NULL;
        free(ptr);
        printf("DELETION COMPLETE");
    }
}

//Deletion of node at a given position in the linked list
void deleteAtPosition(){
    dll *ptr;
    if(head==NULL){
        printf(" \nLINKED LIST IS EMPTY");
        return;
    }


    else{
            int pos;
            printf("\nENTER POSITION FOR NODE TO DELETE : ");
            scanf("%d",&pos);

            if(pos==1){
                ptr=head;
                if(ptr->next==NULL){
                    head=NULL;
                    free(ptr);
                    printf("DELETION COMPLTETE");
                }
                else{
                    head=ptr->next;
                    head->prev=NULL;
                    free(ptr);
                    printf("DELETION COMPLTETE");
                }


            }

            else{
            ptr=head;
            int i=1;
            while(i<pos){

                if(ptr->next==NULL){
                  printf("\nPOSITION NOT FOUND!!\n");
                  return;
                }
                ptr=ptr->next;
                i++;
            }
            if(ptr->next==NULL){
                ptr->prev->next=NULL;
                free(ptr);
                printf("DELETION COMPLTETE");
            }
            else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr); //also can be done as temp = prt->next;
            printf("DELETION COMPLTETE");
            }

        }
    }


}

//Deletion of a specified node in the linked list
void deleteSpecifiedNode(){

    dll *ptr;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }

    else{
        int nd;
        printf("\nENTER NODE VALUE FOR NODE DELETION: ");
        scanf("%d",&nd);
        ptr=head;
        if(ptr->data==nd){
            if(ptr->next==NULL){
                head=NULL;
                free(ptr);
                printf("DELETION COMPLTETE");
            }
            else{
                head=ptr->next;
                head->prev=NULL;
                free(ptr);
                printf("DELETION COMPLTETE");
            }

        }
        else{
                while(ptr->data!=nd){
                if(ptr->next==NULL){
                  printf("\nNODE NOT FOUND!!\n");
                  return;
                }
                ptr=ptr->next;
            }
            if(ptr->next==NULL){
                ptr->prev->next=NULL;
                free(ptr);
                printf("DELETION COMPLTETE");
            }
            else{
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr;
                free(ptr); //also can be done as temp = prt->next;
                printf("DELETION COMPLTETE");
                }
            }

    }
}

/*
Deletion functions ends
*/

//Search function searches given node in the linked list

void searchNode(){
    dll *ptr;
    int node_no=1;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        ptr = head;
        int key;
        printf("\n");
        rep(0,30) printf("-");
        printf("\nENTER A NODE VALUE FOR SEARCHING : ");
        scanf("%d",&key);
        while(ptr->data!=key){
            if(ptr->next==NULL){
              printf("\nNODE NOT FOUND!!\n");
              rep(0,30) printf("-");
              printf("\n");
              return;
            }
            else
                ++node_no;
                ptr = ptr->next;
        }
        if(node_no==1) printf("\nNODE  %d FOUND @ %dst POSITION\n",ptr->data,node_no);
        else if(node_no==2) printf("\nNODE  %d FOUND @ %dnd POSITION\n",ptr->data,node_no);
        else if(node_no==3) printf("\nNODE  %d FOUND @ %drd POSITION\n",ptr->data,node_no);
        else printf("\nNODE  %d FOUND @ %dth POSITION\n",ptr->data,node_no);
        rep(0,30) printf("-");
        printf("\n");
    }
}

//Reverse the entire linked list

void reverseList(){
    dll *ptr,*prev,*next;
    prev=next=NULL;
    ptr=head;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        while(ptr!=NULL){
            next=ptr->next;
            ptr->next=prev;
            ptr->prev=next;
            prev=ptr;
            ptr=next;
        }
        head=prev;
        printf("\nLINKED LIST IS REVERSED\n");
    }
}



int main()
{
    int choice;
    rep(0,10) printf("*");
            printf("WELCOME TO DOUBLY LINKED LIST");
            rep(0,10) printf("*");
            printf("\n");
    while(1){

            rep(0,30) printf("=");
            printf("\n<-<-<-MAIN MENU->->->\n(1)CREATE\n(2)INSERT\n(3)DELETE\n(4)DISPLAY\n(5)SEARCH A NODE\n(6)REVERSE THE LIST\n(7)EXIT\n");
            rep(0,30) printf("-");
            printf("\nENTER YOUR CHOICE: ");
            scanf("%d",&choice);
            printf("\n");
            rep(0,30) printf("-");
            printf("\n");

            switch(choice){
                case 1: {   int num;
                            printf("\nENTER NUMBER OF NODES IN THE STARTING LINKED LIST: ");
                            scanf("%d",&num);
                            while(num!=0){
                                createNode();
                                num--;
                            }
                            break;
                        }

                case 2: {
                            int ch1;
                            rep(0,30) printf(">");
                            printf("\n<-<-<-INSERTION MENU->->->\n(1)INSERT AT THE BEGINNING\n(2)INSERT AT THE END\n(3)INSERT NODE AT POSITION\n(4)INSERT AFTER A SPECIFIED NODE\n");
                            rep(0,30) printf(">");
                            printf("\nENTER YOUR CHOICE: ");
                            scanf("%d",&ch1);
                            switch(ch1){
                                case 1: insertAtBegin();
                                        break;

                                case 2: insertAtEnd();
                                        break;

                                case 3: insertAtPosition();
                                        break;

                                case 4: insertAfterNode();
                                        break;

                                default: exit(0);
                            }
                            break;

                        }


                case 3: {
                            int ch2;
                            printf("\n");
                            rep(0,30) printf("<");
                            printf("\n<-<-<-DELETION MENU->->->\n(1)DELETE THE FIRST NODE\n(2)DELETE THE LAST NODE\n(3)DELETE NODE AT POSITION\n(4)DELETE A NODE OF SPECIFIED VALUE\n");
                            rep(0,30) printf("<");
                            printf("\nENTER YOUR CHOICE: ");
                            scanf("%d",&ch2);
                            switch(ch2){
                                case 1: deleteAtFirst();
                                        break;

                                case 2: deleteAtLast();
                                        break;

                                case 3: deleteAtPosition();
                                        break;

                                case 4: deleteSpecifiedNode();
                                        break;

                                default: exit(0);
                            }
                            break;

                        }

                case 4: display();
                        break;

                case 5: searchNode();
                        break;

                case 6: reverseList();
                        break;


                case 7: exit(0);
                        break;
                default: printf("WRONG OPTION SELCTED!!TRY AGAIN\n");

            }
            printf("\n");
            rep(0,30) printf("=");
            printf("\n\n\n");

    }
    getch();
    return 0;

}
