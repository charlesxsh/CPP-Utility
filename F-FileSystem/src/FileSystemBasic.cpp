//
//  FileSystemBasic.cpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#include "FileSystemBasic.hpp"

namespace xsh
{
    namespace FileSystem
    {
        //strintify functions
        std::ostream& operator<<(std::ostream& stream, const PathType type)
        {
            switch (type) {
                case PathType::Absolute :
                    stream << "Absolute";
                    break;
                case PathType::Relative:
                    stream << "Relative";
                    break;
                default:
                    break;
            }
            return stream;
        }
        
        
        
        //Directroy Implementation
        std::string GetCurrentDirectory()
        {
            char buffer[PATH_MAX];
            char *answer = getcwd(buffer, sizeof(buffer));
            std::string s_cwd;
            if (answer)
            {
                s_cwd = answer;
            }
            return std::move(s_cwd);
        }
        
        bool CreateDirectory(const std::string& path)
        {
            int status = 0;
            
            status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            
            if(status != 0){
                return false;
            }
            return true;
        }

    }
}