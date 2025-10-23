char* longestCommonPrefix(char** strs, int strsSize) {
    char *ans = (char*)malloc(1);
    ans[0] = '\0';
    int minlen = 200;

    // 找最短單字，避免 j++ 取址超過單字長度範圍
    for(int i = 0; i < strsSize; i++) {
        if(minlen > strlen(strs[i])) {
            minlen = strlen(strs[i]);
        }
    }

    if(minlen == 0) {
        return ans;
    }

    // every strings compare with the first one
    // 比較的是第 i 個單字的第 j 個字母
    for(int j = 0; j < minlen; j++) {
        for(int i = 1; i < strsSize; i++) {
            // 找到第一個不同的地方就處理字串 + 跳開（注意 j 位置是第一個不同處）
            if(*(strs[0]+j) != *(strs[i]+j)) {  // if(str[0][j] != str[i][j])
                ans = realloc(ans, j + 1);
                strncpy(ans, strs[0], j);
                ans[j] = '\0';
                return ans;
            }
        }
    }

    // leetcode 回傳規定要自己 malloc
    ans = realloc(ans, minlen + 1);
    strncpy(ans, strs[0], minlen);
    ans[minlen] = '\0';

    // 全部都檢查完了
    return ans;
}
