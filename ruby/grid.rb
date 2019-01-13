def set_piece(grid, i, j, piece, char)
  piece[:coordinates].each do |coordinate|
    grid[i + coordinate[0]][j + coordinate[1]] = char
  end
  return grid
end

def print_grid(grid)
  puts "Vous avez placé #{grid.flatten.join.chars.uniq.size - 1} pièces."
  puts ""

  grid.each do |line|
    puts line.join
  end

  puts ""
end
