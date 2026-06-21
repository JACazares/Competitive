# Competitive

A collection of my code used in competitive programming.

This is an updated version of previous Contest-Archive and Template-Library.

## Workflow

Problems live in their own directories, usually with this shape:

```text
Codeforces/2500/
  A/
    main.cpp
    main.in
  B/
    main.cpp
    main.in
```

Create problem directories from the contest directory:

```sh
cd ~/Desktop/Programming/Competitive/Codeforces
mkdir -p 2500
cd 2500
cppnew A B C D E
```

Add sample input from the contest root:

```sh
cppin A
# paste input, then Ctrl-D
```

Or from inside a problem directory:

```sh
cd A
cppin
```

Run from the contest root:

```sh
cpprun A
```

Or from inside the problem directory:

```sh
cpprun
```

`cpprun` compiles `main.cpp` into `.cpbuild/main` and uses `main.in` automatically
when it exists. If `main.out` exists, it also diffs actual output against it.

The helper scripts live in `tools/`; the active copies are installed on PATH in
`~/.local/bin`.
