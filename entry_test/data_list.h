/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2010, MacroSAN
 *    All rights reserved.
 *
 * @file 	data_list.h
 *
 * ���ļ���Ҫ����Ա����û����ݵ��������ز����ӿڣ��������漸�����ֵ�����:
 * 			1. ���û������Լ���ȫ��������в�������ؽӿڣ�
 * 			2. ���������û���������ݽṹ��
 *	
 *	�汾	����		����			�޶�˵��
 *
 *   1.00     �ļ�		2017-07-28		����汾
 */
#ifndef _DATA_LIST_H
#define _DATA_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pub.h"
                                                     
/**���������û�������Ľṹ��;
*/
typedef struct node{
    struct node *next;        /**<��һ���ڵ�ĵ�ַ*/
    data figure;              /**< �������Ч����*/
}datalist_t;

extern void insert_link(datalist_t *, data );
extern void delete_link(datalist_t *, data );
extern void traversal_link(datalist_t * );
extern datalist_t *create_link();

extern datalist_t *g_link;

#endif

