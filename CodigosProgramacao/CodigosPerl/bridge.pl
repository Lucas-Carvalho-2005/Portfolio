#!/usr/bin/perl
use strict;
use warnings;

# Interface para dispositivos
package Device;
sub new {
    my $class = shift;
    return bless { volume => 50, is_on => 0 }, $class;
}

sub turn_on {
    die "Método 'turn_on' precisa ser implementado pela subclasse!";
}

sub turn_off {
    die "Método 'turn_off' precisa ser implementado pela subclasse!";
}

sub set_volume {
    my ($self, $volume) = @_;
    $self->{volume} = $volume if $volume >= 0 && $volume <= 100;
}

sub get_volume {
    my $self = shift;
    return $self->{volume};
}

sub is_on {
    my $self = shift;
    return $self->{is_on};
}

# Implementação específica de TV
package TV;
use parent 'Device';

sub turn_on {
    my $self = shift;
    $self->{is_on} = 1;
    print "A TV está ligada.\n";
}

sub turn_off {
    my $self = shift;
    $self->{is_on} = 0;
    print "A TV está desligada.\n";
}

# Implementação específica de Rádio
package Radio;
use parent 'Device';

sub turn_on {
    my $self = shift;
    $self->{is_on} = 1;
    print "O Rádio está ligado.\n";
}

sub turn_off {
    my $self = shift;
    $self->{is_on} = 0;
    print "O Rádio está desligado.\n";
}

# Interface para controles remotos
package RemoteControl;
sub new {
    my ($class, $device) = @_;
    return bless { device => $device }, $class;
}

sub toggle_power {
    my $self = shift;
    if ($self->{device}->is_on()) {
        $self->{device}->turn_off();
    } else {
        $self->{device}->turn_on();
    }
}

sub volume_up {
    my $self = shift;
    my $volume = $self->{device}->get_volume();
    $self->{device}->set_volume($volume + 10);
    print "Volume: " . $self->{device}->get_volume() . "\n";
}

sub volume_down {
    my $self = shift;
    my $volume = $self->{device}->get_volume();
    $self->{device}->set_volume($volume - 10);
    print "Volume: " . $self->{device}->get_volume() . "\n";
}

# Controle remoto avançado com funcionalidade extra
package AdvancedRemoteControl;
use parent 'RemoteControl';

sub mute {
    my $self = shift;
    $self->{device}->set_volume(0);
    print "O volume foi silenciado.\n";
}

# Código principal
package main;

# Instanciando os dispositivos
my $tv = TV->new();
my $radio = Radio->new();

# Usando controle básico para TV
my $tv_remote = RemoteControl->new($tv);
$tv_remote->toggle_power();   # Liga a TV
$tv_remote->volume_up();      # Aumenta o volume da TV

# Usando controle avançado para Rádio
my $radio_remote = AdvancedRemoteControl->new($radio);
$radio_remote->toggle_power();  # Liga o Rádio
$radio_remote->mute();          # Silencia o Rádio

# Saída do programa:
# A TV está ligada.
# Volume: 60
# O Rádio está ligado.
# O volume foi silenciado.
