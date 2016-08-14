//
//  Folder.cpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#include "Folder.hpp"
#include "Path.hpp"

namespace xsh
{
    namespace FileSystem
    {
        Folder::Folder(const std::string& name):FileElement(name, FileType::Folder)
        {
            
        }
        
        void Folder::add(const PFileElement e)
        {
            childs_.push_back(e);
        }
        
        void Folder::CreateInPath(xsh::FileSystem::Path path)
        {
            path.join(name_);
            CreateDirectory(path.str());
            for (auto f:childs_) {
                f->CreateInPath(path);
            }
        }
        
        FileType Folder::getType()
        {
            return FileType::Folder;
        }

        
    }
}
