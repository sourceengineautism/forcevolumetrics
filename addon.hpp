#pragma once

namespace addon {
    namespace modules {
        extern HMODULE Engine;
        inline void wait_for_module(const char* name, HMODULE* out) {
            HMODULE m = GetModuleHandleA(name);
            while (m == NULL) {
                m = GetModuleHandleA(name);
                if (m == NULL)
                    Sleep(100);
            }
            *out = m;
        }
    }
    bool load();
    void unload();
}
