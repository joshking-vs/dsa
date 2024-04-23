#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next)
        return false;
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while (fast && fast->next) {
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}

int main() {

    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; 

    std::cout << (hasCycle(head) ? "Cycle detected" : "No cycle detected") << std::endl;

    delete head->next->next->next->next; 
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
    
    return 0;
}
