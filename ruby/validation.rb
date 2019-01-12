class Validator
  def initialize(filepath)
    @filepath = filepath
    @filetext = File.read(filepath)
  end

  def validate
    is_valid = has_at_least_one_piece &&
      valid_number_of_lines &&
      valid_chars &&
      valid_width &&
      valid_number_of_chars &&
      valid_shapes
    return is_valid, @filetext
  end

  private
  
  def valid_chars
    i = 1
    @filetext.each_line do |line|
      if i % 5 == 0
        return false if line != "\n"
      else
        line.chars.each { |char| return false unless ["\n", "#", "."].include? char }
      end
      i += 1
    end
  end
  
  def valid_width
    i = 1
    @filetext.each_line do |line|
      if i % 5 == 0
        return false if line.chars.count != 1
      else
        return false if line.chars.count != 5
      end
      i += 1
    end
    return true
  end
  
  def valid_number_of_chars
    i = 1
    hashtags = 0
    points = 0
  
    @filetext.each_line do |line|
      if i % 5 == 0
        hashtags = 0
        points = 0
      end
  
      line.chars.each do |char|
        hashtags += 1 if char == "#"
        points += 1 if char == "."
      end
  
      if i % 5 == 4
        return false if hashtags != 4 || points != 12
      end
      i += 1
    end
    return true
  end
  
  def valid_shapes
    @filetext.blocks.each do |block_str|
      # read block into an array of arrays
      hashtags_with_two_neighbors = 0
      block = block_string_to_array(block_str)
      for i in 0..3
        for j in 0..3
          if block[i][j] == "#"
            hashtags_with_two_neighbors += 1 if number_of_neighbors(block, i, j) == 2
          end
        end
      end
      return false if hashtags_with_two_neighbors < 2
    end
    return true
  end

  def has_at_least_one_piece
    number_of_lines >= 5
  end

  def number_of_neighbors(block, i, j)
    number_of_neighbors = 0
    directions = [[0,1], [1,0], [-1,0], [0,-1]]
    directions.each do |direction|
      if (0..3).to_a.include?(i + direction[0]) && (0..3).to_a.include?(j + direction[1])
        if block[i + direction[0]][j + direction[1]] == "#"
          number_of_neighbors += 1 
        end
      end
    end
    return number_of_neighbors
  end

  def valid_number_of_lines
    return number_of_lines % 5 == 0
  end

  def number_of_lines
    @filetext.lines.count + 1
  end
end

