/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {   
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while (!lists.empty())
        {
            int minNum = INT_MAX;
            int minIndex = -1;
            for (int i = 0; i < lists.size(); ++i)
            {
                if (lists[i] == nullptr)
                {
                    lists.erase(lists.begin() + i);
                    --i;
                }
                else if (minNum > lists[i]->val)
                {
                    minNum = lists[i]->val;
                    minIndex = i;
                }
            }   

            if (minIndex == -1)
                break;
                
            if (head == nullptr)
                 head = lists[minIndex];
            else if (head->next == nullptr)
                head->next = lists[minIndex];
            
            if (prev != nullptr)
                prev->next = lists[minIndex];
           
            prev = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            if (lists[minIndex] == nullptr)
                    lists.erase(lists.begin() + minIndex);
        }
        return head;
    }
};