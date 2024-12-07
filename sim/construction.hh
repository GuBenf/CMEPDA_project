/**
 * @file construction.hh
 * @brief Declaration of the MyDetectorConstruction class for detector setup in Geant4.
 * 
 * This file contains the declaration of the `MyDetectorConstruction` class, which 
 * is responsible for defining the geometry, materials, and sensitive detectors 
 * for a Geant4 simulation. It includes methods for constructing the detector geometry, 
 * layers, and assigning sensitive detectors.
 */

#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Trd.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4UserLimits.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4LogicalBorderSurface.hh"
#include "detector.hh"

/**
 * @class MyDetectorConstruction
 * @brief Defines the detector geometry, materials, and sensitive detectors.
 * 
 * The `MyDetectorConstruction` class inherits from `G4VUserDetectorConstruction` and 
 * is used to define and build the detector setup for the simulation. This includes 
 * defining the materials, constructing the physical volumes, and assigning sensitive 
 * detectors and fields.
 */
class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    /**
     * @brief Constructor for MyDetectorConstruction.
     * 
     * Initializes the `MyDetectorConstruction` object and its associated materials.
     */
    MyDetectorConstruction();

    /**
     * @brief Destructor for MyDetectorConstruction.
     * 
     * Cleans up resources used by the `MyDetectorConstruction` object.
     */
    ~MyDetectorConstruction();

    /**
     * @brief Constructs the detector geometry and materials.
     * 
     * Defines the physical and logical volumes, placements, and materials for the 
     * detector components. Called automatically by the Geant4 framework.
     * 
     * @return The world physical volume of the detector geometry.
     */
    virtual G4VPhysicalVolume *Construct();

    /**
     * @brief Constructs a detector layer.
     * 
     * Creates a single layer of the detector, including placement and logical volume.
     * 
     * @param posX X-position of the layer center.
     * @param posY Y-position of the layer center.
     * @param posZ Z-position of the layer center.
     * @param logicWorld The logical volume of the world to place the layer in.
     * @param index Identifier index for the detector layer.
     * 
     * @return A tuple containing the physical volumes of the layer components.
     */
    virtual std::tuple<G4VPhysicalVolume *, G4VPhysicalVolume *> DetectorLayer(
        G4double posX, G4double posY, G4double posZ, G4LogicalVolume *logicWorld, G4int index);

private:
    /**
     * @brief Assigns sensitive detectors and fields.
     * 
     * This method is used to define sensitive detectors and magnetic or electric fields 
     * within the simulation.
     */
    virtual void ConstructSDandField();

    G4LogicalVolume *logicDetector; ///< Logical volume representing the detector.

    G4NistManager *nist = G4NistManager::Instance(); ///< Instance of the NIST manager for material definitions.

    G4Material *scint_material = nist->FindOrBuildMaterial("G4_POLYSTYRENE"); ///< Material for the scintillators.

    G4double energy[2] = {1.95 * eV, 1.95 * eV}; ///< Energy range for optical properties.

    // Scintillator dimensions
    G4double det_x = 20. * cm; ///< X dimension of the scintillator.
    G4double det_y = 0.5 * cm; ///< Y dimension of the scintillator.
    G4double det_z = 24 * cm; ///< Z dimension of the scintillator.

    // Waveguide dimensions
    G4double d_x1 = 20. * cm; ///< X1 dimension of the waveguide.
    G4double d_x2 = 2 * cm; ///< X2 dimension of the waveguide.
    G4double d_y1 = det_y; ///< Y1 dimension of the waveguide.
    G4double d_y2 = det_y; ///< Y2 dimension of the waveguide.
    G4double d_z = 10 * cm; ///< Z dimension of the waveguide.

    // PMT dimensions
    G4double pmt_x = d_x2; ///< X dimension of the PMT, matched to the waveguide.
    G4double pmt_y = d_y2; ///< Y dimension of the PMT, matched to the waveguide.
    G4double pmt_z = 1. * cm; ///< Z dimension of the PMT.

    G4int nDetectors = 6; ///< Number of detectors in the setup.
};

#endif // CONSTRUCTION_HH
