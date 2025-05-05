// This solution was originally provided by user 'mentez' on LeetCode's solution section.
// 該解法為該題中解答欄位的 mentez 用戶所提供的解答。

/* For AND, as long as a bit has a 0, that bit will eventually be 0, so any bit that changes in this range will become 0.
The bits that would change are the lower order bits.
This loop repeatedly removes the lowest set bit from `right` until `right` is less than or equal to `left`.

For example,
left     = 1101001100110000
right    = 1101010000000000
right -1 = 1101001111111111
here we apply 'right = right & (right -1)',
right    = 1101000000000000
*/

/* 對於 AND 運算，只要其中一個位元有 0，那麼 AND 的結果就會是 0，也就是任何在 left 到 right 範圍內會改變的 bit，
而這些 bit 都在較低的位置中，
這個迴圈不斷消除會改變的、較低的位元，直到 right <= left。

舉例來說，
left     = 1101001100110000
right    = 1101010000000000
right -1 = 1101001111111111
接著我們執行 'right = right & (right -1)'，
right    = 1101000000000000
*/

int rangeBitwiseAnd(int left, int right) {
    while(right > left) {
        right = right & (right-1);
    }
    return right;
}
