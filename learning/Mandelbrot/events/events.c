#include "../include/complex.h"
#include <mlx.h>

enum {
    ON_KEYDOWN      = 2,
    ON_KEYUP        = 3,
    ON_MOUSEDOWN    = 4,
    ON_MOUSEUP      = 5,
    ON_MOUSEMOVE    = 6,
    ON_EXPOSE       = 12,
    ON_DESTROY      = 17
};

// usage:
// mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);

typedef struct s_vars {
    void    *mlx;
    void    *win;
}   t_vars;

int close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello, World");
    mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);
}