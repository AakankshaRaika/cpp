#include <stdio.h>
#include <string.h>

typedef struct _Person {
	char name[20];
	int age;
} Person;

void readFile();

void writeFile();

int main(int argc, char const *argv[])
{
	if (argc > 1 && *argv[1] == '1'){
		writeFile();
	}else{
		readFile();
	}
	return 0;
}

void readFile(){
	Person p[10];
	FILE *fp;
	fp = fopen("hello.txt", "r");
	if(!fp){
		printf("Failed to open file.");
		return;
	}
	int i;
	fread(p, sizeof(Person), sizeof(p)/sizeof(p[0]), fp);
	for(i=0;i<10;i++){
		printf("%s - %d\n", p[i].name, p[i].age);
	}
	fclose(fp);
}

void writeFile(){
	FILE *fp;
	fp = fopen("hello.txt","w");
	if(!fp){
		printf("Failed to open file.");
		return;
	}
	Person p[10];
	int i;
	for(i=0;i<10;i++){
		p[i].age = 10+i;
		strcpy(p[i].name, "Ramu");
	}
	fwrite(p, sizeof(Person), sizeof(p)/sizeof(p[0]), fp);
	fclose(fp);
}