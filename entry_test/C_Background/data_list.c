/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2017, 瞿佳
 *    All rights reserved.
 *
 * @file data_list.c
 *
 *本文件主要一些操作链表的接口，包括创建，插入，删除，排序和遍历。
 *
 *	版本	作者		日期			修订说明
 *
 *   1.00     瞿佳		2017-7-27		最初版本
 *
 */

#include "data_list.h"
int data_compare(data , data ); 

/**将用户输入的数据保存至全局链表
 *
 *	该函数通过动态内存分配来申请一个节点用来保存用户输入的
 *        数据，并将新分配的节点通过头插法保存至全局链表；
 *
 * @param[in]    validData   全局链表；
 * @param[in]    inserted    用户输入的有效数据；
 * @param[out]  validData   全局链表
 * @return      无返回值；
 * 
 * 
 * 作者	日期		问题单号		修订说明		
 *
 * 瞿佳	2017-07-28   	未涉及		最初版本		
 *
 */
void insert_link(datalist_t *validData, data inserted)
{
        datalist_t *tmpdata = (datalist_t *)malloc(sizeof(datalist_t));
        if(NULL == tmpdata)
        {
                printf("memory is not enough!\n");
                exit(1);
        }

        tmpdata->next = NULL;
        memset(&tmpdata->figure, 0, sizeof(data));

        strcpy(tmpdata->figure, inserted);

        tmpdata->next = validData->next;
        validData->next = tmpdata;

        return;   
}

/**删除用户想要删除的数据
 *
 *     该函数通过遍历整个链表，将每个节点的数据域的数据与用户想删除的
 *     数据进行比对，若找到则删除，若有多个，则只删除一个，否则函数返回并提醒用户该数据不存在。
 *
 * @param[in]   validData   全局链表；
 * @param[in]   inserted    用户输入的想要删除的数据；
 * @param[out]  validData   全局链表
 * @return      无返回值；
 * 
 * 
 * 作者	日期		问题单号		修订说明		
 *
 * 瞿佳	2017-07-28   	未涉及		最初版本		
 *
 */
void delete_link(datalist_t *validData, data inserted)
{
        datalist_t *tmp = validData;
        datalist_t *delNode = NULL;
        int equal_flag = ~(-1);
        int exist_flag = 0;


        while(tmp->next != NULL)
        {
                equal_flag = strcmp(tmp->next->figure, inserted);

                if(0 == equal_flag)
                {
                        delNode = tmp->next;
                        tmp->next = delNode->next;
                        free(delNode);
                        delNode = NULL;
                        exist_flag = 1;
                        break;
                }
                tmp = tmp->next;
        }

        if( 0 == exist_flag )
        {
                printf("the data do not exist!\n");
        }

        return;
}





/**遍历整个链表
 *
 *该函数从前到后遍历整个链表并输出每个节点的数据；
 *
 * @param[in]   validData   全局链表；
 * @return        无返回值；
 * 
 * 
 * 作者	日期		问题单号		修订说明		
 *
 * 瞿佳	2017-07-28   	未涉及		最初版本		
 *
 */
void traversal_link(datalist_t *validData)
{
        int comma_flag = 0;
        datalist_t *tmp = validData->next;

        while(tmp != NULL)
        {
                if(0 == comma_flag)
                {
                        printf("%s", tmp->figure);
                        comma_flag ++;
                }
                else
                {
                        printf(", %s", tmp->figure);
                }
                tmp = tmp->next;
        }

        return;
}


/**创建链表
 *
 *该函数创建一个头结点，并将该头结点的首地址传出；
 *
 * @param[in]   validData   类型为DataList_t 的指针；
 * @return        返回链表头指针；
 * 
 * 
 * 作者	日期		问题单号		修订说明		
 *
 * 瞿佳	2017-07-28   	未涉及		最初版本		
 *
 */
datalist_t *create_link()
{
        datalist_t *validData = (datalist_t *)malloc(sizeof(datalist_t));
        if(NULL == validData)
        {
                printf("memory is not enough!\n");
                exit(1);
        }

        validData->next = NULL;
        memset(&validData->figure, 0, sizeof(data));

        return validData;
}

/**靠靠靠靠�
 * *
 * *靠靠靠靠靠靠靠靠靠靠
 * *靠靠靠靠靠靠�;
 * *
 * * @param[in]   p    靠靠靠�
 * * @param[in]   q    靠靠靠�
 * * @return      靠p縬靠靠靠-1靠p < q; 1靠p >= q�
 * * 
 * * 靠   靠        靠靠        靠靠        
 * *
 * * 靠   2017-07-28      靠�      靠靠        
 * */
int data_compare(data p, data q)
{
        int i = 0;
        int the_big = 0;
        int beforeDot_p = -1; /*靠靠靠靠靠�*/
        int beforeDot_q = -1;
        int afterDot_p = -1;
        int afterDot_q = -1;

        if(p[0] == '-' && q[0] != '-')  /*-1靠p<q,   1靠p>=q;*/
        {
                return LT;
        }

        if(p[0] != '-' && q[0] == '-') 
        {
                return GT;
        }

        if(p[0] == '-' && q[0] == '-')  /*靠靠靠*/
        {
                i = 0;
                while(p[i] != '\0')
                {
                        if(p[i] == '.') 
                        {
                                beforeDot_p = i - 1;
                                break;
                        }
                        i ++;
                }

                if(-1 == beforeDot_p)
                {
                        beforeDot_p = strlen(p) - 1;
                }

                i = 0;
                while(q[i] != '\0')
                {
                        if(q[i] == '.') 
                        {
                                beforeDot_q = i - 1;
                                break;
                        }

                        i ++;
                }

                if(-1 == beforeDot_q)
                {
                        beforeDot_q = strlen(q) - 1;
                }

                if((beforeDot_p == beforeDot_q) /*靠靠靠靠靠*/
                                && (-1 != beforeDot_p && -1 != beforeDot_q))
                {
                        the_big = strncmp(p + 1, q + 1, beforeDot_p);

                        if(the_big < 0)
                        {
                                return GT;
                        }
                        else if(0 == the_big)/*靠靠靠靠靠靠靠�*/
                        {
                                the_big = -2;

                                afterDot_p = strlen(p) - (beforeDot_p + 2);
                                afterDot_q = strlen(q) - (beforeDot_q + 2);

                                afterDot_p = afterDot_p > afterDot_q ? afterDot_p : afterDot_q;

                                the_big = strncmp(p + beforeDot_p + 2, q + beforeDot_q + 2, afterDot_p);
                                if(the_big < 0)
                                {
                                        return GT;
                                }
                                else
                                {
                                        return LT;
                                }
                        }
                        else
                        {
                                return LT;
                        }
                }
                else if(beforeDot_p < beforeDot_q)
                {
                        return GT;
                }
                else
                {
                        return LT;
                }
        }

        /*靠靠靠*/
        i = 0;
        while(p[i] != '\0')
        {
                if(p[i] == '.') 
                {
                        beforeDot_p = i - 1;
                        break;
                }
                i ++;
        }

        if(-1 == beforeDot_p)
        {
                beforeDot_p = strlen(p) - 1;
        }

        i = 0;
        while(q[i] != '\0')
        {
                if(q[i] == '.') 
                {
                        beforeDot_q = i - 1;
                        break;
                }
                i++;
        }

        if(-1 == beforeDot_q)
        {
                beforeDot_q = strlen(q) - 1;
        }

        if((beforeDot_p == beforeDot_q) 
                        && (-1 != beforeDot_p && -1 != beforeDot_q))
        {
                the_big = strncmp(p, q, beforeDot_p +1);

                i = 0;

                if(the_big < 0)
                {
                        return LT;
                }
                else if(0 == the_big)/*靠靠靠靠靠靠靠�*/
                {
                        the_big = -2;

                        afterDot_p = strlen(p) - (beforeDot_p + 2);
                        afterDot_q = strlen(q) - (beforeDot_q + 2);

                        afterDot_p = afterDot_p > afterDot_q ? afterDot_p : afterDot_q;

                        the_big = strncmp(p + beforeDot_p + 2, q + beforeDot_q + 2, afterDot_p);
                        if(the_big < 0)
                        {
                                return LT;
                        }
                        else
                        {
                                return GT;
                        }
                }
                else
                {
                        return GT;
                }

        }
        else if(beforeDot_p < beforeDot_q)
        {
                return LT;
        }
        else
        {
                return GT;
        }
        return 0;   
}


/**对链表中的数据排序
 *
 *该函数通过冒泡排序算法将整个链表的节点按从大到小的顺序进行排序；
 * @param[in]   validData   全局链表；
 * @param[out]  validData   全局链表
 * @return      无返回值；
 * 
 * 
 * 作者	日期		问题单号		修订说明		
 *
 * 瞿佳	2017-07-28   	未涉及		最初版本		
 *
 */
void sort_link(datalist_t *validData)
{
        char tmpbuf[MAXLEN] = {0};
        int size_relat = 0;
        datalist_t *p = NULL, *q = NULL;

        for(p = validData->next; p != NULL; p = p->next)    
        {
                for(q = p->next; q != NULL; q = q->next)
                {       
                        size_relat = data_compare(p->figure, q->figure);

                        if(LT == size_relat)
                        {
                                strcpy(tmpbuf, p->figure);
                                memset(p->figure, 0, MAXLEN);

                                strcpy(p->figure, q->figure);
                                memset(q->figure, 0, MAXLEN);

                                strcpy(q->figure, tmpbuf);
                                memset(tmpbuf, 0, MAXLEN);
                        }
                }

        }

        return;
}
