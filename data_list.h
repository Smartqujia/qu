/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2010, MacroSAN
 *    All rights reserved.
 *
 * @file 	data_list.h
 *
 * 本文件主要定义对保存用户数据的链表的相关操作接口，包含下面几个部分的内容:
 * 			1. 对用户输入以及对全局链表进行操作的相关接口；
 * 			2. 用来保存用户输入的数据结构；
 *	
 *	版本	作者		日期			修订说明
 *
 *   1.00     瞿佳		2017-07-28		最初版本
 */
#ifndef _DATA_LIST_H
#define _DATA_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pub.h"
                                                     
/**描述保存用户的输入的结构体;
*/
typedef struct node{
    struct node *next;        /**<下一个节点的地址*/
    data figure;              /**< 输入的有效数据*/
}datalist_t;

extern void insert_link(datalist_t *, data );
extern void delete_link(datalist_t *, data );
extern void traversal_link(datalist_t * );
extern datalist_t *create_link();

extern datalist_t *g_link;

#endif

