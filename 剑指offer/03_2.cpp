// 不修改数组找出任意一个重复元素， 剑指offer p41

#include<iostream>
using namespace std;

int count_range(const int* numbers, int length, int left, int right){
    int cnt = 0;
    for (int i = 0; i < length; ++i){
        if (numbers[i] >= left && numbers[i] <= right)
            cnt++;
    }
    return cnt;
}

int get_duplication(const int* numbers, int length){
    if (numbers == nullptr || length == 0)
        return -1;
    int left = 1, right = length-1;
    while(left <= right){
        int middle = (left + right) / 2;
        int count = count_range(numbers, length, left, middle);
        if (count > middle-left+1){
            if(left == middle)
                return left;
            else
                right = middle;
        }
        else
            left = middle + 1;
    }
    return -1;
}



int main(){
    const int numbers[] = {2,3,5,4,3,2,6,7};
    int length = 8;
    int res = get_duplication(numbers, length);
    cout<<res<<endl;
    return 0;
}
