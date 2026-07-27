/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:19:13 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/19 18:56:25 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

extern volatile int	g_flag_sig;

typedef enum s_every
{
	WORD,
	PIP,
	INFILE,
	OUTFILE,
	APPEND,
	HEREDOC
}					t_every;

typedef enum s_quote_type
{
	NONE,
	SINGLE,
	DOUBLE
}					t_quote_type;

typedef struct s_token
{
	char			*value;
	t_every			type;
	t_quote_type	quote_type;
	struct s_token	*next;
}					t_token;

typedef struct s_redir
{
	t_every			type;
	char			*file;
	t_quote_type	quote_type;
	int				heredoc_fd;
	struct s_redir	*next;
}					t_redir;

typedef struct s_cmd
{
	char			**args;
	t_redir			*redir;
	unsigned int	infd;
	unsigned int	outfd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_minishell
{
	char			**env;
	t_cmd			*current;
	t_cmd			*head;
	t_token			*tokens;
	char			*line;
	int				(*pfd)[2];
	int				exit_status;
	int				saved_stdin;
	int				saved_stdout;
	int				should_exit;
	int				pipe_count;
	int				*pids;

}					t_mini;

t_token				*tokenize(char *buf);
t_cmd				*parse_tokens(t_token *tokens);
void				free_tokens(t_token *tokens);
void				free_commands(t_cmd *cmds);
int					handle_double_quotes(char *buf, int i, t_token **tok,
						bool the_flag);
int					handle_single_quotes(char *buf, int i, t_token **tok,
						bool the_flag);
t_token				*new_token_item(char *value, t_every type,
						t_quote_type quote_type);
void				add_token(t_token **head, t_token *new);
int					special(char c);
int					collect_word(char *buf, int i, t_token **tok,
						bool the_flag);
int					handle_op(char *buf, int i, t_token **tok);
char				**build_argv(t_token *tokens);
t_redir				*build_redirs(t_token *tokens);
int					validate_tokens(t_token *tok);
const char			*token_type_name(t_every type);
void				ret_error(void);
char				arg_helper(t_token *tmp);
void				fill_argv(char **argv, t_token *tokens);
t_token				*skip_redirections(t_token *tokens);
int					is_redirection(t_token *token);
int					count_args(t_token *tokens);
void				append_or_create(t_token **tok, char *s,
						t_quote_type quote_type);
void				append_or_create_helper(t_token **tok, char *s,
						t_quote_type quote_type);
void				sigint_handler(int sig);
int					handle_helper(char *buf, int i, t_token **tok, int type);

// nours functions
void				execution(t_mini *mini);
int					wait_status_to_exit_code(int status);
void				close_pipes(t_mini *mini, int num_pipes);
int					initialize_pipe(t_mini *mini, int num_pipes);

int					count_cmds(t_cmd *cmd);
int					exec_command(char **paths, char **args, char **envp,
						int flag);
char				*get_next_line(int fd);
char				**duplicate_env(char **env);
void				free_env(char **env);

void				echo_function(char **args);
int					cd_function(char **env, char **args);
void				export_to_env(char **env, char *key, char *value);
int					export_function(t_cmd *node, char **env);
void				unset_function(char **args, char **env);
void				env_function(char **env);
int					exit_function(char **args, t_mini *mini);
void				pwd_function(char **env);
int					is_numeric(char *str);

int					execut_shell_command(t_mini *mini);
int					is_builtin(char *command);
int					execute_one_command(t_mini *mini, int *pid);
int					execute_first_command(t_mini *mini, int *pid);
int					execute_middle_command(t_mini *mini, int *pid, int i);
int					execute_last_command(t_mini *mini, int *pid,
						int last_pipe_index);
void				child_cleanup(t_mini *mini);
void				setup_and_exec(t_mini *mini);
int					pipeline_executor(t_mini *mini, int *pid,
						int num_cmds_total);
void				execute_one_cmd(t_mini *mini);
void				execute_pipeline_cmds(t_mini *mini, int num_cmds_total);
int					handle_heredoc(t_redir *redir, t_mini *mini);
int					process_all_heredocs(t_mini *mini);
void				close_heredoc_fds(t_mini *mini);
void				heredoc_sigint_handler(int sig);
int					redirection_handling(t_mini *mini, t_cmd *node);
void				expand_tokens(t_token *tok, t_mini *mini);
int					check_exit(t_mini *mini);

char				**get_paths(char **envp);
int					free_all(char **arr, char *arg, int res);
char				*extract_var_from_env(char *var, t_mini *mini);
int					handle_double_redirect(char *buf, int i, t_token **tok,
						t_every type);
int					handle_single_redirect(char *buf, int i, t_token **tok,
						t_every type);

char				*expand_string(char *str, t_mini *mini);
char				*handle_exit_status(int last_exit, char *result);
char				*handle_env_var(char *str, int *i, t_mini *mini,
						char *result);
char				*get_env_value(char **env, char *key);
#endif

// 0 stdin
// 1 stdout
// 2 stderr
// 3 infile

// 3 stdin
// 1 stdout
// 2 stderr
// 3 infile
// 4 outfile_trunk

// 3 stdin
// 4 stdout
// 2 stderr
// 3 infile
// 4 outfile_trunk

// 5 stdin
// 4 stdout
// 2 stderr
// 3 infile
// 4 outfile_trunk
// 5 herdoc

// 5 stdin
// 6 stdout
// 2 stderr
// 3 infile
// 4 outfile_trunk
// 5 herdoc
// 6 outfile_append