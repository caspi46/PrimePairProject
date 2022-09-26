import java.util.InputMismatchException;
import java.lang.Math;

/*
 * PrimeCalc class (extends PrimeCalcJava)
 */
public class PrimeCalcs extends PrimeCalcJava{
	/*
	 * Private variables
	 */
	private int gap;
	private int determineNum = 2;
	private int pairNum;
	private int [][] pairList;
	private int count = 0;
	private int rangeNum;
	private int pairListSize;
	final java.util.Scanner input = new java.util.Scanner(System.in);
	
	/*
	 * Private Functions
	 */
	
	/*
	 * Function Name: isPrime
	 * Parameter: integer checkNum 
	 * Return Value: boolean
	 * check if the number (parameter) is prime
	 */
	private boolean isPrime(int checkNum) {
		for (int i = 2; i < checkNum; ++i) {
			if (checkNum % i  == 0)
				return false;
		}
		return true;
	}
	
	/*
	 * Function Name: setPair
	 * Parameter: integer max
	 * Return Value: Boolean
	 * set Prime pair
	 */
	private boolean setPair(int max) {
		for (int i = 0; i < pairNum; ++i){
			pairList[count][i] = max - (pairNum - 1 - i) * gap;
		}
		++count;
		return true;
	}
	
	/*
	 * Function Name: checkPrimePair
	 * Parameter: integer index
	 * Return Value: Boolean
	 * check if the number have number(s) (depends on pair #) with a specific gap & is prime
	 */
	private boolean checkPrimePair(int index) {
		return (index - ((pairNum - 1) * gap) > 1 && isPrime(index));
	}
	
	/*
	 * Function Name: checkBefores
	 * Parameter: integer index
	 * Return Value: Boolean
	 * check if the previous number(S) are prime
	 */
	private boolean checkBefores(int index) {
		int[] tempPair = new int[pairNum];
		int checkBefore = index - gap;
		for (int i = 0; i < pairNum - 1; ++i) {
			if (!isPrime(checkBefore))
				return false;
			tempPair[i] = checkBefore;
			checkBefore -= gap;
		}
		return true;
		
	}
	
	/*
	 * Public Functions
	 */
	
	/*
	 * SETTERS
	 */
	/*
	 * Function Name: setGap
	 * Parameter: None
	 * Return Value: None
	 * set a gap variable
	 */
	public void setGap() {
		while (true) {
			try {
				System.out.print("Enter a gap: ");
				gap = Math.abs(input.nextInt());
				input.nextLine();
				if (gap == 0)
					throw new InputMismatchException();
				break;
			}
			catch(InputMismatchException ime) {
				System.out.println("Invalid Input, try again! Must be a integer value");
			}
		}
		
	}
	/*
	 * Function Name: setPairNum
	 * Parameter: None
	 * Return Value: None
	 * set # of the prime number in the prime pair
	 */
	public void setPairNum() {
		while (true) {
			try {
				System.out.print("Enter # of numbers in the pair: ");
				pairNum = Math.abs(input.nextInt());
				input.nextLine();
				if (pairNum == 0)
					throw new InputMismatchException();
				break;
			}
			catch(InputMismatchException ime) {
				System.out.println("Invalid Input,try again! Must be a integer value");
			}
		}	
	}
	
	/*
	 * Function Name: setRange
	 * Parameter: None
	 * Return Value: None
	 * set the range to calculate the prime pairs
	 */
	public void setRange() {
		while (true) {
			try {
				System.out.print("Enter the range to calculate: ");
				rangeNum = Math.abs(input.nextInt());
				input.nextLine();
				if (rangeNum == 0)
					throw new InputMismatchException();
				break;
			}
			catch(InputMismatchException ime) {
				System.out.println("Invalid Input, try again! Must be a positive integer");
			}
		}
	}
	
	/*
	 * Function Name: setPRivates
	 * Parameter: None
	 * Return Value: None
	 * set the private variables
	 */
	public void setPrivates() {
		setGap();
		setPairNum();
		setRange();
		setPairList();
	}
	
	/*
	 * Function Name: setPairList
	 * Parameter: None
	 * Return Value: None
	 * set a prime pair list
	 * - set the array size as range / # of primes in the pair -
	 */
	public void setPairList() {
		pairListSize = (rangeNum / pairNum);
		pairList = new int[pairListSize][pairNum];
	}
	
	public void calc() {
		for (int i = determineNum; i < rangeNum; ++i) {
			if (checkPrimePair(i)) {
				if (checkBefores(i))
					setPair(i);
			}
		}
	}
	
	/*
	 * Function Name: checkTypePair
	 * Parameter: None
	 * Return Value: None
	 * check the type of the prime pair
	 */
	public void checkTypePair() {
		if (gap == 2)
			System.out.println("Twin Prime: " );
		else if (gap == 4)
			System.out.println("Cousin Prime: ");
		else if (gap == 6)
			System.out.println("Sexy Prime: ");
		else
			System.out.println("Prime Numbers with " + gap + " gap: ");
	}
	
	/*
	 * Function Name: display
	 * Parameter: None 
	 * Return Value: None
	 * display prime pairs in the specific range that the user entered
	 */
	public void display() {
		checkTypePair();
		if (count == 0) {
			System.out.println("\tNO PRIME PAIR IN THE RANGE OF " + rangeNum);
		}
		else {
			for (int i = 0; i < count; ++i) {
				System.out.print("\t(");
				for (int j = 0; j < pairNum; ++j) {
					System.out.print(pairList[i][j]);
					if (j != pairNum - 1)
						System.out.print(", ");
				}
				System.out.print(")\n");
			}
			System.out.println("");
		}
		displayCount();
		
	}
	
	/*
	 * Function Name: displayCount
	 * Parameter: None
	 * Return Value: None
	 * print count, # of the prime pairs
	 */
	public void displayCount() {
		System.out.println("COUNT: " + count);
	}
	
}
