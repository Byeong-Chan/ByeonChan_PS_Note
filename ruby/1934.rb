n = gets.chomp.to_i
while n > 0
    n -= 1
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
    puts pq / q
end
