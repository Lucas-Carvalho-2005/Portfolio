# Definindo a classe Animal
package Animal;

sub new {
    my ($class, $nome) = @_;
    my $self = { nome => $nome };
    bless $self, $class;
    return $self;
}
sub fazer_barulho {
    my $self = shift;
    print "Barulho genérico de animal.\n";
}
1;
# Definindo a classe Cachorro que herda de Animal
package Cachorro;
our @ISA = qw(Animal);
sub fazer_barulho {
    my $self = shift;
    print "Au au!\n";
}
1;