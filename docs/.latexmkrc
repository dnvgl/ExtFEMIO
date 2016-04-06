# .latexmkrc starts

$pdf_mode = 1;
$shell_escape = 1;
$pdflatex = 'xelatex --shell-escape %O %S -file-line-error -synctex=1 --enable-write18 --shell-escape';
# .latexmkrc ends
