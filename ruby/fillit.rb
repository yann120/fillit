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
        if fit_pieces_inside_grid(grid, pieces[1..-1])
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
