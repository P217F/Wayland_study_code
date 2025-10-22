PKGFLAGS=$(shell pkg-config --cflags --libs wlroots-0.20 wayland-server wayland-client libinput xkbcommon)
%: src/%.c
	@rm -rf build
	@mkdir -p build
	@gcc -Wall -Wextra -Wpedantic -std=c23 -O2 $< -o build/$@ $(PKGFLAGS)