//
//  Path.cpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#include "Path.hpp"

namespace xsh
{
    namespace FileSystem
    {
        //Path Implementation
        Path::Path(const std::string&& init)
        {
            parsePathString(init);
        }
        
        Path::Path(const char *init)
        {
            parsePathString(init);
        }
        
        void Path::parsePathString(const std::string& init)
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
        
        Path::Path(const Path& path)
        {
            path_type_ = path.path_type_;
            paths_ = path.paths_;
        }
        
      
        
        Path& Path::join(const std::string& child)
        {
            paths_.push_back(child);
            return *this;
        }
        
        std::ostream& operator<<(std::ostream& stream, const Path& obj)
        {
            return stream << obj.str();
        }
        

    }
}