							String Substitution

- For this project the focus was on combining algorithm development within an object-oriented frame-
work. 
- The task is string substitution within a file while minimizing memory usage.

Application requirements:
- The string substitution must happen inline. That is, no temporary files. Each byte is read
once from the file and (if required) written back to the file.
- The algorithm must work in a single pass, reading from the beginning of the file to the end
of the file.
- The file can only be opened one time. Both reading and writing must be done on the open
file using the same fstream object.
- The algorithm must minimize the use of memory. That is, you cannot simply read the file
into memory, manipulate it, and write it all out again. By default, a single byte buffer is
allowed (if desired). A larger buffer is only allowed if newstring is longer than oldstring. The
buffer is only allowed to grow when writing out a larger newstring requires it.
