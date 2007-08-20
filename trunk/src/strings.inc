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




;	User interface string resources.

   ;     0123456789ABCEDF
titleHookman:
	.db "    HookMan     ",0
	
errLowMem:
	.db "There is insuf- "
	.db "ficient free RAM"
	.db "to complete the "
	.db "operation. Free "
	.db "at least 1KB of "
	.db "RAM and try     "
	.db "again. Press any"
	.db "key...",0
errBadVar:
	.db "The variable    "
	.db "         is in- " 	; that space will be filled in later
	.db "valid. Please   "	; with str_HMConfig, str_HMChains, or
	.db "delete it or re-"	; str_HMDatbas
	.db "name it if it is"
	.db "something you   "
	.db "need. Press any "
	.db "key...",0
errNoChain:
	.db "The hook chain  "
	.db "list variable   "
	.db "HMChains doesn't"
	.db "exist. Use Ad-  "
	.db "vanced, Chain   "
	.db "Editor first.   "
	.db "Press any key...",0

msgScanning:
	.db "Scanning instal-"
	.db "led hooks",0



msgHooksInstalled:
	.db "Hooks were installed:",0

msgHooksUninstalled:
	.db "Hooks were uninstalled:",0

msgChooseChain:
	.db "Choose hook chain to edit:",0
	
itemUninstall:	.db "Uninstall",0
itemInstall:	.db "Install",0
itemAdvanced:	.db "Advanced",0
itemHelp		.db "Help",0
itemAbout		.db "About",0
itemExit		.db "Exit",0
itemBack		.db "Back",0

txtCopyright	.db "Copyright (",$FF,"c) '07 Andy Janata",0


menuNumbers:
	.db "0)",0
	.db "1)",0
	.db "2)",0
	.db "3)",0
	.db "4)",0
	.db "5)",0
	.db "6)",0
	.db "7)",0
	.db "8)",0
	.db "9)",0


;	about screen


;	license and source code acquisition information text
licenseText:
	.db "This pr",$FF,"o",$FF,"gr",$FF,"am is fr",$FF,"e",$FF,"e softwar",$FF,"e;",0
	.db "y",$FF,"ou c",$FF,"an r",$FF,"edistribute it and/or",0
	.db "modify it under the terms of",0
	.db "the GNU Gener",$FF,"a",$FF,"l Pub",$FF,"lic Lic",$FF,"e",$FF,"nse",0
	.db "v2 or later. This program",0
	.db "comes WITHOUT ANY",0
	.db "WARRANTY. For details, see",0
	; should probably change this to http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt eventually
	; of course good luck making that fit
	.db "www",$FF,".gnu.",$FF,"or",$FF,"g",$FF,"/lic",$FF,"ens",$FF,"es/",$FF,"gp",$FF,"l.t",$FF,"x",$FF,"t",0
	.db "Press Enter for more.",0
	; second screen
	.db "Source code is available at",0
	;.db "c",$FF,"ode.goo",$FF,"gle.c",$FF,"om/p",$FF,"/hookman",0
	.db "hookman.googlecode.com",0
	.db "or by writing to Andy Janata,",0
	.db "178 E. 5th St, Brewster, OH,",0
	.db "44613, USA.",0
	.db "Press Enter to continue.",0


; appvars
; chain list
AV_HMChains:
	.db AppVarObj
str_HMChains:
	.db "HMChains",0		; that doesn't get in the way of Mov9ToOP1 :)
Sig_HMChains:
	.db "HMCL",0			; this is not a null-terminator: it is a version byte

; main config
AV_HMConfig:
	.db	AppVarObj
str_HMConfig:
	.db "HMConfig",0
Sig_HMConfig:
	.db "HMCF",0			; that is a version byte, not a null-terminator

; application database
AV_HMDatbas:
	.db AppVarObj
str_HMDatbas:
	.db "HMDatbas",0
Sig_HMDatbas:
	.db "HMDB",0			; version again
	
	
	
	