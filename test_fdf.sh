echo "\033[01;32mGestion d'erreur\033[00m"
./fdf
./fdf maps/plat.fdf maps/basictest.fdf
./fdf nofile
./fdf maps/wrong_map.fdf
./fdf maps/map_vide.fdf
./fdf maps/maps_onlyspaces.fdf

echo "\033[01;32mTests basiques\033[00m"
./fdf maps/plat.fdf
./fdf maps/basictest.fdf
./fdf maps/pnp_flat.fdf
./fdf maps/42.fdf
./fdf maps/pentenegpos.fdf

echo "\033[01;32mTests moyens\033[00m"
./fdf maps/10-2.fdf
./fdf maps/50-4.fdf
./fdf maps/pyra.fdf
./fdf maps/elem.fdf

echo "\033[01;32mTests grande map\033[00m"
./fdf maps/100-6.fdf
./fdf maps/mars.fdf

echo "\033[01;32mTests altitude\033[00m"
./fdf maps/10-70.fdf
./fdf maps/20-60.fdf
./fdf maps/elem2.fdf

echo "\033[01;32mTests couleurs\033[00m"
./fdf maps/pyramide.fdf
./fdf maps/elem-col.fdf

echo "\033[01;32mTests couleurs et altitude\033[00m"
./fdf maps/t1.fdf
./fdf maps/t2.fdf

echo "\033[01;32mTests fractales\033[00m"
./fdf maps/julia.fdf
./fdf maps/elem-fract.fdf
