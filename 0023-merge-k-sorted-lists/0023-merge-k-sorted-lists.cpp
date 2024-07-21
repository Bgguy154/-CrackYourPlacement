class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& arr) {
    int K = arr.size();
    // Your code here
    if (K == 1) return arr[0];

    ListNode* ans = new ListNode(0);
    ListNode* temp = ans;

    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

    for (int i = 0; i < K; i++) {
if (arr[i] != nullptr) {
  pq.push({arr[i]->val, arr[i]});
}    }

    while (!pq.empty()) {
      auto top = pq.top();
      pq.pop();
      temp->next = top.second;
      temp = temp->next;

      // Removed the if condition
      if (temp->next != NULL) {
        pq.push({temp->next->val, temp->next});
      }
    }

    return ans->next;
  }
};
