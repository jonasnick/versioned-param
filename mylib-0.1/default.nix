{ pkgs ? import <nixpkgs> {} }:

with pkgs;
stdenv.mkDerivation rec {
  pname = "mylib";

  version = "0.1";

  src = ./.;

  installPhase = ''
    mkdir -p $out/lib
    mkdir -p $out/include
    cp $src/include/* $out/include
    mv ${pname}-${version}.so $out/lib/lib${pname}.so
  '';
}
