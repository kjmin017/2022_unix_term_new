#include <stdio.h>
#include "linkedlist.h"
#include "textfilewriter.h"
#include "node.h"
void create_music_titles(FILE* stream){
	Node* node = NULL;
	while(feof(stream) == 0){
		char str[MAX_TITLE_SIZE];
		fgets(str, MAX_TITLE_SIZE, fp);//get song titles from file
		printf("%s", str);
		node = insert_after(node, str);//create linkedlist
	}
}

void read_file(char* file_name){
	FILE *fp;
	fp = fopen(*file_name, "r");//open file
	if(fp == NULL){
		printf("failed\n")
	}
	create_music_titles(*fp);

	fclose(fp);
}
void write_file(char* file_name){
	FILE *fp = fopen(*file_name, "w");
	int i = 0;
	while(p != NULL){//p = external node
		fputs(p->song, fp);//save a song title
		p = p -> prev;//prev song title
		i++;//number of song
	}
	fprintf(fp, "%d\n", i);
	fclose(fp);
}
