require_relative "validation"
require_relative "pieces"
require_relative "helper"
require_relative "fillit"

filepath = ARGV[0]
filetext = File.read(filepath)
file_is_valid = validate(filetext)

if file_is_valid
  pieces = read_pieces_from_file(filetext)
  solved_grid = fillit(pieces)
  print_grid(solved_grid)
else
  print_error(:usage)
end
