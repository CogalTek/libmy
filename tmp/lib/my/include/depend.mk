##
## depend.mk for all in /home/benji_epitech/System_Unix/PSU_2016_my_printf
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
## 
## Started on  Wed Nov  9 17:16:44 2016 Benjamin Viguier
## Last update Sun Apr  2 16:39:23 2017 Benjamin Viguier
##

CC		=	gcc

DEBUG		=	true

WALL		=	true

RELEASE		=	true

ALLOW_OPEN	=	true

ALLOW_LSEEK	=	true

ifeq	($(WALL),true)
 CFLAGS		+=	-W -Wall -Wextra
endif

ifeq	($(RELEASE),true)
 CFLAGS		+=	-O2 -Werror -Wno-unused-result
 DEBUG		=	false
else
 CFLAGS		+=	-O0
endif

ifeq	($(DEBUG),true)
 CFLAGS		+=	-g
endif

ODIR		=	obj

SDIR		=	src
