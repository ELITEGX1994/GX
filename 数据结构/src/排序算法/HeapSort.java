package 排序算法;

public class HeapSort {
	 
	public static void main(String[] args) {
		int[] arr = { 50, 10, 90, 30, 70,1231,1111, 40, 80, 60, 20 };
		System.out.println("排序之前：");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
 
		// 堆排序
		heapSort(arr);
 
		System.out.println();
		System.out.println("排序之后：");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}
 
	/**
	 * 堆排序
	 */
	private static void heapSort(int[] arr) { 
		// 将待排序的序列构建成一个大顶堆
		buildHeap(arr);
		/*
		for (int i = arr.length / 2; i >= 0; i--){ 
			heapAdjust(arr, i, arr.length); 
		}
		*/
		
		// 逐步将每个最大值的根节点与末尾元素交换，并且再调整二叉树，使其成为大顶堆
		for (int i = arr.length - 1; i > 0; i--) { 
			swap(arr, 0, i); // 将堆顶记录和当前未经排序子序列的最后一个记录交换
			heapAdjust(arr, 0, i); // 交换之后，需要重新检查堆是否符合大顶堆，不符合则要调整
		}
	}
 
	public static void buildHeap(int[] a) {
		for(int i=a.length/2;i>=0;i--) {
			heapAdjust(a,i,a.length);
		}
	}
	/**
	 * 构建堆的过程
	 * @param a 需要排序的数组
	 * @param i 需要构建堆的根节点的序号
	 * @param last 数组最后一位下标
	 */
	/*
	private static void heapAdjust(int[] a, int i, int last) {
		int childIndex;//子节点下标
		int fatherValue;//父节点值
		for (fatherValue = a[i]; leftChild(i) < last; i = childIndex) {
			childIndex = leftChild(i);
			
			// 如果左子树小于右子树，则需要比较右子树和父节点
			if (childIndex !=last-1 && a[childIndex] < a[childIndex + 1]) {
				childIndex++; // 序号增1，指向右子树
			}
			
			// 如果父节点小于孩子结点，则需要交换
			if (fatherValue < a[childIndex]) {
				swap(a, i, childIndex);
			} else {
				break; // 大顶堆结构未被破坏，不需要调整
			}
		}
	}

	// 获取到左孩子结点
	private static int leftChild(int i) {
		return 2 * i + 1;
	}
	*/
	
	public static void heapAdjust(int[] array, int index, int length) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = index;
        if (left < length && array[left] > array[index]) {
            largest = left;
        }
        if (right < length && array[right] > array[largest]) {
            largest = right;
        }
        if (index != largest) {
            swap(array, largest, index);
            heapAdjust(array, largest, length);
        }
    }
	
	// 交换元素位置
	private static void swap(int[] arr, int index1, int index2) {
		int tmp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = tmp;
	}
}
