

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void split(char* string, char* delimiters, char** tokens, int* tokensCount){
	int lenStr = strlen(string);
	// Считаю число знаков разделителей 
	for (int i = 0; i < lenStr; ++i){
		if (string[i] == *delimiters){
			*tokensCount+=1;
			}
		}
	// Добавляю каждое слово в массив 
	int start = 0;
	int end = 0;
	int top = 0;
	// Добавление слов в массив
	for (int i = 0; i < lenStr; ++i){
		if (string[i] == delimiters[0]){
			end = i;
			for (int j = start; j<end; ++j){
				tokens[top][j] = string[j];
				// printf("%d,%d,%d\n", j, top, end);
				// printf("%c, %c\n", tokens[top][j], string[j]);
				}
			tokens[top][end] = '\0';
			top+=1;
			start = end + 1;
			}
		}
	for (int j = start; j<lenStr; ++j){
				tokens[top][j] = string[j];
				// printf("%d,%d,%d\n", j, top, end);
				// printf("%c, %c\n", tokens[top][j], string[j]);
				}
	tokens[top][end] = '\0';
	top+=1;
	}


int main(){
	// printf("%s\n","Начало ");
	int x = 0;
	int *tokensCount = &x;
	// printf("%s\n","Создаю массив для слов");
	char **tokens = (char**)malloc(100*sizeof(char*));
	for (int i = 0; i < 100; ++i){
		tokens[i] = (char*)malloc(100*sizeof(char));
		}
	
	split("sdelal delo i n", " ", tokens, tokensCount);
	printf("%s\n","Начинаю печаттать слово");
	for (int i=0; i < *tokensCount+1; ++i){
		for (int j = 0; j < 100; ++j){
			printf("%c", tokens[i][j]);
		}
		printf("\n");
	}
	return 0;
}

