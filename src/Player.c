#include <stdio.h>
#include <stdlib.h>
#include <linkedlist.h>
#include <node.h>
#include <textfilewriter.h>
#define BUFFER_LENGTH 200

void handle_add();
void process_command();
//main에서 사용할 함수들의 prototype 선언

int main()
{
	process_command();
}

void process_command()
{
	char command_line[BUFFER_LENGTH];
	char* command; //명령어 저장하는 포인터

	while (1) //무한루프 돌며 프롬프트 출력하여 사용자 명령어 입력받음
	{
		printf("$ "); //명령어 입력받기 위한 프롬프트 출력
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0) //파일 포인터, 데이터 읽어올 변수, 길이
				continue;
		
		command = strtok(command_line, " "); //공백문자 전까지 토큰화해서 저장
		if (strcmp(command, "add") == 0 )
			handle_add();
		else if (strcmp(command, "del") == 0 )
			handle_del();
		else if (strcmp(command, "list") == 0 )
			handle_list();
		else if (strcmp(command, "next") == 0 )
			handle_next();
		else if (strcmp(command, "prev") == 0 )
			handle_prev();
		else if (strcmp(command, "move") == 0 )
			handle_move();
		else if (strcmp(command, "play") == 0 )
			handle_play();
		else if (strcmp(command, "clear") == 0 )
			handle_clear();
		else if (strcmp(command, "load") == 0 )
			handle_load();
		else if (strcmp(command, "save") == 0 )
			handle_save();
		else if (strcmp(command, "quit") == 0 )
			break;

	}
}


void handle_del()
{
	char* id_str = strtok(NULL, " ");
	int index = atoi(id_str);
	del(index);

}

void handle_play()
{
	char* id_str = strtok(NULL, " ");
	int index = atoi(id_str);
	play(index);
}

void handle_add()
{
	char buffer[BUFFER_LENGTH];
	char* song = NULL;
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0) //한글자 이상 입력받음
		song =strdup(buffer); //입력받은 노래명 복사해서 저장
}

void handle_save()
{
	char* song = strtok(NULL, " ");
	FILE* fp = fopen(song, "w");
	save(fp);
	fclose(fp);
}


void handle_list(){

}

void handle_next(){

}

void handle_prev(){

}

void handle_move(){

}

void handle_clear(){

}

void handle_quit(){
	quit();
}


void handle_load(){

}
