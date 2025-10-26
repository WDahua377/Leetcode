/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // 若兩方或其中一方為空，不用特別處理，按情況回傳
    if(!list1 && !list2) {
        return NULL;
    } else if(!list1) {
        return list2;
    } else if(!list2) {
        return list1;
    }

    // 決定結合 list 的頭
    struct ListNode *temp = list1;  // temp 負責組裝
    if(list1->val <= list2->val) {
        temp = list1;
        list1 = list1->next;
    } else {
        temp = list2;
        list2 = list2->next;
    }
    struct ListNode *ans = temp;    // 紀錄頭的位置，最後要回傳它

    // 逐一比較 list1 和 list2 每個點的大小再接上 ans list
    while(list1 && list2) {
        if(list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // 一方接完了就直接接完剩下的全部
     temp->next = (list1 ? list1 : list2);

    // if(!list1->next && !list2->next) {
    //     temp->next = NULL;
    // } else if(!list1->next) {
    //     temp->next = list2;
    // } else if(!list2->next) {
    //     temp->next = list1;
    // }

    return ans;
}
