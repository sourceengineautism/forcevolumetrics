# forcevolumetrics

patches two bytes of portal2's engine.dll to skip an if check in DrawVolumetrics.

compiling:
hl2sdk isnt being pushed to this repo because of its size, if you want to compile it, clone the portal2 branch of hl2sdk (https://github.com/alliedmodders/hl2sdk/tree/portal2) to the forcevolumetrics folder ( the folder containing the actual source code files like "serverplugin.cpp" )

after compiling succeeds the produced dll file will automatically be placed at C:\Program Files (x86)\Steam\steamapps\sourcemods\p2009_beta\addons\forcevolumetrics.dll