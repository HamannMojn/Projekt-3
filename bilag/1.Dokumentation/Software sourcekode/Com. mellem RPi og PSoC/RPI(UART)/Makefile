
CXXFLAGS=-Wall -I.

all: RPIserialCom

RPIserialCom: RPIserialCom.c
	@arm-rpizw-g++ $(CXXFLAGS) RPIserialCom.c -o RPIserialCom
	@chmod 777 RPIserialCom

.PHONY: clean
clean:
	@echo Removing executables...
	@rm -f RPIserialCom
	@echo Done