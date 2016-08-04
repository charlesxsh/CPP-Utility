#xsh::FileSystem
Try to implement an c++ file system universal framework, which supports Linux, Unix, and Windows

#Basic Usage
```C++
#include "FileSystem.hpp"

using namespace xsh::FileSystem;


int main(int argc, const char* argv[])
{
    
    auto file = File::Create("test.txt");
    auto folder = Folder::Create("folder");
    folder->add(file);
    return 0;
}

```
