#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum {
	MOV, /* 1 */
	JMP, // 2
	CMP, // 3
	ADD,	/* 4 */
	db,
	error
} ins;
ins lor(char *cmnd) {
	if(strcmp(cmnd, "mov") == 0) return MOV;
	if(strcmp(cmnd, "add") == 0) return ADD;
	if(strcmp(cmnd, "db") == 0) return db;
	/* i need to add more */
	return error;
}	
		

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("%s <filename>%c", argv[0], 10);
		return 1;
	}
	FILE *cl = fopen(argv[1], "r");
	char seecmd[50];
	char value[50];
	char name[50];
	char randomstring[100];
	int temp1;
	if (cl == NULL) {
		printf("error");
		return -1;
	}
	char ch;
	while (fscanf(cl, "%s %[^,], %s", seecmd, name, value) == 3) { // beware, value is a string
		ins op = lor(seecmd);
		switch(op) {
			case db:
				char *stringandond[50];
				*stringandond = value;
				printf("%s%c", *stringandond, 10);
				break;
			case MOV:
				temp1 = atoi(value);
				printf("%d%c", temp1,10);
				break;
			case ADD:
				temp1 = temp1 + atoi(value);
				printf("%d%c", temp1, 10);
				break;
			default:
				printf("error%c", 10);
				fclose(cl);
				return -1;
		}
	}
	fclose(cl);

	return 0;
}

