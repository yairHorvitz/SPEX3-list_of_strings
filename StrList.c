#include "StrList.h"
#include <stdlib.h>
#include <stdio.h>

struct _StrList
{
    Node* _head;
    size_t _size;
};
typedef struct _StrList StrList;

typedef struct _node {
    char* _data;
    struct _node * _next;
} Node;

//------------------------------------------------
// Node implementation
//------------------------------------------------

Node* Node_alloc(char* data, Node* next) 
{
	Node* p= (Node*)malloc(sizeof(Node));
	p->_data= data;
	p->_next= next;
	return p;
}

void Node_free(Node* node) {
	free(node);
}

//------------------------------------------------
// List implementation
//------------------------------------------------

StrList* StrList_alloc() {
	StrList* p= (StrList*)malloc(sizeof(StrList));
	p->_head= NULL;
	p->_size= 0;
	return p;
}

void StrList_free(StrList* list) {
	if (list==NULL) return;
	Node* p1= list->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		Node_free(p2);
	}
	free(list);
}


size_t StrList_size(const StrList* list) {
	return list->_size;
}

void StrList_insertLast(StrList* StrList, const char* data){
    if(StrList->_head == NULL){
        StrList->_head= Node_alloc(data,StrList->_head);
    }
    else{
        Node* p = StrList->_head;
        while(p){
            p= p->_next;
        }
        p->_next = Node_alloc(data,NULL);
        ++(StrList->_size);
    }
}

void StrList_insertAt(StrList* StrList, const char* data,int index)
{
    if(index > StrList->_size || index < 0) {return;}
    Node* p1 = StrList->_head;
    if(index==0)
    {
    StrList->_head= Node_alloc(data, p1);
    }
    Node* p2;
    Node* pnewNode;
    for (size_t i = 0; i < index-1; i++)
    {
        p1 = p1->_next ;
    }
    p2 = p1->_next;
    pnewNode = Node_alloc(data, p2);
    p1->_next = pnewNode;
}


char* StrList_firstData(const StrList* StrList){
    return StrList->_head->_data;
}


void StrList_print(const StrList* StrList){
    Node* p1 = StrList->_head;
    for (size_t i = 0; i < StrList->_size; i++)
    {
        printf("%S",p1->_data);
        p1= p1->_next;
    }
    

}

void StrList_printAt(const StrList* Strlist,int index){

    Node* p1;
    for (size_t i = 0; i < index; i++)
    {
        p1= p1->_next; 
    }
     printf("%S",p1->_data);
    
}

int StrList_printLen(const StrList* Strlist)
{
 int count=0;
 Node* p=Strlist->_head;
 for (size_t i = 0; i < Strlist->_size; i++)
{
count=count+len(p->_data);
p = p->_next;
}
 return count;
}


int StrList_count(StrList* StrList, const char* data)
{
int count=0;
Node* p=StrList->_head;
for (size_t i = 0; i < StrList->_size; i++)
{
    if (strcmp(p->_data, data) == 0)
    {
       count=count++;
    }
    
p = p->_next;
}
 return count;
}
/*
	Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data)
{
    Node* p1=StrList->_head;
    Node* p2=StrList->_head->_next;
    if (strcmp(p1->_data,'\0')){return;}
     while(strcmp(p1->_data, data) == 0)
     {
        StrList->_head = p1->_next;
        Node_free(p1);
        p1= StrList->_head;
        p2=p2->_next;
        --(StrList->_size);
     }
     while(strcmp(p2->_data, data) == 0)
        {
        p1->_next=p2->_next;
        Node_free(p2);
        --(StrList->_size);
        p1 = p1->_next;
        p2 = p2->_next;
        }

}


void StrList_removeAt(StrList* StrList, int index)
{
     if(index > StrList->_size || index < 0) {return;}
    Node* p1 = StrList->_head;
    if(index == 0)
    {
        StrList->_head = p1->_next;
        Node_free(p1);
        --(StrList->_size);
    }
    else{
        Node* p2=StrList->_head->_next;
        while (index != 1)
        {
          p1= p1->_next;
          p2= p2->_next;
          index = index-1;
        }
          p1->_next=p2->_next;
        Node_free(p2);
        --(StrList->_size);
    }
}
/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
Node* p1 = StrList1->_head;
Node* p2 = StrList2->_head;
if(StrList1->_size != StrList2->_size){return;}
else{
    for (size_t i = 0; i < StrList1->_size; i++)
    {
      if(strcmp(p1->_data,p2->_data)!=0){return 0;}
    }
    return 1;
}
}
/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrList)
{
StrList* copy = StrList_alloc();
 return copy; 
}



void StrList_reverse(StrList* Strlist){ 
    Node* preversed = Strlist->_head;
    Node* p1 = Strlist->_head->_next;
    Node* p2 = p1->_next ;
    Strlist -> _head = p1;
    
     for (size_t i = 0; i < Strlist->_size; i++){
        p2 = p2->_data;
    }


    }
    void StrList_sort(StrList* StrList)
{
Node* p1 = StrList->_head; 
Node* p2 = StrList->_head->_next;


 for(int i=0;i<StrList->_size;i++)
 {
    for(int j=0; j<StrList->_size;i++)
    {
        if (strmp(p1->_data >= p2->_data)>0)
        {
           Node* temp = StrList->_head;
           Node* temp = p1;
           p1 = p2;


        }
        
    }
 }
}