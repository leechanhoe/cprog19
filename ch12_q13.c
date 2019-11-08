#include <stdio.h>
#include <string.h>
#define LINE_SIZE 256

void main()
{
	char seps[] =".,\t\n ";
	char *token;

	char buffer[LINE_SIZE];
	FILE *fp = fopen("london.txt", "r");
	if (fp == NULL) {
		printf("Failed to open file\n");
		return;
	}
	if(fp != NULL) {
		while (!feof(fp)) {
			fgets(buffer, sizeof(buffer), fp);
			token = strtok(buffer, seps);
			while(token != NULL) {
				printf("%s\n", token);
				token = strtok(NULL, seps);
			}
		}
		fclose(fp);
	}
}
