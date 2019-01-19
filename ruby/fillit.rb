require_relative "grid"

def fillit(pieces)
  grid_size = minimal_grid_size(pieces.count)
  puts "Current grid size: #{grid_size}"

  grid = create_grid(grid_size)
  while !fit_pieces_inside_grid(grid, pieces)
    puts "Current grid size: #{grid_size}"
    grid_size += 1
    grid = create_grid(grid_size)
  end
  return grid
end

def minimal_grid_size(n)
  grid_size = 2
  while grid_size ** 2 < n * 4
    grid_size += 1
  end
  return grid_size
end

def fit_pieces_inside_grid(grid, pieces)
  i = 0
  piece = pieces[0]
  if piece.nil?
    return true
  end
  while i < grid.size - piece[:height] + 1
    j = 0
    while j < grid.size - piece[:width] + 1
      if place_piece(grid, piece, i, j)
        if fit_pieces_inside_grid(grid, pieces[1..])
          return true
        else
          set_piece(grid, i, j, piece, ".")
        end
      end
      j += 1
    end
    i += 1
  end
  return false
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
