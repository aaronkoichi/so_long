# so_long project

Assets courtesy of [pixel-boy](https://pixel-boy.itch.io/ninja-adventure-asset-pack), [KMH Studios](https://kevins-moms-house.itch.io/fantasy)
and [biscuitlocker](https://biscuitlocker.itch.io/pixel-block-numbers-gameboy).
Used imagemagick and a python script for converting them into xpm files onto usage in the game.

<hr />

# Introduction

The purpose of this project is to make a 2D view game, where player has to collect all
collectibles in order to exit.

# How To Run

Note: This game works best at 2k / 4k displays. It may be too large for 1080p screens.

You can get the 1080p version of the game [here](https://github.com/aaronkoichi/so_long_1080p).

This game uses Makefiles and C to compile the game:

## 1. Install the dependencies For Linux
```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
## 2. Build the Program from source

The game can be built using the commands below.
```
make
```

To build the game with animations and movement counter:
```
make bonus
```

## 3. Run

The game contains a maps/ folder where you can access different maps to play the game.
```
./so_long [path/to/map/format]
```
Some maps, contains enemy, which only works on the bonus executable.
```
./so_long_bonus [path/to/map/format]
```
### Controls

To move:
- W, A, S, D

To Exit the game:
- Press Escape or the button X


## Clean Up install

You can clean up the binary files by using
```
make clean
```


## Game Render
![nojL73P](https://github.com/user-attachments/assets/1b48d25c-d346-42f1-9a61-785c15f24153)
## Bonus Renders
![so_long_1](https://i.imgur.com/4EINoE8.gif)
