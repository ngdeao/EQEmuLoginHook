#include "Hook.h"
#include "ddraw_hooks.h"
#include "user32_hooks.h"

void HookFunction(const char* dllName, const char* exportName, int HookDetour, int HookTrampoline)
{
	HMODULE toHook = GetModuleHandle(dllName);
	if (!toHook) return;

	FARPROC ProcAddr = GetProcAddress(toHook, exportName);
	if (!ProcAddr) return;


	HookTrampoline = (int)DetourFunction((PBYTE)ProcAddr, (PBYTE)HookDetour);
}

void ApplyMainHooks()
{
	HookFunction("ddraw.dll", "DirectDrawCreate", ,o_DDrawCreate
}