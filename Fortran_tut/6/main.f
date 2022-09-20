      program main

      implicit none


      integer :: n = 0, m = 1
      integer :: num = 7

      do n = 1, 10, 2

         print "(i1)", n
      end do

      do while (m < 20)

         if (mod(m, 2) == 0) then
            print *, m, " even"
            m = m + 1
            cycle
         end if
         
         m = m + 1
         
         if (m >= 10) then
            exit
         end if
      end do
      
      end program main
