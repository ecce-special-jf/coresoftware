#ifndef PHG4VSiliconTrackerSteppingAction_h
#define PHG4VSiliconTrackerSteppingAction_h

#include <g4main/PHG4SteppingAction.h>

#include <map>
#include <set>

class PHG4SiliconTrackerDetector;
class PHParametersContainer;
class PHG4Hit;
class PHG4HitContainer;
class PHG4Shower;

class PHG4SiliconTrackerSteppingAction : public PHG4SteppingAction
{
 public:
  PHG4SiliconTrackerSteppingAction(PHG4SiliconTrackerDetector *, const PHParametersContainer *parameters, const std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> &layer_begin_end);

  virtual ~PHG4SiliconTrackerSteppingAction();

  virtual bool UserSteppingAction(const G4Step *, bool);

  virtual void SetInterfacePointers(PHCompositeNode *);

 private:
  //! pointer to the detector
  PHG4SiliconTrackerDetector *detector_;

  //! pointer to hit container
  PHG4HitContainer *hits_;
  PHG4HitContainer *absorberhits_;
  PHG4Hit *hit;
  PHG4HitContainer *savehitcontainer;
  PHG4Shower *saveshower;
  const PHParametersContainer *paramscontainer;

//  int laddertype[4];
  std::map<int, int> m_LadderTypeMap;
  std::map<int, double> m_StripYMap;
  std::map<int, std::pair<double, double>> m_StripZMap;
  std::map<int, int> m_nStripsPhiCell;
  std::map<int, std::pair<int,int>> m_nStripsZSensor;

  /* double strip_y[2]; */
  /* double strip_z[2][2]; */
  /* int nstrips_z_sensor[2][2]; */
  /* int nstrips_phi_cell[2]; */
  std::map<int, int> IsActive;
  std::map<int, int> IsBlackHole;
  std::map<std::string, int> AbsorberIndex;
  std::set<std::string> missingabsorbers;
};

#endif  // PHG4SiliconTrackerSteppingAction_h
