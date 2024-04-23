#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
        return nullptr;
    
    ListNode *slow = head;
    ListNode *fast = head;
    
    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
            break; // Cycle detected
    }
    
    // No cycle
    if (slow != fast)
        return nullptr;
    
    // Reset one pointer to head and move both at same speed until they meet again
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow; // Return the node where the cycle begins
}

int main() {
    // Example usage
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Cycle: -4 -> 2

    ListNode *cycleStart = detectCycle(head);
    if (cycleStart)
        std::cout << "Cycle begins at node with value: " << cycleStart->val << std::endl;
    else
        std::cout << "No cycle detected" << std::endl;

    // Don't forget to free the memory
    delete head->next->next->next->next; // Delete the last node created to avoid memory leak
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
