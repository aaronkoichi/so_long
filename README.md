# so_long project

Assets courtesy of [pixel-boy](https://pixel-boy.itch.io/ninja-adventure-asset-pack), [KMH Studios](https://kevins-moms-house.itch.io/fantasy)
and [biscuitlocker](https://biscuitlocker.itch.io/pixel-block-numbers-gameboy).


<hr />

# Introduction

The purpose of this project is to add 

# How To Run

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
```
./so_long [path/to/map/format]
```
```
./so_long_bonus [path/to/map/format]
```


## Clean Up install

You can clean up the binary files by using
```
make clean
```

Used imagemagick and a python script for converting them into xpm files onto usage in the game.

## Game Render
![nojL73P](https://github.com/user-attachments/assets/1b48d25c-d346-42f1-9a61-785c15f24153)
## Bonus Renders
![so_long_1](https://i.imgur.com/4EINoE8.gif)
