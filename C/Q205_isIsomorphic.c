bool isIsomorphic(char* s, char* t) {
    char maps2t[128] = {0}, mapt2s[128] = {0};  // 128 including any valid ascii character 128 包含所有 ascii 字元
    while(*s) {  // t.length == s.length
        int num = (int)*s;
        if(maps2t[num] == 0) {
            maps2t[num] = *t;
        } else if(maps2t[num] != *t) {
            return false;
        }

        num = (int)*t;  // map twice to prevent many-to-one 避免多對一，所以要映射兩次
        if(mapt2s[num] == 0) {
            mapt2s[num] = *s;
        } else if(mapt2s[num] != *s) {
            return false;
        }
        s++; t++;
    }
    return true;
}
