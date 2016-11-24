When I first opened up `lldb` and attempted to `run` I got this error:

```
# This is on a macOS computer
(lldb) run
error: process exited with status -1 (lost connection)
'r' and 'run' are aliases that default to launching through a shell.
Try launching without going through a shell by using 'process launch'.
```

Using `process launch` instead of `run` seems to work, but I'm not sure why. Will need to investigate further...

If you remove the `*dSYM` folders, you will get Assembler output in `lldb` instead of useful stuff; so don't delete those until the cleanup step!