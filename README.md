# AutoCommandGenerator

## How to use

1. Build Project

   ![image-20210824090143689](C:\Users\O\AppData\Roaming\Typora\typora-user-images\image-20210824090143689.png)

2. Add config - Rename config - TEMPLATE.txt to config.txt and add to build folder![image-20210824090258193](C:\Users\O\AppData\Roaming\Typora\typora-user-images\image-20210824090258193.png)

3. Add input - Should be csv format without headers e.g.![image-20210824090614248](C:\Users\O\AppData\Roaming\Typora\typora-user-images\image-20210824090614248.png)

   ```
   81765	16343	0	0
   81921	16343	0	0
   81922	16343	0	0
   81923	16343	0	0
   82046	16343	0	0
   82047	16343	0	0
   82072	16343	0	0
   82086	16343	0	0
   82087	16343	0	0
   82088	16343	0	0
   82090	16343	0	0
   ```

4. Add command structure to config e.g.

   ```
   Commands
   -{enter}
   _SLEEP 20
   -.go o $0
   _SLEEP 20
   -{enter}
   _SLEEP 1500
   -{enter}
   _SLEEP 20
   -.gps
   _SLEEP 20
   -{enter}
   ```

   Formatting can be found in config

5. Run .exe

   ![image-20210824091048281](C:\Users\O\AppData\Roaming\Typora\typora-user-images\image-20210824091048281.png)

6. Run output.ahk

7. Enter game and run keybind

8. Done