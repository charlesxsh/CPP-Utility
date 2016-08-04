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
            
        public:
            template<class... Args>
            static PFile Create(Args&&... args)
            {
                return PFile(new File(std::forward<Args>(args)...));
            }
            void CreateInPath(xsh::FileSystem::Path path) override;
            inline FileType getType() override;
            
            template<class T>
            File& operator << (T&& t)
            {
                buffer_ << t;
                return *this;
            }
        private:
            File(const char *name);
            std::stringstream  buffer_;
        };
        

    }
}

#endif /* File_h */
