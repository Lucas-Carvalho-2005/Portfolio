package Pessoa;

sub new {
    my ($class, $nome, $idade) = @_;
    my $self = {
        nome  => $nome,
        idade => $idade,
    };
    bless $self, $class;
    return $self;
}
sub apresentar {
    my $self = shift;
    print "Olá, eu sou " . $self->{nome} . " e tenho " . $self->{idade} . " anos.\n";
}
1;