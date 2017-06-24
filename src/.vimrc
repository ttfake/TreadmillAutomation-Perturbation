set si
set shiftwidth=4
set cinoptions+=j1
set nu
set lbr
colorscheme delek
syntax on
filetype indent on

set tabstop=4
set softtabstop=4
set noexpandtab

set expandtab
set autoindent
set exrc
set secure

set colorcolumn=110

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0


highlight ColorColumn ctermbg=gray

let java_comment_strings=1
let java_highlight_java_lang_ids=1
let java_mark_braces_in_parens_as_errors=1
let java_highlight_all=1
let java_highlight_debug=1
let java_ignore_javadoc=1
let java_highlight_java_lang_ids=1
"let java hightlight_functions="stye"
let java_minlines=150

let g:slime_target = "screen"

let g:clang_library_path='/usr/lib64/libclang.so.3.9'

let g:ycm_global_ycm_extra_conf = "~/.vim/bundle/YouCompleteMe/.ycm_extra_conf.py"

let &t_SI = "\<Esc>]12;orange\x7"
  " use a red cursor otherwise
let &t_EI = "\<Esc>]12;red\x7"

let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<c-b>"
let g:UltiSnipsJumpBackwardTrigger="<c-z>"
let g:UltiSnipsEditSplit="vertical"

let g:airline#extensions#tabline#enabled = 1

nmap <F8> :TagbarToggle<CR>
map <C-J> <C-W>j<C-W>_
map <C-K> <C-W>k<C-W>_


set foldmethod=syntax
set foldcolumn=1

highlight Cursor guifg=Green guibg=black
highlight iCursor guifg=white guibg=steelblue
set guicursor=n-v-c:block-Cursor
set guicursor+=i:ver100-iCursor
set guicursor+=n-v-c:blinkon0
set guicursor+=i:blinkwait10

"Latex"
filetype plugin on
set grepprg=grep\ -nH\ $*
filetype indent on
let g:tex_flavor='latex'

set backspace=indent,eol,start

execute pathogen#infect()


hi TabLine      ctermfg=Black  ctermbg=Green     cterm=NONE
hi TabLineFill  ctermfg=Black  ctermbg=Green     cterm=NONE
hi TabLineSel   ctermfg=White  ctermbg=DarkBlue  cterm=NONE


