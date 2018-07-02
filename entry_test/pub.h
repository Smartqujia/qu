/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2010, MacroSAN
 *    All rights reserved.
 *
 * @file 	pub.h
 *
 * 本文件主要定义一些公用的数据类型，包含下面几个部分的内容:
 * 			1. 对用户输入进行保存的数据的数据类型；
 * 			2. 描述语法检测结果的宏常量；
 *	
 *	版本	作者		日期			修订说明
 *
 *   1.00     qu		2017-07-28		最初版本
 */
#ifndef _PUB_H
#define _PUB_H

#define   LT                      -1    /**<第一个参数小于第二个参数*/      
#define   GT                       1    /**<第一个参数大于或等于第二个参数*/
#define   MAXLEN                   1000 /**<保存用户命令的缓冲区的大小*/

/**< 用户输入的数据的类型*/ 
typedef char data[MAXLEN]; 

#endif

