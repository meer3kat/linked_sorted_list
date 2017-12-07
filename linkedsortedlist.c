#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

 struct List{ 
 	char *name; 
 	int freq;
 	struct List *next; 
 };

 typedef struct List List; 

//function to read a word. 
char *readword() {
	int size = 100;
	char *a = (char *)malloc(size * sizeof(char)); 
	int i = 0;
	int indicator = 0;
	int c;
	while (((c=getchar()) != EOF) && !isalpha(c));

	if (c == EOF){
		return NULL;
	}
	a[0] = c;
	while ( isalpha(c = getchar()) || isdigit(c) ){

		i++;
		a[i] = c;
	}
	i++;
	a[i] = '\0';

	a = (char *)realloc(a, i);
	//reallocate memory 
	//printf("%s the length of my word is %d \n", a, i);
	return a;
}

//constructor:
 List *cons (char *name, List *next){
 	List *n = (List *) malloc(sizeof(List));
 	if (n== NULL){
 		printf("out of memory in cons \n");
 		exit(1);
 	}
 	else {
 		(*n).name = name;
 		(*n).next = next;
 		(*n).freq = 1;
 	}

 	return n;
 }



void addsorted(List **np, char *word) {
	if(*np == NULL || strcmp(word,(**np).name) <0){
		*np = cons(word, *np);

	}
	else if(strcmp(word,(**np).name) == 0){
		(**np).freq++;
		return;
	}
	else{
		addsorted(&((**np).next), word);
	}
}

//to print our list
 void print(List *f) {
  //printf("[");
  while (f) {
    printf("%20s \t %d \n", (*f).name, (*f).freq);
    //if ((*f).next) {
    //  printf(", ");
    //}
    f = (*f).next;
  }
  
}

int main(){
	char *myword;
	List *list = NULL;


	while(myword = readword()){
		addsorted(&list,myword);	
	}
	print(list);
	free(list);
	return 1;
}


