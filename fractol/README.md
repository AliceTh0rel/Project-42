# fract-ol

This project is a graphical exploration of fractals (Mandelbrot and Julia) using C and the MiniLibX library.


## Objectives

- Implement the rendering of fractals (Mandelbrot & Julia)

- Learn the mapping between screen coordinates and the complex plane

- Handle events such as zooming, panning, and color shifting

- Gain experience with graphics programming in C and the MiniLibX library


## Supported fractals

- Mandelbrot

- Julia (with user-defined parameters)


## Usage
make

# Mandelbrot set
./fractol Mandelbrot

# Julia set with parameters (-0.8, 0.156)
./fractol Julia -0.8 0.156


## Controls

- Esc : quit the program

- Arrow keys : move around the fractal

- Mouse scroll : zoom in/out centered on the mouse position

- + / - : change color palette

- Mouse motion (Julia only) : interactively change parameters (if enabled)
