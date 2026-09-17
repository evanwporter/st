{
	description = "st development workspace";

	inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
	inputs.flake-utils.url = "github:numtide/flake-utils";

	outputs = {
		self,
		nixpkgs,
		flake-utils,
	}:
		flake-utils.lib.eachDefaultSystem (
			system: let
				pkgs = nixpkgs.legacyPackages.${system};

				st =
					pkgs.stdenv.mkDerivation {
						pname = "st";
						version = "0.9.3";

						src = self;

						strictDeps = true;

						makeFlags = [
							"PKG_CONFIG=${pkgs.stdenv.cc.targetPrefix}pkg-config"
						];

						nativeBuildInputs = with pkgs; [
							pkg-config
							ncurses
						];

						buildInputs = with pkgs; [
							fontconfig
							freetype
							harfbuzz
							libx11
							libXcursor
							libxft
							libxinerama
							libnotify
						];

						preInstall = ''
							export TERMINFO=$out/share/terminfo
						'';

						installFlags = [
							"PREFIX=$(out)"
						];

						meta = {
							mainProgram = "st";
						};
					};
			in {
				packages = {
					inherit st;
					default = st;
				};

				apps = {
					st =
						flake-utils.lib.mkApp {
							drv = st;
							exePath = "/bin/st";
						};
				};

				devShells.default =
					pkgs.mkShell {
						inputsFrom = [
							st
						];

						packages = with pkgs; [
							bear
							clang-tools
							gnumake
							jq
							pkg-config
						];
					};
			}
		);
}
