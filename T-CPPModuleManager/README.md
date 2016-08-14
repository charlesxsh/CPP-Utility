#xsh::CPPModuleManager
Module manager tool for c++.

##Requirement
CMake installed.

##Basic Usage
```C++
#include "FileSystem.hpp"

using namespace xsh::FileSystem;


int main(int argc, const char* argv[])
{
    Path p = "/Users/Shihao/Desktop";
    xsh::CPPModuleManager manager;
    manager.CreateNewModule("testModule", p);
    return 0;
}

```
Under /Users/Shihao/Desktop there will be:

```
testModule/
|-src/
   |-main.cpp
|-include/
|-lib/
|-build/
   |-Makefile
```

Program will automatically generate a Makefile using CMake.
