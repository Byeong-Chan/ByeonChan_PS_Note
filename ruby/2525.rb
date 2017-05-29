x = gets.chomp;
k = []
x.scan(/\S+/) do |num|
    k << num.to_i
end
minu = k.pop
hou = k.pop
plm = gets.chomp.to_i
allminu = hou*60 + minu + plm
allminu %= 1440
puts "#{allminu/60} #{allminu%60}”
