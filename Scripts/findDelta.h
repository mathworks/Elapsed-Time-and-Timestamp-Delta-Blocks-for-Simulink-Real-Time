// Copyright 2022-2022 The MathWorks, Inc

#include <stdint.h>
/*Note: Macro is needed because of name wrangling.
* Simulink Real-Time compiles in C++ which supports
* name wrangling, external code is in C, which does not
* support name wrangling.
*/
#ifdef __cplusplus
extern "C" {
#endif
	double findDelta(const uint32_t* timestamp1, const uint32_t* timestamp2);
#ifdef __cplusplus
}
#endif