colorscheme desert
"set guioptions="ai"
set langmenu=zh_CN.GBK
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim

"if has("gui_kde")
"	set guifont=Fixed\ [Misc]/10/-1/5/50/0/0/0/1/0
"elseif has("gui_gtk")
"	set guifont=-misc-fixed-medium-r-normal-*-*-100-*-*-c-*-iso10646-1
"elseif has("gui_gnome")
""	set guifont=-misc-fixed-medium-r-normal-*-*-100-*-*-c-*-iso10646-1
""	set guifont=SimSun
"endif

if has("gui_running")
	set guifont=Courier\ 10\ Pitch\ 12
	set guifontwide=SimSun\ 12
	"set guifontwide=FZDaHei-B02\ 20
	"set menufont=SimHei/12/-1/5/50/0/0/0/1/0
endif

