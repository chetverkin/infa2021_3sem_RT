#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>

int main(){

	int fd1[2], fd2[2], a, b, result, sum;
	/* Попытаемся создать pipe */

	if(pipe(fd1) < 0){

		/* Если создать pipe не удалось, печатаем об этом сообщение и прекращаем работу */

		printf("Can\'t create pipe\n");
		exit(-1); 
	} 
	
	if(pipe(fd2) < 0){

		/* Если создать pipe не удалось, печатаем об этом сообщение и прекращаем работу */

		printf("Can\'t create pipe\n");
		exit(-1); 
	} 

	/* Порождаем новый процесс */ 

	result = fork(); 

	if(result <0){ 

		/* Если создать процесс не удалось, сообщаем об этом и завершаем работу */

		printf("Can\'t fork child\n");
		exit(-1);

	} else if (result > 0) {

		/* Мы находимся в родительском процессе*/

		a = 1;
		
		b = 3;
		
		close (fd1[0]);
        close (fd2[1]);

        write (fd1[1], &a, sizeof (a));
        write (fd1[1], &b, sizeof (b));

		read (fd2[0], &sum, sizeof (sum));
		
        printf ("%d\n", sum); 

		/* Закрываем потоки данных и на этом родитель прекращает работу */

		close(fd1[1]);
		close(fd2[0]);
		printf("Parent exit\n");

	} else {

		/* Мы находимся в порожденном процессе */
		
		close (fd1[1]);
        close (fd2[0]);

        read (fd1[0], &a, sizeof (a));
        read (fd1[0], &b, sizeof (b));
		
		sum = a + b;
		
		write (fd2[1], &sum, sizeof (sum));

		/* Закрываем потоки и завершаем работу */

		close(fd1[0]);
		close(fd2[1]);

		}

	return 0;
	}
