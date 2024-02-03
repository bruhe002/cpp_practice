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

- easiest way to open file is pass name to ifstream constructor: 
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
- `getline()` function will read the file by line, not word


## Buffering
- minimizes calls to OS
- flushes the buffer to the target object
    - flushes depend on streams using them
        - ostream depends on terminal configuration
    - no direct way to flush input streams
`std::flush` allows us to control when the stream's buffer is flushed
    - all data in buffer is immediately sent to destination

## Unbuffered input and output
- some operations where stream buffering is not suitable
    - e.g. a network application
        - data must be transmitted in "packets" if a specified size
    - c++ lower level operations on streams / communicating directly with hardware
        - bypass buffer
`get()` reads a single character
`put()` writes a single character
- for more than one character use `read()` and `write()` member functions
    - must provide out own buffer
    - takes two arguments - address of buffer, bufferSize

## File Nodes
- c++ has a number of options for opening a file - called "modes"
    - files are opened by default in **text mode**
    - output files are opened by default in **truncate mode**
        - new data will overwrite current contents of the file
    - **append mode** does not do ^^ that `ofile.open("important.txt", fstream::app)`
        - adds new content to end of old data
    - **binary mode** - data sotred in file will be identical to the data in memory
        - complicated
        - lowlevel
        - needed to work with file formats
- can combine different modes by using vertical line '|'
