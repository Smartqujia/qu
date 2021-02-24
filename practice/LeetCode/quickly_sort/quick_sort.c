#include <stdio.h>

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
    int ret = 0;
    int array[10] = {1, 20, 33, 2, 4, 3, 10, 1, 5, 5};
    
    ret = quick_sort(array, sizeof(array) / sizeof(array[0]));
    if(0 != ret)
    {
        printf("Error, %d\n", ret);
        return -1;
    }

    for(i = 0; i < 10; i ++)
    {
        printf("%d, ", array[i]);
    }

    putchar('\n');

    return 0;
}
