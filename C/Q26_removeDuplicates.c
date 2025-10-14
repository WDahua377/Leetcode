void swap(int *a, int *b);

int removeDuplicates(int* nums, int numsSize) {
    int *i = nums, *j = nums;

    // if nums is empty
    // 若輸入為空數列
    if (numsSize == 0)
        return 0;
    
    while (j - nums != numsSize) {

        // look for the next non-duplicate number
        // 尋找下一個非重複的數字
        if (*i == *j) {
            j++;
        }

        // swap the next non-duplicate number to the next element
        // 將下一個非重複的數字與下一個元素交換
        else {
            i++;
            swap(i, j);
            j++;
        }
    }

    // return the number of unique elements in nums
    // 回傳非重複數列的長度
    return i - nums + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// nums = [0,0,1,1,1,2,2,3,3,4]
// i       ^
// j       ^

// nums = [ ]

