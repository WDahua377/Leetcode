/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *a = nums, *b = nums + 1;
    int *answer = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    while(*a + *b != target) {
        if(b - nums == numsSize - 1) {
            a++;
            b = a + 1;
        } else {
            b++;
        }
    }
    answer[0] = a - nums;
    answer[1] = b - nums;
    return answer;
}
