      program main

      implicit none

      real, parameter :: PI = 3.1415
      real :: r_num1 = 0.0, r_num2 = 0.0
      double precision :: dbl_num = 1.111111111111111d+0
      integer :: i_num1 = 0, i_num2 = 0
      logical :: exists = .true.
      character (len = 10) :: string
      complex :: com_num = (2.0, 4.0)

      print *, "Biggest real  : ", huge(r_num1)
      print *, "Biggest int   : ", huge(i_num1)
      print *, "Smallest real : ", tiny(r_num1)
      
      print "(a20, i4)", "sizeof(int)     = ", kind(i_num1)
      print "(a20, i4)", "sizeof(real)    = ", kind(r_num1)
      print "(a20, i4)", "sizeof(double)  = ", kind(dbl_num)
      print "(a20, i4)", "sizeof(logical) = ", kind(exists)
      
      end program main
      
