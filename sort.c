#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int sorterFunc(const void *a, const void *b){
	const char *aa = *(const char**)a;
	const char *bb = *(const char**)b;
	return strcmp(aa,bb);
}

int main(int argc, char *argv[]){

	//Initializeing and declareing a instance of the vector
	Vector v;
	Vector_ctor(&v);

	FILE *fp;
	
	fp = fopen(argv[1], "r");	
	if(fp == NULL){
		printf("you did not provide a file name\n");
		exit(EXIT_FAILURE);
	}

	char *strPointer;

	while(feof(fp) == 0){
		strPointer = (char*) malloc(sizeof(char) * 1024); //maybe only allocate (sizeof(char) * read) = length of string
		fgets(strPointer, sizeof(char*) * 1024, fp);
		//printf("%s",strPointer);
		Vector_push_back(&v, strPointer);
	}

	//get elements from vector
	/*for(size_t i = 0; i < Vector_size(&v); i++){
		printf("%s \n", (char*) Vector_get(&v, i) );
	}*/

	qsort(Vector_data(&v), Vector_size(&v), sizeof(void *), sorterFunc);

	//printf("***************after sorting the vectore************ \n");

	for(size_t i = 0; i < Vector_size(&v); i++){
		printf("%s", (char*) Vector_get(&v, i) );
	}

	fclose(fp);
	
	//zd size_t format specifyer
	//printf("%zd \n", (size_t) Vector_capacity(&v) ); 

	//Deconstructing the instance of the vector
	Vector_dtor(&v);

	return 0;
}
