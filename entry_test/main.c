/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2017, qu
 *    All rights reserved.
 *
 * @file main.c
 *
 * 本文件主要是创建了一个链表，然后开始用户输入及调用命令有效性检测模
 * 块，最终将处理结果进行一系列后续操作；
 *
 *	版本	作者		日期			修订说明
 *
 *   1.00     qu		2017-7-27		最初版本
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "data_list.h"
#include "input_handle.h"

typedef void (*sighandler_t)(int );

void SIG_INT(int num){};

datalist_t *g_link = NULL;    /**< 保存用户数据的链表的头指针*/

int main(int argc, char *argv[])
{
    int flag = 0, i = 0;
    int check_result = 0;
    int start_bit = 0;
    int stop_bit = 0;
    data input_str = {0};
    
    g_link = create_link();

    signal(SIGINT, SIG_INT);

    while(1)
    {
        flag = 0;
        i = 0;
        memset(input_str, 0, sizeof(input_str));  
 /*
 *printf("please enter you command:\n\
 *              insert:a+data\n\
 *              remove:d+data\n\
 *              print:p \n");
 */
        printf("ODSP CLI>");

        fgets(input_str, MAXLEN, stdin);
        input_str[strlen(input_str) - 1] = '\0';
        
        if(0 == strlen(input_str))
            continue;
        while('\0' != input_str[i])
        {
            if(' ' == input_str[i])
            {
                flag = 1;
                i++;
                continue;
            }
            else
            {
                flag = 0;
                i++;
                break;
            }
        }
        
        if(1 == flag) continue;
        
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
