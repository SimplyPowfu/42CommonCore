/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:38:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/20 15:33:28 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SYNTAX "syntax error near unexpected token"

# include <stdint.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <bits/types/siginfo_t.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

extern int	g_signal;

//struct
typedef struct s_command//for pipes
{
	char	*command;//nome comando
	char	**args;//argomento
	char	*input_file;//redirect
	char	*output_file;
	int		append;//Append
	char	**heredoc;
	int		doc_count;
}	t_command;

typedef struct s_shell//for shell
{
	char		*cmd;//stringa di comando messa in output da readline |
	int			argc;//quanti comandi abbiamo X
	char		**argv;//quali comandi abbiamo X
	char		**envp;//copia dell env |
	char		*path;//path(pwd) dove ti trovi |
	char		*input_file;//aprire fd per input
	char		*output_file;//aprire fd per output
	char		**heredoc;
	int			append;
	int			doc_count;
	int			pipes_count;
	t_command	**command;//pipe execute
}	t_shell;

typedef struct s_heredoc_ctx
{
	pid_t		*pids;
	int			*pipes;
	t_shell		*shell;
	t_command	*cmd;
	int			fd;
	char		*tempfile;
}	t_heredoc_ctx;

//inizialization
void	init(char *cmd, t_shell *shell);
void	init_command(t_shell *shell, t_command *cmd);
int		pipes_init_command(t_shell *shell);
int		syntax(t_shell *shell);//if pipes 0, check cmd else check **cmd
int		syntax_pipes(t_shell *shell, t_command *command);

//parsing
void	take_argc(t_shell *shell, int *i);
void	take_argv(t_shell *shell, int *i, int *j);
void	take_argv_quotes(t_shell *shell, int quotes, int *i, int *j);
void	check_argv(t_shell *shell, int *i, int *j, int *k);
void	check_argv_quote(t_shell *shell, int *i, int *j, int *k);
void	check_argv_quotes(t_shell *shell, int *i, int *j, int *k);
int		pars(t_shell *shell);
void	var_in_env(t_shell *shell, char **argv, int *k);
int		is_builtins(t_shell *shell, t_command *cmd);
char	*space_redir(char *command);
int		parse_redir(t_shell *shell);
void	shift_arg(t_shell *shell, int i, int *k);
int		check_heredoc(t_shell *shell, int *i, int *k, int *egg);
int		check_input_file(t_shell *shell, int *i, int *egg);
int		check_output_file(t_shell *shell, int *i, int *egg);
int		take_redirection(t_shell *shell, int *i, int *k, int *egg);
int		len_pre_dollar(char *str, char **envp);
int		split_struct(t_shell *shell, t_command *command, int *arg);

//parsing pipe
void	shift_arg_pipes(t_command *shell, int i);
int		check_outfile_pipe(t_shell *shell, t_command *command, int *i);
int		check_input_pipe(t_shell *shell, t_command *command, int *i);
int		check_heredoc_pipe(t_shell *shell, t_command *command, int *i, int *k);
int		take_argv_pipe(t_shell *shell, t_command *command, int *i, int *k);
int		parse_redir_pipe(t_shell *shell, t_command *command);

//builtins
int		echo(int argc, char **argv);
int		pwd(void);
int		env(char **envp);
int		cd(t_shell *shell);
int		ft_export(t_shell *shell);
int		unset(t_shell *shell);
void	ft_exit(t_shell *shell);
int		command_bultins(char *cmd);

//pipes
int		execute_path_command(t_shell *shell, t_command *cmd);
int		handle_parent_process(pid_t pid, char **paths);
int		handle_fork_and_execution(t_shell *shell,
			t_command *cmd, char **paths);
int		execute_command(t_shell *shell, t_command *cmd);
void	execute_pipeline(t_shell *shell);

//pipes utility
int		handle_parent_process(pid_t pid, char **paths);
void	cleanup_pipeline(t_shell *shell);
void	close_pipes(int *pipes, int pipes_count);
char	*create_tempfile(int cmd_index);
void	handle_command_heredoc(pid_t *pids, int *pipes, t_shell *shell,
			int cmd_index);
void	handle_pipe_creation(t_shell *shell, int *pipes);
void	handle_heredoc_parent(pid_t pid, t_heredoc_ctx *ctx);

//redirections
void	handle_heredoc(t_shell *shell, t_command *cmd);
void	handle_redirections(t_shell *shell, t_command *cmd);

//redirections-utility
void	print_heredoc_warning(t_command *cmd);

//signal
void	signal_manager(int signal);
void	sig_here(int signal);
void	set_signals_noninteractive(void);
void	handle_sigpipe(int sig);
void	set_pipeline_signals(void);
void	set_signals_noninteractive_child(void);

//free
void	free_all(t_shell *shell, int finish);
void	free_pipes(t_shell *shell);
void	free_command(t_shell *shell);
void	free_env(t_shell *shell, int finish);
void	free_command_args(t_shell *shell, int i);
void	free_heredoc(t_shell *shell);

//utils built-in
void	bubble_sort(char **envp);
int		is_valid_varname(const char *str);
int		add_or_update_var(t_shell *shell, const char *arg);
void	print_export_error(char *arg);

//utils
int		pre_dollar(char *str);
int		is_expandible(char *str, char **envp, int *str_pos);
int		update_env(t_shell *shell, const char *key, const char *value);
char	*in_env(t_shell *shell, char *str, char **envp);
int		exit_error(t_shell *shell, int number);
int		trim_space(char *command);
int		add_space_malloc(char *command);
int		count_char(t_shell *shell, char c);
char	*finish_command(char *command);
void	take_env(char **envp, t_shell *shell);
void	init_shell(t_shell *shell);
int		is_valid(t_shell *shell, char *command);
int		check_syntax_error_pipes(t_shell *shell, t_command *command);
int		check_pipes(t_shell *shell);
void	pipe_is_char(char **argv);
void	count_heredoc(t_shell *shell);
void	count_heredoc_pipe(t_shell *shell, t_command *command);
int		close_quote(char *command);
char	*var_not_expandible(char *str, int finish);
int		echo_is_n(char **argv, int *i);
void	redir_is_char(char **argv);
void	del_extra_space(t_shell *shell);
void	del_extra_space_pipe(t_command *command);
void	search_in_env(char *str, char **envp, int i, int *k);
char	*malloc_result(char *str, char *expand);
void	reset_expand_var(t_shell *shell, char **str, int *i);

#endif