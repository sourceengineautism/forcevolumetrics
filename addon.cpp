#include "includes.hpp"
namespace addon {
	namespace modules {
		HMODULE Engine;
	}
	uint8_t* VolumetricJL;
	bool load() {
		addon::modules::wait_for_module("engine.dll", &addon::modules::Engine);

		VolumetricJL = (uint8_t*)ScanModule(addon::modules::Engine, "7C 19 8B 0D ?? ?? ?? ?? 8B 11 8B 42 14 FF D0 39 87 E0 02 00 00");

		if (!VolumetricJL)
			return false;

		DWORD oldProt;
		VirtualProtect(VolumetricJL, 2, PAGE_EXECUTE_READWRITE, &oldProt);
		
		VolumetricJL[0] = 0xEB; // replace jl with jmp
		VolumetricJL[1] = 0x36; // change instruction to jump from 19 bytes forward to 36 bytes forward, which is the jump to the end of the if check.
		// 36 might not be the same in every version of portal 2, but its 36 in the latest version & the 2014 dev build.
		// so its likely not been changed in between those versions.

		VirtualProtect(VolumetricJL, 2, oldProt, 0);

		return true;
	}
	void unload() {
		if (!VolumetricJL)
			return;
		DWORD oldProt;
		VirtualProtect(VolumetricJL, 2, PAGE_EXECUTE_READWRITE, &oldProt);

		VolumetricJL[0] = 0x7C; // replace jmp with jl
		VolumetricJL[1] = 0x19; // reset 36 offset patch back to the original 19

		VirtualProtect(VolumetricJL, 2, oldProt, 0);
	}
}
