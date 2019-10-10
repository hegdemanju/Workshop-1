#include <stdio.h>
#include <stdlib.h>

// Node of the linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
    Node *head;
    int number_of_nodes;
} List;

// initializes a linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at the beginning of the List
void insert_front(List* dll, int data);

// Deletes the node at position pos. No operation if pos is out of range.
void position_delete(List* dll, int pos);

// Return index of key in the list(0-based). Return -1 if not found
int search_list(List* dll, int key);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* dll);

// Deallocates resources held by the list
void destroy_list(List* dll);

int main() {
    List* dll = initialize_list();
    int ele, choice, pos;
   
    do {
        scanf("%d", &choice);

        switch(choice) {
            // Insert at beginning
            case 1:
                scanf("%d", &ele);
                insert_front(dll, ele);
                break;

            // Delete at position
            case 2:
                scanf("%d", &pos);
                position_delete(dll, pos);
                break;

            // Search for element
            case 3:
                scanf("%d", &ele);
                pos = search_list(dll, ele);
                printf("%d\n", pos);
                break;

            // Print entire list
            case 4:
                display(dll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(dll);
    return 0;
}
List* initialize_list(){
    List*p;
    p=malloc(sizeof(List));
    p->head=NULL;
    p->number_of_nodes=0;
    return p;
}
Node* create_node(int data){
    Node*new_node;
    new_node=malloc(sizeof(Node));
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
    return new_node;
}
void insert_front(List* dll, int data){
    Node*cur;
    cur=create_node( data);
    if(dll->head==NULL){
        dll->head=cur;
        
    }
    else{
        Node*q;
        cur->next=dll->head;
        dll->head->prev=cur;
        dll->head=cur;
        

        

    }
    dll->number_of_nodes++;

}
void position_delete(List* dll, int pos){
    Node*previous;
    Node*present;
    int i=0;
 
    
    if(pos==0){
        Node*temp=dll->head;
        dll->head=dll->head->next;
        
        if(dll->head!=NULL){
            free(temp);
            dll->head->prev=NULL;
            dll->number_of_nodes--;
            return;

        }
        

    }
    if(pos>0&&pos<dll->number_of_nodes){
        Node*temp1=dll->head;
        while(i<pos){

            
            temp1=temp1->next;
            i++;
        }
        if(pos==i&&temp1->next!=NULL){
        temp1->next->prev=temp1->prev;
        temp1->prev->next=temp1->next;
        
        free(temp1);
        dll->number_of_nodes--;
        return;
        }
        else{
            Node*j;
            j=dll->head;
            while(j->next!=NULL){
                j=j->next;



            }
            j->prev->next=NULL;
            j->prev=NULL;
            free(j);
            dll->number_of_nodes--;
            return;




        }



          
    }
}
    int search_list(List* dll, int key){
        int position=-1;
        int i=0;
        Node*k;
        k=dll->head;
        while(k!=NULL){
            if(k->data==key){
                
                position=i;
                return position;
            }
            
            k=k->next;
            i++;
            

        }
        return position;

    }
    void display(List* dll){
        Node*temp;
        temp=dll->head;
        if(dll->number_of_nodes==0){
            printf("EMPTY");
            printf("\n");
        }
        else{
            while(temp!=NULL){
                printf("%d ",temp->data);
                temp=temp->next;

            }
            printf("\n");
        }

    }
    void destroy_list(List* dll){
        free(dll);
        dll->number_of_nodes=0;
    }
    






