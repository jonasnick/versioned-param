# Playground for Versioned Structs Parameters in C

This implements and idea mentioned by [Ingo Molnar on the Linux Kernel Mailing List](https://lkml.org/lkml/2015/7/30/117) for designing C interfaces that are binary backward and forward compatible.
In particular, it resembles the `perf_event_attr` struct parameter of the `perf_event_open` Linux syscall.


```
$ nix-build --no-out-link -A test

App 0.1 linked to lib 0.1
What is the answer?
  - 42
  - 5 (discordia)

App 0.1 linked to lib 0.2
What is the answer?
  - 42
  - 5 (discordia)

App 0.2 linked to lib 0.2
What is the answer?
  - 42
  - 5 (discordia)
  - 23 (illuminati)

App 0.2 linked to lib 0.1
What is the answer?
  - 42
  - 5 (discordia)
  - 0 (illuminati)
```

