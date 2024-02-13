#include "so_long.h"

int is_valid_path(t_map *map_array, t_dimensions dimensions, int x, int y)
{
    if (x < 0 || y < 0 || x >= (int)dimensions.length || y >= (int)dimensions.breadth)
        return 0; // Out of bounds

    if (map_array->map_array[y][x] == '1')
        return 0; // Hit a wall

    if (map_array->map_array[y][x] == 'E')
        return 1; // Reached the exit

    if (map_array->map_array[y][x] != 'P' && map_array->map_array[y][x] != '0')
        return 0; // Invalid character

    // Mark the current position to avoid revisiting
    map_array->map_array[y][x] = 'V'; // 'V' for visited

    // Recursively check in all directions
    int result =
        is_valid_path(map_array, dimensions, x + 1, y) ||
        is_valid_path(map_array, dimensions, x - 1, y) ||
        is_valid_path(map_array, dimensions, x, y + 1) ||
        is_valid_path(map_array, dimensions, x, y - 1);

    // Reset the visited mark for backtracking
    map_array->map_array[y][x] = '0';

    return result;
}