{ pkgs ? import <nixpkgs> {} }:

rec {
  mylib-0_1 = pkgs.callPackage ./mylib-0.1 { };
  mylib-0_2 = pkgs.callPackage ./mylib-0.2 { };
  myapp-0_1 = pkgs.callPackage ./myapp-0.1 { mylib = mylib-0_1; };
}
