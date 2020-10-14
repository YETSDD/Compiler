#include "symtab.h"

/*
 * symbol table type, binary tree impl
 */
struct symtab {
    entry entry;
    struct symtab *left, *right;
};

// ************************************************************
//    Your implementation goes here
// ************************************************************

symtab *symtab_init(){
    symtab *newNode = (symtab*)malloc(sizeof(symtab));
    memset(newNode, 0, sizeof(symtab));
    entry_init(&newNode->entry,"-1",-1);
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int symtab_insert(symtab *self, char *key, VAL_T value){
    if(symtab_lookup(self,key)!=-1)
        return 0;
    //printf("insert %s %d\n",key,value);
    if(self->right==NULL&&self->entry.value==-1){
        symtab *newNode = (symtab*)malloc(sizeof(symtab));
        newNode->left=NULL;
        newNode->right=NULL;
        entry_init(&newNode->entry,key,value);
        self->right=newNode;
        return 1;
    }
    else if(self->right!=NULL&&self->entry.value==-1){
        return symtab_insert(self->right,key,value);
    }
    else{
        if(value<self->entry.value){
            //printf("left\n");
            if(self->left==NULL){
                symtab *newNode = (symtab*)malloc(sizeof(symtab));
                newNode->left=NULL;
                newNode->right=NULL;
                entry_init(&newNode->entry,key,value);
                self->left=newNode;
                return 1;
            }
            else{
                return symtab_insert(self->left,key,value);
                
            }
        }
        else{
            //printf("right\n");
            if(self->right==NULL){
                symtab *newNode = (symtab*)malloc(sizeof(symtab));
                newNode->left=NULL;
                newNode->right=NULL;
                entry_init(&newNode->entry,key,value);
                self->right=newNode;
                return 1;
            }
            else{
                return symtab_insert(self->right,key,value);
                
            }
        }
    }
    return 0;
}

VAL_T symtab_lookup(symtab *self, char *key){
    if(strcmp(self->entry.key,key)==0){
        return self->entry.value;
    }
    if(self->left!=NULL&&self->right!=NULL){
        VAL_T result1=symtab_lookup(self->left,key);
        VAL_T result2=symtab_lookup(self->right,key);
        if(result1==-1&&result2==-1)
            return -1;
        else
            return result1+result2+1;
    }
    else if(self->left!=NULL&&self->right==NULL){
        return symtab_lookup(self->left,key);
    }
    else if(self->left==NULL&&self->right!=NULL){
        return symtab_lookup(self->right,key);
    }
    else if(self->left==NULL&&self->right==NULL){
        return -1;
    }

}

int symtab_remove(symtab *self, char *key){
    //printf("remove %s %d\n",key,self->entry.value);
    int result1=0;
    int result2=0;
    symtab * temp=self;
    if(self->left!=NULL){
        temp=self->left;
        if(strcmp(temp->entry.key,key)==0){
            if(temp->left==NULL&&temp->right==NULL){
                self->left=NULL;
                free(temp);
            }
            else if(temp->left!=NULL&&temp->right==NULL){
                self->left=temp->left;
                free(temp);
            }
            else if(temp->left==NULL&&temp->right!=NULL){
                self->right=temp->right;
                free(temp);
            }
            else if(temp->left!=NULL&&temp->right!=NULL){
                symtab*cur=temp->right;
                symtab*parent=temp;
                while(cur->left!=NULL){
                    parent=cur;
                    cur=cur->left;
                }
                //printf("current value %d\n",cur->entry.value);
                if(cur->right!=NULL)
                    parent->left=cur->right;
                strcpy(temp->entry.key,cur->entry.key);
                temp->entry.value=cur->entry.value;
                free(cur);
            }
            //printf("remove %s successful\n",key);
            return 1;
        }
    result1=symtab_remove(temp,key);
    }
    if(self->right!=NULL){
        temp=self->right;
        if(strcmp(temp->entry.key,key)==0){
            if(temp->left==NULL&&temp->right==NULL){
                self->right=NULL;
                free(temp);
            }
            else if(temp->left!=NULL&&temp->right==NULL){
                self->left=temp->left;
                free(temp);
            }
            else if(temp->left==NULL&&temp->right!=NULL){
                self->right=temp->right;
                free(temp);
            }
            else if(temp->left!=NULL&&temp->right!=NULL){
                symtab*cur=temp->right;
                symtab*parent=temp;
                while(cur->left!=NULL){
                    parent=cur;
                    cur=cur->left;
                }
                //printf("current value %d\n",cur->entry.value);
                if(cur->right!=NULL)
                    parent->left=cur->right;
                strcpy(temp->entry.key,cur->entry.key);
                temp->entry.value=cur->entry.value;
                free(cur);
            }
            //printf("remove %s successful\n",key);
            return 1;
        }
    result2=symtab_remove(temp,key);
    }
    return result1+result2;
}
