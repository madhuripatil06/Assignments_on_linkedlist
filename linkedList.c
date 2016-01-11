#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList createList(void){
	LinkedList list;
	list.first = NULL;
	list.last = NULL;
	list.length = 0;
	return list;
};

int add_to_list(LinkedList *list,void *value){
	Element *ele = (Element *)malloc(sizeof(Element));
	ele -> next = NULL;
	ele -> value = value;
	if(list -> length == 0){
		list -> first = ele;
		list -> last = ele;
	}else{
		list -> last -> next = ele;
		list -> last = ele;
	}
	list -> length++;
	return list -> length;
};

void *get_first_element(LinkedList list){
	if(list.first == NULL)
		return NULL;
	return list.first->value;
};

void *get_last_element(LinkedList list){
	if(list.last == NULL)
		return NULL;
	return list.last->value;
};

void forEach(LinkedList list, ElementProcessor e){
	while(list .first != NULL){
		e(list.first->value);
		list.first = list.first -> next;
	};
};
