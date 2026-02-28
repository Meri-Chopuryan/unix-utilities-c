# Unix Utilities in C (wc + uniq)

## Overview
This repository contains C implementations of two common Unix command-line utilities:

- `word_count` — a simplified version of `wc` that counts lines, words, and characters
- `unique` — a simplified version of `uniq` that prints only one instance of consecutive duplicate lines

Both programs support reading from a file passed as a command-line argument or from standard input.

## Programs

### 1) word_count (`wc`-style)
**Features**
- Counts lines, words (whitespace-delimited), and characters
- Reads from a file or stdin
- Processes input one character at a time

**Run**
```bash
make
./word_count <optional_filename>
