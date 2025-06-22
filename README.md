# Cube3D

Je vous partage ici quelques notes prises au cours du développement du projet cub3d de l'école 42.

# Démonstration fonctionnement de la MiniLibX

## Code complet

```c
#include <stdio.h>
#include "mlx/mlx.h"
#include <stdlib.h>

#define WIN_LENGTH 1000
#define WIN_WIDTH 500

typedef struct s_data 
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_vars 
{
	void *mlx;
	void *win;
} t_vars;

typedef struct s_picture
{
	int value;

} t_picture;

typedef struct s_data_vars
{
	t_data		*data;
	t_vars		*vars;
	t_picture	*picture;

} t_data_vars;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void display_data (t_data img)
{
	printf("     void *img = %p\n", img.img);
	printf("    char *addr = %p\n", img.addr);
	printf("bits_per_pixel = %d\n", img.bits_per_pixel);
	printf("   line_length = %d\n", img.line_length);
	printf("        endian = %d\n", img.line_length);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int manage_OnKeydown(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
	{
		printf("Kycode = %d\n", keycode);
	}

	return (0);
}

int manage_MouseEvents(int keycode/*, t_vars *vars*/)
{
	printf("Mouse event = %d\n", keycode);
	return 0;
}

int render_next_frame (t_data_vars *data_vars)
{

	if (data_vars->picture->value == 400)
	{
		data_vars->picture->value = 0;
	}
	else
	{
		data_vars->picture->value += 1;
	}

	my_mlx_pixel_put(data_vars->data, data_vars->picture->value, data_vars->picture->value, 0x00FF0000);
	mlx_put_image_to_window(data_vars->vars->mlx, data_vars->vars->win, data_vars->data->img,0,0);

	//same but using sync
	//my_mlx_pixel_put(data_vars->data, data_vars->picture->value, data_vars->picture->value, 0x00FF0000);
	//mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data_vars->data->img);
	//mlx_put_image_to_window(data_vars->vars->mlx, data_vars->vars->win, data_vars->data->img,0,0);
	//mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, data_vars->vars->win);

	return 0;
}

int main()
{
	t_data		data;
	t_vars		vars;
	t_picture	picture;

	t_data_vars data_vars;

	data_vars.data = &data;
	data_vars.vars = &vars;
	data_vars.picture = &picture;

	picture.value = 1;

	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, WIN_LENGTH, WIN_WIDTH,"Window");

	data.img = mlx_new_image(vars.mlx, WIN_LENGTH, WIN_WIDTH);

	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	mlx_loop_hook(vars.mlx, render_next_frame, &data_vars);

	mlx_hook(vars.win, 2, 1L<<0, manage_OnKeydown, &vars);
	mlx_mouse_hook(vars.win, manage_MouseEvents, &vars);

	//display_data(data);

	mlx_loop(vars.mlx);

	return 0;
}
```

## Les structures :

### s_vars

```c
typedef struct s_vars 
{
	void *mlx;
	void *win;
} t_vars;
```

- mlx : Connexion avec la MinilibX
- win : Pointeur vers la fenêtre

### s_data

```c
typedef struct s_data 
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;
```

- img : pointeur vers l’emplacement mémoire de l’image
- addr : pointeur vers l’emplacement mémoire du premier pixel de l’image
- bits_per_pixel : nombre de bit nécessaire pour coder la couleur d’un pixel (= 32)
- line_length : longueur d’une ligne de l’image
- endian : ????

### s_picture

```c
typedef struct s_picture
{
	int value;
} t_picture;
```

Tous le nécessaire pour le rendu de l’image.

### s_data_vars

```c
typedef struct s_data_vars
{
	t_data		*data;
	t_vars		*vars;
	t_picture	*picture;

} t_data_vars;
```

Possède 3 pointeurs : un vers chaque type de structure

## Fonctions du main

```c
	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, WIN_LENGTH, WIN_WIDTH,"Window");

	data.img = mlx_new_image(vars.mlx, WIN_LENGTH, WIN_WIDTH);

	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	mlx_loop_hook(vars.mlx, render_next_frame, &data_vars);

	mlx_hook(vars.win, 2, 1L<<0, manage_OnKeydown, &vars);
	mlx_mouse_hook(vars.win, manage_MouseEvents, &vars);

	//display_data(data);

	mlx_loop(vars.mlx);
```

- mlx_init : établit la connexion avec ??????
- mlx_new_window : création de la fenêtre
- mlx_new_image : création de l’image
- mlx_get_data_addr : renvoie un pointeur vers l’emplacement memoire du premier pixel de l’image
- mlx_loop_hook : fonction permettant de rafraichir l’image tant que l’on ne sort pas de la boucle
- mlx_hook : permet de surveiller les évènements du clavier
- mlx_mouse_hook : même chose mais pour les évènements de la souris
- mlx_loop : continue la boucle tant que la connexion existe

# Code

- A ⇒ 0
- D ⇒ 2
- W ⇒ 13
- S ⇒ 1

## Problème avec la couleur des coins des murs

## Réponse de Phind

To determine the color of a corner pixel in your game based on the player's position, you can use a method that takes into account the player's relative position to the wall and the direction they're facing.

First, you need to calculate the player's viewing angle. The viewing angle can be defined as the angle between the player's direction and the line connecting the player's position to the corner pixel.

```c
float player_angle = atan2f(direction.y, direction.x);
float angle_to_corner = atan2f(corner.y - position.y, corner.x - position.x);
float viewing_angle = fmodf(angle_to_corner - player_angle + 2 * M_PI, 2 * M_PI);`
```

Next, you can define a threshold angle (e.g., PI/2 or 90 degrees). If the  viewing angle is smaller than this threshold, the player is considered  to be looking at the corner from one side, and if it's larger, from the other side.

```c
if (viewing_angle < M_PI / 2)
{
    // player is looking from one side
    draw_3D_line_south(general, ray, wall_height, imageincre);
}
else
{
    // player is looking from the other side
    draw_3D_line_west(general, ray, wall_height, imageincre);
}
```

The exact logic and the threshold angle would depend on the specific layout of your game and the visual effect you want to achieve.

Lastly, note that the `atan2f` function returns an angle in the range [-PI, PI], and the `fmodf` function is used to convert the difference of the two angles to the range [0, 2*PI]. This is done to avoid negative angles and to make the comparison with the threshold angle meaningful.

Remember to always consider the player's position relative to the wall and the direction they're facing. It's also important to keep in mind that the decision about which texture to use for the corner pixel can impact how the player perceives the 3D environment in your game.

## Ma solution

Alors... J'ai une autre idée pour notre problème de texture du bord des coins des murs...

J'ai retourné le problème dans tous les sens mais ça me semble impossible de le résoudre en utilisant la direction du joueur et son emplacement...
Du coup j'ai pensé à un truc. Ce serait de vérifier les coordonnées de l'avant dernier pixel de l'extrémité du rayon... Je m'explique...
Il y a 4 cas litigieux (NE NW SE SW). Ce sont les pixels pouvant prendre une couleur ou une autre selon l'orientation du rayon qui arrive dessus. En prenant l'exemple du coin d'un mur qui se trouverait au milieu de la map. Il y a 5 possibilité pour l'avant dernier pixel du rayon :

- 1 et 2 : le rayon arrive du nord donc ==> texture NORD. Dans ce cas on peut dire que le rayon arrive verticalement.
- 4 et 5 : le rayon arrive de l'est donc ==> texture EST. Dans ce cas le rayon arrive horizontalement.
- 3 : le rayon arrive en diagonale et la je ne sais pas trop quoi faire. J'ai 2 idées : soit on le met en noir ? soit on choisit arbitrairement une une des 2 textures qu'on aura prédertéminé à l'avance ?

![cubissue.jpg](https://github.com/FXC-ai/Cube3D/blob/main/cubissue.jpg)

Pour être tout a fait clair je vais essayer de lister les étapes de l'algorithme pour le cas du pixel B de coordonnées (9;9)
1/ On détermine les 2 possibilité de texture : EST ou SUD (c'est déjà codé).
2/ On utilise une fonction qui nous donne les coordonnées de l'avant dernier pixel du rayon (je l'ai représenté en rose). Dans mon exemple c'est le pixel 11 qui a pour coordonnées (10;9).
3/ On teste les 5 pattern (même si dans ce cas seuls les pixels 10 11 et 12 peuvent être les avant derniers pixels du rayon)
PIXEL 10 (x + 1; y - 1) => NON
PIXEL 11 (x + 1 ; y) => OUI, c'est donc une texture EST
PIXEL 12 (x + 1; y +1) => NON, mais c'est inutile de cheker car on sait déjà quelle texture utiliser mais c'est pour être exhaustif
PIXEL 13 (x; y + 1) => NON, ce n'est donc pas une texture SUD
PIXEL 14 (x -1; y +1) = > NON, ce n'est pas une texture SUD

# Problème quand on s’approche des murs

```c
float	get_dist(t_coord pos, t_coord ray, float delta_angle)
{
	float	dist;

	dist = sqrtf((ray.x - pos.x) * (ray.x - pos.x)
			+ (ray.y - pos.y) * (ray.y - pos.y));
	dist /= SIZE_WALL;
	dist *= cos(delta_angle);
	return (dist);
}

wall_height = round((float)(WIDTH) / get_dist(general->scene->player.pos, result.v2, angle - pl_st_end[0]));

void draw_3D_line_north(t_general *general, t_coord ray, int wall_height, int imageincre)
{
    int             i;
    unsigned int    color;
        
    i = 0;
    if ((HEIGHT - wall_height) / 2 > 0)
    {
        while (i < wall_height)
        {
            color = get_color_wall_north(general, ray.x, i, wall_height);
            my_mlx_pixel_put(&general->mlib->data, imageincre, (HEIGHT - wall_height) / 2 + i, color);
            i++;
        }
    }
    else
    {
        while (i < HEIGHT)
        {
            color = get_color_wall_north(general, ray.x, (wall_height - HEIGHT) / 2 + i, wall_height);
            my_mlx_pixel_put(&general->mlib->data, imageincre, i, color);
            i++;
        }
    }
}
```

wall_height devient très grand quand on s’approche du mur. Dés lors cette valeur n’est plus utilisée dans la boucle permettant le rendu à l’écran. On l’utilise pour savoir quel pourcentage de la texture doit être utilisée pour le rendu.

# Sources

[MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)

[cub3d](https://harm-smits.github.io/42docs/projects/cub3d)

[Algorithme_Cub3D](https://docs.google.com/document/d/1tdNYHg3Mfqf8dr8W6Ajs3seUugwtmaQizZ7BzimkXog/edit?pli=1)
