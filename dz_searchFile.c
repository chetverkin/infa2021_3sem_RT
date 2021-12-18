
#include <stdio.h>

void searchFile(char folder[255], int bottom, int ourLevel, char target[100]){
	
	// Eсли мы не на дне
	if(ourLevel <= bottom) {
        DIR *dir;
        struct dirent *dp;
        // открываем директорию 
        dir = opendir(folder);
        // пока не дошли до конца
		while ((dp = readdir(dir)) != NULL) {
			// если нашли файл
            if (dp->d_type != 4) {
                if (strcmp(dp->d_name, target) == 0) printf("%s/%s \n", folder, dp->d_name);
            }
            // углубляемся, елси не нашли
            else if ((dp->d_type == 4) && ((strcmp(dp->d_name, ".") != 0) && (strcmp(dp->d_name, "..") != 0))) {
                char fld[255];
                strcpy(fld, strcat(folder, "/"));
                findFile(strcat(fld, dp->d_name), bottom, ourLevel + 1,target);
            }
        }
        closedir(dir);
		
		
	
	
	}

/// это копия упражнения вашего одногруппника, где переменные названы иначе. не засчитано.




int main(int argc, char **argv)
{
	char filename[256];
    if (argc < 2) strcpy(filename, ".");
    else strcpy(filename, argv[1]);
    searchFile(filename, atoi(argv[2]), 0, argv[3]);
	return 0;
}

