NAME = Valeria
SURNAME = BoschPerez
PROJECT_NAME = CyA-P02-2526
PRACTICE = p02

DIR_PATH=$(shell realpath .)
DIR_NAME=$(shell basename $(DIR_PATH))

cmake:
	cmake -S . -B build

build: cmake
	cd build; make

clean:
	rm -rf build

reload:
	make clean
	make build

git:
	git add .
	git commit -m "Quick commit"
	git push

tar: 
	git archive --format=tar.gz -o $(PROJECT_NAME)-$(PRACTICE)-$(NAME)$(SURNAME).tar.gz HEAD