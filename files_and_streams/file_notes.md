## FILES AND STREAMS
    
- In c++ a file is represented by a sequence of bytes with a filename

- File interactions are represented byy fstream objects
    - access files sequentially
        - a sequence in order of bytes
    - fstream operations
        - open
        - read
        - write
        - close
    - fstream will call a function in the OS API
    - program will stop and wait while the operation is performed
    - good practice to close files when you use them

- as data passes between the program and the file, it may be temporarily stored in a memory buffer
    - makes large data transfers more efficient but less timely


## File Streams

- iostream
    - ostream (cout)
    - istream (cin)

- fstream
    - ofstream - writing
    - ifstream - reading

- easiest way to open file is pass name to ifstream 
`ifstream ifile{"text.txt"}`
- should check the stream's state before using it
```
if (ifile)
    cout << "Success!!";
```

- we can use ifile the same way as a cin
```
while (ifile >> text)
    cout << text << ",";
```
- This reads one word at a time, no whitespace