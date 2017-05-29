n = gets.chomp.to_i
k = 0
while n > 0
    n -= 1
    i = n
    while i > 0
        i -= 1
        print " "
    end
    i = k
    while i > 0
        i -= 1
        print "*"
    end
    i = k+1
    while(i > 0)
        i -=1
        print "*"
    end
    print "\n"
    k += 1
end
