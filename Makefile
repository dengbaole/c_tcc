

format:
	@echo Astyle source code format
	./utils_bin/astyle.exe --project="./utils_bin/.astylerc" -r **.c,**.h --ignore-exclude-errors --exclude=_build --exclude=utils_bin --exclude=dist --exclude=utils -v -Q



build:
	@echo [START]-----  build -----
	@tcc -run main.c
	@echo [ END ]-----  build -----
clean:
	@rm -rf a.out
	@echo chean success