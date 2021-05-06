### Definition
```what can I say except [ASCII-character/8-bit register]```
### Description
Prints the given character to stdout. The given parameter can either be a letter itself, an ASCII-value in decimal form or a 8-bit register (e.g. al) containing an ASCII-value. Numbers from 0-9 are interpreted as characters and not as ASCII-values. \
All [common escape sequences](https://en.wikipedia.org/wiki/Escape_sequences_in_C#Table_of_escape_sequences) are also supported and can be used without any issues. Here is an overview:

Escape Sequence  | Usage
------------- | -------------
```\n``` | New line
```\s``` / ```space``` | Space
```\b``` | Backspace
```\t``` | Horizontal Tab
```\v``` | Vertical Tab
```\f``` | Formfeed Page Break
```\"``` | Double quotation mark
```\?``` | Question mark
```\\``` | Backslash

> Please note: Printing Unicode-Characters directly is not possible. However, using [this program](https://play.golang.org/p/TojzlTMIcJe), you can get the sequence of commands needed to print your character.

### Examples
#### 1. Hello World!
```
what can I say except H
what can I say except e
what can I say except l
what can I say except l
what can I say except o
what can I say except \s
what can I say except W
what can I say except o
what can I say except r
what can I say except l
what can I say except d
what can I say except !
what can I say except \n
```
#### 2. Print the Unicode-Character "😎"
```
what can I say except 240
what can I say except 159
what can I say except 152
what can I say except 142
```

#### 3. Print the alphabet with spaces in between and a new line at the end
```
eax is great, but I want 65

upgrade
what can I say except al
what can I say except \s
upvote eax
corporate needs you to find the difference between eax and 91
fuck go back

they're the same picture
what can I say except \n
```