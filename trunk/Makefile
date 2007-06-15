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

emulate2:
	$(WABBITEMU) bin/HookMan.8xk bin/testapp1.8xk bin/testapp2.8xk _local/calcsys.8xk > $(NULL) 2>&1

emulate3:
	$(WABBITEMU) bin/HookMan.8xk _local/omnicalc.8xk _local/ShortCut.8xk _local/calcsys.8xk > $(NULL) 2>&1

testing:
	spasm test/testapp1.z80 -I src
	spasm test/testapp2.z80 -I src
	wabbit test/testapp1.bin bin/testapp1.8xk
	wabbit test/testapp2.bin bin/testapp2.8xk

clean:
	-$(RM) src/hookman.bin src/hookman.inc bin/*.8xk test/testapp*.bin tilp.log
