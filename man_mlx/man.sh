# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 13:11:20 by alalonzo          #+#    #+#              #
#    Updated: 2017/05/16 13:31:52 by alalonzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [ "$1" = "mlx" ]
then
	man ./mlx.1
elif [ "$1" = "loop" ]
then
	man ./mlx_loop.1
elif [ "$1" = "image" ]
then
	man ./mlx_new_image.1
elif [ "$1" = "window" ]
then
	man ./mlx_new_window.1
elif [ "$1" = "pixel" ]
then
	man ./mlx_pixel_put.1
else
	echo "\033[0;32musage: sh script.sh <argument>\033[0m"
	echo "\033[0;32mman disponibles : mlx, loop, image, window, pixel\033[0m"
	echo "\033[0;33mmlx_man scriptshell for teamfamilia42, by skaara @42\033[0m"
fi
