      program main
      
      implicit none

      character *50 :: string1
      character *50 :: string2
      
      print *, "Enter a string: "
      read  *, string1, string2

      print *, "Hello ", trim(string1), " ", trim(string2)

      end program main
      
