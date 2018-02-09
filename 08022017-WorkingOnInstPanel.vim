let SessionLoad = 1
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <Plug>IMAP_JumpBack =IMAP_Jumpfunc('b', 0)
inoremap <silent> <Plug>IMAP_JumpForward =IMAP_Jumpfunc('', 0)
inoremap <silent> <C-Tab> =UltiSnips#ListSnippets()
nmap v <Plug>SlimeConfig
nmap  <Plug>SlimeParagraphSend
xmap  <Plug>SlimeRegionSend
map  :call SwitchDB()
snoremap <silent>  c
xnoremap <silent> 	 :call UltiSnips#SaveLastVisualSelection()gvs
snoremap <silent> 	 :call UltiSnips#ExpandSnippet()
vmap <NL> <Plug>IMAP_JumpForward
nmap <NL> <Plug>IMAP_JumpForward
omap <NL> j_
map  k_
map  :call Doquery()
snoremap  "_c
map Q gq
nmap <silent> \w\y <Plug>VimwikiMakeYesterdayDiaryNote
nmap <silent> \w\t <Plug>VimwikiTabMakeDiaryNote
nmap <silent> \w\w <Plug>VimwikiMakeDiaryNote
nmap <silent> \w\i <Plug>VimwikiDiaryGenerateLinks
nmap <silent> \wi <Plug>VimwikiDiaryIndex
nmap <silent> \ws <Plug>VimwikiUISelect
nmap <silent> \wt <Plug>VimwikiTabIndex
nmap <silent> \ww <Plug>VimwikiIndex
nnoremap \as :call ArduinoSerialMonitor()
nnoremap \ad :call ArduinoDeploy()
nnoremap \ac :call ArduinoCompile()
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
vnoremap <silent> <Plug>IMAP_JumpBack `<i=IMAP_Jumpfunc('b', 0)
vnoremap <silent> <Plug>IMAP_JumpForward i=IMAP_Jumpfunc('', 0)
vnoremap <silent> <Plug>IMAP_DeleteAndJumpBack "_<Del>i=IMAP_Jumpfunc('b', 0)
vnoremap <silent> <Plug>IMAP_DeleteAndJumpForward "_<Del>i=IMAP_Jumpfunc('', 0)
nnoremap <silent> <Plug>IMAP_JumpBack i=IMAP_Jumpfunc('b', 0)
nnoremap <silent> <Plug>IMAP_JumpForward i=IMAP_Jumpfunc('', 0)
snoremap <silent> <Del> c
snoremap <silent> <BS> c
snoremap <silent> <C-Tab> :call UltiSnips#ListSnippets()
nmap <F8> :TagbarToggle
inoremap <silent> 	 =UltiSnips#ExpandSnippet()
imap <NL> <Plug>IMAP_JumpForward
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set backspace=indent,eol,start
set cinoptions=j1
set completeopt=preview,menuone
set cpoptions=BceFs
set expandtab
set exrc
set fileencodings=ucs-bom,utf-8,default
set grepprg=grep\ -nH\ $*
set guicursor=n-v-c:block-Cursor,i:ver100-iCursor,n-v-c:blinkon0,i:blinkwait10
set hlsearch
set nomodeline
set report=10000
set ruler
set runtimepath=~/.vim,~/.vim/bundle/nerdtree,~/.vim/bundle/restore_view,~/.vim/bundle/syntastic,~/.vim/bundle/tabline.vim,~/.vim/bundle/tagbar,~/.vim/bundle/ultisnips,~/.vim/bundle/vim-airline,~/.vim/bundle/vim-airline-themes,~/.vim/bundle/vim-arduino-ino,~/.vim/bundle/vim-ipython,~/.vim/bundle/vim-slime,~/.vim/bundle/vimproc.vim,~/.vim/bundle/vimwiki,/usr/share/vim/vimfiles,/usr/share/vim/vim80,/usr/share/vim/vimfiles/after,~/.vim/bundle/ultisnips/after,~/.vim/after,~/.vim/eclim,~/.vim/eclim/after
set scrollopt=ver,jump,hor
set secure
set shiftwidth=4
set showtabline=2
set smartindent
set softtabstop=4
set statusline=%#warningmsg#%{SyntasticStatuslineFlag()}%*
set suffixes=.bak,~,.o,.h,.info,.swp,.obj,.info,.aux,.log,.dvi,.bbl,.out,.o,.lo
set tabline=%!airline#extensions#tabline#get()
set tabstop=4
set viminfo='20,\"500
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/projects/C_+_+/hreflex/TreadmillAutomation
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 src/SubjectInterface.qml
badd +1235 src/PerturbationTabWidget.cpp
badd +25 src/SubjectInterface.cpp
badd +41 build/cleanCmakeWindows.sh
badd +10 src/MainSubjectInterface.qml
badd +29 include/SubjectInterface.h
badd +52 src/SubjectInterfaceWidget.cpp
badd +1 src/Smiley.qml
badd +5 src/InstrumentationPanel.cpp
badd +26 include/InstrumentationPanel.h
badd +8 src/InstrumentationPanel.qml
badd +1 src/MainInstrumentationPanel.qml
badd +161 src/TreadmillAutomation.cpp
badd +314 include/PerturbationTabWidget.h
badd +7 src/SmileyGone.qml
badd +17 src/MouseInterface.cpp
badd +25 src/SubjectInterface.qml_bkup
badd +107 src/ParseRunProfile.cpp
badd +522 src/TreadmillAutomationDbIFace.cpp
badd +35 include/TreadmillAutomationDbIFace.h
badd +15 src/PersonSessionStimData.qml
badd +41 src/ConfigTabWidget.cpp
badd +172 src/Timer.qml
badd +20 include/ConfigTabWidget.h
badd +51 include/MouseInterface.h
badd +40 include/ParseRunProfile.h
badd +132 include/TreadmillAutomation.h
argglobal
silent! argdel *
$argadd src/SubjectInterface.qml
edit src/PerturbationTabWidget.cpp
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
argglobal
nnoremap <buffer> <silent>  
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=j1
setlocal cinwords=if,else,while,do,for,switch
set colorcolumn=110
setlocal colorcolumn=110
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=ClangComplete
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'cpp'
setlocal filetype=cpp
endif
setlocal fixendofline
set foldcolumn=1
setlocal foldcolumn=1
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=4
setlocal foldmarker={{{,}}}
set foldmethod=syntax
setlocal foldmethod=syntax
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=-1
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal nomodeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
set numberwidth=3
setlocal numberwidth=3
setlocal omnifunc=ClangComplete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal signcolumn=auto
setlocal smartindent
setlocal softtabstop=4
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%!airline#statusline(1)
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'cpp'
setlocal syntax=cpp
endif
setlocal tabstop=4
setlocal tagcase=
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal undolevels=-123456
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
5
normal! zo
890
normal! zo
948
normal! zo
1069
normal! zo
1153
normal! zo
1176
normal! zo
1190
normal! zo
1293
normal! zo
1293
normal! zo
1334
normal! zo
1337
normal! zo
1340
normal! zo
1217
normal! zo
1219
normal! zo
1334
normal! zo
1339
normal! zo
1341
normal! zo
1344
normal! zo
let s:l = 1354 - ((35 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1354
normal! 040|
lcd ~/projects/C_+_+/hreflex/TreadmillAutomation
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
