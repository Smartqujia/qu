/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2017, �ļ�
 *    All rights reserved.
 *
 * @file data_list.c
 *
 *���ļ���ҪһЩ��������Ľӿڣ��������������룬ɾ��������ͱ�����
 *
 *	�汾	����		����			�޶�˵��
 *
 *   1.00     �ļ�		2017-7-27		����汾
 *
 */

#include "data_list.h"
int data_compare(data , data ); 

/**���û���������ݱ�����ȫ������
 *
 *	�ú���ͨ����̬�ڴ����������һ���ڵ����������û������
 *        ���ݣ������·���Ľڵ�ͨ��ͷ�巨������ȫ������
 *
 * @param[in]    validData   ȫ������
 * @param[in]    inserted    �û��������Ч���ݣ�
 * @param[out]  validData   ȫ������
 * @return      �޷���ֵ��
 * 
 * 
 * ����	����		���ⵥ��		�޶�˵��		
 *
 * �ļ�	2017-07-28   	δ�漰		����汾		
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

/**ɾ���û���Ҫɾ��������
 *
 *     �ú���ͨ����������������ÿ���ڵ����������������û���ɾ����
 *     ���ݽ��бȶԣ����ҵ���ɾ�������ж������ֻɾ��һ�������������ز������û������ݲ����ڡ�
 *
 * @param[in]   validData   ȫ������
 * @param[in]   inserted    �û��������Ҫɾ�������ݣ�
 * @param[out]  validData   ȫ������
 * @return      �޷���ֵ��
 * 
 * 
 * ����	����		���ⵥ��		�޶�˵��		
 *
 * �ļ�	2017-07-28   	δ�漰		����汾		
 *
 */
void delete_link(datalist_t *validData, data inserted)
{
        datalist_t *tmp = validData;
        datalist_t *delNode = NULL;
        int equal_flag = 0;

        while(tmp->next != NULL)
        {
                equal_flag = strcmp(tmp->next->figure, inserted);

                if(0 == equal_flag)
                {
                        delNode = tmp->next;
                        tmp->next = delNode->next;
                        free(delNode);
                        delNode = NULL;
                        break;
                }
                tmp = tmp->next;
        }

        if(0 != equal_flag)
        {
                printf("the data do not exist!\n");
        }

        return;
}





/**������������
 *
 *�ú�����ǰ������������������ÿ���ڵ�����ݣ�
 *
 * @param[in]   validData   ȫ������
 * @return        �޷���ֵ��
 * 
 * 
 * ����	����		���ⵥ��		�޶�˵��		
 *
 * �ļ�	2017-07-28   	δ�漰		����汾		
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


/**��������
 *
 *�ú�������һ��ͷ��㣬������ͷ�����׵�ַ������
 *
 * @param[in]   validData   ����ΪDataList_t ��ָ�룻
 * @return        ��������ͷָ�룻
 * 
 * 
 * ����	����		���ⵥ��		�޶�˵��		
 *
 * �ļ�	2017-07-28   	δ�漰		����汾		
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

/**���������
 * *
 * *��������������������
 * *�������������;
 * *
 * * @param[in]   p    �������
 * * @param[in]   q    �������
 * * @return      ��p�q������-1��p < q; 1��p >= q�
 * * 
 * * ��   ��        ����        ����        
 * *
 * * ��   2017-07-28      ���      ����        
 * */
int data_compare(data p, data q)
{
        int i = 0;
        int the_big = 0;
        int beforeDot_p = -1; /*�����������*/
        int beforeDot_q = -1;
        int afterDot_p = -1;
        int afterDot_q = -1;

        if(p[0] == '-' && q[0] != '-')  /*-1��p<q,   1��p>=q;*/
        {
                return LT;
        }

        if(p[0] != '-' && q[0] == '-') 
        {
                return GT;
        }

        if(p[0] == '-' && q[0] == '-')  /*������*/
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

                if((beforeDot_p == beforeDot_q) /*����������*/
                                && (-1 != beforeDot_p && -1 != beforeDot_q))
                {
                        the_big = strncmp(p + 1, q + 1, beforeDot_p);

                        if(the_big < 0)
                        {
                                return GT;
                        }
                        else if(0 == the_big)/*���������������*/
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

        /*������*/
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
                else if(0 == the_big)/*���������������*/
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


/**�������е���������
 *
 *�ú���ͨ��ð�������㷨����������Ľڵ㰴�Ӵ�С��˳���������
 * @param[in]   validData   ȫ������
 * @param[out]  validData   ȫ������
 * @return      �޷���ֵ��
 * 
 * 
 * ����	����		���ⵥ��		�޶�˵��		
 *
 * �ļ�	2017-07-28   	δ�漰		����汾		
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
