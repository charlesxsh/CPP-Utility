//
//  FileElement.h
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef FileElement_hpp
#define FileElement_hpp

#include "FileSystemBasic.hpp"
#include "Path.hpp"

namespace xsh
{
    namespace FileSystem
    {
        class FileElement;
        typedef std::shared_ptr<FileElement> PFileElement;

        class FileElement
        {
        public:
            FileElement(const char *name, FileType type);
            FileElement(const std::string& name, FileType type);
            virtual void CreateInPath(Path path) = 0;
            virtual inline FileType getType() = 0;
        protected:
            std::string name_;
            FileType type_;
        };

    }
}

#endif /* FileElement_h */
