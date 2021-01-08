{ pkgs ? import <nixpkgs> {} }:

rec {
  mylib-0_1 = pkgs.callPackage ./mylib-0.1 { };
  mylib-0_2 = pkgs.callPackage ./mylib-0.2 { };
  myapp-0_1 = pkgs.callPackage ./myapp-0.1 { mylib = mylib-0_1; };
  myapp-0_2 = pkgs.callPackage ./myapp-0.2 { mylib = mylib-0_2; };
  test = pkgs.runCommandLocal "test" {} ''
    mkdir $out
    cp ${myapp-0_1}/bin/myapp $out/myapp-0.1

    echo App 0.1 linked to lib 0.1
    $out/myapp-0.1
    echo

    chmod +w $out/myapp-0.1
    patchelf --replace-needed libmylib.so ${mylib-0_2}/lib/libmylib.so $out/myapp-0.1
    echo App 0.1 linked to lib 0.2
    $out/myapp-0.1
    echo

    cp ${myapp-0_2}/bin/myapp $out/myapp-0.2
    echo App 0.2 linked to lib 0.2
    $out/myapp-0.2
    echo

    chmod +w $out/myapp-0.2
    patchelf --replace-needed libmylib.so ${mylib-0_1}/lib/libmylib.so $out/myapp-0.2
    echo App 0.2 linked to lib 0.1
    $out/myapp-0.2
    echo
  '';
}
