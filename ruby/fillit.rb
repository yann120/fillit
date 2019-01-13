def fillit(pieces)
  grid_size = minimal_grid_size(pieces.count)
  puts grid_size, pieces.count
end

def minimal_grid_size(n)
  grid_size = 2
  while (grid_size ** 2 < n * 4)
    grid_size += 1
  end
  return grid_size
end