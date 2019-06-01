class RedBlackTree:
	class _vertex:
		def __init__(self):
			self.color=None 		#b for black and r for red
			self.key=None			#key
			self.right=None			#right child
			self.left=None			#left child
			self.p=None				#parent

	def __init__(self):		
		self.root=None

	def __str__(self):

		if(self.root is None):
			return 'tree is empty'
		return self._to_string(self.root, s='')

	def _to_string(self, vertex, s):
		if(vertex is None):
			return ''
		s+=vertex.color+str(vertex.key)
		s+='('
		s+=self._to_string(vertex.left,s)
		s+=')'
		s+='{'
		s+=self._to_string(vertex.right,s)
		s+='}'
		return s

			#insert generic binary tree insert
	def _insert(self, z):
		y=None						#parent of current point
		x=self.root					#point of insertion
		while (x is not None):		#loop until point of insertion is found
			y=x
			if(z.key<x.key):
				print 'down and left'
				x=x.left
			else:
				print 'down and right'
				x=x.right
		z.p=y
		if(y is None):				#y is only none when the tree is empty
			self.root=z
			return self.root
		elif(z.key<y.key):
			y.left=z
			return y.left
		else:
			y.right=z
			return y.right
		
	#in the middle of implementing
	def rb_insert(self, key):
		x=RedBlackTree._vertex()
		x.key=key
		x=self._insert(x)
		x.color='r'
		while((x.key != self.root.key) and (x.p.color=='r')):
			print 'gets into the while loop'
			if(x.p.key==x.p.p.left.key):		#goes here if x's parent is a left child
				y=x.p.p.right

				if((y is not None) and (y.color=='r')):			#recolor if the uncle of x is red
					print 'case 1'
					x.p.color='b'
					y.color='b'
					x.p.p.color='r'

				elif(x.key==x.p.right.key):	#rotate x's parent if path to grandparent is a triangle
					print 'case 2'
					x=x.p
					self._left_rotate(x)

				else:						#rotate and recolor x's grandparent if path to it is in a straight line
					print 'case 3'
					x.p.color='b'			
					x.p.p.color='r'		
					self._right_rotate(x.p.p)

			else:	#goes here if x's parent is a right child. same as if clause but left and right are switched
				y=x.p.p.right

				if((y is not None) and (y.color=='r')):
					print 'case 1'
					x.p.color='b'
					y.color='b'
					x.p.p.color='r'

				elif(x.key==x.p.right.key):
					print 'case 2'
					x=x.p
					self._right_rotate(x)

				else:					
					print 'case 3'
					x.p.color='b'			
					x.p.p.color='r'		
					self._right_rotate(x.p.p)
			
		self.root.color='b'

	def _black_height(self):
		return
			
	#need to implement
	def delete(self, key):
		return
		
	def _left_rotate(self, x):
		print 'left rotate'
		y=x.right					#make ptr to right child
		x.right=y.left				#change right child of x
		if(y.left is not None):		#make x the parent of y.left if not null
			y.left.p=x
		y.p=x.p						#set y's parent to x's parent
		if(x.p is None):			#check if x's parent is root
			self.root=y
		elif(x==x.p.left):			#check if x was a left vertex
			x.p.left=y
		else:						#x is resolved to be a right child
			x.p.right=y
		y.left=x
		x.p=y
		return
	
	def _right_rotate(self, y):
		print 'right rotate'
		x=y.left
		y.left=x.right
		if(x.right is not None):
			x.right.p=y.left
		x.p=y.p
		if(y.p is None):
			self.root=x
		elif(y==y.p.left):
			y.p.left=x
		else:
			y.p.right=x
		x.right=y
		y.p=x
		return

