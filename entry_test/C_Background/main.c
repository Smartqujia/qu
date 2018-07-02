/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2017, �ļ�
 *    All rights reserved.
 *
 * @file main.c
 *
 * ���ļ���Ҫ�Ǵ�����һ������Ȼ��ʼ�û����뼰����������Ч�Լ��ģ
 * �飬���ս�����������һϵ�к���������
 *
 *	�汾	����		����			�޶�˵��
 *
 *   1.00     �ļ�		2017-7-27		����汾
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "data_list.h"
#include "input_handle.h"

//typedef void (*sighandler_t)(int);

void handle(int signum)
{
    printf("\n");
    printf("(null)@(null)Qujia Cli# ");
    fflush(stdout);
    return;
}

void handle1(int signum)
{
    printf("hello world\n");
    return;
}


datalist_t *g_link = NULL;    /**< �����û����ݵ������ͷָ��*/

int main(int argc, char *argv[])
{
    int check_result = 0;
    int start_bit = 0;
    int stop_bit = 0;
    int blank_flag = 0;
    data input_str = {0};
    int idx = 0;

    signal(SIGINT, handle);
    signal(SIGKILL, handle1);
    
#ifdef QUJIA
printf("hello world\n");
sleep(10);
#endif

    g_link = create_link();

    while(1)
    {
        blank_flag = 0;
        memset(input_str, 0, sizeof(input_str));  
        printf("(null)@(null)Qujia Cli# ");

        fgets(input_str, MAXLEN, stdin);
        input_str[strlen(input_str) - 1] = '\0';

        idx = 0;
        while ('\0' != input_str[idx])
        {
            if (32 != input_str[idx] && 9 != input_str[idx])
            {
                blank_flag = 1;
                break;
            }
            idx ++;
        }

        if (0 == blank_flag)
        {
            continue;
        }
        if (0 == strcmp(input_str, "quit"))
        {
            exit(0);
        }
        check_result = syntax_check(input_str, &start_bit, &stop_bit);

        if(TEST_PASSED == check_result)
        {
            switch(input_str[0])
            {
                case 'a':
                    valid_data_copy(input_str, start_bit, stop_bit);
                    insert_link(g_link, input_str);
                    break;

                case 'd':
                    valid_data_copy(input_str, start_bit, stop_bit);
                    delete_link(g_link, input_str);
                    break;

                case 'p':
                    sort_link(g_link);
                    traversal_link(g_link);
                    putchar('\n');
                    break;

                default:
                    break;
            }
        }
    }
    return 0;
}
