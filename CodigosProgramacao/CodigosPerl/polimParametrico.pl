#!/usr/bin/perl
use strict;
use warnings;

my $num = 3;
my $str = '4';

multPor3($num);
multPor3($str);

sub multPor3 {
    my $a = shift;
    my $m = $a * 3;
    print "$m\n";
}

