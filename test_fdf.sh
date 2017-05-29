echo "\033[01;32mGestion d'erreur\033[00m"
./fdf_staff
./fdf_staff nofile
./fdf_staff maps/pylone.fdf
./fdf_staff maps/map_vide.fdf
./fdf_staff maps/maps_onlyspaces.fdf

echo "\033[01;32mTests basiques\033[00m"
./fdf_staff maps/plat.fdf
./fdf_staff maps/basictest.fdf
./fdf_staff maps/pnp_flat.fdf
./fdf_staff maps/42.fdf
./fdf_staff maps/pentenegpos.fdf

echo "\033[01;32mTests moyens\033[00m"
./fdf_staff maps/10-2.fdf
./fdf_staff maps/50-4.fdf
./fdf_staff maps/pyra.fdf
./fdf_staff maps/elem.fdf

echo "\033[01;32mTests grande map\033[00m"
./fdf_staff maps/100-6.fdf
./fdf_staff maps/mars.fdf

echo "\033[01;32mTests altitude\033[00m"
./fdf_staff maps/10-70.fdf
./fdf_staff maps/20-60.fdf
./fdf_staff maps/elem2.fdf

echo "\033[01;32mTests couleurs\033[00m"
./fdf_staff maps/pyramide.fdf
./fdf_staff maps/elem-col.fdf

echo "\033[01;32mTests couleurs et altitude\033[00m"
./fdf_staff maps/t1.fdf
./fdf_staff maps/t2.fdf

echo "\033[01;32mTests fractales\033[00m"
./fdf_staff maps/julia.fdf
./fdf_staff maps/elem-fract.fdf
