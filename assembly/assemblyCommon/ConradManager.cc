#include "ConradManager.h"
#include "ConradModel.h"

ConradManager::ConradManager(ConradModel* cnrd1)
{
  ConradModel_ = cnrd1;
    // connect(this, SIGNAL(changeVacuumState()), this, SLOT(toggleVacuum()));
  
}

/// toggleVacuum slot description
void ConradManager::toggleVacuum(int channelNumber)
{
  if (ConradModel_ -> getSwitchState(channelNumber) == 0){
    ConradModel_ -> setSwitchEnabled(channelNumber, true);
                
  }else if (ConradModel_ -> getSwitchState(channelNumber) == 1){
    ConradModel_ -> setSwitchEnabled(channelNumber, false);
  }

  //looped status checking

}


//maybe need checkStatus SLOT
