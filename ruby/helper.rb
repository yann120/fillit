def print_error(kind)
  if kind == :usage
    puts "usage: ./fillit source_file"
  else
    puts "error"
  end
end

def block_string_to_array(block_str)
  return block_str.split("\n").each_with_object([]) { |block_line, b| b << block_line.chars }
end

class String
  def blocks
    self.split("\n\n")
  end
end

def set_axis_to_zero(piece)
  first_coordinate = piece[:coordinates][0]
  x_diff = 0 - first_coordinate[0]
  y_diff = 0 - first_coordinate[1]

  for i in 0..3
    piece[:coordinates][i][0] += x_diff
    piece[:coordinates][i][1] += y_diff
  end

  return piece
end