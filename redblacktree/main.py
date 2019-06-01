import redblacktree
import random

def main():
	rbt=redblacktree.RedBlackTree()
	inp=random.sample(range(1, 100), 10)
	'''
	inp=[1,0,2]
	'''
	for i in inp:
		print 'insert ' + str(i)
		rbt.rb_insert(i)
		print rbt
		print ''
	
if __name__ == '__main__':
	main()
