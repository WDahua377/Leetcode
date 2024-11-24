bool canConstruct(char* ransomNote, char* magazine) {
    char *i = magazine;
    int Letter[26] = {0};

    // Count the number of letters in magazine
    // 計算 magazine 中的字母數量
    while(*i != '\0') {
        *(*i - 'a' + Letter) += 1;
        i++;
    }

    i = ransomNote;

    // Subtract letters from ransomNote
    // 減去 ransomNote 中的字母
    while(*i != '\0') {
        *(*i - 'a' + Letter) -= 1;
        i++;
    }

    // Check if any letters are reduced to negative
    // 檢查是否有數字被減到負數
    for(int j = 0; j < 26; j++) {
        if(Letter[j] < 0)
            return false;
    }
    return true;
}
