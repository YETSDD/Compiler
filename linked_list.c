#include "linked_list.h"

node *linked_list_init(){
    node *head = (node*)malloc(sizeof(node));
    head->count = 0;
    head->next = NULL;
    return head;
}

void linked_list_free(node *head){
    node *cur = head;
    node *last;
    while(cur != NULL){
        last = cur;
        cur = cur->next;
        free(last);
    }
}

char linked_list_string[0x10000];

char *linked_list_tostring(node *head){
    node *cur = head->next;
    char *position;
    int length = 0;
    while(cur != NULL){
        position = linked_list_string + length;
        length += sprintf(position, "%d", cur->value);
        cur = cur->next;
        if(cur != NULL){
            position = linked_list_string + length;
            length += sprintf(position, "->");
        }
    }
    position = linked_list_string + length;
    length += sprintf(position, "%c", '\0');
    return linked_list_string;
}

int linked_list_size(node *head){
    return head->count;
}

void linked_list_append(node *head, int val){
    node *cur = head;
    node *new_node;
    while(cur->next != NULL){
        cur = cur->next;
    }
    new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    cur->next = new_node;
    head->count++;
}

/* your implementation goes here */
void linked_list_insert(node *head, int val ,int index) {
    node *temp=head;
    for(int i=0;i<index;i++){
        if(temp->next!=NULL){temp=temp->next;}
        else{ return ;}
    }
    node* toinsert = (node*) malloc(sizeof(node));
    toinsert->value=val;
    toinsert->next=temp->next;
    temp->next=toinsert;
    head->count++;
}

void linked_list_delete(node *head, int index){
    if(index<0 || index>=head->count){
    return;
    }

    node *temp=head;
    for(int i=0;i<index;i++){
        if(temp->next!=NULL){ temp=temp->next;}
        else return;

    }

    node* temp2=temp->next;
    temp->next=temp2->next;
    head->count--;
}
void linked_list_remove(node *head, int val){
    node *temp = head;
    while(temp->next!=NULL){
        if(val==temp->next->value) {

                temp->next=temp->next->next;
            head->count--;
            break;
        }
        temp=temp->next;
    }
}

void linked_list_remove_all(node * head, int val){
    node *temp =head;
    while(temp->next!=NULL){
        if(val== temp->next->value){
            while(temp->next->value==val){
            temp->next=temp->next->next;
            head->count--;
            }
        }
        temp=temp->next;
    }
}

int linked_list_get(node* head, int index){
    if(index<0 || index>=head->count)
        return 0x80000000;
    node* temp = head->next ;

    for(int i=0;i<index;i++){
        if(temp->next!=NULL){temp=temp->next;}
        else {return 0x8000000;}
    }
    return temp->value;
}

int linked_list_search(node * head, int val){
    int index=-1;
    node * temp = head;
    while(temp->next!=NULL){
        if(val == temp->value)
            return index;
        temp=temp->next;
        index++;

    }
    return -1;
}

node *linked_list_search_all(node * head, int val){
    node *res = linked_list_init();
    node *temp = head;
    int index = -1;
    while(temp->next!=NULL){
        if(val==temp->value)
            linked_list_append(res,index);
        temp = temp->next;
        index++;
    }
    return res;
}
