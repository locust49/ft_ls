/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:51:27 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 13:00:04 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"

# include <stdarg.h>

# include <dirent.h>
# include <sys/types.h>

# include <sys/stat.h>

# include <sys/ioctl.h>

# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>

# include <sys/xattr.h>
# include <sys/acl.h>

# include <time.h>

# include <unistd.h>

# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct		s_dir_content
{
	struct dirent			current;
	struct s_dir_content	*next;
	struct s_dir_content	*prev;
}					t_dcont;

typedef struct		s_args
{
	char			*name;
	size_t			len;
	mode_t			type;
	struct s_args	*next;
}					t_args;

typedef struct		s_lsdet
{
	unsigned short		a: 1;
	unsigned short		c: 1;
	unsigned short		f: 1;
	unsigned short		l: 1;
	unsigned short		r: 1;
	unsigned short		t: 1;
	unsigned short		n: 1;
	unsigned short		d: 1;
	unsigned short		o: 1;
	unsigned short		g: 1;
	unsigned short		u: 1;
	unsigned short		one: 1;
	unsigned short		fcap: 1;
	unsigned short		gcap: 1;
	unsigned short		scap: 1;
	unsigned short		rcap: 1;
}					t_lsdet;

typedef struct		s_width
{
	int				xatt;
	int				lnk;
	unsigned int	usr;
	unsigned int	grp;
	off_t			size;
	int				maj;
	int				wtime;
	int				min;
}					t_width;

typedef struct		s_ownership
{
	struct passwd	*pw;
	struct group	*gp;
	unsigned int	max_gp;
	unsigned int	max_pw;
}					t_ownership;

int					ft_display_error(char *path);

char				*ft_find_name(char *fullpath);

int					ft_operands(int ac, char **av, t_lsdet *opt);
char				set_options(char *opt, t_lsdet *det);
int					n_op(int ac, char **av);

void				ft_sort_args(int nargs, char **args,
					int nops, t_lsdet opts);

t_args				*ft_add_first(char *name, t_args *pos, mode_t type,
					t_lsdet opts);
void				ft_new_file(t_args *dirs, char *name, mode_t type);
t_args				*get_dir_lst(int bounds[], char **argv,
					t_lsdet opts, int *err);

int					get_tab_size(int max_len);
int					get_max_len(t_args *lst);
t_args				*get_item_inpos(t_args *list, int pos, int init);
int					get_list_length(t_args *list);

int					ft_check_content(char *path, struct dirent *elem,
					t_lsdet opts);
char				*ft_join_path(char *name, char *dirs_name);
t_args				*ft_print_files(t_args *list, t_lsdet opts);

void				ft_single_arg_details(t_args *dirs, t_width w,
					t_lsdet opts);
void				ft_display_single_arg(t_args *dirs, t_lsdet opts, int err);
void				ft_multiplearg_details(t_args *dirs, t_width w,
					t_lsdet opts);
void				ft_display_multiple_arg(char *name, t_args *dirs,
					t_lsdet opts);

char				set_xattr_acl(char *path);

void				ft_swap_fields(t_args *lst, t_args *next);
t_args				*ft_sort_input(t_args *args, char *name, t_lsdet opt);

char				*get_fullpath(char *path, char *dirents_name);
void				ft_display_links(DIR *pdir, char *dirs_name, t_width w,
					t_lsdet opts);
void				ft_long_display(char *name, t_args *dirs,
					t_lsdet opts, t_width w);

void				ft_initialize_width(t_width *width);
int					ft_width(char *name, t_args *dirents,
					t_width *width, t_lsdet opts);

void				ft_print_type_symb(mode_t st_mode);
void				ft_add_symbol(t_args *lst, mode_t st_mode);
void				ft_print_color(mode_t st_mode, char *toprint, int width);

char				*set_permissions(unsigned short mode);
void				ft_print_type(mode_t st_mode);
void				ft_print_nbrlink(nlink_t nlink, int w);
void				ft_print_owner(uid_t uid, int w, t_lsdet opts);
void				ft_print_group(gid_t gid, int w, t_lsdet opts);
void				ft_print_size(blksize_t blksize, int w);
void				ft_print_owners(t_lsdet opts, t_width width,
					struct stat info);
void				ft_print_major_minor(t_width width, struct stat info);
void				ft_print_time(t_lsdet opts, struct stat info);
void				ft_print_links(char *fullpath, struct stat info);
void				ft_display_long_format(char *name, t_args *dirents,
										t_lsdet opts, int isnotrecursive);

void				ft_list_long_format(char *fullpath, char *arg_name,
										t_width w, t_lsdet opts);
void				ft_ls_display(t_args *list, t_lsdet opts);

void				ft_display_dirname(char *dirs_name, DIR *pdir);
void				ft_print_dir(char *name, t_lsdet opts);
void				ft_display_args(char *name, t_args *dirs,
					t_lsdet opts, int err);

t_args				*ft_merge_sort(t_args *head, char *parent,
					int (*ft_cmpfunc)(const char *, const char *));
void				quick_sort(char **argv, int left, int right,
					int (*ft_cmpfunc)(const char *, const char *));

int					ft_sort_argsmt(int nargs, char **args, int nops);
int					ft_sort_argsat(int nargs, char **args, int nops);
int					ft_sort_argsct(int nargs, char **args, int nops);
int					ft_time_mcmp(const char *item1, const char *item2);
int					ft_time_acmp(const char *item1, const char *item2);
int					ft_time_ccmp(const char *item1, const char *item2);
int					ft_alphacmp(const char *item1, const char *item2);

#endif
