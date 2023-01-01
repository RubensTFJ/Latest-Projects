/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:00:19 by rteles-f          #+#    #+#             */
/*   Updated: 2022/12/29 20:41:11 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	end_img_list()
{
	return ;
}

int	end_game(t_vars *vars)
{
	end_img_list(*img_list());
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, sprite()->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(map());
	exit(0);
	return (0);
}

exe	*define_move(void)
{
	exe	*function;

	return (function);
}

int	update(t_vars *vars)
{
	movement(vars);
	(void *)vars;
	return (0);
}

t_data	*blank(void)
{
	static t_data	blank;
	
	return (&blank);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iterate;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		iterate = *lst;
		while (iterate->next)
			iterate = iterate->next;
		iterate->next = new;
	}
}

void	init_objects(t_vars *vars, t_infomap *map)
{
	create_object("sprites/ground.xpm", vars, map->map[i][j]);
	create_object("sprites/swimmer.xpm", vars, map->map[i][j]);
	create_object("sprites/enemy.xpm", vars, map->map[i][j]);
}

void	clear_trail(t_vars *vars, t_object *obj)
{
	int	i;
	int	j;

	i = (int)(obj->x - 1);
	while (i < (int)(obj->x + 1))
	{
		j = (int)(obj->y - 1);
		while (i < (int)(obj->x + 1))
			paint_texture(vars, obj->data, i, j);
	}
	obj->
	return ;
}

void	create_object(char *path, t_vars *vars, int id)
{
	t_list	*node;
	
	node = calloc(sizeof(t_list), 1);
	set_new_object(node);
	node->obj.id = id;
	node->obj.data.img = mlx_xpm_file_to_image(vars->mlx, path, &node->obj.data.width, node->obj.data.height);
	node->obj.data.addr = mlx_obj_data_addr(node->obj.data.img, node->obj.data.bits_per_pixel, node->obj.data.line_length, node->obj.data.endian);
	if (id != 1 || id != 0)
	{
		node->obj.trail = clear_trail;
		node->obj.new_pos = movement;
	}
	ft_lstadd_back(obj_list(), node);
}

t_object	**this(void)
{
	t_object	*element;

	return (&element);
}

t_object	*get_object(t_list *list, int tifier)
{
	while (list->obj.id != tifier)
		list = list->next;
	*this() = (&(list->obj));
	return (&(list->obj));
}

void	do_nothing(t_vars *vars)
{
	return ;
}

void	set_new_object(t_object *obj)
{
	obj->id = -1;
	obj->x = -1;
	obj->y = -1;
	obj->new_pos = do_nothing;
	obj->trail = do_nothing;
	obj->animation = 0;
	obj->data.addr = 0;
	obj->data.bits_per_pixel = 0;
	obj->data.endian = 0;
	obj->data.img = 0;
	obj->data.line_length = 0;
	obj->data.height = 0;
	obj->data.width = 0;
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_down, &vars);
	mlx_hook(vars->win, 3, 1L << 1, key_up, &vars);
	mlx_loop_hook(vars->mlx, update, &vars);
}

void	test_canvas(t_vars *vars, t_list *image, int xl, int yl)
{
	int	i;
	int	j;

	i = 0;
	while (i < xl)
	{
		j = 0;
		while (j < yl)
		{
			put_ground(vars, &(image->obj.data), i, j);
		}
	}
}

void	make_frame(t_infomap *map, t_vars *vars, t_list *list)
{
	while (list)
	{
		list->obj.trail(vars, get_object(*obj_list(), '1'));
		list->obj.new_pos(vars, &(list->obj));
		paint_obj(list->obj);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	static t_vars	vars;

	if (!check_map(argv[1], init_mapstruct(map())))
		return (0);
	player()->x = map()->pstart[0];
	player()->y = map()->pstart[1];
	vars.mlx = mlx_init();
	init_hooks(&vars);
	vars.win = mlx_new_window(vars.mlx, (map()->width_x * SCALE), (map()->height_y * SCALE), "Hello world!");	
	vars.img.img = mlx_new_image(vars.mlx, (map()->width_x * SCALE), (map()->height_y * SCALE));
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	make_frame(map(), &vars, *obj_list());
	init_images(&vars);
	test_canvas(&vars, *img_list(), map()->width_x, map()->height_y);
}
	// (sprite()->img) = mlx_xpm_file_to_image(vars.mlx, "sprites/swimmer.xpm", &sprite()->width, &sprite()->height);
	// sprite()->addr = mlx_get_data_addr(sprite()->img, &sprite()->bits_per_pixel, &sprite()->line_length, &sprite()->endian);
	// mlx_loop(vars.mlx);

	// vars.win = mlx_new_window(vars.mlx, (map()->height_y * 63), 
	//(map()->width_x * 63) , "Hello world!");
// void	do_nothing(t_vars *vars)
// {
// 	return ;
// }

// exe	*t(void)
// {
// 	static exe	f[2] = {
// 		do_nothing,
// 		end_game		
// 	};

/*
	mlx_init
	
	mlx_put_image_to_window
	mlx_xpm_file_to_image
	mlx_destroy_image
	mlx_xpm_to_image
	mlx_new_image
	mlx_pixel_put
	
	mlx_destroy_display
	mlx_clear_window
	mlx_new_window
	
	mlx_do_sync
	
	
	mlx_get_color_value
	mlx_get_screen_size
	mlx_get_data_addr
	
	mlx_do_key_autorepeatoff
	mlx_do_key_autorepeaton
	
	mlx_expose_hook
	mlx_key_hook
	mlx_hook
	
	mlx_loop_end
	mlx_loop
	
	mlx_mouse_get_pos
	mlx_mouse_hide
	mlx_mouse_hook
	mlx_mouse_move
	mlx_mouse_show
	
	mlx_string_put
	mlx_set_font
	MLX_H

*/