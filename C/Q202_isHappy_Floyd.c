// Floyd's Cycle Detection Algorithm：在循環中，fast 每次走兩步，而 slow 每次走一步，fast 最終會等於 slow
int nextSum(int n) {
    int sum = 0;
    while(n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    while(fast != 1) {
        slow = nextSum(slow);
        fast = nextSum(nextSum(fast));
        if(fast == slow && fast != 1)    return false;  // 要考慮到同時為 1 會誤判
    }
    return true;
}
