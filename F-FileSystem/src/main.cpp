//
//  main.cpp
//  Cppdemo
//
//  Created by Shihao Xia on 2/17/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//  

#include "FileSystem.hpp"

using namespace xsh::FileSystem;

#include "CPPModuleManager.hpp"

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};
int main(int argc, const char* argv[])
{
//    Path path = "adf";
//    auto file = File::Create("test.txt");
//    auto folder = Folder::Create("folder");
//    folder->add(file);
    
    Path p = "/Users/Shihao/Desktop";
//
    xsh::CPPModuleManager manager;
    manager.CreateNewModule("testModule", p);
    //ReadDirectory("/Users/Shihao/");
    return 0;
}
