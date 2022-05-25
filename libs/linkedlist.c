#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "node.h"
#include "linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;


bool empty(){

	return _head==NULL;
}

size_t size(){

	size_t count=0;
	Node *ptr=_head;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		count++;
	}

	return count;
}

void print(){
	Node *ptr=_head;
	printf("[ ");
	while(ptr!=NULL)
	{
		printf("%s ", ptr->data);
		ptr=ptr->next;
	}
	printf("]\n");

	ptr = _tail;
	printf("[ ");
	while(ptr!=NULL)
	{
		printf("%s ",ptr->data);
		ptr=ptr->prev;
	}
	printf("]\n");
}

void print_file(FILE* stream){

	Node *ptr=_head;
	fprintf(stream, "[ ");
	while(ptr!=NULL)
	{
		fprintf(stream,"%s ",ptr->data);
		ptr=ptr->next;
	}
	fprintf(stream,"]\n");
}

void clear(){

	Node* prev;
	Node* ptr;
	ptr=_head;
	while(ptr!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
		free_node(prev);
	}
	_head = NULL;
	_tail = NULL;
	_cur_node = NULL;
}

Node* push( char new_data[])
{
	struct Node* new_node=alloc_node(new_data);
	new_node->next = _head;
	new_node->prev = NULL;

	if (_head != NULL)
		_head->prev = new_node;
	else
	{
		_cur_node=_tail=new_node;
	}

	_head = new_node;

	return new_node;
}

Node* append_left(Node* cur_node, char new_data[]){
	if(size()==0)
	{
		return push(new_data);
	}

	if(cur_node==_head)
	{
		return push(new_data);
	}

	struct Node* new_node=alloc_node(new_data);

	new_node->prev = cur_node->prev;

	cur_node->prev = new_node;

	new_node->next = cur_node;

	if (new_node->prev != NULL)
		new_node->prev->next = new_node;

	return new_node ;
}

Node* insert_after(Node* cur_node, char new_data[]){
	if(size()==0)
	{
		return push(new_data);
	}

	struct Node* new_node=alloc_node(new_data);

	new_node->next = cur_node->next;
	cur_node->next = new_node;
	new_node->prev = cur_node;

	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	else
		_tail=new_node;

	return new_node;
}

Node* append(char new_data[]){
	struct Node* new_node=alloc_node(new_data);

	if (_head ==NULL)
	{
		_head = _tail = _cur_node=new_node;
	}
	else
	{
		_tail->next=new_node;
		new_node->prev=_tail;
		_tail=new_node;
	}

	return new_node;
}

Node* delete_node(Node* cur_node){
	if (size()==0)
		return NULL;
	if(cur_node==_head)
	{
		Node *ptr=cur_node->next;
		ptr->prev=NULL;
		free(cur_node);
		_head=ptr;
		return NULL;
	}
	Node *prev=cur_node->prev;
	prev->next=cur_node->next;
	if(prev->next!=NULL)
		prev->next->prev=prev;
	else
		_tail=prev;

	free_node(cur_node);

	return NULL;
}

Node* delete1(char* data){
	Node *ptr=_head;

	while(ptr!=NULL)
	{
		if(strcmp(ptr->data,data)==0)
		{
			return delete_node(ptr);
		}
		ptr=ptr->next;
	}

	return NULL;
}

Node* get_node(size_t index){
	int count=0;

	if(size()-1<index)
	{
		return NULL;
	}

	Node *ptr=_head;
	while(count!=index)
	{
		ptr=ptr->next;
		count++;
	}

	return ptr;
}

Node* first(){

	return _head;
}

Node* last(){

	return _tail;
}

Node* next(){
	_cur_node=_cur_node->next;
	return _cur_node;
}

Node* curr(){
	
	return _cur_node;
}

