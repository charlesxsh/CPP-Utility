//
//  FileSystem.cpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/1/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#include "FileSystem.hpp"

namespace xsh
{
    namespace FileSystem
    {
        //Path Implementation
        Path::Path(const std::string& init)
        {
            if(!init.empty())
            {
                //check if it is root
#ifdef _WIN32
                if (init.find(":") != std::string::npos)
                {
                    path_type_ = PathType::Absolute;
                }
                else
                {
                    path_type_ = PathType::Relative;
                }
#else
                if(init[0] == '/')
                {
                    path_type_ = PathType::Absolute;
                }
                else
                {
                    path_type_ = PathType::Relative;
                }
#endif
                char separator = '\0';
                if (init.find("/") != std::string::npos)
                {
                    separator = '/';
                }
                else if(init.find("\\") != std::string::npos)
                {
                    separator = '\\';
                }
                
                if(separator != '\0')
                {
                    std::stringstream ss(init);
                    std::string item;
                    while (getline(ss, item, separator)) {
                        if(!item.empty()){
                            paths_.push_back(item);
                        }
                    }
                }
                else
                {
                    if (!init.empty()) {
                        paths_.push_back(init);
                    }
                }
            }
        }
        
        Path::Path(PathType path_type):path_type_(path_type){}
        
        std::string Path::str() const
        {
            std::ostringstream temp;
            char separator;
#ifdef _WIN32
            separator = '\\';
#else
            separator = '/';
#endif
            if(path_type_ == PathType::Absolute)
            {
                temp << separator;
            }
            
            auto i = paths_.begin();
            auto last = paths_.end()-1;
            for (; i < last; i++) {
                temp << *i << separator;
            }
            temp << *i;
            return temp.str();
        }
        
        
        Path& Path::join(const std::string& child)
        {
            paths_.push_back(child);
            return *this;
        }
        

        
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
        
        std::ostream& operator<<(std::ostream& stream, const Path& obj)
        {
            return stream << obj.str();
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