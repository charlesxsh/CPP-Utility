//
//  File.cpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#include "File.hpp"
#include "Path.hpp"
#include <fstream>

namespace xsh
{
    namespace FileSystem
    {
        File::File(const char *name):FileElement(name, FileType::File)
        {
            
        }
        
        void File::CreateInPath(xsh::FileSystem::Path path)
        {
            path.join(name_);
            std::ofstream file(path.str());
            file << buffer_.rdbuf() << std::endl;
        }
        
        
        
        FileType File::getType()
        {
            return FileType::File;
        }
        
        

    }
}