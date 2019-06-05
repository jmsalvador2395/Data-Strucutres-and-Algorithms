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
			return 'empty'
		return self._to_string(self.root)

	def _to_string(self, vertex):
		if(vertex is None):
			return ''

		s=vertex.color+str(vertex.key)
		s+='('

		if(vertex.left is not None):
			s+=self._to_string(vertex.left)

		s+=')'
		s+='{'
		if(vertex.right is not None):
			s+=self._to_string(vertex.right)

		s+='}'
		return s

	#generic binary tree insert
	def _insert(self, z):
		y=None						#parent of current point
		x=self.root					#point of insertion

		while (x is not None):		#loop until point of insertion is found
			y=x
			if(z.key<x.key):
				x=x.left

			else:
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
			if((x.p.p.left is not None) and (x.p.key==x.p.p.left.key)):		#goes here if x's parent is a left child
				y=x.p.p.right

				if((y is not None) and (y.color=='r')):			#recolor if the uncle of x is red
					x.p.color='b'
					y.color='b'
					x.p.p.color='r'
					x=x.p.p

				elif((x.p.right is not None) and (x.key==x.p.right.key)):	#rotate x's parent if path to grandparent is a triangle
					x=x.p
					x=self._left_rotate(x)

				else:						#rotate and recolor x's grandparent if path to it is in a straight line
					x.p.color='b'			
					x.p.p.color='r'		
					x=self._right_rotate(x.p.p)

			else:	#goes here if x's parent is a right child. same as if clause but left and right are switched
				y=x.p.p.left

				if((y is not None) and (y.color=='r')):
					x.p.color='b'
					y.color='b'
					x.p.p.color='r'
					x=x.p.p

				elif((x.p.left is not None) and (x.key==x.p.left.key)):
					x=x.p
					x=self._right_rotate(x)

				else:					
					x.p.color='b'			
					x.p.p.color='r'		
					x=self._left_rotate(x.p.p)
			
		self.root.color='b'

	def _black_height(self):
		return
			
	def _left_rotate(self, x):
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
		return x
	
	def _right_rotate(self, y):
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
		return x

	def _rb_transplant(self, u, v):
		if(u.p == None):
			self.root=v
		elif((u.p.left is not None) and (u==u.p.left)):
			u.p.left=v
		else:
			u.p.right=v
		v.p=u.p
		return v
	
	def _tree_minimum(self, x):
		while(x.left!=None):
			x=x.left
		return x

	def rb_delete(self, z):
		y=z
		y_original_color=y.color
		if(z.left==None):
			self._rb_transplant(z, z.right)
		elif(z.right==None):
			x=z.left
			self._rb_transplant(z, z.left)
		else:
			y=self._tree_minimum(self.right)
			y_original_color=y.color
			x=y.right
			if(y.p==z):
				x.p=y
			else:
				y=self._rb_transplant(y, y.right) #may not have to set y like this
				y.right=z.right
				y.right.p=y
			y=self_rb_transplant(z, y)	#may not have to set y like this
			y.left=z.left
			y.left.p=y
			y.color=z.color
		if(y_original_color=='b'):
			_rb_delete_fixup(x)

	def _rb_delete_fixup(self, x):
		while x.data!=root.data and x.color=='b':
			if x==x.p.left:
				w=x.p.right
				if w.color == 'r'
					w.color='b'
					x.p.color='r'
					self._left_rotate(x.p)
					w=x.p.right
				if w.left.color == 'b' and w.right.color == 'b':
					w.color='r'
					x=x.p
				elif w.right.color == 'b':
					w.left.color = 'b'
					w.color='r'
					self._right_rotate(w)
					w=x.p.right
				w.color=x.p.color
				x.p.color='b'
				self._left_rotate(x.p)
				x=self.root
			else:
				if x==x.p.right:
					w=x.p.left
					if w.color == 'r'
						w.color='b'
						x.p.color='r'
						self._right_rotate(x.p)
						w=x.p.left
					if w.right.color == 'b' and w.left.color == 'b':
						w.color='r'
						x=x.p
					elif w.left.color == 'b':
						w.right.color = 'b'
						w.color='r'
						self._left_rotate(w)
						w=x.p.left
					w.color=x.p.color
					x.p.color='b'
					self._right_rotate(x.p)
					x=self.root

		return
