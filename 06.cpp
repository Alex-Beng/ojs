#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        int cnt=0;
        ListNode* t_ptr = head;
        while (t_ptr != NULL) {
            cnt++;
            t_ptr = t_ptr->next;
        }
        ans.resize(cnt);
        t_ptr = head;
        for (int i=cnt-1; i>=0; i--) {
            ans[i] = t_ptr->val;
            t_ptr = t_ptr->next;
        }
        return ans;
    }
};