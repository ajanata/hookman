default:
	spasm src/hookman.z80 -I src
	wabbit src/hookman.bin bin/HookMan.8xk

install:
	tilp --no-gui bin/HookMan.8xk > tilp.log
