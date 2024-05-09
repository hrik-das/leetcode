#include <iostream>
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};
class Solution{
public:
    void deleteNode(ListNode* node){
        if(node == nullptr || node->next == nullptr){
            return;
        }
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }
};
void printList(ListNode* head){
    ListNode* current = head;
    while(current != nullptr){
        std::cout<<current->val<<"->";
        current = current->next;
    }
    std::cout<<"nullptr"<<std::endl;
}
int main(int argc, char* argv[]){
    Solution ob;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    std::cout<<"Original List: ";
    printList(head);
    ListNode* nodeToDelete = head->next->next;
    ob.deleteNode(nodeToDelete);
    std::cout<<"List after deleting node: ";
    printList(head);
    while(head != nullptr){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}