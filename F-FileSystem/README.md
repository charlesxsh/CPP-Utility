#xsh::FileSystem
Try to implement an c++ file system universal framework, which supports Linux, Unix, and Windows

#Basic Usage
```C++
#include "file.hpp"


int main(int argc, const char* argv[])
{
    
    xsh::FileSystem::Path path("/Users/Shihao/Desktop");
    xsh::Module m("testmodule");
    m.GenerateInFolder(path);

    xsh::File testFile = xsh::CreateFile("test.txt");
    testFile->writeToFile("This is test");
    testFile->GenerateInFolder(xsh::FileSystem::Path("/Users/Shihao/Desktop"));
    return 0;
}


```
