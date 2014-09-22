#################################################
#
# This file is part of RA_Amstrad.
# RA_Amstrad is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# RA_Amstrad is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with RA_Amstrad. If not, see <http://www.gnu.org/licenses/>.
#
#################################################

# Variables

CC=sdcc
OBJECT_DIR=.obj/
CFLAGS=-o $(OBJECT_DIR) -mz80 --code-loc 0x0138 --data-loc 0 --no-std-crt0 crt0_cpc.rel putchar_cpc.rel
CPCTELERA=-lcpctelera.lib
SOURCE_NAME=main
DIR_EJEM=HolaMundo/ PintandoPantalla/
GAME_NAME=$(SOURCE_NAME)

##################################################

# Targets
all: directorios clean
directorios:
	make -C ${DIR_EJEM}

clean:
	rm -rf crt0_cpc.rel putchar_cpc.rel $(OBJECT_DIR)
