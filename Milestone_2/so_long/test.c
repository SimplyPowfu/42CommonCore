#include "so_long.h"

// Funzione chiamata per chiudere la finestra
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

// Funzione chiamata per gestire i tasti premuti
int key_press(int keycode, void *param)
{
    (void)param;
    if (keycode == XK_Escape)
        exit(0);
    return (0);
}

int main(void)
{
	t_root			root;

	root = (t_root){0};
	root.mlx = mlx_init();
	root.mlx_win = mlx_new_window(root.mlx, 800, 600, "Finestra Test");

    mlx_hook(root.mlx_win, 17, 0, close_window, NULL); // Gestisce l'evento di chiusura della finestra

    mlx_key_hook(root.mlx_win, key_press, NULL); // Gestisce l'input da tastiera

	texture_init(&root); // Inizializzazione Texture

	mlx_put_image_to_window(root.mlx, root.mlx_win, root.exit, 100, 100); // Disegna l'immagine nella finestra, dando la posizione
    mlx_loop(root.mlx); // Mantiene la finestra aperta
}
