PROGRAM SumFortran

  IMPLICIT NONE 

  REAL*8, ALLOCATABLE :: t(:)
  REAL *8 :: r
  INTEGER :: n, j

  n = 32
  r = 0.0
  
  OPEN (1, file = 'test/data32.txt')
  
  ALLOCATE ( t(n))
  
  READ (1,*)t          

  DO j = 1, n
     r = r + t(j)
  END DO

  PRINT *, "Sum = ", r
  
  DEALLOCATE(t)

  CLOSE(1)

END PROGRAM SumFortran

