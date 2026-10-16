# redis
My own redis implementation.

## Execution

- Build: ```$ g++ -o redis ./src/input.cpp ./src/execution.cpp ./src/main.cpp```
- run: ```$ ./redis```

## Examples

### Create item
Input:
```
$ > SET user:1:name test
```

Output:
```
OK
```

### Get single item
Input:
```
$ > GET user:1:name
```

Output:
```
$1
*1
test
```

### Delete item
Input:
```
$ > DEL user:1:name
```

Output:
```
OK
```

### Check if item exists
Input:
```
$ > EXISTS user:1:name
```

Output:
```
TRUE
```

### List all items by table
Input:
```
$ > GET user
```

Output:
```
$2
*1
test
*2
test2
```
