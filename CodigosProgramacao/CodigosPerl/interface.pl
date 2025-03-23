package InterfaceForma;
use Carp;

sub verificar {
    my ($class, $objeto) = @_;
    for my $metodo (qw(area perimetro)) {
        croak "Método $metodo não implementado!"
            unless $objeto->can($metodo);
    }
}

# Subclasse que implementa a interface
package Circulo;
our @ISA = qw(InterfaceForma);

sub new { bless {}, shift }
sub area { "Calculando área do círculo..." }
sub perimetro { "Calculando perímetro do círculo..." }

# Validação
package main;
my $circulo = Circulo->new();
InterfaceForma::verificar($circulo); # OK
