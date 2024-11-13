// This solution is based on Boyer-Moore Voting Algorithm
// Reference: https://ithelp.ithome.com.tw/articles/10213285

int majorityElement(int* nums, int numsSize) {

    // Boyer-Moore Voting Algorithm

    int res = *nums, cnt = 1, *i = nums + 1;
    
    while(i - nums != numsSize){
        if(*i == res)
            cnt++;
        else if(cnt > 0)
            cnt--;
        else
            res = *i;

        i++;
    }

    return res;
}
