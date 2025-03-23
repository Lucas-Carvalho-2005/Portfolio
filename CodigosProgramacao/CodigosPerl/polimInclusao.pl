#!/usr/bin/perl
use strict;
use warnings;

# Classe base
package Animal;
sub new {
    my ($classe, $nome) = @_;
    my $self = { nome => $nome };
    bless $self, $classe;
    return $self;
}

sub som {
    return "Algum som genérico";
}

sub falar {
    my $self = shift;
    print $self->{nome} . " diz: " . $self->som . "\n";
}

# Subclasse Cachorro
package Cachorro;
our @ISA = qw(Animal); # Herança
sub som {
    return "Au Au!";
}

# Subclasse Gato
package Gato;
our @ISA = qw(Animal); # Herança
sub som {
    return "Miau!";
}

# Código principal
package main;
my $cachorro = Cachorro->new("Snoopy");
my $gato = Gato->new("Garfield");

$cachorro->falar(); # Snoopy diz: Au Au
$gato->falar();     # Garfield diz: Miau