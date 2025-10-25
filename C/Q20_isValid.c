bool isValid(char* s) {
    // 建立一個 int stack[] 當 stack
    // 3 種左括號都放入 stack
    // 遇到右括號時看 stack 的第一個元素是否為對應左括號，是則取出左括號，否則 return false
    char *stack = (char*)malloc(strlen(s)*sizeof(char));

    // 將第一個元素放入 stack
    int count = 0;
    stack[count++] = s[0];

    // 接著看第二個元素
    char cur = s[1];
    int i = 2;
    while(cur != '\0') {
        if(count > 5002)    return false;   // 不可能合法
        switch(cur) {
            case '(':
                stack[count++] = '(';
                break;
            case ')':   // stack 為空又遇到右括胡不合法
                if(count == 0 || stack[count - 1] != '(') return false;
                else    count--;
                break;
            case '[':
                stack[count++] = '[';
                break;
            case ']':
                if(count == 0 || stack[count - 1] != '[') return false;
                else    count--;
                break;
            case '{':
                stack[count++] = '{';
                break;
            case '}':
                if(count == 0 || stack[count - 1] != '{') return false;
                else    count--;
                break;
        }
        cur = s[i++];
    }
    // s 結束了，但stack裡還有東西
    if(count != 0)  return false;
    else    return true;
}
