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



;	Various equates not found in ti83plus.inc.

; ROM calls
_OffPageJump			.equ	$44F2
_FlashToRAM2			.equ	$8054
_FillBasePageTable		.equ	$5011
_GetAppBasePage			.equ	$50BC
_FindAppHeaderSubField	.equ	$80AB


; RAM locations used for temporary storage
MD5Temp					.equ	$8259
MD5Hash					.equ	$8292
MD5Length				.equ	$8269
