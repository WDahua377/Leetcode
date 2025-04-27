// by XOR-ing all input numbers, duplicates are eliminated (become 0), and the unique number remains
// 將所有輸入得數字進行xor比較，相同的數字會將彼此消除（結果為0），最後的結果就是只出現一次的那個數字

int singleNumber(int* nums, int numsSize) {
    for(int i = 1; i < numsSize; i++) {
        *nums = *nums ^ *(nums+i);
    }
    return *nums;
}
