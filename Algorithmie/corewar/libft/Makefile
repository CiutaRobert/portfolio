# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/02 22:13:03 by jzak              #+#    #+#              #
#    Updated: 2014/02/02 22:35:35 by jzak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

ifndef config
  config=release
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),release)
  OBJDIR     = obj/Release
  TARGETDIR  = .
  TARGET     = $(TARGETDIR)/libft.a
  DEFINES   += -DVERSION=\"RELEASE-0.1.1\"
  INCLUDES  += -Iincludes
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -Wall -Wextra -Werror
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -Wl,-x -L.
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug)
  OBJDIR     = obj/Debug
  TARGETDIR  = .
  TARGET     = $(TARGETDIR)/libft_debug.a
  DEFINES   += -DDEBUG -DVERSION=\"DEBUG-0.1.1\"
  INCLUDES  += -Iincludes
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall -Wextra
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L.
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/printf.o \
	$(OBJDIR)/printf_core.o \
	$(OBJDIR)/printf_format_int.o \
	$(OBJDIR)/printf_type_d.o \
	$(OBJDIR)/printf_type_s.o \
	$(OBJDIR)/printf_type_x.o \
	$(OBJDIR)/xmem.o \
	$(OBJDIR)/xmem_core.o \
	$(OBJDIR)/xmem_free.o \
	$(OBJDIR)/xmem_free_all.o \
	$(OBJDIR)/dynbuf_del.o \
	$(OBJDIR)/dynbuf_new.o \
	$(OBJDIR)/dynbuf_write.o \
	$(OBJDIR)/ft_abs.o \
	$(OBJDIR)/ft_arrlen.o \
	$(OBJDIR)/ft_atoi.o \
	$(OBJDIR)/ft_basename.o \
	$(OBJDIR)/ft_bzero.o \
	$(OBJDIR)/ft_calloc.o \
	$(OBJDIR)/ft_clstadd.o \
	$(OBJDIR)/ft_clstaddnew.o \
	$(OBJDIR)/ft_clstclean.o \
	$(OBJDIR)/ft_clstnew.o \
	$(OBJDIR)/ft_clstpop.o \
	$(OBJDIR)/ft_dirname.o \
	$(OBJDIR)/ft_dlstadd.o \
	$(OBJDIR)/ft_dlstaddnew.o \
	$(OBJDIR)/ft_dlstnew.o \
	$(OBJDIR)/ft_error.o \
	$(OBJDIR)/ft_getline.o \
	$(OBJDIR)/ft_getnbr.o \
	$(OBJDIR)/ft_indexof.o \
	$(OBJDIR)/ft_intcmp.o \
	$(OBJDIR)/ft_intlen.o \
	$(OBJDIR)/ft_isalnum.o \
	$(OBJDIR)/ft_isalpha.o \
	$(OBJDIR)/ft_isascii.o \
	$(OBJDIR)/ft_isdigit.o \
	$(OBJDIR)/ft_islower.o \
	$(OBJDIR)/ft_isprint.o \
	$(OBJDIR)/ft_isupper.o \
	$(OBJDIR)/ft_itoa.o \
	$(OBJDIR)/ft_itobase.o \
	$(OBJDIR)/ft_lstadd.o \
	$(OBJDIR)/ft_lstaddnew.o \
	$(OBJDIR)/ft_lstaddsort.o \
	$(OBJDIR)/ft_lstaddstr.o \
	$(OBJDIR)/ft_lstdel.o \
	$(OBJDIR)/ft_lstdelif.o \
	$(OBJDIR)/ft_lstdelone.o \
	$(OBJDIR)/ft_lstdup.o \
	$(OBJDIR)/ft_lstdupone.o \
	$(OBJDIR)/ft_lstiter.o \
	$(OBJDIR)/ft_lstlen.o \
	$(OBJDIR)/ft_lstmap.o \
	$(OBJDIR)/ft_lstnew.o \
	$(OBJDIR)/ft_lstrev.o \
	$(OBJDIR)/ft_lstsort.o \
	$(OBJDIR)/ft_ltoa.o \
	$(OBJDIR)/ft_ltobase.o \
	$(OBJDIR)/ft_memccpy.o \
	$(OBJDIR)/ft_memchr.o \
	$(OBJDIR)/ft_memcmp.o \
	$(OBJDIR)/ft_memcpy.o \
	$(OBJDIR)/ft_memdel.o \
	$(OBJDIR)/ft_memdup.o \
	$(OBJDIR)/ft_memmove.o \
	$(OBJDIR)/ft_memrev.o \
	$(OBJDIR)/ft_memset.o \
	$(OBJDIR)/ft_optiter.o \
	$(OBJDIR)/ft_pathjoin.o \
	$(OBJDIR)/ft_putchar.o \
	$(OBJDIR)/ft_putchar_fd.o \
	$(OBJDIR)/ft_putendl.o \
	$(OBJDIR)/ft_putendl_fd.o \
	$(OBJDIR)/ft_putnbr.o \
	$(OBJDIR)/ft_putnbr_fd.o \
	$(OBJDIR)/ft_putstr.o \
	$(OBJDIR)/ft_putstr_fd.o \
	$(OBJDIR)/ft_realloc.o \
	$(OBJDIR)/ft_strarrdel.o \
	$(OBJDIR)/ft_strarrdup.o \
	$(OBJDIR)/ft_strarrtolst.o \
	$(OBJDIR)/ft_strcat.o \
	$(OBJDIR)/ft_strchr.o \
	$(OBJDIR)/ft_strclr.o \
	$(OBJDIR)/ft_strcmp.o \
	$(OBJDIR)/ft_strcount.o \
	$(OBJDIR)/ft_strcpy.o \
	$(OBJDIR)/ft_strdel.o \
	$(OBJDIR)/ft_strdup.o \
	$(OBJDIR)/ft_strequ.o \
	$(OBJDIR)/ft_striter.o \
	$(OBJDIR)/ft_striteri.o \
	$(OBJDIR)/ft_strjoin.o \
	$(OBJDIR)/ft_strjoinsep.o \
	$(OBJDIR)/ft_strlcat.o \
	$(OBJDIR)/ft_strlen.o \
	$(OBJDIR)/ft_strltrim.o \
	$(OBJDIR)/ft_strmap.o \
	$(OBJDIR)/ft_strmapi.o \
	$(OBJDIR)/ft_strncat.o \
	$(OBJDIR)/ft_strncmp.o \
	$(OBJDIR)/ft_strncpy.o \
	$(OBJDIR)/ft_strnequ.o \
	$(OBJDIR)/ft_strnew.o \
	$(OBJDIR)/ft_strnstr.o \
	$(OBJDIR)/ft_strrchr.o \
	$(OBJDIR)/ft_strrtrim.o \
	$(OBJDIR)/ft_strsplit.o \
	$(OBJDIR)/ft_strstr.o \
	$(OBJDIR)/ft_strsub.o \
	$(OBJDIR)/ft_strtrim.o \
	$(OBJDIR)/ft_tolower.o \
	$(OBJDIR)/ft_toupper.o \
	$(OBJDIR)/ft_uitoa.o \
	$(OBJDIR)/ft_ultoa.o \
	$(OBJDIR)/ft_xmalloc.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking ft
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

$(NAME): all

clean:
	@echo Cleaning ft
	$(SILENT) rm -rf $(OBJDIR)

fclean: clean
	@echo Remove $(TARGET)
	$(SILENT) rm -f $(TARGET)

re: fclean all

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	-$(SILENT) cp $< $(OBJDIR)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
endif

$(OBJDIR)/printf.o: modules/printf/printf.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/printf_core.o: modules/printf/printf_core.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/printf_format_int.o: modules/printf/printf_format_int.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/printf_type_d.o: modules/printf/printf_type_d.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/printf_type_s.o: modules/printf/printf_type_s.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/printf_type_x.o: modules/printf/printf_type_x.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/xmem.o: modules/xmem/xmem.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/xmem_core.o: modules/xmem/xmem_core.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/xmem_free.o: modules/xmem/xmem_free.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/xmem_free_all.o: modules/xmem/xmem_free_all.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/dynbuf_del.o: modules/dynbuf/dynbuf_del.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/dynbuf_new.o: modules/dynbuf/dynbuf_new.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/dynbuf_write.o: modules/dynbuf/dynbuf_write.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_abs.o: srcs/ft_abs.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_arrlen.o: srcs/ft_arrlen.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_atoi.o: srcs/ft_atoi.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_basename.o: srcs/ft_basename.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_bzero.o: srcs/ft_bzero.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_calloc.o: srcs/ft_calloc.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_clstadd.o: srcs/ft_clstadd.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_clstaddnew.o: srcs/ft_clstaddnew.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_clstclean.o: srcs/ft_clstclean.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_clstnew.o: srcs/ft_clstnew.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_clstpop.o: srcs/ft_clstpop.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_dirname.o: srcs/ft_dirname.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_dlstadd.o: srcs/ft_dlstadd.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_dlstaddnew.o: srcs/ft_dlstaddnew.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_dlstnew.o: srcs/ft_dlstnew.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_error.o: srcs/ft_error.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_getline.o: srcs/ft_getline.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_getnbr.o: srcs/ft_getnbr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_indexof.o: srcs/ft_indexof.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_intcmp.o: srcs/ft_intcmp.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_intlen.o: srcs/ft_intlen.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_isalnum.o: srcs/ft_isalnum.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_isalpha.o: srcs/ft_isalpha.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_isascii.o: srcs/ft_isascii.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_isdigit.o: srcs/ft_isdigit.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_islower.o: srcs/ft_islower.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_isprint.o: srcs/ft_isprint.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_isupper.o: srcs/ft_isupper.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_itoa.o: srcs/ft_itoa.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_itobase.o: srcs/ft_itobase.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstadd.o: srcs/ft_lstadd.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstaddnew.o: srcs/ft_lstaddnew.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstaddsort.o: srcs/ft_lstaddsort.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstaddstr.o: srcs/ft_lstaddstr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstdel.o: srcs/ft_lstdel.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstdelif.o: srcs/ft_lstdelif.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstdelone.o: srcs/ft_lstdelone.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstdup.o: srcs/ft_lstdup.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstdupone.o: srcs/ft_lstdupone.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstiter.o: srcs/ft_lstiter.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstlen.o: srcs/ft_lstlen.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstmap.o: srcs/ft_lstmap.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstnew.o: srcs/ft_lstnew.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstrev.o: srcs/ft_lstrev.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_lstsort.o: srcs/ft_lstsort.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_ltoa.o: srcs/ft_ltoa.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_ltobase.o: srcs/ft_ltobase.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memccpy.o: srcs/ft_memccpy.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memchr.o: srcs/ft_memchr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memcmp.o: srcs/ft_memcmp.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memcpy.o: srcs/ft_memcpy.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memdel.o: srcs/ft_memdel.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memdup.o: srcs/ft_memdup.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memmove.o: srcs/ft_memmove.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memrev.o: srcs/ft_memrev.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_memset.o: srcs/ft_memset.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_optiter.o: srcs/ft_optiter.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_pathjoin.o: srcs/ft_pathjoin.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_putchar.o: srcs/ft_putchar.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_putchar_fd.o: srcs/ft_putchar_fd.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_putendl.o: srcs/ft_putendl.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_putendl_fd.o: srcs/ft_putendl_fd.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_putnbr.o: srcs/ft_putnbr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_putnbr_fd.o: srcs/ft_putnbr_fd.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_putstr.o: srcs/ft_putstr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_putstr_fd.o: srcs/ft_putstr_fd.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_realloc.o: srcs/ft_realloc.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strarrdel.o: srcs/ft_strarrdel.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strarrdup.o: srcs/ft_strarrdup.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strarrtolst.o: srcs/ft_strarrtolst.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strcat.o: srcs/ft_strcat.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strchr.o: srcs/ft_strchr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strclr.o: srcs/ft_strclr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strcmp.o: srcs/ft_strcmp.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strcount.o: srcs/ft_strcount.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strcpy.o: srcs/ft_strcpy.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strdel.o: srcs/ft_strdel.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strdup.o: srcs/ft_strdup.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strequ.o: srcs/ft_strequ.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_striter.o: srcs/ft_striter.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_striteri.o: srcs/ft_striteri.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strjoin.o: srcs/ft_strjoin.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strjoinsep.o: srcs/ft_strjoinsep.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strlcat.o: srcs/ft_strlcat.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strlen.o: srcs/ft_strlen.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strltrim.o: srcs/ft_strltrim.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strmap.o: srcs/ft_strmap.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strmapi.o: srcs/ft_strmapi.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strncat.o: srcs/ft_strncat.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strncmp.o: srcs/ft_strncmp.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strncpy.o: srcs/ft_strncpy.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strnequ.o: srcs/ft_strnequ.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strnew.o: srcs/ft_strnew.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strnstr.o: srcs/ft_strnstr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strrchr.o: srcs/ft_strrchr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strrtrim.o: srcs/ft_strrtrim.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strsplit.o: srcs/ft_strsplit.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strstr.o: srcs/ft_strstr.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strsub.o: srcs/ft_strsub.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_strtrim.o: srcs/ft_strtrim.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_tolower.o: srcs/ft_tolower.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_toupper.o: srcs/ft_toupper.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_uitoa.o: srcs/ft_uitoa.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_ultoa.o: srcs/ft_ultoa.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ft_xmalloc.o: srcs/ft_xmalloc.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
