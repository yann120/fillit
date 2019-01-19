require_relative "validation"
require_relative "pieces"
require_relative "helper"
require_relative "fillit"
require_relative "grid"

init_time = Time.now
filepath = ARGV[0]
VERBOSE = ["-v", "--verbose"].include?(ARGV[1]) ? "ON" : "OFF"

filetext = File.read(filepath)
if file_is_valid(filetext)
  pieces = read_pieces_from_file(filetext)
  solved_grid = fillit(pieces)
  print_grid(solved_grid)
  open("logs.out", "a") { |f| f << "#{solved_grid.size},#{Time.now - init_time}\n" }
else
  print_error(:usage)
end
