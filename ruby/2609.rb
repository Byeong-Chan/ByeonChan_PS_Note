x = gets.chomp
k = []
x.scan(/\S+/) do |num|
    k << num.to_i
end
p = k.pop
q = k.pop
pq = p * q
while p % q != 0
    tmp = q
    q = p % q
    p = tmp
end
puts q
puts pq / q
