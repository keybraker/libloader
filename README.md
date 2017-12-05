# Simultaneous Progress Bars

The best way to make loading/progress bars without any extra library in C++

## Explanation for comprehension 

1. LoadingBar.cpp :
   
   Loading bar, are moving dots representing progress.
   Percentage, alongside time is shown and dynamically 
   changed from seconds to minutes

   ```
      make loading
   ```

2. progressBar.cpp :
   
   Progress bar, are expanding bars representing progress.
   Percentage, is also shown

   ```
      make progress
   ```

3. pingpongBar.cpp :
   
   Pingpong bar, is simulation of pingpong.
   Percentage, is also shown.

   ```
      make pingpong
   ```

## Run your program with the API
   
1.
   Include library on your_program.cpp
   ```
      #include "multibar.h"
      .
      .
      .

   ```

2.
* 2.1

   If implementation (libmultibar.so) is in the same path as your .cpp (your_program.cpp) simply execute:
   ```
      g++ -L./ -lmultibar your_program.cpp
   ```

* 2.2

   If you want to put the library on system directory library, execute
   command:
   ```
      export LD_LIBRARY_PATH=/path_to_lib_without_lib.so:$LD_LIBRARY_PATH
   ``` 

   And now that you have put the new library on the system path, compile your 
   new your_program.cpp with: 
   ```
      g++ -lmultibar your_program.cpp
   ```  
   if library is in the same path as you program
    