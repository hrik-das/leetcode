#include <iostream>
#include <vector>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};
class Solution{
    public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* current = head;
        while(current != nullptr && current->next != nullptr){
            if(current->val == current->next->val){
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }else{
                current = current->next;
            }
        }
        return head;
    }
};
ListNode* createLinkedList(const std::vector<int>& values){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int val : values){
        ListNode* newNode = new ListNode(val);
        if(!head){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void printLinkedList(ListNode* head){
    while(head){
        std::cout<<head->val<<"->";
        head = head->next;
    }
    std::cout<<"NULL"<<std::endl;
}
int main(int argc, char* argv[]){
    Solution ob;
    std::vector<std::vector<int>> testCases = {{1, 1, 2}, {1, 1, 2, 3, 3}};
    for(const auto& testCase : testCases){
        ListNode* head = createLinkedList(testCase);
        std::cout<<"\nOriginal list: ";
        printLinkedList(head);
        ListNode* result = ob.deleteDuplicates(head);
        std::cout<<"After removing duplicates: ";
        printLinkedList(result);
    }
    return 0;
}