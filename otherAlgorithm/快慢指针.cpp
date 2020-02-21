//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置
//（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *low = head;
        ListNode *fast = head;
        ListNode *meet = NULL;
        while(fast)
        {
                fast = fast->next;
                low = low->next;
                if(!fast)
                return NULL;
                fast = fast->next;
                if(low == fast)
                {
                    meet = fast;
                    break;
                }
        }
        if(meet == NULL)
        return NULL;
        while(head && meet)   //head和meet到达一定相同的步数会在环的起始点相遇
        {
            if(head == meet)
            {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};
