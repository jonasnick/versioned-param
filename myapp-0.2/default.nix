{ stdenv, mylib }:

stdenv.mkDerivation {
  name = "myapp";

  version = "0.2";

  buildInputs = [ mylib ];

  src = ./.;

  LD_LIBRARY_PATH = "${mylib}/lib";
  shellHook = ''
    export LD_LIBRARY_PATH = "${mylib}/lib";
    echo $LD_LIBRARY_PATH
  '';
  makeFlags = [ "LD_LIBRARY_PATH=${mylib}/lib" ];

  installPhase = ''
    mkdir -p $out/bin
    mv myapp $out/bin/
  '';
}
