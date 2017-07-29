d_main.c:
# void D_DoomMain(void)

## Parameter checking
reuses again and again the “p” variable to represent the parameter checking it's doing
quite a few of the parameters checked initialise global variables, others call functions. a lot of it seems to be related to multiplayer.

## Zone Memory Allocation
bit of a loss here. a zone consists of a blocklist of memblocks?
the blocks have "users"? seem to take structure of linked list?
have tags and ids, too. 
something to do with locality?

## Init Subsystems

### Allocate Screens

### Load config files, use defaults where not overridden

Also setup a hook to save config file when we exit

### Find and load IWAD

### Get version / variant from IWAD so we know how to switch up behaviour

### Add PWADs

### Play demos

### Generate lump hash table for performance?

### Set game description

### Print startup banner

### Deal with screensaver support

### Init SDL stuff

#### Timer

#### Joystick

#### Sound

Looks like it always tried to start timidity when it's set to native musi? Maybe its needed to use native midi. Might have to fork it or sometihg?

