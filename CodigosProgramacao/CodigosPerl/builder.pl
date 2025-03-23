package Meal;

use strict;
use warnings;

sub new {
    my ($class) = @_;
    my $self = {
        drink       => undef,
        main_course => undef,
        dessert     => undef,
    };
    bless $self, $class;
    return $self;
}

sub set_drink {
    my ($self, $drink) = @_;
    $self->{drink} = $drink;
}

sub set_main_course {
    my ($self, $main_course) = @_;
    $self->{main_course} = $main_course;
}

sub set_dessert {
    my ($self, $dessert) = @_;
    $self->{dessert} = $dessert;
}

sub show_meal {
    my ($self) = @_;
    print "Refeição:\n";
    print " - Bebida: " . ($self->{drink} // 'Nenhuma') . "\n";
    print " - Prato Principal: " . ($self->{main_course} // 'Nenhum') . "\n";
    print " - Sobremesa: " . ($self->{dessert} // 'Nenhuma') . "\n";
}

1;

package MealBuilder;

use strict;
use warnings;

# Interface para os Builders concretos
sub build_drink {
    die "O método 'build_drink' deve ser implementado pelo Builder concreto.\n";
}

sub build_main_course {
    die "O método 'build_main_course' deve ser implementado pelo Builder concreto.\n";
}

sub build_dessert {
    die "O método 'build_dessert' deve ser implementado pelo Builder concreto.\n";
}

sub get_meal {
    die "O método 'get_meal' deve ser implementado pelo Builder concreto.\n";
}

1;



package VegetarianMealBuilder;

use strict;
use warnings;
use parent 'MealBuilder';
use Meal;

sub new {
    my ($class) = @_;
    my $self = { meal => Meal->new() };
    bless $self, $class;
    return $self;
}

sub build_drink {
    my ($self) = @_;
    $self->{meal}->set_drink('Suco de Laranja');
}

sub build_main_course {
    my ($self) = @_;
    $self->{meal}->set_main_course('Lasanha Vegetariana');
}

sub build_dessert {
    my ($self) = @_;
    $self->{meal}->set_dessert('Salada de Frutas');
}

sub get_meal {
    my ($self) = @_;
    return $self->{meal};
}

1;

package MealDirector;

use strict;
use warnings;

sub new {
    my ($class, $builder) = @_;
    my $self = { builder => $builder };
    bless $self, $class;
    return $self;
}

sub construct_meal {
    my ($self) = @_;
    $self->{builder}->build_drink();
    $self->{builder}->build_main_course();
    $self->{builder}->build_dessert();
}

1;


use strict;
use warnings;

use VegetarianMealBuilder;
use NonVegetarianMealBuilder;
use MealDirector;

# Construindo uma refeição vegetariana
my $veg_builder = VegetarianMealBuilder->new();
my $veg_director = MealDirector->new($veg_builder);
$veg_director->construct_meal();
my $veg_meal = $veg_builder->get_meal();
$veg_meal->show_meal();

# Construindo uma refeição não vegetariana
my $non_veg_builder = NonVegetarianMealBuilder->new();
my $non_veg_director = MealDirector->new($non_veg_builder);
$non_veg_director->construct_meal();
my $non_veg_meal = $non_veg_builder->get_meal();
$non_veg_meal->show_meal();
