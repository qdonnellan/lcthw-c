Running `make` in a dir where a `Makefile` is present will default to run the first target (top of the file).

Makefile dependencies seem to resolve not necessarily in order, but in dependence order. For example:

```
all: hello world clean
```

Will load `hello` and then `world` and then `clean`. But this:

```
all: hello world clean

hello: clean
```

Will run `clean` `hello` and then `world`. The target `clean` is loaded first because `hello` depends on it first. Since it was loaded already, it won't be loaded again.