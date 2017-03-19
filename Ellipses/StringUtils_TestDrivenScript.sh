# Test Driven Development - Shell Script

function startScript()
{
			   # Test Name #
	executeTests "TestForEllipses"

	read
}

function checkIfEqual()
{
	if [ "$1" == "$2" ]
	then 
		echo "Pass"
	else
		echo "Fail"
	fi
}

function printTestCaseResult()
{
	echo "$1 Test $2 : $3"
}

function executeTests()
{
	testnumber=1

	# Compile and generate Executable 
	gcc StringUtilTest.c StringUtils.c -o StringUtils.exe

  #-------------------------- TEST CASE 1 ------------------------------#
	expected="Indonesia"
	output=$(./StringUtils.exe -maxlength 12 -lastnchars 3 "Indonesia")
	result=$(checkIfEqual $expected $output)

	printTestCaseResult $1 $testnumber $result
  #---------------------------------------------------------------------#
	((testnumber++))
  

  #-------------------------- TEST CASE 2 --------------------------------#
	expected="Indonesia123"
	output=$(./StringUtils.exe -maxlength 12 -lastnchars 3 "Indonesia123")
	result=$(checkIfEqual $expected $output)

	printTestCaseResult $1 $testnumber $result
  #-----------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 3 ---------------------------------#
	expected="Indone...234"
	output=$(./StringUtils.exe -maxlength 12 -lastnchars 3 "Indonesia1234")
	result=$(checkIfEqual $expected $output)

	printTestCaseResult $1 $testnumber $result
  #------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 4 ------------------------------#
	expected="Ind..."
	output=$(./StringUtils.exe -maxlength 6 -lastnchars 0 "Indonesia")
	result=$(checkIfEqual $expected $output)

	printTestCaseResult $1 $testnumber $result
  #---------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 5 ------------------------------#
	expected="...nesia"
	output=$(./StringUtils.exe -maxlength 8 -lastnchars 7 "Indonesia")
	result=$(checkIfEqual $expected $output)

	printTestCaseResult $1 $testnumber $result
  #---------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 6 ------------------------------#
	expected="Error!"
	output=$(./StringUtils.exe -maxlength 8 -lastnchars 9 "Indonesia")
	result=$(checkIfEqual $expected $output)	

	printTestCaseResult $1 $testnumber $result
  #---------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 7 ------------------------------#
	expected="Error!"
	output=$(./StringUtils.exe -maxlength -8 -lastnchars 3 "Indonesia")
	result=$(checkIfEqual $expected $output)	

	printTestCaseResult $1 $testnumber $result
  #---------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 8 ------------------------------#
	expected="Error!"
	output=$(./StringUtils.exe -maxlength 8 -lastnchars -3 "Indonesia")
	result=$(checkIfEqual $expected $output)	

	printTestCaseResult $1 $testnumber $result
  #---------------------------------------------------------------------#
}

startScript