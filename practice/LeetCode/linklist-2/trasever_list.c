#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
        int val;
        struct ListNode *next;
};

#if 0
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

        struct ListNode *tmp = NULL;

        while(NULL != l1->next)
        {
                tmp = l1->next;
                l1->next = tmp->next;                          
        }

}
#endif

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

        struct ListNode *NewHead = malloc(sizeof(struct ListNode));
        struct ListNode *tmp = NULL;
        struct ListNode *tmp1 = NULL;
        int result = 0;
        int carry_bit = 0;

        NewHead->next = NULL;
        NewHead->val = 0;

        while(NULL != l1 && NULL != l2)
        {
                result = l1->val + l2->val + carry_bit;
                if(result >= 10)
                {
                        carry_bit = 1;
                }
                else
                {
                        carry_bit = 0;
                }

                result = result % 10;
                tmp = malloc(sizeof(struct ListNode));
                tmp->next = NULL;
                tmp->val = result;

                tmp->next = NewHead->next;
                NewHead->next = tmp;

                l1 = l1->next;
                l2 = l2->next;
        }

        if(NULL == l1 && NULL == l2 && carry_bit)
        {
                tmp = malloc(sizeof(struct ListNode));
                tmp->next = NULL;
                tmp->val = 1;

                tmp->next = NewHead->next;
                NewHead->next = tmp;
            
        }

        if(NULL != l1)
        {
                while(NULL != l1)
                {
                        result = l1->val + carry_bit;
                        if(result >= 10)
                        {
                                carry_bit = 1;
                        }
                        else
                        {
                                carry_bit = 0;
                        }

                        result = result % 10;
                        tmp = malloc(sizeof(struct ListNode));
                        tmp->next = NULL;
                        tmp->val = result;

                        tmp->next = NewHead->next;
                        NewHead->next = tmp;
                        l1 = l1->next;  
                }
                if(carry_bit)
                {
                        tmp = malloc(sizeof(struct ListNode));
                        tmp->next = NULL;
                        tmp->val = 1;

                        tmp->next = NewHead->next;
                        NewHead->next = tmp;
                }
        }


        if(NULL != l2)
        {
                while(NULL != l2)
                {
                        result = l2->val + carry_bit;
                        if(result >= 10)
                        {
                                carry_bit = 1;
                        }
                        else
                        {
                                carry_bit = 0;
                        }

                        result = result % 10;
                        tmp = malloc(sizeof(struct ListNode));
                        tmp->next = NULL;
                        tmp->val = result;

                        tmp->next = NewHead->next;
                        NewHead->next = tmp;
                        l2 = l2->next;  
                }
                if(carry_bit)
                {
                        tmp = malloc(sizeof(struct ListNode));
                        tmp->next = NULL;
                        tmp->val = 1;

                        tmp->next = NewHead->next;
                        NewHead->next = tmp;
                }
        }

        tmp = NewHead->next;
        NewHead->next = NULL;
        
        while(NULL != tmp)
        {
                tmp1 = tmp;
                tmp = tmp->next;
                tmp1->next = NewHead->next;
                NewHead->next = tmp1;
        }

        return NewHead->next;

}

int main(int argc, char *argv[])
{
    struct ListNode *head = NULL;
    struct ListNode *head1 = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *tmp1 = NULL;
    int i = 0;
    
    head = malloc(sizeof(struct ListNode));
    head->val = 5;
    head->next = NULL;
#if 1
    for(i = 0; i < 4; i ++)
    {
        tmp  = malloc(sizeof(struct ListNode));
        tmp->val = 5;
        tmp->next = head->next;
        head->next = tmp;
    }

#endif

    head1 = malloc(sizeof(struct ListNode));
    head1->val = 5;
    head1->next = NULL;
#if 1
    for(i = 0; i < 4; i ++)
    {
        tmp  = malloc(sizeof(struct ListNode));
        tmp->val = 5;
        tmp->next = head1->next;
        head1->next = tmp;
    }
#endif
    tmp = addTwoNumbers(head, head1);

#if 1
    while(NULL != tmp)
    {
       printf("%d\n", tmp->val);
       tmp = tmp->next;
    }
#else 
    tmp = head->next;
    head->next = NULL;
    while(NULL != tmp)
    {   
        tmp1 = tmp;
        tmp = tmp->next;
        tmp1->next = head->next;
        head->next = tmp1;
    }

    tmp = head;
    printf("head is %d\n", tmp->val);
    head = head->next;
    tmp->next = NULL;
    tmp1 = head;
    while(NULL != tmp1->next)
    {
       tmp1=tmp1->next;
    }

    printf("last is %d\n", tmp1->val);
    tmp1->next = tmp;
    printf("%p\n", tmp1);

    while(NULL != head)
    {
        printf("%d  %p\n", head->val, head);
        head = head->next;
    }
#endif
    return 0;
}
