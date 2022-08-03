/**
 * Definition for singly-linked list.
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode* l) {
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* iter = new ListNode(0, head);
        ListNode* left = nullptr;
        ListNode* right = nullptr;
        
        while (iter->next != nullptr) {
            while (iter->next != nullptr && iter->next->val < x) {
                iter = iter->next;
                if (left == nullptr) head = iter;
                left = iter;
            }
            if (right == nullptr) right = iter->next;
            while (iter->next != nullptr && iter->next->val >= x) {
                iter = iter->next;
            }

            if (iter->next == nullptr) break;
            ListNode* t = iter->next;
            ListNode* leftNext = iter->next;
            while (t != nullptr && t->val < x) {
                leftNext = t;
                t = t->next;
            }

            if (left == nullptr) {
                left = iter->next;
                head = left;
                leftNext->next = right;
                left = leftNext;
            } else {
                left->next = iter->next;
                leftNext->next = right;
                left = leftNext;
            }
            iter->next = t;
        }
        
        return head;
    }
};

int main() {
    Solution s;
    ListNode* l = new ListNode(1, 
    new ListNode(4, 
    new ListNode(3, 
    new ListNode(0, 
    new ListNode(2, 
    new ListNode(5, 
    new ListNode(2)))))));
    print_list(s.partition(l, 3));

    // ListNode* l2 = new ListNode(2, new ListNode(1,nullptr));
    // print_list(s.partition(l2, 2));

    return 0;
}
