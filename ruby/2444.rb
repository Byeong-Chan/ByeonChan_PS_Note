n = gets.chomp.to_i
m = n - 1;
k = 0;
while n > 0
    n -= 1
    n.times do
        print " "
    end
    k.times do
        print "*"
    end
    k += 1
    k.times do
        print "*"
    end
    print "\n"
end
while m > 0
    n += 1
    n.times do
        print " "
    end
    m.times do
        print "*"
    end
    m -= 1
    m.times do
        print "*"
    end
    print "\n"
end
