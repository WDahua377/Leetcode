void swap(int *a, int *b);

int removeDuplicates(int* nums, int numsSize) {
    int *i = nums, *j = nums;

    // if nums is empty
    if (numsSize == 0)
        return 0;
    
    while (j - nums != numsSize) {

        // look for the next non-duplicate number
        if (*i == *j) {
            j++;
        }

        // swap the next non-duplicate number to the next element
        else {
            i++;
            swap(i, j);
            j++;
        }
    }

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

