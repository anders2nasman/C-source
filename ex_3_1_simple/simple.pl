perl -ne 'split;foreach(@_){/((\d+\.?\d*)/and(push(@a,$1);}for($i=0,$r=$#a;$i<$#a;$i++,$i--){print "$a[$i] $a[$r]\n";$g+=$a[$i];}print "avg=",$g/$#a,"\n"'
perl -ne 'split;foreach(@_){/(\d+\.?\d*)/and(push(@a,$1))}for($i=0,$r=$#a;$i<$#a;$i++,$r--){print "$a[$i] $a[$r]\n";$g+=$a[$i];}print "avg=",$g/$#a,"\n"'


perl -ne 'split;foreach(@_){/(\d+\.?\d*)/and(push(@a,$1))}for($i=0,$r=$#a;$i<=$#a;$i++,$r--){print "$a[$i] $a[$r]\n";$g+=$a[$i];}print "avg=",$g/$#a,"\n" if($#a>0);@a=undef;'


perl -ne 'split;foreach(@_){/(\d+\.?\d*)/and(push(@a,$1))}for($i=0,$r=$#a-1;$i<=$#a;$i++,$r--){print "$a[$i] $a[$r]\n";$g+=$a[$i];}print "avg=",$g/($#a+1),"\n" if($#a>0);@a=undef;'

while (<>) {
	split;
	foreach(@_){
		/(\d+\.?\d*)/and(push(@a,$1))
	}
	@a=sort(@a);
	for($i=0,$r=$#a-1;$i<=$#a;$i++,$r--) {
		print "$a[$i] $a[$r]\n";
		$g+=$a[$i];
	}
	print "avg=",$g/($#a+1),"\n" if($#a>0);
	@a=undef;
}

perl -ne 'split;foreach(@_){/(\d+\.?\d*)/and(push(@a,$1))};@a=sort(@a);for($i=0,$r=$#a-1;$i<=$#a;$i++,$r--){print "$a[$i] $a[$r]\n";$g+=$a[$i];}print "avg=",$g/($#a+1),"\n" if($#a>0);@a=undef;'




while (<>) {
	split;
	foreach(@_) { /(\d+\.?\d*)/and(push(@a,$1)) }
	@a=sort(@a);
	foreach(@a) { $g+=$_; print "$_\n"; }
	foreach($#a..0) { print "$a[$_] \n"; }
	print "avg=",$g/($#a+1),"\n" if($#a>0);
	@a=undef;
}



