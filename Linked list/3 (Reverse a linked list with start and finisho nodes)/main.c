#include <string.h>
#include <stdlib.h>


struct ListNode {
      int val;
      struct ListNode *next;
  };

 int find_the_number_of_node(struct ListNode* );
struct ListNode* reverse(struct ListNode * head,int ,int);




struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int number_node=find_the_number_of_node(head);
    if (number_node==0);
        return NULL;


}

int find_the_number_of_node(struct ListNode* head){
    if(head==NULL)
        return 0;

    struct ListNode* temp;
    temp=head;
    int count=0;
    while (temp!=NULL){
        count++;
        temp=temp->next;
    }

    return count;
}
struct ListNode* reverse(struct ListNode * head,int start ,int finish){
    struct ListNode* temp=head;
    struct ListNode* temp_second;
    int array[finish-start];

    for (int i=0 ;i<start;i++)
        temp=temp->next;

    temp_second=temp;

    for (int i=start,j=0;i<finish;i++,temp->next)
        array[j]=temp->val;

    int temp_number;
    for (int i=0 ; i< (finish-start)/2;i++){
        temp_number=array[i];
        array[i]=array[finish-start-i];
        array[finish-start-i]=temp_number;
    }

    int i=0;
    while(temp_second!=NULL){
        temp_second->val=array[i];
        i++;
        temp_second->next;
    }


    return head;
}