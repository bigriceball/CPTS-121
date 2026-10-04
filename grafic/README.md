# Using this folder on macOS (Apple Silicon)

This guide shows how to compile and run `square.c` and `sierpinski.c` with the SDL2 graphics library on a Mac.

## 0. Download the files

Download these files into the same folder as your `.c` files:

- `grafic.h`
- `grafic.o`

## 1. Install SDL2

Install SDL2 with Homebrew:

```bash
brew install sdl2
```

Then check where it was installed (this lists the include and header paths):

```bash
brew list sdl2
```

## 2. Add Homebrew to your PATH

```bash
echo 'export PATH="/opt/homebrew/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
```

## 3. Check that Homebrew works

```bash
which brew
```

Expected output:

```
/opt/homebrew/bin/brew
```

## 4. Check the SDL2 path

```bash
ls /opt/homebrew/opt/sdl2-compat/include/SDL2/SDL.h
```

Expected output:

```
/opt/homebrew/opt/sdl2-compat/include/SDL2/SDL.h
```

If the file is shown, the path is correct and you can compile.

## 5. Compile

Open Terminal in this folder (`cd` into it), then run:

**square.c**

```bash
gcc -Wall -I/opt/homebrew/opt/sdl2-compat/include/SDL2 square.c grafic.o -L/opt/homebrew/opt/sdl2-compat/lib -lSDL2 -o square
```

**sierpinski.c**

```bash
gcc -Wall -I/opt/homebrew/opt/sdl2-compat/include/SDL2 sierpinski.c grafic.o -L/opt/homebrew/opt/sdl2-compat/lib -lSDL2 -o sierpinski
```

## 6. Run

```bash
./square
./sierpinski
```

## Troubleshooting

- `brew: command not found`: redo step 2 and open a new Terminal window.
- `SDL.h: No such file or directory`: re-run step 4. If the path differs, use the path shown by `brew list sdl2` in the `-I` and `-L` options.
- `cannot find -lSDL2` or linker errors: check that the `-L` path points to the folder containing `libSDL2`.
