package Forma;
sub new {
    my ($class) = @_;
    die "Não é permitido instanciar a classe abstrata Forma\n"
        if $class eq 'Forma';
    return bless {}, $class;
}

sub area {
    die "Método abstrato! Deve ser implementado pela subclasse.\n";
}
