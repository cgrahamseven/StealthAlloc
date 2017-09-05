# StealthAlloc
Windows hook-evasion memory allocation routine

StealthAlloc is a small lib that contains a single routine that allows the user to make memory allocation calls on Windows without having those calls monitored by endpoint software. 

One of the most critical steps in executing code within the current process or in a remote process, is allocating a page of memory with the EXECUTE flag set. Requesting memory with PAGE_EXECUTE_READWRITE or setting a READ_WRITE page of memory to PAGE_EXECUTE_READWRITE will immediately draw attention from endpoint security software. Thankfully, it is trivial to avoid this unwanted attention since in order for a security solution to detect these types of memory allocations, hooks must be placed on the memory allocation APIs themselves.

This routine takes advantage of the fact that a user mode process does not at all have to call into one of these hooked APIs. Instead, it will dynamically set up a call to NtAllocateVirtualMemory, but avoid the normal code path to this function. 

Until the day that Microsoft allows all security solutions to receive notifications from the kernel of memory allocations where the EXECUTE flag is set, there is no way to avoid having a user evade your hooks in this manner. 

# Use
Two library files are provided for both 32-bit and 64-bit applications to link in. There are no imports required by the routine. As such it should be able to be safely used in Reflective Dlls, etc. Simply include the provided header file in your project in Visual Studio and call StealthAlloc as needed. See the provided header file for details on required function parameters.

# File Hashes (SHA256)

d6fa01430fa137ccabdabe88cc2049cb87ab54e33d64fe5dc820adabfdecfbd2  StealthAlloc32.lib
f1e653df69a8f327ec477ef98666468caf415ffbce1f8cd531076191cef05c56  StealthAlloc64.lib
