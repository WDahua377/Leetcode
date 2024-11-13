int SymboltoValue(char c);

int romanToInt(char* s) {
    int sum = 0, cnt = 0;
    int length = strlen(s);
    char *a = s + length - 1, *b = a;

    // Since 'if' checks *(b-1), 'b' can not >= s
    // 因為 if 會檢查*(b-1)，所以不能 >= s 
    while(b > s) {

        cnt = 0;
        a = b;

        // Checks cases like IV, XC... where a smaller numeral precedes a larger one
        // 檢查 IV、XC... 等後減前的情況
        if(SymboltoValue(*b) > SymboltoValue( *(b-1) )) {
            sum = sum + SymboltoValue(*b) - SymboltoValue( *(b-1) );
            if(b >= s + 2) {
                b -= 2;
                continue;
            }
            else    
                // If already at the first two characters, return directly to avoid out-of-bounds access
                // 已經是最前面兩位，直接 return(再減會超過範圍到 -1)
                return sum;
        }

        // Checks for repeated Roman numerals and single (cnt == 1) occurrences
        // 檢查重複以及單個存在(cnt == 1)的羅馬數字
        while(*b == *a) {
            cnt++;
            if(b > s)
                b--;
            else
                // If 'b' is already at the first character, break to avoid out-of-bounds access
                // b 已經在 s 的首位，再減會超過範圍到 -1
                break;
        }
        sum = sum + cnt * SymboltoValue(*a);
    }

    // If the first character is a single (non-repeated) Roman numeral, it needs to be added to the sum since the while loop exits when b == s
    // 當首字母若為單個(不重複)羅馬數字時，由於前面 while 在 b == s 時就會跳出，無法被其中的 while(*b == *a) 檢查出來加入 sum，因此要額外加
    if( *(s+1) != *s) {
        sum = sum + SymboltoValue(*b);
    }

    return sum;
}

int SymboltoValue(char c) {
    int value = 0;
    switch (c) {
            case 'I':
                value = 1;
                break;
            case 'V':
                value = 5;
                break;
            case 'X':
                value = 10;
                break;
            case 'L':
                value = 50;
                break;
            case 'C':
                value = 100;
                break;
            case 'D':
                value = 500;
                break;
            case 'M':
                value = 1000;
                break;
            default:
                break;
        }
    return value;
}
