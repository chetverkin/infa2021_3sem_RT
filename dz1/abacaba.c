
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void GeneateString(int n){
	// Преобразование первого символа в код
	char* letter = "a";
	int letterСode = (int)letter[0];
	// Выделение памяти
	char *string1 = malloc((n*n*n)*sizeof(char));
	char *string2 = malloc((n*n*n)*sizeof(char));
	string1[0] = letter[0];
	// Печать строк
	printf("%c\n", letter[0]);
	for (int i = 0; i < n; ++i){
		string2 = strcpy(string2, string1);
		letterСode+=1;
		string1[strlen(string1)] = (char)(letterСode);
		string1 = strcat(string1, string2);
		printf("%s\n", string1);
		}
	
	}






int main(int argc, char **argv)
{
	GeneateString(8);
	return 0;
}

