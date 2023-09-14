/*
    ผู้ใช้ทำการกรอกค่าที่ต้องการสร้างอาเรย์(Array1 และ Array2) และให้ทำการผสานอาเรย์ทั้งสองมาเป็นอาเรย์ใหม่(Array3) และแสดงผลลัพธ์หลังจากการผสานกันแสดงผลจากมากไปน้อย
    
    Test case:
        Enter element of Array1 :
            4
        --| Array1 [0] : 
            9
        --| Array1 [1] : 
            7
        --| Array1 [2] : 
            6
        --| Array1 [3] : 
            3
        Enter element of Array2 :
            5
        --| Array2 [0] : 
            2
        --| Array2 [1] : 
            3
        --| Array2 [2] : 
            5
        --| Array2 [3] : 
            8
        --| Array2 [4] : 
            9
    Output:
        Merge Array1 & Array2 to Array3
        Array3 = 9 9 8 7 6 5 3 3 2
    
    Test case:
        Enter element of Array1 :
            8
        --| Array1 [0] : 
            7
        --| Array1 [1] : 
            8
        --| Array1 [2] : 
            9
        --| Array1 [3] : 
            6
        --| Array1 [4] : 
            1
        --| Array1 [5] : 
            2
        --| Array1 [6] : 
            8
        --| Array1 [7] : 
            3
            
        Enter element of Array2 :
            6
        --| Array2 [0] : 
            2
        --| Array2 [1] : 
            1
        --| Array2 [2] : 
            3
        --| Array2 [3] : 
            5
        --| Array2 [4] : 
            3
        --| Array2 [5] : 
            6
    Output:
        Merge Array1 & Array2 to Array3
        Array3 = 9 8 8 7 6 6 5 3 3 3 2 2 1 1
*/

#include <stdio.h>

int main() {
    
    int n1 , n2 , temp = 0 ;

    // สร้าง array ตัวแรก พร้อมรับค่า
    printf ( "Enter element of Array1 :\n" ) ;
    scanf ( "%d", &n1 ) ;
    int array1[ n1 ] ;
    for ( int i = 0 ; i < n1 ; i++ ) {
        printf ( "--| Array1 [%d] :\n", i ) ;
        scanf ( "%d", &array1[ i ] ) ;
    } // end for

    // สร้าง array ตัวที่ 2 พร้อมรับค่า
    printf ( "Enter element of Array2 :\n" ) ;
    scanf ( "%d", &n2 ) ;
    int array2[ n2 ] ;
    for ( int i = 0 ; i < n2 ; i++ ) {
        printf ( "--| Array2 [%d] : \n", i ) ;
        scanf ( "%d", &array2[ i ] ) ;
    } // end for

    // สร้าง array3 จากการรวมของ array1 และ array2
    printf ( "\n" ) ;
    int array3[ n1 + n2 ] ;
    for ( int  i = 0 ; i < n1 ; i++ ) {
        array3[ i ] = array1[ i ] ;
    }
    
    for ( int i = n1 ; i < n1 + n2 ; i++ ) {
        array3[ i ] = array2[ i - n1 ] ;
    }
    
    // เรียงเลขจากมากไปหาน้อย
    for ( int i = 0 ; i < n1 + n2 ; i++ ) {
        for ( int k = i + 1 ; k < n1 + n2 ; k++ ) {
            if ( array3[ i ] < array3[ k ] ) {
                temp = array3[ i ] ;
                array3[ i ] = array3[ k ] ;
                array3[ k ] = temp ;
            } // end if
        } // end for
    } // end for
    
    // แสดงค่า
    printf ( "Merge Array1 & Array2 to Array3\n" ) ;
    printf ( "Array3 =" ) ;
    for ( int i = 0 ; i < n1 + n2 ; i++ ) {
        printf( " %d", array3[ i ] ) ;
    }
    
    return 0 ;
} // end main