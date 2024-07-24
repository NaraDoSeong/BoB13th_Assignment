#include <stdio.h>
#include <stdint.h>
void main(int argc, char *argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <filename> <filename>\n", argv[0]);
		return;
	}
	FILE *f1 = fopen(argv[1], "rb");
	FILE *f2 = fopen(argv[2], "rb");
	
	if(f2 == NULL|| f1 == NULL){
		printf("f1 or f2 open error");
		return;
	}
	
	uint32_t n1;
	uint32_t n2;
	
	fread(&n1, sizeof(n1),1,f1);
	fread(&n2, sizeof(n2),1,f2);
	
	n1 = n1>>24 | n1<<24 | (n1&0xff0000)>>8 | (n1 &0xff00)<<8;
	n2 = n2>>24 | n2<<24 | (n2&0xff0000)>>8 | (n2 &0xff00)<<8;
	
	//printf("%d %d\n", n1,n2);
	printf("%d", n1+n2);
}
