valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --error-limit=no --suppressions=./valgrind-mlx.supp --gen-suppressions=all --track-fds=yes ./cub3d $1
