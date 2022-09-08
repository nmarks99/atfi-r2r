# ATFI R2R
Software for ATFI IRAD Subscale Roll-to-Roll system. This repo
currently contains Arduino firmware for the load cell 
which reads/monitors the roller force in the subscale R2R system.

## Usage 
If you need to modify the code or flash it to another board,
first install [https://platformio.org/](PlatformIO). Then download 
the code in this repo by either downloading it as a .zip file by 
clicking the green code button at the top right of the page, or 
by cloning the repo with git by running the following:
```
git clone https://github.com/nmarks99/atfi-r2r
```

Flash the code as you would with any other PlatformIO project. If you are 
using the PlatformIO extension for VScode, click the upload button at the 
bottom left of the editor.
To do this from the command line, ensure the pio executable is on your path and run
```
pio run --target upload 
```
