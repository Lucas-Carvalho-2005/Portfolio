package Classe;

use strict;
use warnings;
use overload
    "-" => "menos",
    "+" => "mais";

# Construtor
sub new {
    my ($class, $valor) = @_;
    return bless { valor => $valor }, $class;
}

# Método para o operador '-'
sub menos {
    my ($self, $outro) = @_;
    return __PACKAGE__->new($self->{valor} - $outro->{valor});
}

# Método para o operador '+'
sub mais {
    my ($self, $outro) = @_;
    return __PACKAGE__->new($self->{valor} + $outro->{valor});
}

# Getter para acessar o valor interno
sub valor {
    my ($self) = @_;
    return $self->{valor};
}

1;

# Código principal
package main;

use strict;
use warnings;

# Criando objetos
my $obj1 = Classe->new(10);
my $obj2 = Classe->new(5);

# Usando os operadores sobrecarregados
my $subtracao = $obj1 - $obj2; # Chamará o método menos
my $soma = $obj1 + $obj2; # Chamará o método mais

# Exibindo os resultados
print "Resultado menos: ", $resultado_menos->valor(), "\n"; # 5
print "Resultado mais: ", $resultado_mais->valor(), "\n";  # 15
package Classe;

use strict;
use warnings;
use overload
    "-" => "menos",
    "+" => "mais";

# Construtor
sub new {
    my ($class, $valor) = @_;
    return bless { valor => $valor }, $class;
}

# Método para o operador '-'
sub menos {
    my ($self, $outro) = @_;
    return __PACKAGE__->new($self->{valor} - $outro->{valor});
}

# Método para o operador '+'
sub mais {
    my ($self, $outro) = @_;
    return __PACKAGE__->new($self->{valor} + $outro->{valor});
}

# Getter para acessar o valor interno
sub valor {
    my ($self) = @_;
    return $self->{valor};
}

1;

# Código principal
package main;

use strict;
use warnings;

# Criando objetos
my $obj1 = Classe->new(10);
my $obj2 = Classe->new(5);

# Usando os operadores sobrecarregados
my $resultado_menos = $obj1 - $obj2; # Chamará o método menos
my $resultado_mais = $obj1 + $obj2; # Chamará o método mais

# Exibindo os resultados
print "Resultado menos: ", $resultado_menos->valor(), "\n"; # 5
print "Resultado mais: ", $resultado_mais->valor(), "\n";  # 15