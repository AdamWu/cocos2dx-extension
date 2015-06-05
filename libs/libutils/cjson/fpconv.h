/* Lua CJSON floating point conversion routines */

/* Buffer required to store the largest string representation of a double.
 *
 * Longest double printed with %.14g is 21 characters long:
 * -1.7976931348623e+308 */
# define FPCONV_G_FMT_BUFSIZE   32

#define USE_INTERNAL_FPCONV

#if _MSC_VER
	#define  inline __inline // vs: The inline keyword is available only in C++. The __inline and __forceinline keywords are available in both C and C++. 
	#include <float.h>  
	#define isnan(x) ((x) != (x))  
	#define isinf(x) (!_finite(x) && !_isnan(x))  
	#define strncasecmp  _strnicmp 
	#define snprintf _snprintf
#endif // _DEBUG

#ifdef USE_INTERNAL_FPCONV
static inline void fpconv_init()
{
    /* Do nothing - not required */
}
#else
extern inline void fpconv_init();
#endif

extern int fpconv_g_fmt(char*, double, int);
extern double fpconv_strtod(const char*, char**);


/* vi:ai et sw=4 ts=4:
 */
