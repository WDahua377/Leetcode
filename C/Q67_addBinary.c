int max(int a, int b);
void swap(char *a, char *b);

char* addBinary(char* a, char* b) {
    char *ap = a + strlen(a) - 1, *bp = b + strlen(b) - 1;  // pointing to the end 指向尾端
    char *ans = malloc((max(strlen(a), strlen(b)) + 2) * sizeof(char)), *head = ans, *tail = ans;  // +2 is for carry and \0   +2為進位與\0
    int carry = 0, numa = *ap - '0', numb = *bp - '0';
    
    
    while (1) {
        *tail = (numa ^ numb ^ carry) + '0';
        if (tail < ans + max(strlen(a), strlen(b)))    tail++;
      // tail eventually point to the last bit of ans (the last carry bit)
      // tail最後會指向答案的最後一位（最後一個carry的位置）
        carry = (numa & numb) | (numb & carry) | (numa & carry);

        if (ap == a && bp == b) {  // a and b are at the last bit
            if (carry == 1) *tail = '1';  // if there's a last carry  如果最後有進位
            else tail--;  // else the number of digits -1  否則位數-1
            break;
        } else {
            if (ap > a) {
                ap--;
                numa = *ap - '0';
            } else {  // a is finished  a加完了
                numa = 0;
            }
            if (bp > b) {
                bp--;
                numb = *bp - '0';
            } else {  // b is finished  b加完了
                numb = 0;
            }
        }
    }
    *(tail + 1) = '\0';

    // the answer is inverse so we need to swap
    // 答案是相反的，所以需要前後交換
    while (head < tail) {
        swap(tail, head);
        tail--;
        head++;
    }

    return ans;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
