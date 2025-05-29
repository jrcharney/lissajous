# Lissajous

A program that displays a Lissajous Curve

# What is a Lissajous Curve?

A **Lissajouse curve** is the graph of the parametric equations

$$
\begin{aligned}
\begin{cases}
x &= A \sin(\omega_a \cdot t + \delta) \\
y &= B \sin(\omega_b \cdot t)
\end{cases}
\end{aligned}
$$

which describe the superposition of two perpendicular oscillations in $x$ and $y$ directions with different *angular frequencies* $\omega_a$ and $\omega_b$.

**Angular frequency** can be describe with

$$
\begin{aligned}
\omega = 2 \pi f
\end{aligned}
$$

where $f$ is the frequency in Hertz (Hz).  It also simplifies the need to calculate the $A : B$ ratio.  I set it to $2 : 3$ for that classic Lissajous curve everyone is familiar with.

A $\delta$ (delta) value provides for a *phase shift* variable.

> Note: If $f_a = 1$ and $f_b = N$ where $N$ belongs to the set of natural numbers, and $\delta = \frac{N - 1}{N} \cdot \frac{\pi}{2}$, this will corm a *Chebyshev polynomial* for the first kind of degree $N$. This property can be exploited to produce a set of points, called *Padua points*, at which a function may be sampled in order to computer either a bivariate interpolation or quadrature of the function over the domain $[-1,1] \times [-1,1]$.
> The relation of some Lissajous curves to Chebyshev polynomias is better understood if the Lissajous curve which generates each of them is express using a cosing function rather than a sine function.

$$
\begin{aligned}
\begin{cases}
x &= \cos(t) \\
y &= \cos(Nt)
\end{cases}
\end{aligned}
$$

TLDR: Math stuff.


Honestly, I just wanted to make a C++ program that did something with graphics using the SDL library that did some cool math stuff.  Also, oscilloscopes are expensive.

# Features

For convenience, $f_a$ and $f_b$ are used instead of $\omega_a$ and $\omega_b$.  If you have every used an oscilloscpe, this is ideal.

Also for convenience, the $\delta$ variable is in degrees instead of radians.

A rotation transformation was added in case you wanted to rotate the curve.

Holding down shift will chage values in larger steps.

You can reset the figure using the backspace key.

# Requirements

To run this program you will need a few things from the Ubuntu repository:

- `gcc` (for compiling)
- `libsdl2-dev` (for SDL2 and `sdl2-config`)
- `libsdl2-ttf-dev` (for text rendering)
- `fonts-dejavu` (for the DejaVu fonts)

If you want to compile this on Windows, you should have Windows 11, and use WSL2.

I don't have this set up for SDL3 as of yet, but soon.  There will be Arch Linux support later.

# Install or Clean

- To compile and build, just run `make`.
- To clean up the object files and the binary, run `make clean`
- To run, use `./lissajous`

# AI Notice

I have to confess, I did use ChatGPT to help me write this code.  However, I know enough about C++ that I could guide it to help me write **graphical** C++ programs that would do some cool math stuff. Things I wanted to do years ago when I was first starting out with Computer Science.

Employers are visual people. They don't want to be bored to death with a bunch of consoles and command lines. They want something that will draw their attention.

While there has been controversy on the ethics of using generative artificial intelligence to write code, the truth is that AI is not here to replace people. If anything, AI needs human guidance.  This assumption that AI will come and replace us and do a better job is foolish.  It's like the people who think if they buy a Tesla and enable the autopilot, they don't have to keep their eyes on the road.  That's not what its used for.

AI has helped me out a lot the past few months that I've used it.  It's reignited my interest in writing programs.  It has given me something to write about.  It has helped me fix several computers, set the correct settings on them, and taught me some new features in a programming language that I was too timid to use.  These lessons are reflected in this code.  (I do like using `#pragma once` over the `#ifndef, #define, #endif` from years ago.)

There will be more programs to come written in C++ with the SDL library with the assitance of AI, but it won't be all the AIs work as I still control what I want to put into this code and have plenty of knowledge of C++ to give it directions to add features that not only will benefit myself but other people who wish to code.

Python is easy. C and C++ are harder.

Let's make something that makes using C and C++ cool again.

