/**
 * @file action.cc
 * @brief Implementation of the MyActionInitialization class methods.
 * 
 * This file contains the implementation of the `MyActionInitialization` class,
 * which sets up user-defined actions for the Geant4 simulation. Specifically,
 * it initializes the primary particle generator and run action.
 */

#include "action.hh"

/**
 * @brief Default constructor for MyActionInitialization.
 * 
 * This constructor initializes the `MyActionInitialization` object but does not perform
 * any specific setup. Actions are defined in the `Build` method.
 */
MyActionInitialization::MyActionInitialization()
{
    // No initialization logic needed here.
}

/**
 * @brief Destructor for MyActionInitialization.
 * 
 * Cleans up resources used by the `MyActionInitialization` object, if any.
 */
MyActionInitialization::~MyActionInitialization()
{
    // No specific cleanup required.
}

/**
 * @brief Defines user actions for the simulation.
 * 
 * This method is responsible for creating and registering user-defined actions
 * to the Geant4 framework. It sets the following:
 * - A primary generator action (`MyPrimaryGenerator`).
 * - A run action (`MyRunAction`).
 */
void MyActionInitialization::Build() const
{
    // Create and set the primary particle generator.
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    // Create and set the run action.
    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
}