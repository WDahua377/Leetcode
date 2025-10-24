bool wordPattern(char* pattern, char* s) {
    char **map = (char**)calloc(26, sizeof(char*));    // map pattern(26 characters) to stings, using calloc for initialize
    char *token = strtok(s, " "); // get the first token
    int len = strlen(pattern);
    
    for(int i = 0; i < len; i++) {
        char c = pattern[i];   // next pattern
        if(token == NULL)   goto free;   // s.length > pattern.length

        if(map[c - 'a'] == NULL) {  // 先塞進 map 後面再檢查，錯了就回傳 flase
            map[c - 'a'] = (char*)malloc(strlen(token) + 1);
            memcpy(map[c - 'a'], token, strlen(token) + 1);
        } else if(strcmp(map[c - 'a'], token) != 0) { // 檢查字母 -> 多字串（index 值相同但字串不同）
            goto free;
        }

        // 檢查單字串 -> 多字母（字串相同但 index 值不同）
        for(int j = 0; j < 26; j++) {
            if(map[j] != NULL) {
                if(strcmp(map[j], token) == 0 && j != c - 'a')  goto free;
            }
        }
        // strtok會從上一個位置開始，所以第一個參數為 NULL
        token = strtok(NULL, " ");  // next token
    }

    if(token != NULL)   goto free;   //pattern.length > s.length
    return true;

free:
    for(int i = 0; i < 26; i++) {
        free(map[i]);
    }
    free(map);
    return false;
}
