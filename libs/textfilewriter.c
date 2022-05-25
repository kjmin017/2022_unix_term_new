#include <stdio.h>
#include "linkedlist.h"
#include "textfilewriter.h"
void create_music_titles(FILE* stream){
	//make linked list?
	while(feof(stream) == 0){
		char str[MAX_TITLE_SIZE];
		fgets(str, MAX_TITLE_SIZE, fp);
		printf("%s", str);
		add(str); //add song to linked list
	}
}

void read_file(char* file_name){
	FILE *fp;
	fp = fopen(*file_name, "r");
	if(fp == NULL){
		printf("failed\n")
	}
	create_music_titles(*fp);

	fclose(fp);
}
void write_file(char* file_name){
	FILE *fp = fopen(*file_name, "w");
	int i = 0;
	while(p != NULL){
		fputs(p->song, fp);
		p = p -> prev;
		i++;
	}
	char num = i + '0';
	fputs(num, fp);
	fclose(fp);
}
