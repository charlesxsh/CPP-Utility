//
//  FileSystemBasic.hpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef FileSystemBasic_hpp
#define FileSystemBasic_hpp

#include <string>
#include <iostream>
#include <sstream>

/**
 * header for windows platform
 */
#ifdef _WIN32
#endif

#ifdef __APPLE__
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

namespace xsh
{
    namespace FileSystem
    {
        enum class FileType
        {
            File,
            Folder,
            Unknown
        };
        
        enum class PathType
        {
            Relative,
            Absolute
        };
        
        //strintify functions
        template<class T>
        std::string ToString(T&& obj)
        {
            std::ostringstream str_stream;
            str_stream << obj;
            return str_stream.str();
        }

        //directory
        std::string GetCurrentDirectory();
        bool CreateDirectory(const std::string& path);
        
        std::ostream& operator<<(std::ostream& stream, const PathType& type);

    }
}

#endif /* FileSystemBasic_hpp */
