{ pkgs }: {
	deps = [
   pkgs../test
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}