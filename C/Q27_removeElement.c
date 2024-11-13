void swap(int* a, int* b);

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    int *front = nums, *tail = nums + numsSize - 1;

    // 檢查是否是空數組
    if(numsSize == 0)
        return 0;

    // 不知道要放什麼先放個範圍判斷，雖然好像用不到
    while(front >= nums && front < nums + numsSize &&
           tail >= nums && tail < nums + numsSize) {

        // 找到前面的第一個 `val`
        while(front <= tail && *front != val) {
            front++;
            k++;
        }

        // 找到後面的第一個非 `val`
        while(front <= tail && *tail == val) {
            tail--;
        }

        // 檢查 front 和 tail 的相對位置，如果 front > tail 表示兩個檢查的之標重疊 or 越過對方，已經交換完了
        if(front > tail)
            break;
        else
            swap(front, tail);
    }

    return k;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
