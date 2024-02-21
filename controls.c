/* 
#include "so_long.h"

void move_player_left(t_game *map_array)
{
    if (map_array->map_array[map_array->player_y][map_array->player_x - 1] != '1')
    {
        map_array->map_array[map_array->player_y][map_array->player_x] = '0';
        map_array->player_x -= 1;
        map_array->map_array[map_array->player_y][map_array->player_x] = 'P';
    }
}

void move_player_down(t_game *map_array)
{
    if (map_array->map_array[map_array->player_y + 1][map_array->player_x] != '1')
    {
        map_array->map_array[map_array->player_y][map_array->player_x] = '0';
        map_array->player_y += 1;
        map_array->map_array[map_array->player_y][map_array->player_x] = 'P';
    }
}

void move_player_right(t_game *map_array)
{
    if (map_array->map_array[map_array->player_y][map_array->player_x + 1] != '1')
    {
        map_array->map_array[map_array->player_y][map_array->player_x] = '0';
        map_array->player_x += 1;
        map_array->map_array[map_array->player_y][map_array->player_x] = 'P';
    }
}

void move_player_up(t_game *map_array)
{
    if (map_array->map_array[map_array->player_y - 1][map_array->player_x] != '1')
    {
        map_array->map_array[map_array->player_y][map_array->player_x] = '0';
        map_array->player_y -= 1;
        map_array->map_array[map_array->player_y][map_array->player_x] = 'P';
    }
}

int key_controls(int keycode, void *param)
{
	
    t_game *map_array = (t_game *)param;


    if (map_array == NULL) {
        ft_printf("Error: map_array is NULL\n");
        return (0);
    }

    if (keycode == 53)
    {
        ft_printf("Exit game\n");
        exit(0);
    }
    else if (keycode == 0)
    {
        ft_printf("Move left\n");
        if (map_array->player_x > 0) 
		{
            move_player_left(map_array);
        }
    }
    else if (keycode == 1)
    {
        ft_printf("Move down\n");
        if (map_array->player_y < map_array->dimensions.breadth - 1) 
		{
            move_player_down(map_array);
        }
    }
    else if (keycode == 2)
    {
        ft_printf("Move right\n");
        if (map_array->player_x < map_array->dimensions.length - 1) {
            move_player_right(map_array);
        }
    }
    else if (keycode == 13)
    {
        ft_printf("Move up\n");
        if (map_array->player_y > 0) 
		{
            move_player_up(map_array);
        }
    }

    return (0);
}

 */