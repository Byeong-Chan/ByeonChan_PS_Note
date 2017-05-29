n = gets.chomp.to_i
k = []
_in = gets.chomp
_in.scan(/\d+/) do |num|
    k << num.to_i
end
k = k.sort
if n & 1 == 1
    puts k[n/2] * k[n/2]
    else
    puts k[0] * k[n-1]
end
