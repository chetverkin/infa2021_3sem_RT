

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void split(char* string, char* delimiters, char** tokens, int* tokensCount){
	int lenStr = strlen(string);
	printf("%s\n","Считаю число знаков разделителей");
	// Считаю число знаков разделителей 
	for (int i = 0; i < lenStr; ++i){
		if (string[i] == *delimiters){
			*tokensCount+=1;
			}
		}
	printf("%s\n","Создаю массив для слов");
	// Создаю массив для слов
	tokens = (char **)malloc((*tokensCount+1)*sizeof(char*));
	for (int i = 0; i < *tokensCount; ++i){
		tokens[i] = (char*)malloc(lenStr*sizeof(char));
		}
	// Добавляю каждое слово в массив 
	printf("%s\n","Добавляю каждое слово в массив ");
	int start = 0;
	int end = 0;
	int top = 0;
	for (int i = 0; i < lenStr; ++i){
		if (string[i] == delimiters[0]){
			end = i;
			// Добавление слова в массив
			for (int j = start; j<end; ++j){
				tokens[top][j] = string[j];
				//printf("%d,%d,%d\n", j, top, end);
				}
			tokens[top][end] = '\0';
			top+=1;
			start = end + 1;
			}
		}
	}


int main(){
	printf("%s\n","Начало ");
	int x = 0;
	int *tokensCount = &x;
	char A[][];
	char** tokens;
	split("sdelal delo i n", " ", tokens, tokensCount);
	printf("%s\n","Начинаю печаттать слово");
	for (int i=0; i < *tokensCount + 1; ++i){
		printf("%c\n", **tokens);
	}
	return 0;
}

