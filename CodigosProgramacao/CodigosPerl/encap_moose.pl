package Animal;
use Moose;

has '_nome' => (
    is      => 'rw',         
    isa     => 'Str',         
    default => 'Desconhecido' 
);

has '_idade' => (
    is      => 'rw',          
    isa     => 'Int',        
    default => 0              
);

sub get_nome {
    my $self = shift;
    return $self->_nome;     
}

sub set_nome {
    my ($self, $novo_nome) = @_;
    $self->_nome($novo_nome); 
}

sub get_idade {
    my $self = shift;
    return $self->_idade;    
}

sub set_idade {
    my ($self, $nova_idade) = @_;
    $self->_idade($nova_idade); 
}

1;