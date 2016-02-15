class countSort{
public:
    static vector<int> toSort(vector<int>& nums){
        if(nums.size() <= 1) return nums;
        int myMax = nums[0];
        int myMin = nums[0];
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] > myMax) myMax = nums[i];
            if(nums[i] < myMin) myMin = nums[i];
        }
        int myRange = myMax - myMin + 1;
        vector<int> buckets (myRange, 0);
        for(int i = 0; i < nums.size() ; i ++){
            buckets[nums[i] - myMin] ++;
        }
        vector<int> out;
        for(int i = 0; i < buckets.size(); i ++){
            for(int j = 0; j < buckets[i]; j ++){
                out.push_back(myMin + i);
            }
        }
        return out;
    }
};

int main(){
    int tmp [] = {3,2,3,1,6,3,4,1,3,2,8,10,13,0,2,1,3,1,6,5,9,6,13,24,12,13,21,16,8};
    vector<int> case1 (tmp, tmp + sizeof(tmp)/sizeof(int));
    for(auto &i : case1) cout << i << " " ;
    cout << endl;
    case1 = countSort::toSort(case1);
    for(auto &i : case1) cout << i << " " ;
    cout << endl;
    return 0;
}
