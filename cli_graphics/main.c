# perl
my $commands = {
    'circle'=>{cmd=>qr("circle(\s*\%d\s*,\s*\%d\s*\s*\%d\s*)"),fun=>circle},
    'rect'=>{cmd=>qr("rect(\s*\%d\s*,\s*\%d\s*\s*\%d\s*)"),fun=>rect},
    'line'=>{cmd=>qr("line(\s*\%d\s*,\s*\%d\s*\s*\%d\s*)"),fun=>line},
    'elli'=>{cmd=>qr("elli(\s*\%d\s*,\s*\%d\s*\s*\%d\s*)"),fun=>elli},
}
sub circle { print join(',',@_)."\n"; }
sub rect { print join(',',@_)."\n"; }
sub line { print join(',',@_)."\n"; }
sub elli { print join(',',@_)."\n"; }
sub interpret {
    shift;
    /^([\s]+)/ and ( &$commands->{$1} if ref($commands->{$1}) eq 'CODE' );
}
while (<>) {
    interpret($_);
}
