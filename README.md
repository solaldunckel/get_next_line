# get_next_line

## Final grade : 115/115

#### Mandatory : 100/100
#### Bonus : 15/15

## Description

get_next_line is a function that reads a ``fd`` line by line and fill ``line`` with its content. <br>

## Usage

```c
int   get_next_line(int fd, char **line)
```
* return ``1`` if it filled ``line``
* return ``0`` when it reaches the end of file
* return ``-1`` if it encountered any error while reading the file
