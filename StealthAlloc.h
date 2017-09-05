#pragma once
/*++
Copyright 2017 Chris Graham

Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the "Software"), to deal in the Software 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
permit persons to whom the Software is furnished to do so, subject to the following 
conditions:

The above copyright notice and this permission notice shall be included in all copies 
or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
--*/

#ifdef __cplusplus
extern "C" {
#endif
/*++
	
Routine Name: 
	
	StealthAlloc

Routine Description:

	This routine provides the caller with a method to obtain a memory allocation
	without alerting security software. It does so by attempting to evade hooks 
	that may be placed on memory allocation routines. It requires no imports and 
	makes no win32 api calls. 

Parameters:

	ImageBase - A pointer to the image base of the module that is calling this
		routine. This address can be obtained by simply calling GetModuleHandle 
		and passing NULL as the parameter or it can be passed a pointer to the
		image base if it is known before hand. 

	Size - The required allocation size in bytes.

	Protection - A value indicating the required memory protection to be applied
		to the newly allocated region. This can be one of PAGE_READ, 
		PAGE_READWRITE, PAGE_EXECUTE, PAGE_EXECUTE_READWRITE, etc.

Return Value:

	On successfull allocation, a pointer will be returned to the newly allocated
	region. If the routine cannot safely allocate memory without detection, or
	if another error occurs, NULL is returned.
--*/
	PVOID
	WINAPI
	StealthAlloc(
		_In_ ULONG_PTR ImageBase,
		_In_ SIZE_T Size,
		_In_ ULONG Protection);
#ifdef __cplusplus
}
#endif

#ifdef _WIN64
#pragma comment(lib, "StealthAlloc64")
#else
#pragma comment(lib, "StealthAlloc32")
#endif