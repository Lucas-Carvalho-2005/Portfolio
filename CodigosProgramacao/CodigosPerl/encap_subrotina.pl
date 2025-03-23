package Animal;

sub new {
    my ($class, %args) = @_;
    my $self = {};
    my $atributos = {
        _nome  => $args{nome} || "Desconhecido",
        _idade => $args{idade} || 0,
    };

    $self->{_get_attr} = sub {
        my ($attr) = @_;
        return $atributos->{$attr};
    };

    $self->{_set_attr} = sub {
        my ($attr, $valor) = @_;
        $atributos->{$attr} = $valor;
    };

    bless $self, $class;
    return $self;
}

sub get_nome {
    my $self = shift;
    return $self->{_get_attr}->('_nome');
}

sub set_nome {
    my ($self, $novo_nome) = @_;
    $self->{_set_attr}->('_nome', $novo_nome) if defined $novo_nome;
}

sub get_idade {
    my $self = shift;
    return $self->{_get_attr}->('_idade');
}

sub set_idade {
    my ($self, $nova_idade) = @_;
    $self->{_set_attr}->('_idade', $nova_idade) if defined $nova_idade;
}

1;
