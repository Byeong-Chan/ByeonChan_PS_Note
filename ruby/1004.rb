t = gets.chomp.to_i
while t > 0
    t -= 1
    _in = gets.chomp
    k = []
    _in.scan(/\S+/) do |num|
        k << num.to_i
    end
    y2 = k.pop
    x2 = k.pop
    y1 = k.pop
    x1 = k.pop
    n = gets.chomp.to_i
    ans = 0;
    while n > 0
        n -= 1
        _in = gets.chomp
        _in.scan(/\S+/) do |num|
            k << num.to_i
        end
        r = k.pop
        dy = k.pop
        dx = k.pop
        ans += 1 if (dx-x1)*(dx-x1) + (dy-y1)*(dy-y1) < r*r && (dx-x2)*(dx-x2) + (dy-y2)*(dy-y2) > r*r
        ans += 1 if (dx-x1)*(dx-x1) + (dy-y1)*(dy-y1) > r*r && (dx-x2)*(dx-x2) + (dy-y2)*(dy-y2) < r*r
    end
    puts ans
end
