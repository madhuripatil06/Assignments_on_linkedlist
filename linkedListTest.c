#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_for_create_list(){
	LinkedList result = createList();
	assert(result.first == NULL);
	assert(result.last == NULL);
};

void test_for_add_element_to_a_list(){
	LinkedList list = createList();
	int a = 2;
	add_to_list(&list,&a);
	assert(list.length == 1);
	int b = 8;
	add_to_list(&list,&b);
	assert(list.length == 2);
};

void test_for_get_first_ele(){
	LinkedList list = createList();
	assert((int *)get_first_element(list) == 0);
	int first = 6;
	int second = 9; 
	add_to_list(&list,&first);
	int res = *((int *)get_first_element(list));
	assert(res == 6);
	add_to_list(&list,&first);
	int result = *((int *)get_first_element(list));
	assert(result == 6);
};

void test_for_get_first_ele_char(){
	LinkedList list = createList();
	assert((int *)get_first_element(list) == 0);
	char first = 'a';
	char second = 'b'; 
	add_to_list(&list,&first);
	char res = *((char *)get_first_element(list));
	assert(res == 'a');
	add_to_list(&list,&second);
	char result = *((char *)get_first_element(list));
	assert(result == 'a');
};


void test_for_get_last_ele(){
	LinkedList list = createList();
	assert((int *)get_last_element(list) == 0);
	int a = 9;
	int b = 45;
	add_to_list(&list,&a);
	int last = *((int *)get_last_element(list));
	assert(last == 9);
	add_to_list(&list,&b);
	int last_for_2 = *((int *)get_last_element(list));
	assert(last_for_2 == 45);
};

void add_2(void * ele){
	*((int *)ele) += 2;
};

void test_for_forEach_in_list_add_2(){
	LinkedList list = createList();
	int array[3] ={43,90,67}; 
	int copy[3] = {43,90,67};
	add_to_list(&list,&array[0]);
	add_to_list(&list,&array[1]);
	forEach(list,add_2);
	Element *first = list.first;
	for(int  i = 0 ; i < list.length ; i ++){
		assert(*(int *)list.first -> value == copy[i] +2);
		list.first = list.first -> next;
	};
	list.first = first;
	add_to_list(&list,&array[2]);
	forEach(list,add_2);
	for(int i = 0 ; i < list.length-1 ; i++){
		assert(*(int*)list.first -> value == copy[i]+4);
		list.first = list.first -> next;
	};
	assert(*(int *)list.last -> value == copy[2]+2);
};

