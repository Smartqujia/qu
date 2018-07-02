/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2010, MacroSAN
 *    All rights reserved.
 *
 * @file 	input_handle.h
 *
 * 本文件主要定义对用户的输入进行操作的公用接口，包含下面几个部分的内容:
 * 			1. 对用户输入进行检测及操作的相关接口；
 * 			2. 描述语法检测结果的宏常量；
 *	
 *	版本	作者		日期			修订说明
 *   1.00     qu		2017-07-28		最初版本
 */
#ifndef _INPUT_HANDLE_H
#define _INPUT_HANDLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>
#include "pub.h"

#define   TEST_PASSED                   0  /**<语法检测的结果*/

extern int data_compare(data , data );
extern int syntax_check(data , int *, int *);
extern int regex_syntax_check(data );
extern void valid_data_copy(data , int , int );

#endif

