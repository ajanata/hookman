;    HookMan - System Hook Manager for TI-83+ Series.
;    Copyright (C) 2007  Andy Janata
;
;    This program is free software; you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation; either version 2 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License along
;    with this program; if not, write to the Free Software Foundation, Inc.,
;    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
;
;	 You can contact the author via electronic mail at <ajanata@gmail.com>,
;	 or by writing to Andy Janata, 178 E. 5th St., Brewster, OH 44613 USA.


;	Information about all of the hooks (name, addresses, etc.).


;	First, we define a natural number for every hook. This is used as an
;	offset into the LUT (below) and as an identifier in hook lists.

LinkActivityHook	.equ 0
CursorHook			.equ 1
RawKeyHook			.equ 2
GetCSCHook			.equ 3
HomescreenHook		.equ 4
WindowHook			.equ 5
GraphHook			.equ 6
YEquHook			.equ 7
FontHook			.equ 8
RegraphHook			.equ 9
GraphicsHook		.equ 10
TraceHook			.equ 11
ParserHook			.equ 12
AppChangeHook		.equ 13
Catalog1Hook		.equ 14
HelpHook			.equ 15
cxRedispHook		.equ 16
MenuHook			.equ 17
Catalog2Hook		.equ 18
TokenHook			.equ 19
LocalizeHook		.equ 20
SilentLinkHook		.equ 21
USBActivityHook		.equ 22


MAX_HOOK			.equ USBActivityHook

;	This LUT is in the same order as above.
HookInfoLUT:
	.dw LinkActivityHookInfo
	.dw CursorHookInfo
	.dw RawKeyHookInfo
	.dw GetCSCHookInfo
	.dw HomescreenHookInfo
	.dw WindowHookInfo
	.dw GraphHookInfo
	.dw YEquHookInfo
	.dw FontHookInfo
	.dw RegraphHookInfo
	.dw GraphicsHookInfo
	.dw TraceHookInfo
	.dw ParserHookInfo
	.dw AppChangeHookInfo
	.dw Catalog1HookInfo
	.dw HelpHookInfo
	.dw cxRedispHookInfo
	.dw MenuHookInfo
	.dw Catalog2HookInfo
	.dw TokenHookInfo
	.dw LocalizeHookInfo
	.dw SilentLinkHookInfo
	.dw USBActivityHookInfo



;	Now the actual data for the hook info blocks.
;	Format:
;		identification number (defined above) (byte)
;		4-byte block address (word)
;		hook active flag - byte address (byte - add to flags at runtime)
;		hook active flag - bitmask for bit (byte)
;		name - keep relatively short (null-terminated string)

LinkActivityHookInfo:
	.db LinkActivityHook
	.dw $9B78
	.db $33
	.db 1 << 4
	.db "Link Activity",0
	
CursorHookInfo:
	.db CursorHook
	.dw $9B7C
	.db $34
	.db 1 << 7
	.db "Cursor",0
	
RawKeyHookInfo:
	.db RawKeyHook
	.dw $9B84
	.db $34
	.db 1 << 5
	.db "RawKey",0
	
GetCSCHookInfo:
	.db GetCSCHook
	.dw $9B88
	.db $34
	.db 1 << 0
	.db "GetCSC",0

HomescreenHookInfo:
	.db HomescreenHook
	.dw $9B8C
	.db $34
	.db 1 << 4
	.db "Homescreen",0
	
WindowHookInfo:
	.db WindowHook
	.dw $9B90
	.db $35
	.db 1 << 2
	.db "Window",0

GraphHookInfo:
	.db GraphHook
	.dw $9B94
	.db $35
	.db 1 << 3
	.db "Graph",0

YEquHookInfo:
	.db YEquHook
	.dw $9B98
	.db $35
	.db 1 << 4
	.db "Y=",0

FontHookInfo:
	.db FontHook
	.dw $9B9C
	.db $35
	.db 1 << 5
	.db "Font",0

RegraphHookInfo:
	.db RegraphHook
	.dw $9BA0
	.db $35
	.db 1 << 6
	.db "Regraph",0

GraphicsHookInfo:
	.db GraphicsHook
	.dw $9BA4
	.db $35
	.db 1 << 7
	.db "Graphics",0

TraceHookInfo:
	.db TraceHook
	.dw $9BA8
	.db $36
	.db 1 << 0
	.db "Trace",0
	
ParserHookInfo:
	.db ParserHook
	.dw $9BAC
	.db $36
	.db 1 << 1
	.db "Parser",0

AppChangeHookInfo:
	.db AppChangeHook
	.dw $9BB0
	.db $36
	.db 1 << 2
	.db "App Change",0

Catalog1HookInfo:
	.db Catalog1Hook
	.dw $9BB4
	.db $36
	.db 1 << 3
	.db "Catalog 1",0

HelpHookInfo:
	.db HelpHook
	.dw $9BB8
	.db $36
	.db 1 << 4
	.db "Help",0

cxRedispHookInfo:
	.db cxRedispHook
	.dw $9BBC
	.db $36
	.db 1 << 5
	.db "cxRedisp",0
	
MenuHookInfo:
	.db MenuHook
	.dw $9BC0
	.db $36
	.db 1 << 6
	.db "Menu",0

Catalog2HookInfo:
	.db Catalog2Hook
	.dw $9BC4
	.db $34
	.db 1 << 6
	.db "Catalog 2",0

TokenHookInfo:
	.db TokenHook
	.dw $9BC8
	.db $35
	.db 1 << 0
	.db "Token",0

LocalizeHookInfo:
	.db LocalizeHook
	.dw $9BCC
	.db $35
	.db 1 << 1
	.db "Localize",0

SilentLinkHookInfo:
	.db SilentLinkHook
	.dw $9BD0
	.db $36
	.db 1 << 7
	.db "Silent Link",0

USBActivityHookInfo:
	.db USBActivityHook
	.dw $98D4
	.db $3A
	.db 1 << 0
	.db "USB Activity",0
