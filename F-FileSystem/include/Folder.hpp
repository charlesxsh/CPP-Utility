//
//  Folder.h
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef Folder_hpp
#define Folder_hpp

#include "FileElement.hpp"

namespace xsh
{
    namespace FileSystem
    {
        
        class Folder;
        typedef std::shared_ptr<Folder> PFolder;
        
        class Folder:public FileElement
        {
        public:
            template<class... Args>
            static PFolder Create(Args&&... args)
            {
                return PFolder(new Folder(std::forward<Args>(args)...));
            }
            void CreateInPath(xsh::FileSystem::Path path) override;
            void add(const PFileElement e);
            inline FileType getType() override;
        private:
            Folder(const std::string& name);
            std::vector<PFileElement> childs_;
        };
    }
}

#endif /* Folder_h */
