#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char* name;
    char* lang;
    struct node *next;
    struct node *prev;
};
typedef struct node* node;

node create_node(char* nam, char* la) {
    node list = (node)malloc(sizeof(struct node));
    list->next = NULL;
    list->prev = NULL;
    if(nam[0]=='\0' || la[0]=='\0'){return NULL;}
    // Allocate memory for the name and language fields and copy the strings
    list->name = (char*)malloc(strlen(nam) + 1); // +1 for the null-terminator
    strcpy(list->name, nam);

    list->lang = (char*)malloc(strlen(la) + 1); // +1 for the null-terminator
    strcpy(list->lang, la);

    return list;
}



node add_song(node list, node x, char* ss) {
    if (list == NULL) {
        list=x;
        list->next=list->prev=NULL;
        return list;
    }

    node temp = list;
    int c = 0;

    if (strlen(ss) == 0) {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = x;
        x->prev = temp;
        x->next = NULL;
    }

    while (temp->next) {
        if (strcmp(temp->name, ss) == 0) {c=1;
            break;
        }
        temp = temp->next;
    }

    if (c==1) {
        if (temp->next) {
            x->next = temp->next;
            x->prev = temp;
            temp->next->prev = x;
            temp->next = x;
        } else {
            temp->next = x;
            x->prev = temp;
            x->next = NULL;
        }
    }else {
        if (temp->prev) {
            temp->prev->next = x;
            x->prev = temp->prev;
            x->next = temp;
            temp->prev = x;
        } else {
            temp->next=x;
            x->next=NULL;
            x->prev=temp;
            list=temp;
        }
    return list;
}}

node remove_song(node list,char* ss){
    node temp=list;int c=0;
    if(list==NULL)printf("-1\n");
    while(temp->next){
        if(strcmp(temp->name,ss)==0){c++;break;}
        temp=temp->next;
    }
    if (c) {
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            // If the node to be removed is the head of the list
            list = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }

        free(temp);
    } else {
        printf("-1\n");
    }
    return list;
}
void play_next_song(node list,char* ss){
    if(list==NULL){printf("-1\n");return;}
        node temp=list;int c=0;
    while(temp){
        if(strcmp(temp->name,ss)==0){c++;break;}
        temp=temp->next;
    }
    if(c==1){
     if(temp->next){
        printf("%s\n",temp->next->name);
    }
     else{
        printf("-1\n");
    }}
    else{
        printf("-1\n");
    }
}
void play_prev_song(node list,char* ss){
        if(list==NULL){printf("-1\n");return;}
        node temp=list;int c=0;
    while(temp){
        if(strcmp(temp->name,ss)==0){break;c++;}
        temp=temp->next;
    }
    if(c==1){
     if(temp->prev){
        printf("%s\n",temp->prev->name);
    }
     else{
        printf("-1\n");
    }}
    else{
        printf("-1\n");
    }

}
void display(node list){
    node temp=list;
            if(list==NULL){printf("-1\n");return;}
    while(temp){
        printf("%s %s\n",temp->name,temp->lang);
        temp=temp->next;
    }
}
int blank(char s[]){
    int count=0;int i=0;
    while(s[i]!='\0'){if(s[i]==' ')count++;i++;}
    return count;
}
int ii(char s[]){
    int i=0;int count=0;
    while(s[i]!='\0' && count!=2){ if(s[i]==' '){count++;}i++;}
return i;}
int main(){
   node list=create_node("","");
    char ch;
    char mod[100];
    char nam[100];
    char lan[100];
    char xtra[100];
    int i;int j;int k;
    int count;
    while(ch!='e'){
        scanf(" %c",&ch);

        switch(ch){
           case 'a':
              fgets(mod, sizeof(mod), stdin); // Read the entire line
              if (sscanf(mod, "%s %s %s", nam, lan, xtra) == 3) {
              // Successfully read all three strings
              node x = create_node(nam, lan);
             add_song(list, x, xtra);
             } else if (sscanf(mod, "%s %s", nam, lan) == 2) {
             // Read only two strings (nam and lan)
             node x = create_node(nam, lan);
             list=add_song(list, x, "");}
            break;
            case 'r':

              scanf("%s",nam);
              list=remove_song(list,nam);
            break;
            case 'd':
              display(list);
            break;
            case 'n':
             scanf("%s",nam);
             play_next_song(list,nam);
            break;
            case 'p':
             scanf("%s",nam);
             play_prev_song(list,nam);
            break;
        }
    }
}