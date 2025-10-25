bool isAnagram(char* s, char* t) {

    // 長度不一樣一定不對
    if(strlen(s) != strlen(t))  return false;

    // 用一個表 sTable 紀錄，當字母出現在 s 中則 +1，出現在 t 中則 -1
    int sTable[26] = {0};
    for(int i = 0; s[i] != '\0'; i++) {
        sTable[s[i] - 'a']++;
        sTable[t[i] - 'a']--;
    }
    
    // 兩種情況表示構成 s 和 t 的字母組成不同
    // 1. t 出現不存在於 sTable 中的字母    2. sTable 中還有剩
    // -> 都會讓 sTable != 0
    for(int i = 0; i < 26; i++) {
        if(sTable[i] != 0)  return false;
    }

    return true;
}
