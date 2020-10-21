package recursion;

public class floodfill {

	public static void main(String[] args) {
		int a[][] = {{1,1,1,1,1,1,1,1},
				     {1,1,1,1,1,1,0,0},
				     {1,0,0,1,1,0,1,1},
				     {1,2,2,2,2,0,1,0},
				     {1,1,1,2,2,0,1,0},
				     {1,1,1,2,2,2,2,0},
				     {1,1,1,1,1,2,1,1},
				     {1,1,1,1,1,2,2,1}};
		printmatrix(a);
		System.out.println();
		fill( a, 4, 3, 3, 2);
		printmatrix(a);
		}

	static void fill(int a[][], int r, int c, int toFill, int prevFill) {
		int rows = a.length;
		int cols = a[0].length;
		
		if (r<0 || r>=rows || c<0 || c>=cols) {
			return;
		}
		if (a[r][c]!=prevFill) {
			return;
		}
		a[r][c] = toFill;
		
		fill( a, r-1, c, toFill, prevFill);
		fill( a, r, c+1, toFill, prevFill);
		fill( a, r+1, c, toFill, prevFill);
		fill( a, r, c-1, toFill, prevFill);
	}
	
	static void printmatrix(int a[][])
	{
		for(int i=0; i<a.length; i++) {
			for(int j=0; j<a[0].length; j++) {
				System.out.print(a[i][j]+" ");
			}
			System.out.println();
		}
	}
	}


