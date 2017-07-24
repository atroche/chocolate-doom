let &makeprg = "cd build && make"
autocmd! BufWritePost * make
