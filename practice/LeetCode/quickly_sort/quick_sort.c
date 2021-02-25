#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int quick_sort(int *array, int size)
{
        int left = 0;
        int right = 0;
        int guard = 0;

        if(NULL == array || 0 == size)
        {
                return -1;
        }

        right = size - 1;
        guard = array[0];

        if(size > 1)
        {
                while(left < right)
                {
                        while(array[right] >= guard 
                                        && left < right)
                        {
                                right --;
                        }

                        array[left] = array[right];

                        while(array[left] <= guard 
                                        && left < right)
                        {
                                left ++;
                        }

                        array[right] = array[left];
                }

                array[left] = guard;

                quick_sort(array, left);
                quick_sort(array  + right + 1, size - right - 1);
        }

        return 0;
}

int main()
{
        int i = 0;
        int j = 0;
        int ret = 0;
        int array[10];


        srand(time(NULL));
        for (j = 0; j < 10000000; j ++)
        {
                memset(array, 0x00, sizeof(array));

                for(i = 0; i < sizeof(array) / sizeof(array[0]); i ++)
                {
                        //srand(time(NULL));
                        array[i] = rand() % 100;
                }

                ret = quick_sort(array, sizeof(array) / sizeof(array[0]));
                if(0 != ret)
                {
                        printf("Error, %d\n", ret);
                        return -1;
                }

                for(i = 0; i < sizeof(array) / sizeof(array[0]) - 1; i ++)
                {
                        if(array[i] > array[i + 1])
                        {
                                printf("FALSE\n");
                                printf("%d, ", array[i]);
                                
                                return -1;
                        }
                }

        }

        printf("True\n");

        return 0;
}
