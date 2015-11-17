# .latexmkrc starts

print("Hello!  I'm a .latexmkrc\n");

$pdf_mode = 1;
$shell_escape = 1;
$pdflatex = 'xelatex --shell-escape %O %S -file-line-error -synctex=1';
# .latexmkrc ends
