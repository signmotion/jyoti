#pragma once

#include <string>


namespace jyoti {


// Для отладки.
#ifdef _DEBUG
#define ASSERT(EXPR)   assert(EXPR);
#define DASSERT(EXPR)  if (!(EXPR)) __debugbreak();

#define QUOTE_(WHAT)      #WHAT
#define QUOTE(WHAT)       QUOTE_(WHAT)
#define DBG(format, ...)  printf("%s: "format, __FILE__":"QUOTE(__LINE__), ## __VA_ARGS__)
#define LOG  DBG

#else
#define ASSERT(EXPR)      ((void)0)
#define DASSERT(EXPR)     ((void)0)
#define DBG(format, ...)  ((void)0)

#endif


#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
    #define DEPRECATED_ATTRIBUTE_JYOTI __attribute__((deprecated))
#elif _MSC_VER >= 1400 //vs 2005 or higher
    #define DEPRECATED_ATTRIBUTE_JYOTI __declspec(deprecated) 
#else
    #define DEPRECATED_ATTRIBUTE_JYOTI
#endif 


} // jyoti
