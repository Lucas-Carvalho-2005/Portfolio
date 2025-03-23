package Animal;

sub new {
    my ($class, %args) = @_;
    my $self = {
        _nome  => $args{nome} || "Desconhecido", 
        _idade => $args{idade} || 0,          
    };
    bless $self, $class;
    return $self;
}

sub get_nome {
    my $self = shift;
    return $self->{_nome};
}

sub set_nome {
    my ($self, $novo_nome) = @_;
    $self->{_nome} = $novo_nome if defined $novo_nome;
}

sub get_idade {
    my $self = shift;
    return $self->{_idade};
}

sub set_idade {
    my ($self, $nova_idade) = @_;
    $self->{_idade} = $nova_idade if defined $nova_idade;
}

1;
