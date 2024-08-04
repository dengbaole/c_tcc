



build:
	@echo $(SHELL)
	@echo [START]----- UV build -----
	tcc -run main.c
	@echo [ END ]----- UV build ----
clean:
	@rm -rf a.out
	@echo chean success