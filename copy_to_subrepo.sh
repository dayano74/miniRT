#!/bin/bash

# this script copies files from the current directory to the new directory
# Usage: ./copy_to_subrepo.sh

echo -n "dir?>"
read input

mkdir -p $input \
&& cp -r bvh/ $input \
&& cp -r color/ $input \
&& cp -r error/ $input \
&& cp -r event/ $input \
&& cp -r free/ $input \
&& cp -r insec_point/ $input \
&& cp -r light/ $input \
&& cp -r libft/ $input \
&& cp -r parser/ $input \
&& cp -r scenes/ $input \
&& cp -r utils/ $input \
&& cp -r vector/ $input \
&& cp main.c $input \
&& cp minirt.h $input \
&& cp Makefile $input \

echo "output done!"
