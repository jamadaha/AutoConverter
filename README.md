# AutoCommandGenerator

## Requirements

* Windows OS - See AutoHotkey requirement for why.

* [CMake](https://cmake.org/)

* [AutoHotkey](https://www.autohotkey.com/) - This is not used for compiling, but the program outputs in .ahk format. This is a format which AutoHotkey uses. (Doesn't seem to be available on Linux)

## How to use
### AHK generator
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

5. Run .exe - Should see an .ahk file after running

   ![image](https://user-images.githubusercontent.com/53914190/130573391-f9083c86-40c1-4df6-a10b-77ac35de2acb.png)

6. Run output.ahk

7. Enter game and run keybind - Default ctrl + j

8. Done

### GM log formatter
1. Build Project

   ![image](https://user-images.githubusercontent.com/53914190/130573257-4e21888c-5c6e-4455-afd0-c99f038645a2.png)

2. Add config - Rename config - TEMPLATE.txt to config.txt and add to build folder ![image](https://user-images.githubusercontent.com/53914190/130573328-00a68505-57b5-4267-8d02-8c84353af42c.png)
3. Add input - Should be a GM log e.g.                 
   ![image](https://user-images.githubusercontent.com/53914190/130573360-5a964382-31f8-4b4e-83c7-41a5c8adb733.png)

   ```
   2021-08-24_18:02:25 INFO  [commands.gm] Command: .go o 1 [Player: Testhunter (GUID Full: 0x0000000000000002 Type: Player Low: 2) (Account: 11) X: 1299.535522 Y: 319.459656 Z: -58.974792 Map: 0 (Eastern Kingdoms) Area: 1497 (Undercity) Zone: Unknown Selected:  (GUID Full: 0x0000000000000000 Type: None Low: 0)]
   2021-08-24_18:02:26 INFO  [commands.gm] Command: .gps [Player: Testhunter (GUID Full: 0x0000000000000002 Type: Player Low: 2) (Account: 11) X: -959.702026 Y: -3739.060059 Z: 5.662160 Map: 1 (Kalimdor) Area: 392 (Ratchet) Zone: The Barrens Selected:  (GUID Full: 0x0000000000000000 Type: None Low: 0)]
   2021-08-24_18:02:27 INFO  [commands.gm] Command: .go o 2 [Player: Testhunter (GUID Full: 0x0000000000000002 Type: Player Low: 2) (Account: 11) X: -959.702026 Y: -3739.060059 Z: 5.662160 Map: 1 (Kalimdor) Area: 392 (Ratchet) Zone: The Barrens Selected:  (GUID Full: 0x0000000000000000 Type: None Low: 0)]
   2021-08-24_18:02:28 INFO  [commands.gm] Command: .gps [Player: Testhunter (GUID Full: 0x0000000000000002 Type: Player Low: 2) (Account: 11) X: -7826.899902 Y: -1851.920044 Z: 128.527603 Map: 0 (Eastern Kingdoms) Area: 250 (Ruins of Thaurissan) Zone: Burning Steppes Selected:  (GUID Full: 0x0000000000000000 Type: None Low: 0)]
   ```
4. Run .exe - Should see a .csv file after running   
   ![image](https://user-images.githubusercontent.com/53914190/130686255-1f5b2a50-03f4-4490-bb00-be87df6e9f5b.png)
5. Done
