      program main

      implicit none

      integer :: a = 16

      if ((a >= 5) .and. (a <= 10)) then
         print *, "Between 5 and 10"
      else if ((a >= 10)) then
         print *, "Greater than 10"
      end if

      print *, .true. .or. .false.
      print *, .not. .true.
      print *, 5 /= 9
      print *, 'a' < 'b'

      select case (a)
      case (5:10)
         print *, "Between 5 and 10"
         
      case (11, 12, 13, 14)
         print *, "11, 12, 13, 14"
         
      case default
         print *, "Unknown!"
         
      end select
      
      end program main
      
