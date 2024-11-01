

project_name := PROJ123456
uvproj_path := .
day_version := 99
.PHONY: default build cformat format clean flash debug assets

# Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser

default: macro2path build path2macro

.PHONY: dist clear

clear:
	@echo clear
	@- rmdir /Q /S "./_build"

dist:
	make
	./utils_bin/tcc/tcc.exe .\utils_bin\tcc\sha1\sha1.c -run .\utils_bin\dist.c $(day_version) WELCOME

build:
	@echo $(SHELL)
	@echo [START]----- UV build -----
	tcc -run main.c
	@echo [ END ]----- UV build ----



format:
	@echo Astyle source code format
	./utils_bin/astyle.exe --project="./utils_bin/.astylerc" -r **.c,**.h --ignore-exclude-errors --exclude=_build --exclude=utils_bin --exclude=dist --exclude=utils -v -Q

assets:
	@echo Create Assets
	./utils_bin/p2a-win-amd64.exe -in ./assets/UI -out ./modules/assets

