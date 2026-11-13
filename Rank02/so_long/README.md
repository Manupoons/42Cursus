# so_long

A small 2D game made with the MiniLibX graphics library. Collect every collectible and reach the exit.

```
make
./so_long maps/map1.ber
```

**Controls:** `W` `A` `S` `D` to move, `ESC` to quit.

**Maps** are `.ber` files made of these characters:

| Char | Meaning |
|------|---------|
| `1` | wall |
| `0` | empty floor |
| `P` | player start (exactly one) |
| `E` | exit (exactly one) |
| `C` | collectible (at least one) |

The map must be rectangular, enclosed by walls, and have a valid path to every collectible and the exit. `maps/err*.ber` are invalid maps used for testing.

`mlx/` is a vendored copy of MiniLibX (Linux).
