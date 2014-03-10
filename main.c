/*
 * 	main.c
 */
#include "main_header.h"


int main(int argc, char const *argv[])
{
	// var
	FILE *fr, *fw, *fk;
	unsigned char b = '\0';
	unsigned char k = '\0';

	if (argc != 4)
	{
		printf("%s KEY FROM TO\n", argv[0]);
		exit(0);
	}

	//copy file
	printf("KEY:  %s\n", argv[1]);
	printf("FROM: %s\n", argv[2]);
	printf("TO:   %s\n", argv[3]);
	fr = fopen(argv[2], "rb");
	fw = fopen(argv[3], "wb");
	fk = fopen(argv[1], "rb");
	if (fr && fw && fk) {
	    while (fread(&b, 1, 1, fr)) {
	    	if ( ! fread( &k, 1, 1, fk ) ) {
	    		fclose(fk);
	    		fk = fopen(argv[1], "rb");
	    	}
	    	b = b ^ k;
	    	fwrite(&b, 1, 1, fw);
	    }
	    fclose(fr);
		fclose(fw);
		fclose(fk);
	}
	else {
	    printf("ERROR\n");
	}
	return 0;
}
