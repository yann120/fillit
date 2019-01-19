def set_piece(grid, i, j, piece, char)
  piece[:coordinates].each do |coordinate|
    grid[i + coordinate[0]][j + coordinate[1]] = char
  end
  return grid
end

def print_grid(grid)
  puts "Vous avez placé #{grid.flatten.join.chars.uniq.size - 1} pièces."
  puts ""
  grid.each { |line| puts line.join }
  puts ""
end

def minimal_grid_size(n)
  grid_size = 2
  while grid_size ** 2 < n * 4
    grid_size += 1
  end
  return grid_size
end

def place_piece(grid, piece, i, j)
  piece[:coordinates].each do |coordinate|
    if grid[i + coordinate[0]][j + coordinate[1]] != "."
      return false
    end
  end
  set_piece(grid, i, j, piece, piece[:letter])
  return true
end
