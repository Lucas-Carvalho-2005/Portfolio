package Subject;

use strict;
use warnings;

# Construtor
sub new {
    my $class = shift;
    my $self = {
        observers => [], # Lista de observadores
    };
    bless $self, $class;
    return $self;
}

# Adiciona um observador à lista
sub add_observer {
    my ($self, $observer) = @_;
    push @{$self->{observers}}, $observer;
}

# Remove um observador da lista
sub remove_observer {
    my ($self, $observer_to_remove) = @_;
    @{$self->{observers}} = grep { $_ != $observer_to_remove } @{$self->{observers}};
}

# Notifica todos os observadores
sub notify_observers {
    my ($self, $data) = @_;
    foreach my $observer (@{$self->{observers}}) {
        $observer->update($data);
    }
}

1;


package Observer;

use strict;
use warnings;

# Construtor
sub new {
    my ($class, $name) = @_;
    my $self = {
        name => $name,
    };
    bless $self, $class;
    return $self;
}

# Método para atualizar o observador
sub update {
    my ($self, $data) = @_;
    print "Observer " . $self->{name} . " recebeu a atualização: $data\n";
}

1;


use strict;
use warnings;

use Subject;
use Observer;

# Cria o sujeito (Subject)
my $subject = Subject->new();

# Cria observadores
my $observer1 = Observer->new("A");
my $observer2 = Observer->new("B");

# Adiciona os observadores ao sujeito
$subject->add_observer($observer1);
$subject->add_observer($observer2);

# Notifica os observadores
$subject->notify_observers("Nova mensagem!");

# Remove um observador e notifica novamente
$subject->remove_observer($observer1);
$subject->notify_observers("Mensagem após remover um observador.");
