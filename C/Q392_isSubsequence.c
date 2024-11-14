bool isSubsequence(char* s, char* t) {
    if(strlen(s) == 0)
        return true;
    else if(strlen(t) == 0) // s != 0 && t == 0
        return false;
    else{   // s != 0 && t != 0
        char *i = s, *j = t;
        while(1) {
            if(*i == *j){
                i++;
                j++;
            }
            else
                j++;

            // we should check first if s reaches the end in case s = t = "aaa"
            // 我們要先檢查 s 是否達到句尾，避免比如 s = t = "aaa" 的情況
            if(*i == '\0')
                return true;
            if(*j == '\0')
                return false;
        }
        return true;
    }
}

// s = "abc"
// i    ^

// t = "ahbgdc"
// j    ^
