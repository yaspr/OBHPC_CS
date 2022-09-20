      program main

      implicit none

      real :: n1 = 1.11111111111111
      real :: n2 = 1.11111111111111

      double precision :: d1 = 1.1111111111111111d+0
      double precision :: d2 = 1.1111111111111111d+0

      real :: rand(1)

      integer :: low = 1, high = 10

      print "(a8, i1)", "5 + 4 = ", (5 + 4)
      print "(a8, i1)", "5 - 4 = ", (5 - 4)
      print "(a8, i2)", "5 * 4 = ", (5 * 4)
      print "(a8, i1)", "5 / 4 = ", (5 / 4)
      print "(a8, i1)", "5 % 4 = ", mod(5, 4)
      print "(a7, i3)", "5 ** 4 = ", (5 ** 4)

      print "(f17.15)", n1 + n2
      print "(f17.15)", d1 + d2

      call random_number(rand)
      print "(i2)", low + floor((high + 1 - low) * rand)
      
      end program main
