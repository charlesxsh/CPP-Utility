//
//  Path.hpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef Path_hpp
#define Path_hpp

#include "FileSystemBasic.hpp"
#include <vector>

namespace xsh {
    namespace FileSystem
    {
        class Path
        {
        public:
            Path(const std::string&& init);
            Path(const char *init);
            Path(const Path&);
            Path(PathType path_type);
            Path& join(const std::string& child);
            std::string str() const;
            PathType GetType() const{return path_type_;}
        private:
            PathType path_type_;
            std::vector<std::string> paths_;
            void parsePathString(const std::string& init);
        };
        
        std::ostream& operator<<(std::ostream& stream, const Path& type);

    }
}
#endif /* Path_hpp */
