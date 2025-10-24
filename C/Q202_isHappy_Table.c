bool isHappy(int n) {
    int sum = n;
    bool checked[811] = {false};

    while(sum != 1) {
        n = sum;    // new round
        sum = 0;

        // calculate sum
        while(n != 0) {
            sum += (n % 10) * (n% 10);
            n /= 10;
        }

        // 檢查 sum 是否已出現過，有則為無限迴圈
        if(checked[sum] == true)    return false;    // loops endlessly

        checked[sum] = true;
    }

    return true;
}
