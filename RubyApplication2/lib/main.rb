# To change this template, choose Tools | Templates
# and open the template in the editor.

def spans arr
  n = arr.length
  s = []
  arr.each_with_index do |val,i|
    if i == 0
      s << 1
    elsif val > arr[i-1]
      s << s[i-1] + 1
    else
      s << 1
    end
  end
  s
end

p spans([6,3,4,5,2])