/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:00:52 by slight            #+#    #+#             */
/*   Updated: 2022/08/14 11:50:28 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <fcntl.h>
# include <termios.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

# define WORD 1
# define SEP 2
# define FIELD 3
# define EXP_FIELD 4
# define REDIR_OUT 5
# define REDIR_IN 6
# define REDIR_APPEND 7
# define REDIR_INSOURSE 8
# define PIPE 9
# define EXP 10
# define STATUS 11
# define WORDS "abcdefghijklmnopqrstuvwxyz1234567890!@#^&*()-=+_/.,;:"

typedef struct s_main_data	t_main_data;
typedef struct s_list		t_list;
typedef struct s_info		t_info;

struct s_list
{
	t_list	*next;
	int		key;
	char	*value;
};

struct s_main_data
{
	char	*command_name;
	char	*absulut_path;
	char	*relative_path;
	char	*file_name;
	int		count_pipes;
	int		count_in;
	int		count_out;
	int		count_inin;
	int		count_outout;
	int		count_variables;
	int		invitation_len;
	int		print_code;
};

struct s_info
{
	char	*lib_of_command[7];
	t_list	*jrs_list;
};

void			do_command(char *str, t_main_data *res);
int				ft_strlen(char *str);
char			**create_command_names(void);
void			init_main_data(t_main_data *res);
void			clean_main_data(t_main_data *res);
void			final_print(int code, t_main_data *res);
void			skip_spaces(char **str);
void			clean_command_names(char ***lib);
void			do_echo(char *str);
bool			ft_strcmp(char *s1, char *s2);
bool			ft_strchr(char *str, char ch);
void			push_back(t_list **head, int key, char *value);
void			lexer(t_info *info, char *invitation);
void			fun_pipe(t_info *info, char **invitation);
void			fun_redir_insourse(t_info *info, char **invitation);
void			fun_redir_append(t_info *info, char **invitation);
void			fun_redir_in(t_info *info, char **invitation);
void			fun_redir_out(t_info *info, char **invitation);
void			fun_exp(t_info *info, char **invitation);
#endif