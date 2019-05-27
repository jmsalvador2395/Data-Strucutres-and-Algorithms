

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
	def insert(key):
		if(this.root.data is None):
			this.root.data = key
		if(key>this.root.key):
			_insert(self, key, root.right)
		elif(key<this.root.key):
			_insert(self, key, root.left)
			
	#need to implement
	def delete(self, key):
		return
		
	def _left_rotate(self, node):
		temp=node.right
		node.right=temp.left
		if(temp.left is not None):
			temp.left.p=node
		temp.p=node.p
		if(node.p is None):
			self.root=temp
		#elif(node == 						#<<<<<<<<<<<<<<<<<<<<<<<<
