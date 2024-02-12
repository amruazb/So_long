#include "so_long.h"





int main(int ac, char **av)
{
    if(ac != 2)
    {
       ft_printf("Error:<usage><so_long><ber-file>\n");
           return 0;
    }
    if (berfile(av[1]))
    {
        t_dimensions map_dimensions = get_map_dimensions(av[1]);
		get_map_array(av[1], map_dimensions);
        // printf("Map Dimensions:\nLength: %zu\nBreadth: %zu\n", map_dimensions.length, map_dimensions.breadth);

        ft_printf("it is a valid ber file\n");

    }
   
}

