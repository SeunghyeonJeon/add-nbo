#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>



int file_read(char argv[]){
	uint32_t buffer, result;
	
	FILE* f = fopen(argv, "rb");
	
	result = fread(&buffer, 1, sizeof(uint32_t), f);
	if(result == 0){
		perror("fread error");
		return 1;
	}
	else
		return buffer;
}



int main(int argc, char *argv[])
{
   uint32_t n1,n2,n_result;


   int result1, result2;

   if(argc!=3){
       perror("argument error");
       return 1;
   }
   
   n1 = ntohl(file_read(argv[1]));
   n2 = ntohl(file_read(argv[2]));

   n_result = n1+n2;

   printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",n1,n1,n2,n2,n_result,n_result);
}
