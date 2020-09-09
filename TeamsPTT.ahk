#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

; Teams Global Mute Toggle
F14::
if WinExist("ahk_exe Teams.exe") {
; Capture current active window so we can switch back later
WinGet, winID ,, A ; <-- need to identify window A = active

; Switch to Teams and send the mute toggle "<Ctrl><Shift>m"
WinActivate, ahk_exe Teams.exe
Sleep, 10
Send ^+m
Sleep, 10

; Switch back to the original active application
WinActivate, ahk_id %winID%
}
return