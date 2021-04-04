A Minecraft version of Ben Eater's 8-bit breadboard computer.

Computer    -- The Minecraft world. Copy into the .minecraft/saves folder  
mcram.c     -- Program to convert raw binary file to an mcfunction file, which can be used in Minecraft  
TickRateMod -- My mod to add a gamerule which speeds up the game. Copy into the .minecraft/versions folder  


### Using mcram
After compiling (with gcc or any other compiler), run "mcram [YOUR 16 BYTE BINARY FILE] [MINECRAFT WORLD DIRECTORY]/datapacks/utils/data/utils/functions/write.mcfunction".

### Installing the Tick Rate Mod
Since the computer is a bit too slow, it really helps to speed up the process.
To install this mod, copy the folder to the .minecraft/versions folder. In the launcher, add a new installation and select the "TickRateMod" version.
Now, go to the Play tab and start.

IMPORTANT: If the game crashes when you hit Play, you are most likely using the wrong Java version. Click "More Options" in the installation settings and change the Java executable to Java 11. In my case (Arch Linux), it is set to "/usr/lib/jvm/java-11-openjdk/bin/java".
