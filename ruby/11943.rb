x = gets.chomp;
k = [];
x.scan(/\S+/) do |num|
    k << num.to_i;
end
orange1 = k.pop;
apple1 = k.pop;

x = gets.chomp;
k = [];
x.scan(/\S+/) do |num|
    k << num.to_i;
end
orange2 = k.pop;
apple2 = k.pop;

if apple1 + orange2 < apple2 + orange1
    puts apple1 + orange2
    else
    puts apple2 + orange1
end
