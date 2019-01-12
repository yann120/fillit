def print_error(kind)
  if kind == :usage
    puts "usage: ./fillit source_file"
  else
    puts "error"
  end
end