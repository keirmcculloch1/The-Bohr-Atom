// Keir McCulloch
// Last edited 06/02/26

// Assignment 1 PHYS30762

// Program to calculate transition energy using simple Bohr formula

#include<iostream>
#include<iomanip>
#include<cmath>

int main()
{
  // Declare input variables

  int atomic_number;

  int init_quantum_number;

  int final_quantum_number;

  char energy_unit;

  // Declare eV (electron Volts) to J (Joules) conversion factor

  float conversion_factor{1.60218e-19};

  // Declare variables to store final photon energy in eV and J

  double photon_energy_ev;
  double photon_energy_j;

  //Variable to track whether the user wishes to run another loop

  char repeat_program{121};

  // While loop containing input and calculation code
  //The user can choose to run the main loop again to complete a new calculation

  while(repeat_program == 121){

    // Take atomic number as input from user

    //Provide initial input message to user
    std::cout << "Enter the atomic number of the atom: ";

    // While loop is used to validate the user input
    // Valid inputs are integers between 1-118 inclusive

    while(!(std::cin >> atomic_number) || atomic_number < 1 || atomic_number > 118) {

      //Clears the "bad" input
      std::cin.clear();
      std::cin.ignore(10000, '\n');

      //Provides a new input message to the user to clarify valid input parameters
      std::cout << "Atomic number must be a positive integer below 119." << std::endl;
      std::cout << "Enter the atomic number of the atom: ";
    } 

    // Take initial quantum number as input

    //Provide initial input message to user
    std::cout << "Enter the initial principle quantum number of the electron: ";

    // While loop is used to validate the user input
    // Valid inputs are integers between 1-100 inclusive

    while(!(std::cin >> init_quantum_number) || init_quantum_number < 1 || init_quantum_number > 100) {

      //Clears the "bad" input
      std::cin.clear();
      std::cin.ignore(10000, '\n');

      //Provides a new input message to the user to clarify valid input parameters
      std::cout << "Initial principle quantum number must be a positive integer below 101." << std::endl;
      std::cout << "Enter the initial principle quantum number of the electron: ";

    }

    // Take final quantum number as input

    //Provide initial input message to user
    std::cout << "Enter the final principle quantum number of the electron: ";

    // While loop is used to validate the user input
    // Valid inputs are integers between 1 and (the initial principle quantum number - 1) inclusive

    while(!(std::cin >> final_quantum_number) || final_quantum_number < 1 || final_quantum_number > init_quantum_number-1) {

      //Clears the "bad" input
      std::cin.clear();
      std::cin.ignore(10000, '\n');

      //Provides a new input message to the user to clarify valid input parameters
      std::cout << "Final principle quantum number must be a positive integer below the initial principle quantum number." <<std::endl;
      std::cout << "Enter the final principle quantum number of the electron: ";

    }

    // Ask the user whether to output the energy in eV or J

    //Provide initial input message to user
    std::cout << "Enter e to output the energy in electron Volts, J to output the energy in Joules: ";

    // While loop is used to validate the user input
    // Valid inputs are either "e" or "J"

    while(!(std::cin >> energy_unit) || !( energy_unit == 101 || energy_unit == 74)) {

      //Clears the "bad" input
      std::cin.clear();
      std::cin.ignore(10000, '\n');

      //Provides a new input message to the user to clarify valid input parameters
      std::cout << "Enter only 'e' or 'J'." <<std::endl;
      std::cout << "Enter e to output the energy in electron Volts, J to output the energy in Joules: ";

    }
    

    // Compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV

    photon_energy_ev = 13.6*(pow(atomic_number,2))*(pow((1/final_quantum_number),2)-pow((1/init_quantum_number),2));

    photon_energy_j = photon_energy_ev*conversion_factor;

    //Check the energy unit given by the user and output the corresponding value

    if(energy_unit == 101){
      std::cout << "Photon energy is " << photon_energy_ev << "eV" << std::endl;
    }
    else {
      std::cout << "Photon energy is " << photon_energy_j << "J" << std::endl;
    }

    // Ask the user whether or not to repeat the main calculation code

    //Provide initial input message to user
    std::cout << "Enter y to perform another calculation, n to terminate the program: ";

    // While loop is used to validate the user input
    // Valid inputs are either "y" or "n"

    while(!(std::cin >> repeat_program) || !( repeat_program == 121 || repeat_program == 110)) {

      //Clears the "bad" input
      std::cin.clear();
      std::cin.ignore(10000, '\n');

      //Provides a new input message to the user to clarify valid input parameters
      std::cout << "Enter only 'y' or 'n'." <<std::endl;
      std::cout << "Enter y to perform another calculation, n to terminate the program: ";

    }

  }

  
}
