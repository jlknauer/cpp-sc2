#include "sc2api/sc2_api.h"
#include "sc2api/sc2_agent.h"
#include "sc2utils/sc2_manage_process.h"

class ObservationBot : public sc2::Agent {
public:
    virtual void OnGameStart() final {

    }

    virtual void OnStep() final {
        const sc2::ObservationInterface* observation = Observation();
        const sc2::ActionInterface* action = Actions();
        const sc2::QueryInterface* query = Query();
        const sc2::DebugInterface* debug = Debug();
    }
};

int main(int argc, char* argv[]) {
    sc2::Coordinator coordinator;
    coordinator.LoadSettings(argc, argv);

    ObservationBot bot;

    coordinator.SetParticipants({
        CreateParticipant(sc2::Race::Terran, &bot),
        CreateComputer(sc2::Race::Terran)
    });

    coordinator.LaunchStarcraft();
    coordinator.StartGame(sc2::kMapBelShirVestigeLE);

    while (!coordinator.AllGamesEnded()) {
        coordinator.Update();
    }

    return 0;
}