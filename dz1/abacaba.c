
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void GeneateString(int n, char* string1){
	// Преобразование первого символа в код
	char* letter = "a";
	int letterСode = (int)letter[0];
	// Выделение памяти
	char *string2 = malloc((n*n*n)*sizeof(char));
	string1[0] = letter[0];
	// Печать строк
	printf("%c\n", letter[0]);
	for (int i = 0; i < n; ++i){
		string2 = strcpy(string2, string1);
		letterСode+=1;
		string1[strlen(string1)] = (char)(letterСode);
		string1 = strcat(string1, string2);
		}
	free(string2);
	string2 = NULL;
	}






int main(int argc, char **argv)
{    
	int n = 8;
	char *string1 = malloc((n*n*n)*sizeof(char));
	// Длина результирующей строки растет как степень двойки, что быстрее, чем n^3. Ну, пусть пока так.
	GeneateString(n, string1);
	printf("%s\n", string1);
	free(string1);
	string1 = NULL;
	
	return 0;
}
