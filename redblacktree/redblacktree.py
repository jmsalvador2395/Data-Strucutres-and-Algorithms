class RedBlackTree:
	class _node:
		def __init__(self):
			self.color=None 		#b for black and r for red
			self.key=None			#data
			self.right=None			#right child
			self.left=None			#left child
			self.p=None				#parent

	def __init__(self):
		
		self.root=RedBlackTree._node()
		self.root.color='b'

	#need to implement
	def __str__(self):
		return 'blank'

	def root_color(self):
		return self.root.color

	#in the middle of implementing
	def _insert(self, key, node):
		return

	#in the middle of implementing
	def insert(self, key):
		if(this.root.data is None):
			this.root.data = key
		if(key>this.root.key):
			_insert(self, key, root.right)
		elif(key<this.root.key):
			_insert(self, key, root.left)
	
	def _black_height(self):
		return
			
	#need to implement
	def delete(self, key):
		return
		
	def _left_rotate(self, x):
		y=x.right					#make ptr to right child
		x.right=y.left				#change right child of x
		if(y.left is not None):		#make x the parent of y.left if not null
			y.left.p=x
		y.p=x.p						#set y's parent to x's parent
		if(x.p is None):			#check if x's parent is root
			self.root=y
		elif(x==x.p.left):			#check if x was a left node
			x.p.left=y
		else:						#x is resolved to be a right child
			x.p.right=y
		y.left=x
		x.p=y
	
	def _right_rotate(self, y):
		x=y.left
		y.left=x.right
		if(x.right is not None):
			x.right.p=y.left
		x.p=y.p
		if(y.p is None):
			self.root=x
		else if(y==y.p.left):
			y.p.left=x
		else:
			y.p.right=x
		x.right=y
		y.p=x
		return

