# AutoCommandGenerator

## How to use

1. Build Project

   ![image](https://user-images.githubusercontent.com/53914190/130573257-4e21888c-5c6e-4455-afd0-c99f038645a2.png)

2. Add config - Rename config - TEMPLATE.txt to config.txt and add to build folder![image](https://user-images.githubusercontent.com/53914190/130573328-00a68505-57b5-4267-8d02-8c84353af42c.png)

3. Add input - Should be csv format without headers e.g.![image](https://user-images.githubusercontent.com/53914190/130573360-5a964382-31f8-4b4e-83c7-41a5c8adb733.png)

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

5. Run .exe - Should see an ahk file after running

   ![image](https://user-images.githubusercontent.com/53914190/130573391-f9083c86-40c1-4df6-a10b-77ac35de2acb.png)

6. Run output.ahk

7. Enter game and run keybind - Default ctrl + j

8. Done
