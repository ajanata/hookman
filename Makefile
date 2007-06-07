WABBITEMU = wine ../wabbitemu/wabbitemu.exe
NULL = /dev/null
# Or for windows (untested!)
# WABBITEMU = wabbitemu
# NULL = nul

default:
	spasm src/hookman.z80 -I src
	wabbit src/hookman.bin bin/HookMan.8xk

listing:
	spasm src/hookman.z80 -L -I src

install:
	tilp --no-gui bin/HookMan.8xk > tilp.log

emulate:
	$(WABBITEMU) bin/HookMan.8xk > $(NULL) 2>&1

clean:
	-$(RM) src/hookman.bin src/hookman.inc bin/hookman.8xk tilp.log
