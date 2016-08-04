//
//  FileElement.cpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#include "FileElement.hpp"

namespace xsh {
    
    namespace FileSystem
    {
        
        FileElement::FileElement(const std::string& name, FileType type)
        {
            name_ = std::move(name);
            type_ = type;
        }
        
        FileElement::FileElement(const char *name, FileType type)
        {
            name_ = name;
            type_ = type;
        }
    }
}
