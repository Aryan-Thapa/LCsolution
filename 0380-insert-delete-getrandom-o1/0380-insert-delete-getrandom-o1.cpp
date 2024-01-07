class RandomizedSet {
public:
vector<int>v;
unordered_map<int,int>mp;
int ind=0;
    RandomizedSet() {
        ind=0;
        mp.clear();
        v.clear();
    }
    
    bool insert(int val) 
    {
        if(mp.find(val)!=mp.end())return false;
        mp[val]=ind;
        v.push_back(val);
        ind++;
        return true;
    }
    
    bool remove(int val) 
    {
        if(mp.find(val)==mp.end())return false;
        int i=mp[val];
        swap(v[i],v[ind-1]);
        mp[v[i]]=i;
        v.pop_back();
        ind--;
        mp.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        int i=rand()%ind;
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */