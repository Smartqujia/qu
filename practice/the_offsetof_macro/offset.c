#include <stdio.h>
#include <string.h>

#define offsetof(typ, memb)     ((unsigned long)((char *)&(((typ *)0)->memb)))

typedef struct{
    int wieght;
    short age;
    char name[10];
}student;

int main()
{
    student qujia;
    qujia.age = 24;
    qujia.wieght = 110;
    strcpy(qujia.name, "qujia");
    
    printf("offset is %d\n", offsetof(student, name));
		
	return 0;
}
