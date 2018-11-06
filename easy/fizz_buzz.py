import sys

def fb(n,f,b):
    if n%f == 0 and n%b == 0:
        return "FB"
    elif n%f == 0:
        return "F"
    elif n%b == 0:
        return "B"
    else:
        return str(n)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        with open(sys.argv[1]) as f:
            for line in f:
                nums = tuple(int(i) for i in line.strip().split(' ') if len(i) > 0)
                print (' '.join(fb(i,nums[0],nums[1]) for i in xrange(1,int(nums[2])+1))).strip()
