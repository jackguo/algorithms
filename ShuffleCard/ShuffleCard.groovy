/** Shuffle card
 *  http://group.jobbole.com/23572/
 */

def shuffle(original, res, n) {
  def indices = [n / 2 - 1, n - 1] as int[] 

  for (int i = n - 1; i >= 0; --i) {
    res[i] = original[indices[i % 2]--]
  }
}

def  shuffleKTimes(original, n, k) {
  def res = original.collect()
  while (k > 0) {
    shuffle(original, res, n)
    /* switch the two arrays */
    def tmp = original
    original = res
    res = tmp
    --k
  }

  return original
}

def parseLine(line) {
  line.split("\\s+").collect {
    it -> Integer.valueOf(it)
  }
}

def input = System.in.readLines()

if (input.size() % 2 == 0) {
  println "Invalid input!"
}

Iterator<String> iterator = input.iterator()
iterator.next()

while (iterator.hasNext()) {
  def info = parseLine(iterator.next())
  def original = parseLine(iterator.next())
  shuffleKTimes(original, info[0], info[1]).each {
    it -> print "$it "
  }

  println()
}
