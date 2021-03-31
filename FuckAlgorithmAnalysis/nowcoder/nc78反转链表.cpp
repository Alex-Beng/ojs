struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

/*
pre cur nex 
1. 将cur指向pre
2. 将pre设为自己
*/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = nullptr;
        ListNode* hea = pHead;
        ListNode* nex = nullptr;

        while (hea) {
            nex = hea->next;
            hea->next = pre;
            pre = hea;
            hea = nex;
        }
        return pre;
    }
};