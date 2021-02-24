#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
        char a[127] = "0";
        int unrepeat_bit = 0;
        int last_bitsum = 0; 

        memset(a, 0x00, sizeof(a));

        while('\0' != *s)
        {
                if(0 == a[*s])
                {
                        a[*s] = 1;
                        unrepeat_bit ++;
                }
                else
                {
                        memset(a, 0x00, sizeof(a));
                        if(unrepeat_bit > last_bitsum)
                        {
                            last_bitsum = unrepeat_bit;
                        }
                        unrepeat_bit = 1;
                }
                s++;
        }

        return last_bitsum;

}

int main()
{
    char a[1024];
    printf("%d\n", lengthOfLongestSubstring(gets(a)));  

    return 0;
}
