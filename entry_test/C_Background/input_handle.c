/**
 *    COPYRIGHT NOTICE
 *    Copyright (c) 2017, �ļ�
 *    All rights reserved.
 *
 * @file input_handle.c
 *
 * ���ļ���Ҫ�Ƕ��û�����ĺϷ��Խ��м�飬�����Ϸ�������пո��Լ�����ǰ��
 * ������޳�,�������ݴ�С�Ƚ�ģ�飻
 *
 *	�汾	����		����			�޶�˵��
 *
 *   1.00     �ļ�		2017-7-27		����汾
 *
 */

#include "input_handle.h"

/**���û��������������﷨��⣬�����Ϸ������wipeoff_zero_and_space()������
 *
 *	�ú�����ʾ�û��������룬��ͨ�������û�����������ַ��������Ϸ���������ݱ�������
 *     �����Ϸ������ݲ����沢��ʾ�û�������Ч��
 * 
 *@return     �����﷨���Ľ����
 * 
 * ����	����		���ⵥ��		�޶�˵��		
 *
 * �ļ�	2017-07-28   	δ�漰		����汾		
 *
 **/
int regex_syntax_check(data input_str)
{   
    int i = 0;
    regex_t reg;
    int status = 0;
    int num_flag = 0;
    int error_flag = 0;
    const int nmatch = 1;
    regmatch_t pmatch[1];
    int cflags = REG_EXTENDED;
    char *pattern = "^([ad] *(([+]{0,1})|([-]{0,1}))[0-9]+([.]{0,1}[0-9]+){0,1}[ ]*$)|([p] *$)";

    if(strlen(input_str) > 300)
    {
        error_flag = 1;
        printf("invalid command!\n");
    }
    regcomp(&reg, pattern, cflags);

    status = regexec(&reg, input_str, nmatch, pmatch, 0);

    if(status == REG_NOMATCH)
    {
        error_flag = 1;
        printf("invalid command!\n");        
    }

    i = 0;
    while('\0' != input_str[i])
    {
        if((input_str[i] >= '0' && input_str[i] <= '9') || '.' == input_str[i])
        {
            num_flag ++;
            if(num_flag > 100)
            {
                printf("the operand is too big!\n");
                error_flag = 1;
            }
        }
        i ++;
    }
    
    regfree(&reg);

    return error_flag;
}

/**���û��������������﷨��⣬�����Ϸ������wipeoff_zero_and_space()������
 *
 *	�ú�����ʾ�û��������룬��ͨ�������û�����������ַ��������Ϸ���������ݱ�������
 *     �����Ϸ������ݲ����沢��ʾ�û�������Ч��
 * 
 *@return     �����﷨���Ľ����
 * 
 * ����	����		���ⵥ��		�޶�˵��		
 *
 * �ļ�	2017-07-28   	δ�漰		����汾		
 *
 **/
int syntax_check(data input_str, int *start_bit, int *stop_bit)
{
    int i = 0;
    int sign_flag = 0;
    int space_flag = 0;
    int error_flag = 0;
    int p_flag = 0;
    int dot_flag = 0;
    int ad_flag = 0;
    int all_space = 0;
    int tmp_start_bit = 0;
    int tmp_stop_bit = 0;
    int flag = 0;
    int allZero = 0;
    int scal_pos = MAXLEN;
    char tmpbuf[MAXLEN] = {0};
    
    if((input_str[i] != 'p') 
        && (strlen(input_str) < 2))
    {
        printf("invalid command!\n");
        error_flag = 1;
        return error_flag;
    }

    if((strlen(input_str) > 300) 
        || (input_str[0] != 'a' 
        && input_str[0] != 'd' 
        && input_str[0] != 'p'))
    {
        printf("invilid command!\n");
        error_flag = 1;
        return error_flag;
    }

    i = 0;
    while(input_str[++i] != '\0')
    {
        if(!(input_str[i] == ' ' 
            || input_str[i] == '+' 
            || input_str[i] == '-' 
            || input_str[i] == '.' 
            || (input_str[i] >= '0' 
            && input_str[i] <= '9')))
        {
            printf("invilid command!\n");
            error_flag = 1;
            break;
        }

        if((1 == dot_flag) 
            && ('.' == input_str[i]))
        {
            printf("invilid command!\n");
            error_flag = 1;
            break;
        }

        if('.' == input_str[i])
        {
            dot_flag = 1;
        }
            
        if((input_str[i] == '.') 
            && (input_str[i - 1] < '0' 
            || input_str[i - 1] > '9'))
        {
            printf("invilid command!\n");
            error_flag = 1;
            break;
        }

        if((input_str[i] == '+') 
            || (input_str[i] == '-'))
        {

            if((input_str[i + 1] < '0' 
                || input_str[i + 1] > '9')
                || (' ' != input_str[i - 1] 
                && 'a' != input_str[i - 1] 
                && 'd' != input_str[i - 1]))
            {
                printf("invilid command!\n");
                error_flag = 1;
                break;
            }
            sign_flag ++;
        }

        if (sign_flag > 1)
        {
            printf("invalid command!\n");
            error_flag = 1;
            break;
        }

        if((input_str[i] >= '0' 
            && input_str[i] <= '9') 
            && (0 == space_flag))
        {
            space_flag = 1;
        }

        if((1 == space_flag) 
            && (' ' == input_str[i]))
        {
            space_flag = 2;
        }

        if((' ' != input_str[i]) 
            && (2 == space_flag))
        {
            printf("invalid command!\n");
            error_flag = 1;
            break;
        }

        if(('.' == input_str[i]) 
            && ((input_str[i - 1] < '0' 
            || input_str[i - 1] > '9') 
            || (input_str[i + 1] < '0' 
            || input_str[i + 1] > '9')))
        {
            printf("invalid command!\n");
            error_flag = 1;
            break;
        }

        if('p' == input_str[i - 1])
        {
            p_flag = 1;
        }
        
        if((1 == p_flag) 
            && (' ' != input_str[i]))
        {
            printf("invalid command!\n");
            error_flag = 1;
            break;
        }

        if(('a' == input_str[i - 1])
            || ('d' == input_str[i - 1]))
        {
            ad_flag = 1;
        }

        if((1 == ad_flag)
            && (' ' != input_str[i]))
        {
            all_space = 1;
        }

    }

    if(0 == error_flag)
    {
        i = 0;
        while('\0' != input_str[i++])
        {
            if('+' == input_str[i])
            {    
                input_str[i] = ' ';
                break;
            }
        }

        i = 1;
        while('\0' != input_str[i])
        {
            if((' ' != input_str[i]) 
                && ('0' != input_str[i]) 
                && ('-' != input_str[i]) 
                && ('.' != input_str[i]))
            {
                allZero = 1;
            }
            i ++;
        }

        if(0 == allZero)
        {
            *start_bit = *stop_bit = -1;
        }
        else
        {
            i = 1;
            while('\0' != input_str[i])
            {
                if((input_str[i] > '0')
                    && (input_str[i] <= '9'))
                {
                    break;      
                }
                i ++;
            }

            tmp_start_bit = i;

            i = 1;
            while('\0' != input_str[i])
            {
                if('.' == input_str[i])
                {
                    flag = 1;
                    scal_pos = i;
                    break;      
                }
                i ++;
            }

            if(tmp_start_bit > scal_pos)
            {
                tmp_start_bit = scal_pos - 1;
            }

            if(1 == flag)
            {
                i = 1;
                while('\0' != input_str[i])
                {
                    if((input_str[i] > '0')
                        && (input_str[i] <= '9'))
                    {
                        tmp_stop_bit = i;
                    }
                    i ++;
                }

                if(tmp_stop_bit < scal_pos)
                {
                    tmp_stop_bit = scal_pos - 1;
                }
            }
            else
            {
                i = 1;
                while('\0' != input_str[i])
                {
                    if((input_str[i] >= '0')
                        && (input_str[i] <= '9'))
                    {
                        tmp_stop_bit = i;
                    }
                    i ++;
                }
            }
        }

        if(tmp_stop_bit - tmp_start_bit + 1 > 100)
        {
            printf("the operand is too big!\n");
            error_flag = 1;
            return error_flag;
        }
        else
        {   
            if(0 != allZero)
            {
                *start_bit = tmp_start_bit;
                *stop_bit = tmp_stop_bit;
            }
        }
    }

    if((0 == all_space)
        && ('p' != input_str[0]))
	{
	    if(1 != error_flag)
		{
		    printf("invalid command!\n");
		    error_flag = 1;
            return error_flag;
        }
	}
    
    return error_flag;
}

/**ȥ����Ч�����еĿո�����ǰ��Ӱ��ԭ���ݴ�С��0��
*  
*�ú���ͨ������������Ч���ݣ�����Ч������λ�����޳���
* @param[in]   input_str  �û�����ĺϷ����ݣ�
* @return      �޷���ֵ��
* 
* 
* ����	����		���ⵥ��		�޶�˵��		
*
* �ļ�	2017-07-28   	δ�漰		����汾		
*
*/
void valid_data_copy(char *input_str, int start_bit, int stop_bit)
{
    int i = 0, j = 0;
    char tmpbuf[MAXLEN] = {0};

    if(-1 != start_bit)
    {
        i = 1;
        while('\0' != input_str[i])
        {
            if('-' == input_str[i])
            {
                tmpbuf[j++] = '-';
            }    
            i ++;
        } 
        for(i = start_bit; i <= stop_bit; i ++, j ++)
        {
            tmpbuf[j] = input_str[i];
        }
        
        memset(input_str, 0, MAXLEN);
        strcpy(input_str, tmpbuf);
    }
    else
    {
        memset(input_str, 0, MAXLEN);
        strcpy(input_str, "0");
    }
    return;
}

#if 0
/**�û����ݴ�С�ıȽ�
*
*�ú���ͨ�����û��������Ч���ݽ�����λ��
*�ϣ��Ӷ��ж��������ݵĴ�С;
*
* @param[in]   p    �����е����ݣ�
* @param[in]   q    �����е����ݣ�
* @return      ����p��q�Ĵ�С��ϵ��-1��ʾp < q; 1��ʾp >= q��
* 
* ����	����		���ⵥ��		�޶�˵��		
*
* �ļ�	2017-07-28   	δ�漰		����汾		
*/
int data_compare(data p, data q)
{
    int i = 0;
    int the_big = 0;
   	int beforeDot_p = -1; /*С����֮ǰ�����ֵ�λ��*/
   	int beforeDot_q = -1;
   	int afterDot_p = -1;
  	int afterDot_q = -1;

    if(p[0] == '-' && q[0] != '-')  /*-1��ʾp<q,   1��ʾp>=q;*/
    {
        return LT;
  	}

    if(p[0] != '-' && q[0] == '-') 
    {
        return GT;
   	}

    if(p[0] == '-' && q[0] == '-')  /*������Ϊ����*/
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

        if((beforeDot_p == beforeDot_q) /*С����ǰ���λ�����*/
            && (-1 != beforeDot_p && -1 != beforeDot_q))
        {
      	    the_big = strncmp(p + 1, q + 1, beforeDot_p);

            if(the_big < 0)
            {
           	    return GT;
            }
       	    else if(0 == the_big)/*С����ǰ���λ����ͬ�Ҵ�С���*/
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

    /*������Ϊ����*/
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
        else if(0 == the_big)/*С����ǰ���λ����ͬ�Ҵ�С���*/
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
#endif
