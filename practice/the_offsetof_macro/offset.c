#include <stdio.h>
#include <string.h>

#define offsetof(typ, memb)     ((unsigned long)((char *)&(((typ *)NULL)->memb)))

typedef struct{
    int wieght;
    short age;
    char name[10];
}student;

int main()
{
    student qujia;
    student *p = NULL;
    qujia.age = 24;
    qujia.wieght = 110;
    strcpy(qujia.name, "qujia");
    
    printf("offset is %d\n", offsetof(student, name));
    //printf("my_offset is %d\n", p->name);
		
	return 0;
}
