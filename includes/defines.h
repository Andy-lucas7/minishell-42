/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:27:48 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/14 11:27:16 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifndef ERROR_MSG
#  define ERROR_MSG "\033[1;31mERROR\n\033[0m"
# endif

# ifndef EXIT_MSG
#  define EXIT_MSG "\n\033[1;37m\
                       .,,uod8B8bou,,.                             \n\
              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.                    \n\
         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||                   \n\
         !...:!TVBBBRPFT||||||||||!!^^\"\"'   ||||                   \n\
         !.......:!?|||||!!^^\"\"'            ||||                   \n\
         !.........||||                     ||||                   \n\
         !.........||||                     ||||                   \n\
         !.........||||   \033[32mSHELL\033[37m-E: Bye!     ||||                   \n\
         !.........||||                     ||||                   \n\
         !.........||||                     ||||                   \n\
         !.........||||                     ||||                   \n\
         `.........||||                    ,||||                   \n\
          .;.......||||               _.-!!|||||                   \n\
   .,uodWBBBBb.....||||       _.-!!|||||||||!:'                    \n\
!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....               \n\
!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.             \n\
!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.           \n\
!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"`;:::       `.         \n\
!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.   \n\
`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo. \n\
  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'\n\
    `........::::::::::::::::;iof688888888888888888888b.     `     \n\
      `......:::::::::;iof688888888888888888888888888888b.         \n\
        `....:::;iof688888888888888888888888888888888899fT!        \n\
          `..::!8888888888888888888888888888888899fT|!^\"'          \n\
            `' !!988888888888888888888888899fT|!^\"'                \n\
                `!!8888888888888888899fT|!^\"'                      \n\
                  `!988888888899fT|!^\"'                            \n\
                    `!9899fT|!^\"'\033[0m\n"
# endif

# ifndef PROMPT_MSG
#  define PROMPT_MSG "\001\033[1;32mSHELL\001\033[1;37m\002-E: \001\033[0m\002"
# endif

# ifndef INVALID_USAGE
#  define INVALID_USAGE "invalid usage"
# endif

# ifndef BFF_SIZE
#  define BFF_SIZE 4096
# endif

# ifndef SEP
#  define SEP -1
# endif

enum e_type{
	PIPE = 10,
	EXECVE = 11,
	BUILDIN = 12,
	ARG = 13,
	ARG_FILE = 14,
	REDIRECT = 15,
	HEREDOC = 16
};

#endif