//
//  CPPModuleManager.hpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef CPPModuleManager_hpp
#define CPPModuleManager_hpp

#include <string>
#include "FileSystem.hpp"

namespace xsh {
    
    class CPPModuleManager
    {
    public:
        CPPModuleManager();
        
        void CreateNewModule(const std::string& module_name, FileSystem::Path& path);
        
        std::string SyncRunScript(const std::string& script);
    };
}

#endif /* CPPModuleManager_hpp */
