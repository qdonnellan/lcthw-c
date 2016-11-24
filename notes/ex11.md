It would appear that C coerces characters to a numeric presentation, such that
when I set an integer array like this:

```C
int numbers[4] = {1, 2, 3, '4'}; // numbers = {1, 2, 3, 52}
```

This appears to be an ASCII decimal converter of some sort.