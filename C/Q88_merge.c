int compare(const void *a, const void *b);

// 將 nums2 移到 nums1 後面，然後使用 qsort 排列
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *j = nums1 + m, *i = nums2;

    // j == n + m 時已經超過數列範圍了
    while(j - nums1 != n + m) {
        *j = *i;
        j++;
        i++;
    }
    qsort( (void*)nums1, n + m, sizeof(int), compare );
}

// qsort 所需要的 compare 函數
int compare(const void *a, const void *b) {
    int c = *(int*)a;
    int d = *(int*)b;
    
    if(c < d)
        return -1;
    else if(c == d)
        return 0;
    else
        return 1;
}

// nums1 = [1, 2, 3, 0, 0, 0]
// j                          ^ nums1 + n + m

// nums2 = [2, 5, 6]
// i        ^ 
