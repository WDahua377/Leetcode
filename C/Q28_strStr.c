int strStr(char* haystack, char* needle) {
    char *i = haystack, *j = needle;
    char *k = haystack;
    // k is the new starting point for comparisons in haystack
    // k 是 haystack 中比較的新起點

    while(1) {
        if(*i == *j) {
            i++;
            j++;
        }
        // Comparison failed, new round
        // 比較失敗，新的一輪
        else {
            k++;
            j = needle;
            i = k;
        }

        // needle has reached the end (successful comparison)
        // needle 到結尾了（比較成功）
        if(*j == '\0')
            return i - haystack - (j - needle);

        // haystacks has reached the end (failed comparison)
        // haystacks 到結尾了（比較失敗）
        if(*i == '\0')
            break;
    }
    return -1;

}
