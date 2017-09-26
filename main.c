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
#include "data_list.h"
#include "input_handle.h"


datalist_t *g_link = NULL;    /**< �����û����ݵ������ͷָ��*/

int main(int argc, char *argv[])
{
    int check_result = 0;
    int start_bit = 0;
    int stop_bit = 0;
    data input_str = {0};
    
    g_link = create_link();

    while(1)
    {
        memset(input_str, 0, sizeof(input_str));  
        /*printf("please enter you command:\n\
                insert:a+data\n\
                remove:d+data\n\
                print:p \n");*/
        printf("ODSP CLI>");

        fgets(input_str, MAXLEN, stdin);
        input_str[strlen(input_str) - 1] = '\0';
        
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
