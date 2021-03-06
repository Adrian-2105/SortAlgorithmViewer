# Sort Algorithm Viewer

Made by Adrián Fenollar Navarro, 3rd year computer engineering student
at the University of Murcia; October 26, 2020.

------

## Introduction
This project consists of an sorting algorithm viewer that aims to be
a tool that can facilitate the study and learning of these algorithms.

That's the first beta version of the application, with only two sort algorithms implemented.

## Executuion example

![Alt text](Examples/SortAlgorithmViewer-v0.1_Selection&BubbleSort_example.gif)

-------

## Requirements

The only thing you need to be able to execute it is:

- A Linux environment (it has only been tested on Ubuntu)
- Have the SFML library installed

If you don't have SFML installed, you can use the attached script `sfml_installer.sh`
to install it, or use the next commands (valid on Ubuntu):
```
sudo apt-get update
sudo apt-get install libsfml-dev
```
If you use another version of linux and the above has not worked for you,
here is the [official SFML installation page on Linux](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).

If you want to recompile it, you must have the following packages installed:

```
sudo apt-get build-essential make cmake
```

## How to compile it

In this repository there is already an executable called `SortAlgorithmViewer` with the
project code compiled and ready to run. In the event that this executable does not
work for you, or you want to try to make modifications to the code and recompile it,
you must execute the next commands from the project directory:

```
cmake CMakeLists.txt
make
```

-------

## How to use it

A more detailed user manual will be included in later versions. At the moment, the
program runs as follows:

```
./SortAlgorithmViewer [OPTIONS] <algorithms>
```

where the `OPTIONS` are

- `-n, --size <array_size>`: specifies the size of the array. The default is 250
- `-f, --framerate <framerate>`: specify the number of frames per second. The default is 60
- `-r, --random:`: initialize the array with random values
- `-h, --help`: show help menu

and `algorithms` can be (non case sensitive)

- `Selection`
- `Bubble`
- `Heap`

At the moment only one algorithm can be included per run.

### Examples of use

- Selection Sort with an array of length 200, 30 FPS and uniform initialization:

`./SortAlgorithmViewer -n 200 -f 30 Selection`
- Heap Sort with an array of length 500, 60 FPS and random initialization:

`./SortAlgorithmViewer -n 500 -f 60 -r Heap`

------

## Updates

- [25/01/2021] Included Heap Sort Algorithm and uniform initialization

