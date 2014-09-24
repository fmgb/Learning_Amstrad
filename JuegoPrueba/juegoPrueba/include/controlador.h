#ifndef CONTROLADOR_H
#define CONTROLADOR_H

unsigned int
elegirOpcion() {
	while(1) {
		if(cpc_TestKey(11)) {
			printf("Pulsado 1");
			return 1;
		}
		else if(cpc_TestKey(12)) {
			printf("Pulsado 2");
			return 2;
		}
		else if(cpc_TestKey(13)) {
			printf("Pulsado 3");
			return 3;
		}
		else if(cpc_TestKey(14)) {
			printf("Pulsado 4");
			return 4;
		}else if(cpc_TestKey(15)) {
			return 5;
		}
	}

}

#endif
