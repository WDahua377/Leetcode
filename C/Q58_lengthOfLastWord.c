int lengthOfLastWord(char* s) {
    int length = strlen(s);
    char *c = s + length - 1;
    int cnt = 0;

    // remove spaces at the end
    // 移除句尾的空格
    while(*c == ' ') {
        if(c > s)
            c--;
        
        // c == s which means s only have spaces
        // 由後往前移除空格後就沒了，表示 s 沒有單字，直接回傳 0
        else 
            return 0;
    }

    // check forward until the first space is encountered
    // 持續往前檢查直到遇見第一個空格
    while(*c != ' ') {
        cnt++;
        
        if(c > s)
            c--;
        else    // c == s
            return cnt;
    }

    return cnt;
}
