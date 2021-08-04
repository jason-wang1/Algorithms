#include <stddef.h>
#include <vector>
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
    ListNode(vector<int> &list) {
        val = list[0];
        next = NULL;
        if (list.size() > 1){
            ListNode *pNode = new ListNode(list[1]);
            next = pNode;
            for (int i = 2; i < list.size(); ++i) {
                ListNode *lastNode = new ListNode(list[i]);
                pNode->next = lastNode;
                pNode = lastNode;
            }
        }
    }

    void print() {
        cout << val << endl;
        ListNode *pNode = next;
        while (pNode){
            cout << pNode->val << endl;
            pNode = pNode->next;
        }
    }
};
