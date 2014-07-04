#!/usr/bin/make -f
#
# Backup snapshots, based on rsync.
#
# usage:
# 	mkdir backup && cd backup
# 	echo "server:dir" > source
# 	snapshot-backup.mk
#
# 2007.2  Fengguang Wu <wfg@ustc.edu>
#

SRC	:= $(shell cat source)
DST	:= $(shell date +'%Y-%m-%d')
CURRENT	:= $(shell readlink current)
EXCLUDE	:= $(wildcard exclude)
FILES	:= $(wildcard files)

LINK_DEST	:= $(if $(CURRENT),--link-dest=../$(CURRENT))
EXCLUDE_FROM	:= $(if $(EXCLUDE),--exclude-from=$(EXCLUDE))
FILES_FROM	:= $(if $(FILES),--files-from=$(FILES))

RSYNC_OPTIONS	:= -av --delete --numeric-ids $(FILES_FROM) $(EXCLUDE_FROM) $(LINK_DEST)

backup:
	@test "$(SRC)"
	rsync $(RSYNC_OPTIONS) $(SRC) $(DST)
	rm -f current
	ln -s $(DST) current
