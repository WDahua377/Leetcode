/* This solution is based on hamming weight Algorithm
Reference: https://blog.csdn.net/shaohui973/article/details/109627989
*/
/* 該解法基於漢明算法
參考網址：https://blog.csdn.net/shaohui973/article/details/109627989
*/
// basiclly adding up each bit of the number
// 基本上就是把所有位元相加

int hammingWeight(int n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);  // 0101
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);  // 0011
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);  // 0000 1111
    n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);  // 0000 0000 1111 1111
    n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
    return n;
}
