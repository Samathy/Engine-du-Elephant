Engine-du-Elephant
==================

A simple game engine project that i made for college and uploaded here with the intention of improving it.

This code is:
1)A mess
2)Badly written
3)Badly commented
4)Doesnt even work very well.


Depends on:

SDL 2.0+
OpenGL 2.1
Boost 1.53+ (Could probably use less versions that that, but thats the only version i have tested on.)
Lua 5.2



TODO
==================

URGENT:
* ~~Impliment "placement new" for all of the entity objects and allocate that menory when map is read in order to hopefully remove the laggy feeling when moving the player entity. (thought to be beacuse of memory acsess times.)~~ - Did not impliment this. After further research the laggy movement issue was cause by cheching for command line input from inside the game loop. 
* Clean up code to remove large commented out parts, unused variables, defunct and broken code, and try to optomize code. 


Not so urgent.
* Remove entitys being hardcoded with rendering code, colour, textures etc. Make it so that there is one entity object type which can be configured in using the map file/s
* Impliment Lua scripting to configure engine and to program the entities.
* Add support for textures.
* Add "globals" class holding pseudo global variables such as screen size, amount of entities, memory being used, game ticks and other variables that are currently passed around either as pointers or copied between functions as arguments.
