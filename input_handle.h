/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2010, MacroSAN
 *    All rights reserved.
 *
 * @file 	input_handle.h
 *
 * ���ļ���Ҫ������û���������в����Ĺ��ýӿڣ��������漸�����ֵ�����:
 * 			1. ���û�������м�⼰��������ؽӿڣ�
 * 			2. �����﷨������ĺ곣����
 *	
 *	�汾	����		����			�޶�˵��
 *
 *   1.00     �ļ�		2017-07-28		����汾
 */
#ifndef _INPUT_HANDLE_H
#define _INPUT_HANDLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>
#include "pub.h"

#define   TEST_PASSED                   0  /**<�﷨���Ľ��*/

extern int data_compare(data , data );
extern int syntax_check(data , int *, int *);
extern int regex_syntax_check(data );
extern void valid_data_copy(data , int , int );

#endif

