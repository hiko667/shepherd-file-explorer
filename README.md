
# Shepherd
Fully keyboard-driven file explorer for Windows and Linux (under development)


## Deployment

DO NOT UNDER ANY CIRCUMSTANCE DEPLOY IT YET I HAVE NOT FINISHED THIS PROJECT NOR IS IT NEAR END thank you

To compile shepherd yourself download it via git clone command like

```bash
  git clone https://github.com/hiko667/shepherd-file-explorer .
```
to make current directory the source directory. Then, to generate build folder run

```cmd
  md build
  cd build
  cmake -G "MinGW Makefiles" ..
  cd ..
```

or if you're on linux

```bash
  mkdir build
  cd build
  cmake ..
  cd ..
```
 
when you finished run

```bash
  cmake --build build --clean-first
```

to compile source code to executable. This tutorial assumes you have gcc and cmake installed, if not install it first


## Control

You control the aplication using your keyboard. No mouse needed. 

| Key | Acction     |
| :-------- | :------- |
| `w` | Go up |
| `s` | Go down |
| `f` | Open directory, or file in the other window (on widnows) |
| `q` | Quit |
| `c` | Clear cache |
| `d` | Go back to the parent dir |

