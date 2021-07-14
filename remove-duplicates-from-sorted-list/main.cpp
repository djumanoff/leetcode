/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* ans = head;
        while (head->next != nullptr) {
            ListNode* curr = head;
            while (curr->next != nullptr && curr->val == curr->next->val) {
                curr = curr->next;
            }
            if (curr != head) {
                head->next = curr->next;
                curr->next = nullptr;
            }
            head = head->next;
        }
        return ans;
    }
};

int main() {
    return 0;
}
