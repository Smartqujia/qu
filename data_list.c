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
