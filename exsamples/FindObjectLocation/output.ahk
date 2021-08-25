#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.; #Warn  ; Enable warnings to assist with detecting common errors.SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
^j::
SEND, {enter} 
SLEEP 20 
SEND, .go o 1 
SLEEP 20 
SEND, {enter} 
SLEEP 1500 
SEND, {enter} 
SLEEP 20 
SEND, .gps 
SLEEP 20 
SEND, {enter} 
SEND, {enter} 
SLEEP 20 
SEND, .go o 2 
SLEEP 20 
SEND, {enter} 
SLEEP 1500 
SEND, {enter} 
SLEEP 20 
SEND, .gps 
SLEEP 20 
SEND, {enter} 
