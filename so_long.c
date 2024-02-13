#include "so_long.h"





int main(int ac, char **av)
{
    if(ac != 2)
    {
       ft_printf("Error: <usage> <so_long> <.ber-file>\n");
           return 0;
    }
    if (berfile(av[1]))
    {
        t_dimensions map_dimensions = get_map_dimensions(av[1]);
		t_map *map_array = get_map_array(av[1], map_dimensions);
		//(void)map_array;
		if (is_valid_map(map_array, map_dimensions))
		{	
			ft_printf("map is valid\n");
		}
		else{
			ft_printf("not valida\n");
		}
        // //printf("Map Dimensions:\nLength: %zu\nBreadth: %zu\n", map_dimensions.length, map_dimensions.breadth);

        // ft_printf("it is a valid .ber file\n");

    }
   
}

