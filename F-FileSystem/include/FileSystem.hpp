//
//  FileSystem.hpp
//  Cppdemo
//
//  Created by Shihao Xia on 7/29/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP
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

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>

#define PATH_MAX 1024

namespace xsh {
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
        
        class Path;
        
        
        class Path{
        public:
            Path(const std::string& init);
            Path(PathType path_type = PathType::Absolute);

            Path& join(const std::string& child);
            std::string str() const;
            PathType GetType() const{return path_type_;}
        private:
            PathType path_type_;
            std::vector<std::string> paths_;
        };
        
        //directory
        std::string GetCurrentDirectory();
        bool CreateDirectory(const std::string& path);
        
        //strintify functions
        template<class T>
        std::string ToString(T&& obj)
        {
            std::ostringstream str_stream;
            str_stream << obj;
            return str_stream.str();
        }
        
        std::ostream& operator<<(std::ostream& stream, const PathType& type);
        std::ostream& operator<<(std::ostream& stream, const Path& type);

    }
}

#endif
