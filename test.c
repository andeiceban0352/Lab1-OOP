#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void delete(int);

struct node {
    int data;
    struct node *next;
    struct node *last;
};

void append(struct node** ref_head, int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *last = *ref_head;

    new_node->data = new_data;

    new_node->next = NULL;
    
    if(*ref_head == NULL){
        *ref_head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

void prepend(struct node **head, int val){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void reverse(struct node **head){
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;

    while(current != NULL){
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}

void spec_index(struct node **current, int pos, int val) {
    if(pos < 1 || pos > (val + 1)) {
        printf("%s","Wrong Position ! \n");
    } else {
        while(pos--){
            if(pos == 0){

            }
        }
    }
}


int getCurrSize(struct node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}


//function to insert after nth node
void insertAfterNthNode(int n, int data, struct node** head)
{
    int size = getCurrSize(*head);

    struct node* newNode = (struct node*) malloc(sizeof(struct node)); 
    newNode->data = data;
    newNode->next = NULL;
    
    // Can't insert if position to insert is greater than size of Linked List
    // can insert after negative pos
    if(n < 0 || n > size) 
        printf("Invalid position to insert\n"); 
        
    // inserting first node
    else if(n == 0){
        newNode->next = *head; 
        *head = newNode;
    }
    
    else 
    {
        // temp used to traverse the Linked List
        struct node* temp = *head; 
        
        // traverse till the nth node
        while(--n)
            temp=temp->next;
        
        // assign newNode's next to nth node's next
        newNode->next= temp->next;
        // assign nth node's next to this new node
        temp->next = newNode;
        // newNode inserted b/w 3rd and 4th node
    }
}


bool search_for_value(struct node* head, int x)
{
    struct node* current = head; // Initialize current
    while (current != NULL) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}


void sortedInsert(struct node** head, struct node* newNode)
{
    struct node dummy;
    struct node* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
// Given a list, change it to be in sorted order (using `sortedInsert()`).
void insertSort(struct node **head)
{
    struct node* result = NULL;     // build the answer here
    struct node* current = *head;   // iterate over the original list
    struct node* next;
 
    while (current != NULL)
    {
        // tricky: note the next pointer before we change it
        next = current->next;
 
        sortedInsert(&result, current);
        current = next;
    }
 
    *head = result;
}

void show_ls(struct node *head){
    struct node *temp = head;

    while(temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

void deletes(struct node *head,int pos)
{
    struct node* temp = head; // Creating a temporary
                              // variable pointing to head
    int i;
    if (pos == 0) {
        printf("\nElement deleted is : %d\n", temp->data);
        head = head->next; // Advancing the head pointer
        temp->next = NULL;
        free(temp); // Node is deleted
    }
    else {
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        // Now temp pointer points to the previous node of
        // the node to be deleted
        struct node* del = temp->next; // del pointer points to the node
                          // to be deleted
        temp->next = temp->next->next;
        printf("\nElement deleted is : %d\n", del->data);
        del->next = NULL;
        free(del); // Node is deleted
    }
    printf("\nUpdated Linked List is : \n");

    return;
}

int findlength(struct node* head)
{
    struct node* curr = head;
    int cnt = 0;
    while (curr != NULL) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}


void combineTwoLists(struct node** head, struct node** head2) {
    struct node* val = *head2;
    while (val != NULL) {
        append(head, val->data);
        val = val->next;
    }
}

void Backwards(struct node** head) {
    struct node *tail = *head;
    while (tail->next != NULL)
        tail = tail->next;
    struct node* ptr = tail;

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->last;
    }
    printf("\n");
}


// Function to convert the
// Linked List to an array
void convertArr(struct node* head,int arr[],int* index)
{
    

    // Traverse the Linked List and add the
    // elements to the array one by one
    while (head != NULL) {
        arr[*index++] = head->data;
        head = head->next;
    }
}

int main() {
    int number = 1;
    int element;
    int index;  
    struct node *head = NULL; // store the addres of the first node
    struct node *head2 = NULL; // store the addres of the first node
    FILE *fp;
    int len;
    
    while(number != 12) {
        printf("- 1 Append \n");
        printf("- 2 Prepend \n");
        printf("- 3 Reverse \n");
        printf("- 4 Add value to index \n");
        printf("- 5 Remove a value at index \n");
        printf("- 6 Sort the list \n");
        printf("- 7 Search for a value \n");
        printf("- 8 Join two linked lists \n");
        printf("- 9 Backwards traversal \n");
        printf("- 10 Load the data structure \n");
        printf("- 11 Type the data structure and save it in a file \n");
        printf("- 12 Exit \n");
        
        printf("Type a number to execute a command : ");

        


    scanf("%d", &number);

         
    switch(number){
        case 1:
            printf("\n Append and element :");
            scanf("%d", &element);
            append(&head, element);
            append(&head2, element);
            printf("The list is : ");
            show_ls(head);
            printf("\n");
            break;
        case 2:
            printf("\n Prepend and element :");
            scanf("%d", &element);
            prepend(&head, element);
            printf("The list is : ");
            show_ls(head);
            printf("\n");
            break;
        case 3:
            printf("\n Reverse the list :");
            reverse(&head);
            printf("The reversed list is : ");
            show_ls(head);
            printf("\n");
            break;
        case 4:
            printf("\n Add a value : ");
            scanf("%d", &element);
            printf("\n Add a index : ");
            scanf("%d", &index);
            insertAfterNthNode(index,element, &head);
            printf("The list is : ");
            show_ls(head);
            printf("\n");
            break;
        case 5:
            printf("\n Enter the index of the numebr :");
	    scanf("%d", &element);
            deletes(head, element);
            show_ls(head);
            printf("\n");
            break;
        case 6:
            printf("\n Sort the list :");
            insertSort(&head);
            show_ls(head);
            printf("\n");
            break;
        case 7:
            printf("\n What number are you looking for :");
            scanf("%d", &element);
	    printf("\n");
            search_for_value(head,element) ? printf("Exist \n") : printf("Not exist ! \n");
            printf("\n");
            break;
        case 8:
            printf("The combined lists : ");
            combineTwoLists(&head,&head2);
            show_ls(head);
            printf("\n");
            break;
        case 9:
            printf("Backwards traversal: ");
            Backwards(&head);
            show_ls(head);
            printf("\n");
            break;
        case 10:
            fp=fopen("elements.txt","r");
            int* list=malloc(100*sizeof(*list));
            int j=0,n;
            while(fscanf(fp,"%d",&n)>0){
                list[j]=n;
                j++;
            }
            for(int i=0;i<j;i++){
                append(&head,list[i]);
            }
            fclose(fp);

            printf("The list is : ");
            show_ls(head);
            printf("\n");
            break;
        case 11:
            len = findlength(head);
            int* randbl=malloc(len*sizeof(*randbl));
            int i=0;
            convertArr(head,randbl,&i);
            for(int i=0;i<len;i++){
                printf("%d ",randbl[i]);
            };
            break;
        case 12:
            break;
        default:
            printf("Error! Invalid choice.");
        }
    }

    return 0;
}
