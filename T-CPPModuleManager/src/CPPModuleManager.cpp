//
//  CPPModuleManager.cpp
//  Cppdemo
//
//  Created by Shihao Xia on 8/4/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#include "CPPModuleManager.hpp"


namespace xsh {

    CPPModuleManager::CPPModuleManager()
    {
        
    }

    void CPPModuleManager::CreateNewModule(const std::string &module_name, FileSystem::Path& path)
    {
        auto module_folder = FileSystem::Folder::Create(module_name);
        
        auto src_folder = FileSystem::Folder::Create("src");
        
        auto main_cpp = FileSystem::Folder::Create("main.cpp");
        src_folder->add(main_cpp);
        
        auto include_folder = FileSystem::Folder::Create("include");
        auto lib_folder = FileSystem::Folder::Create("lib");
        auto cmake_file = FileSystem::File::Create("CMakeLists.txt");
        
        module_folder->add(src_folder);
        module_folder->add(include_folder);
        module_folder->add(lib_folder);
        module_folder->add(cmake_file);
        
        cmake_file << "cmake_minimum_required (VERSION 2.8)\n";
        
        cmake_file << "project(" << module_name <<")\n";
        
        cmake_file << "AUX_SOURCE_DIRECTORY(src SOURCE_FILES)\n";
        cmake_file << "file(GLOB_RECURSE HEADER_FILES include/*.*)\n";
        cmake_file << "include_directories(include)\n";
        
        cmake_file << "add_executable(Demo ${HEADER_FILES} ${SOURCE_FILES})\n";
        
        module_folder->CreateInPath(path);
        
        std::cout << xsh::FileSystem::GetCurrentDirectory() << std::endl;
        path.join(module_name);
        xsh::FileSystem::ChangeWorkingDirectory(path.str());
        std::cout << xsh::FileSystem::GetCurrentDirectory() << std::endl;

        xsh::FileSystem::CreateDirectory("build");
        
        path.join("build");
        
        xsh::FileSystem::ChangeWorkingDirectory(path.str());
        std::cout << xsh::FileSystem::GetCurrentDirectory() << std::endl;

        std::cout << SyncRunScript("/usr/local/bin/cmake ..");
    }
    
    std::string CPPModuleManager::SyncRunScript(const std::string& script)
    {
        char buffer[128];
        std::stringstream result;
        std::shared_ptr<FILE> pipe(popen(script.c_str(), "r"), pclose);
        if (!pipe) throw std::runtime_error("popen() failed!");
        while (!feof(pipe.get()))
        {
            if (fgets(buffer, 128, pipe.get()) != NULL)
            {
                result << buffer;
            }
        }
        return result.str();
    }
    
    
    
}