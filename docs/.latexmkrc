# .latexmkrc starts

$pdf_mode = 1;
$shell_escape = 1;
$pdflatex = 'xelatex --shell-escape %O %S -synctex=1 --enable-write18 -interaction=batchmode';
# .latexmkrc ends
