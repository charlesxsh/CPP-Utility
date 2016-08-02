//
//  file.hpp
//  Cppdemo
//
//  Created by Shihao Xia on 7/26/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef file_hpp
#define file_hpp

#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
#include "FileSystem.hpp"

namespace xsh {
    
    
    class BaseFile_;
    class File_;
    class Folder_;
    class FileBuffer;

    using BaseFile = std::shared_ptr<BaseFile_>;
    using File = std::shared_ptr<File_>;
    using Folder = std::shared_ptr<Folder_>;
    
    class FileBuffer
    {
    public:
        FileBuffer()
        {
        }
        FileBuffer& operator<<(const std::string& content)
        {
            buffer << content;
            return *this;
        }
        std::string str() const
        {
            return buffer.str();
        }
        private:
        std::stringstream buffer;
    };

    std::ostream& operator<<(std::ostream& stream, const FileBuffer& buffer)
    {
        return stream << buffer.str();
    }
    
    class BaseFile_
    {
    public:
        BaseFile_()
        {
            type_ = FileSystem::FileType::Unknown;
        }
        BaseFile_(const std::string& name, FileSystem::FileType type):file_name_(std::move(name)), type_(type)
        {}
        virtual FileSystem::FileType GetType() const = 0;
        virtual bool GenerateInFolder(FileSystem::Path path) const = 0;
        std::string file_name_;
        FileSystem::FileType type_;
    };
    
    class File_:public BaseFile_
    {
    public:
        File_():BaseFile_()
        {
            file_size_ = 0;
        }
        File_(const std::string& name):BaseFile_(name, FileSystem::FileType::File){
            file_size_ = 0;
        }
        File_(const File_& f):xsh::BaseFile_(f.file_name_, f.type_)
        {
            file_size_ = f.file_size_;
        }
        
        FileSystem::FileType GetType() const override { return FileSystem::FileType::File; }
        
        bool GenerateInFolder(FileSystem::Path path) const override{
            path.join(file_name_);
            std::ofstream f(path.str(), std::ios_base::app);
            f << buffer;
            return true;
        }
        
            void writeToFile(const std::string& content)
            {
                buffer << content;
            }
    private:
        size_t file_size_;
        FileBuffer buffer;
    };
    
    class Folder_:public BaseFile_
    {
    public:
        Folder_():BaseFile_(){
            
        }
        Folder_(const std::string& name):BaseFile_(name, FileSystem::FileType::Folder){
        }
        FileSystem::FileType GetType() const override{ return FileSystem::FileType::Folder; }
        void Add(const BaseFile& f){
            childs.push_back(f);
        }
        bool GenerateInFolder(FileSystem::Path path) const override{
            path.join(file_name_);
            FileSystem::CreateDirectory(path.str());
            for(auto& i:childs)
            {
                i->GenerateInFolder(path);
            }
            return true;
        }
        BaseFile GetFile(const std::string& name)
        {
            
            for(auto& i: childs)
            {
                if(i->file_name_ == name){
                    return i;
                }
            }
            
            throw std::runtime_error("No found file" + name);
        }
    private:
        std::vector<BaseFile> childs;
    };
    
    
    template<typename... Args>
    File CreateFile(Args&&... args)
    {
        return File(new File_(std::forward<Args>(args)...));
    }
    
    template<typename... Args>
    Folder CreateFolder(Args&&... args)
    {
        return Folder(new Folder_(std::forward<Args>(args)...));
    }

    
    class Module: public Folder_
    {
    public:
        Module(const std::string& name):Folder_(name){
            Add(CreateFolder("src"));
            Add(CreateFolder("include"));
            Add(CreateFolder("lib"));
            Add(CreateFile("CMakeLists.txt"));
            ab_path_ = std::make_unique<FileSystem::Path>(FileSystem::PathType::Absolute);
        }
    private:
        std::unique_ptr<FileSystem::Path> ab_path_;
    };
    
    
    
   }


#endif /* demo_hpp */
