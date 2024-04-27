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
    - files are opened by default in *text mode*
    - output files are opened by default in *truncate mode*
        - new data will overwrite current contents of the file
    - *append mode* does not do ^^ that `ofile.open("important.txt", fstream::app)`
        - adds new content to end of old data
    - *binary mode* - data sorted in file will be identical to the data in memory
        - complicated
        - lowlevel
        - needed to work with file formats
- can combine different modes by using vertical line '|'

## Stream Member functions and States
`open()` - binds file name to a stream after it has been declared
    - if file does not exist it will be created

`is_open()` checks if the stream is opened

`good()`, `fail()`, `bad()` checks the files state

**NOTE** input streams do not support flush
- it does have an `ignore()` member function
    - 2 arguments
        - the maximum number of characters to remove
        - a delimiter character

## Stream Manipulators and Formatting
- a manipulator is something we can push on a stream
    - e.g. `flush` and `endl`
    - most are in iostream and iomanip
    - `boolalpha` is a manipulator that prints True and False 
        `cout << boolalpha << 9 == 10;`
- be default output streams do not format data

`setw()` is a manipulator 
    - will pad the output field to make it the width of the argument

`left` manipulator will make the output left-justified
    - yes there is a `right` manipulator

`setfill()` manipulator sets padding to a specific character

## Floating-point Output Formats
- default, fp numbers will be output to 6 significant figures
- sometimes followed by an exponent

`scientific` manipulator forces the stream to use scientific notation
- sticky - will maintain their behavior throughout the program
    - to reset use the mainpulator `defaultfloat`

`setprecision(#)` manipulator sets the precision of a stream

## Stringstreams
- basic c++ stream is represented by std::ios
- stringstreams are defined in `<sstream>`
    - it is a wrapper around std::string that makes it look like a stream
    - `ostringstream` contains an empty string object
        - store data in this string, use str() function to return a copy of it
```
string to_string(int i) {
    ostringstream os;
    os << i;
    return os.str();
}
```

- `istringstream` object uses copy of existing string
    - can read data from the string
    - validate input data
    - handle errors
    - bind the string object to an istringstream

- ostringstreams are useful when interfacing to systems that expect strings in a particular format
- istringstreams can be used with getline() to process input more easily

## Resource Management
- resources are used 
    - they need to be managed
        - allocate
        - release
        - error handling
- stdlib has some classes which manage resources
- fstream class encapsulates the details of how to manage a file
    - all we need to do is give a name
    - use << & >> operators
    - close files
- C++ classes manage resources through an idiom RAII - Resource Aquisition Is Initialization
    - The resource is stored as a private member variable
    - class constructor acquires the resource
    - public member functions control access to resource
    - class destructor releases the resource
- This is straightforward and deterministic
- only one object has access to the resource

## Random access to streams
- streams have a position marker
    - keeps track of where the next read or write data will take place
    - seek member functions can change the position of the marker
        - ex: seekg()
    - tell member functions can tgell you the position of the marker
        - ex: tellg()
- `std::ios_base` provides three global position markers
    - `::beg`, `::cur`, `::end`
- you can utilize these as a way to save your marker

## Stream iterators
- stdlib provides iterators that work on streams
    - all data in the stream must be the same type
    - in the `<iterator>` library
- very limited interface
- `ostream_iterator` must be bound to an output stream
```
ostream_iterator<int> oi (cout, "\n");

for (int i = -; i < 10; i++) {
    *oi = i;
    oi++;           // Does NOTHING
}
```
- istream iter works the same way
    - to read multiple input, you must loop
    - to stop reading, compare with an empty iterator
    
    `istream__iterator<string> eof;`

## Binary Files
- use binary mode to work with binary files
- shift operators are not suitable
- always use write() and read() with binary files
- file format has structure (.jpg .zip)
    - like headers and stuff
- best way to work with binary file is to create a struct whose data members correspond to the fields in the file format
- calls look like this

```
ofile.write(reinterpret_cast<char *>(&p), sizeof(point));
```

- modern hardware is optimized to be word aligned
    - in a 32-bit system, addresses are placed in multiples of four
- if a struct is not word aligned, compilers will usually add extra bytes
    - known as padding bytes
- `#pragma` directive will allow us to not follow modern alignment
- `alignas` keyword (C++11)
    - force compiler to align an element at a given offset

```
struct point {
    char c;
    alignas(4) int32_t x;       // Use 4 byte alignment for x
}
```

- bitmap is a simple image format
- image is made up of pixels
    - in bitmap format, each pixel consists of three bytes
    - one for each primary color
