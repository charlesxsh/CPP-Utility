//
//  function.hpp
//
//  Created by Shihao Xia on 7/26/16.
//  Copyright © 2016 Shihao Xia. All rights reserved.
//

#ifndef function_hpp
#define function_hpp

#include <utility>

namespace xsh 
{
 
    template<class F>
    class Function;
    
    template<class R, class... Args>
    class Function<R(Args...)>
    {
    public:
        using FPtr = R(Args...);
        
        Function()
        {
            f = nullptr;
        }
        
        Function(FPtr&& _fp)
        {
            f = _fp;
        }
        
        R operator()(Args&&... args)
        {
            return f(std::forward<Args...>(args...));
        }
        
        Function& operator=(FPtr&& _fp)
        {
            f = _fp;
            return *this;
        }
        
        Function& operator=(const Function<FPtr>& ff)
        {
            f = ff.f;
            return *this;
        }
    private:
        FPtr* f;
        
    };
    
}

#endif /* demo_hpp */
