# so_long

![C](https://img.shields.io/badge/language-C-blue.svg)
![School](https://img.shields.io/badge/school-42-black.svg)
![MinilibX](https://img.shields.io/badge/graphics-MinilibX-purple.svg)

A small 2D tile-based game built with **MinilibX**: load a map from a file, render it as a grid of textured sprites, move a player character around with the keyboard, collect every item on the map, and reach the exit — all without leaking a single byte of graphics or map memory.

## Map format

Maps are plain text files (`.ber`) describing a rectangular grid, validated before anything is rendered: the map must be surrounded by walls, contain exactly one player, at least one collectible, exactly one exit, and every open tile must be reachable via flood fill.

| Symbol | Meaning |
|--------|---------|
| `1` | Wall |
| `0` | Floor |
| `P` | Player start position (exactly one) |
| `C` | Collectible (at least one) |
| `E` | Exit (only reachable once every `C` is collected) |

```
1111111111111111111111111111111111
1E100000000000000000000000C0000001
101001010010C000101001000000010101
1000110010101010001001000000010101
100P100000000000000C00000000000101
1111111111111111111111111111111111
```

## Controls

`W` / `A` / `S` / `D` move the player one tile at a time. Each move is validated against the map (no walking through walls) and prints the move counter to the terminal. Collecting the last `C` unlocks the `E` tile; stepping onto it while it's unlocked ends the game.

## Build

```sh
make        # builds libft, minilibx, and the so_long binary
make clean  # removes object files
make fclean # full clean, including the sub-libraries
make re     # rebuilds from scratch
```

## Usage

```sh
./so_long maps/map.ber
```

## Structure

```
├── so_long.c / .h        # Entry point, game struct, function prototypes
├── map_parser.c          # Reads the map file into memory
├── map_checker.c         # Validates map shape, elements, and reachability
├── processing.c          # Game state updates (movement, collection, win check)
├── processes.c           # MLX event loop wiring
├── press.c                # Keypress handlers (W/A/S/D)
├── textures/              # XPM sprites for player, walls, floor, collectibles, exit
├── maps/                  # Sample .ber map files
└── minilibx/              # Bundled MinilibX graphics library
```

## Context

Part of the [42 School](https://42.fr/) common core curriculum — the first graphical project, focused on 2D rendering, event-driven input, and rigorous input validation.
