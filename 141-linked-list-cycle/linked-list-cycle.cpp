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
    bool hasCycle(ListNode *head) {
       ListNode* temp = head;

        // Create a map to keep track of visited nodes
        set<ListNode*> nodeMap;

        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap.insert(temp);

            // Move to the next node
            temp = temp->next;
        }

        // If traversal completes, no loop detected
        return false;
    }
};