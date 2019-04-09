all:
	cd src; $(MAKE)

clean:
	cd src; $(MAKE) clean

install:
	mkdir /etc/simplepack
	cp bin/simplepack /usr/bin/simplepack
	cp conf/simplepack.conf /etc/simplepack/simplepack.conf

uninstall:
	rm /usr/bin/simplepack
	rm /etc/simplepack/simplepack.conf
	rm -r /etc/simplepack
