      program main

      implicit none

      character (len=5) :: i_char
      
      print *, "Ten: ", 10

      print "(3i5)", 7, 6, 8
      print "(i5)", 7, 6, 8

      print "(2f8.5)", 3.1415, 1.234

      print "(/, 2a8)", "string1", "string2"

      print "(e10.3)", 123.456

      print "(a6,i2)", "Hello ", 12

      write (i_char, "(i5)") 10
      print "(a,a)", "Ten: ", adjustl(i_char)
      
      end program main
      
