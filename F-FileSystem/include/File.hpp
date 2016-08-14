//
//  File.h
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include "FileElement.hpp"

namespace xsh
{
    namespace FileSystem
    {
        class File;
        
        typedef std::shared_ptr<File> PFile;

        class File:public FileElement
        {
            File(const File&) = delete;
            File(File&&) = delete;
            File& operator=(const File&) = delete;
            File& operator=(File&& ) = delete;
            
            template<class T>
            friend PFile& operator << (PFile& file, T&& stuff);
        public:
            template<class... Args>
            static PFile Create(Args&&... args)
            {
                return PFile(new File(std::forward<Args>(args)...));
            }
            void CreateInPath(xsh::FileSystem::Path path) override;
            inline FileType getType() override;
            
            private:
            File(const char *name);
            std::stringstream  buffer_;
        };
        
        template<class T>
        PFile& operator << (PFile& file, T&& stuff)
        {
            file->buffer_ << stuff;
            return file;
        }

    }
}

#endif /* File_h */
