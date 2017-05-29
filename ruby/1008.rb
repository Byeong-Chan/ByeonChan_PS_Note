tmp = []
_in = gets.chomp
_in.scan(/\d+/) do |num|
    tmp << num.to_f
end
y = tmp.pop
x = tmp.pop
puts x/y
