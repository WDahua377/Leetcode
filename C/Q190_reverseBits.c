// `(n >> (31 - i) & 1)` gets whether the (31-i)th bit is 1 or 0, and `<< i` multiplies 1/0 by the power of 2 of that bit
// then adds all the results
// 從`(n >> (31 - i) & 1)`得到第31-i位是1還是0，接著將得到的結果乘以該位的2的冪，將所有結果相加

uint32_t reverseBits(uint32_t n) {
    unsigned int ans = 0;
    ans += (n >> 31) & 1;
    ans += ((n >> 30) & 1) << 1;
    ans += ((n >> 29) & 1) << 2;
    ans += ((n >> 28) & 1) << 3;
    ans += ((n >> 27) & 1) << 4;
    ans += ((n >> 26) & 1) << 5;
    ans += ((n >> 25) & 1) << 6;
    ans += ((n >> 24) & 1) << 7;
    ans += ((n >> 23) & 1) << 8;
    ans += ((n >> 22) & 1) << 9;
    ans += ((n >> 21) & 1) << 10;
    ans += ((n >> 20) & 1) << 11;
    ans += ((n >> 19) & 1) << 12;
    ans += ((n >> 18) & 1) << 13;
    ans += ((n >> 17) & 1) << 14;
    ans += ((n >> 16) & 1) << 15;
    ans += ((n >> 15) & 1) << 16;
    ans += ((n >> 14) & 1) << 17;
    ans += ((n >> 13) & 1) << 18;
    ans += ((n >> 12) & 1) << 19;
    ans += ((n >> 11) & 1) << 20;
    ans += ((n >> 10) & 1) << 21;
    ans += ((n >> 9) & 1) << 22;
    ans += ((n >> 8) & 1) << 23;
    ans += ((n >> 7) & 1) << 24;
    ans += ((n >> 6) & 1) << 25;
    ans += ((n >> 5) & 1) << 26;
    ans += ((n >> 4) & 1) << 27;
    ans += ((n >> 3) & 1) << 28;
    ans += ((n >> 2) & 1) << 29;
    ans += ((n >> 1) & 1) << 30;
    ans += (n & 1) << 31;
    return ans;
}

// the same code using a for loop
// 一樣的方法但是用for loop
// uint32_t reverseBits(uint32_t n) {
//     unsigned int ans = 0;
//     for(int i = 0; i < 32; i++) {
//         ans += (n >> (31 - i) & 1 ) << i;
//     }
//     return ans;
// }
