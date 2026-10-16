# redis
My own redis implementation.

## Execution

- Build: ```$ g++ -o redis ./src/cli.cpp ./src/execution.cpp ./src/main.cpp```
- run: ```$ ./redis```

## Examples

### Create item
Input:
```bash
> SET user:1:name "test"
```

Output:
```bash
OK
```

### Get single item
Input:
```bash
> GET user:1:name
```

Output:
```bash
"test"
```

### Delete item
Input:
```bash
> DEL user:1:name
```

Output:
```bash
(integer) 1
```

### Check if item exists
Input:
```bash
> EXISTS user:1:name
```

Output:
```bash
(integer) 1
```

### Increase item value
Input:
```bash
> SET number 1
```
```bash
> INCR number 5
```

Output:
```bash
(integer) 6
```

### Decrease item value
Input:
```bash
> SET number 5
```
```bash
> DECR number 2
```

Output:
```bash
(integer) 3
```
