/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 16:54:19 by tlesven           #+#    #+#             */
/*   Updated: 2014/05/01 11:00:58 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# define BUFF_SIZE 4096

int			ft_posix_openpt(int flags);
int			ft_grantpt(int fd);
char		*ft_ptsname(int fd);
int			ft_unlockpt(int fd);
void		ft_script(int fdf, char **env, char **av);
void		ft_master(int fdm, int fdf);
void		ft_slave(int fds, char **env, char **av);
char		*singleton_file(char *s);
void		ft_message(int i, int fdf);
char		*ft_date(void);
#endif
