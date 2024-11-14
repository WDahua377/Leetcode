bool isPalindrome(char* s) {
    if(strlen(s) == 0)
        return true;

    char *i = s, *j = s + strlen(s);
    // i checks from front to back, j checks from back to front
    // i 從前往後檢查，j 從後往前檢查

    while(i <= j) {

        // ignore characters other than numbers and letters
        // 忽略數字和字母以外的字元
        while( (*j < '0' || *j > '9' && *j < 'A' || *j > 'Z' && *j < 'a' || *j > 'z') && i < j) {
            j--;
        }
        while( (*i < '0' || *i > '9' && *i < 'A' || *i > 'Z' && *i < 'a' || *i > 'z') && i < j) {
            i++;
        }

        // switch uppercase to lowercase
        // 將大寫切換為小寫
        if(*j >= 'A' && *j <= 'Z') 
            *j = *j + 32;
        if(*i >= 'A' && *i <= 'Z') 
            *i = *i + 32;

        if(*i != *j)
            return false;
        else if(i >= j) 
            return true;
        else {  // *i == *j && i < j
            i++;
            j--;
        }
    }
    return true;
}
