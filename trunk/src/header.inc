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
;	  You can contact the author via electronic mail at <ajanata@gmail.com>,
;	  or by writing to Andy Janata, 178 E. 5th St., Brewster, OH 44613 USA.

;Field: Program length
	.DB 080h,0Fh
;Length=0 (N/A for unsigned apps)
	.DB 00h,00h,00h,00h
;Field: Program type
	.DB 080h,012h
	.DB 01h,04h
;Field: App ID
	.DB 080h,021h
;Id = 1
	.DB 01h
;Field: App Build
	.DB 080h,031h
	; version 0.1
	.DB 001h
;Field: App Name
	.DB 080h,048h
;App Name = APPNAME
	.DB "AHookMan"
;Field: App Pages
	.DB 080h,081h
;App Pages = 1
	.DB 01h
;No default splash screen
	.DB 080h,090h
;Field: Date stamp - 5/12/1999
	.DB 003h,026h,009h,004h,004h,06fh,01bh,080h
;Dummy encrypted TI date stamp signature
	.DB 002h ,00dh ,040h                             
	.DB 0a1h ,06bh ,099h ,0f6h ,059h ,0bch ,067h 
	.DB 0f5h ,085h ,09ch ,009h ,06ch ,00fh ,0b4h ,003h ,09bh ,0c9h 
	.DB 003h ,032h ,02ch ,0e0h ,003h ,020h ,0e3h ,02ch ,0f4h ,02dh 
	.DB 073h ,0b4h ,027h ,0c4h ,0a0h ,072h ,054h ,0b9h ,0eah ,07ch 
	.DB 03bh ,0aah ,016h ,0f6h ,077h ,083h ,07ah ,0eeh ,01ah ,0d4h 
	.DB 042h ,04ch ,06bh ,08bh ,013h ,01fh ,0bbh ,093h ,08bh ,0fch 
	.DB 019h ,01ch ,03ch ,0ech ,04dh ,0e5h ,075h 
;Field: Program Image length
	.DB 80h,7Fh
	.DB 0,0,0,0    ;Length=0, N/A
	.DB 0,0,0,0    ;Reserved
	.DB 0,0,0,0    ;Reserved
	.DB 0,0,0,0    ;Reserved
	.DB 0,0,0,0    ;Reserved