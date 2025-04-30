// 'one' tracks bits seen once, 'two' tracks bits seen twice, on the third occurrence, bits are cleared from both
// one 紀錄每個位元的 1 出現過 1 次，two 紀錄每個位元的 1 出現過 2 次，而到達第3次則歸零

// in the end, 'one' contains the bits that appeared only once — the unique number
// 最後看哪些位元的1只出現過1次

int singleNumber(int* nums, int numsSize) {
    int one = 0, two = 0;
    for(int i = 0; i < numsSize; i++) {
        one = (one ^ *(nums+i)) & ~two;
        two = (two ^ *(nums+i)) & ~one;
    }
    return one;
}
