h = [[10], [1], [2, 4, 8, 6], [3, 9, 7, 1], [4, 6], [5], [6], [7, 9, 3, 1], [8, 4, 2, 6], [9, 1]]
h_size = [1, 1, 4, 4, 2, 1, 1, 4, 4, 2]
t = gets.chomp.to_i
x = 0
y = 0
while t > 0
    t -= 1
    _in = gets.chomp
    k = []
    _in.scan(/\d+/) do |num|
        k << num.to_i
    end
    y = k.pop
    x = k.pop
    tmp = x % 10
    y -= 1
    puts h[tmp][y%h_size[tmp]]
end
