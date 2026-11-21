// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/MissionTypes.h"

void UFortAthenaCreativeSupplyDropOpenedParams::BreakParams(AFortPawn*& OutPawn, AFortAthenaCreativeSupplyDrop*& OutAthenaCreativeSupplyDrop) const
{
}

void UFortAthenaCreativeSupplyDropOpenedParams::SetParams(AFortPawn* InPawn, AFortAthenaCreativeSupplyDrop* InAthenaCreativeSupplyDrop, UFortAthenaCreativeSupplyDropOpenedParams*& ThisParam)
{
}

void UFortBuildingContainerOpenedParams::BreakParams(AFortPlayerPawn*& OutPlayerPawn, ABuildingContainer*& OutBuildingContainer) const
{
}

void UFortBuildingContainerOpenedParams::SetParams(AFortPlayerPawn* InPlayerPawn, ABuildingContainer* InBuildingContainer, UFortBuildingContainerOpenedParams*& ThisParam)
{
}

void UFortBuildingDamagedParams::BreakParams(ABuildingActor*& _Building, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AController*& _DamagedBy, float& _DamageAmount)
{
}

void UFortBuildingDamagedParams::SetParams(ABuildingActor* _Building, EFortBuildingType::Type _BuildingType, AController* _DamagedBy, float _DamageAmount, UFortBuildingDamagedParams*& ThisParam)
{
}

void UFortBuildingDestroyedParams::BreakParams(ABuildingActor*& _Building, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AController*& _Destroyer)
{
}

void UFortBuildingDestroyedParams::SetParams(ABuildingActor* _Building, EFortBuildingType::Type _BuildingType, AController* _Destroyer, UFortBuildingDestroyedParams*& ThisParam)
{
}

void UFortBuildingEditedParams::BreakParams(ABuildingActor*& _OriginalBuilding, ABuildingActor*& _NewBuilding, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AFortPlayerController*& _Editor)
{
}

void UFortBuildingEditedParams::SetParams(ABuildingActor* _OriginalBuilding, ABuildingActor* _NewBuilding, EFortBuildingType::Type _BuildingType, AFortPlayerController* _Editor, UFortBuildingEditedParams*& ThisParam)
{
}

void UFortBuildingUpgradedParams::BreakParams(ABuildingActor*& _OriginalBuilding, ABuildingActor*& _NewBuilding, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AFortPlayerController*& _Editor)
{
}

void UFortBuildingUpgradedParams::SetParams(ABuildingActor* _OriginalBuilding, ABuildingActor* _NewBuilding, EFortBuildingType::Type _BuildingType, AFortPlayerController* _Editor, UFortBuildingUpgradedParams*& ThisParam)
{
}

void UFortCreativePickupFishedParams::BreakParams(APlayerState*& OutPlayerState, AFortPickup*& OutPickup) const
{
}

void UFortCreativePickupFishedParams::SetParams(APlayerState* InPlayerState, AFortPickup* InPickup, UFortCreativePickupFishedParams*& ThisParam)
{
}

void UFortCreativePlayerStateParams::BreakParams(APlayerState*& OutPlayerState) const
{
}

void UFortCreativePlayerStateParams::SetParams(APlayerState* InPlayerState, UFortCreativePlayerStateParams*& ThisParam)
{
}

void UFortCreativeRaceCheckpointActivatedParams::BreakParams(APlayerState*& OutPlayerState, AActor*& OutRaceCheckpoint) const
{
}

void UFortCreativeRaceCheckpointActivatedParams::SetParams(APlayerState* InPlayerState, AActor* InRaceCheckpoint, UFortCreativeRaceCheckpointActivatedParams*& ThisParam)
{
}

void UFortDayPhaseChangeParams::BreakParams(AFortTimeOfDayManager*& _LightingAndFogManager, EFortDayPhase& _NewDayPhase)
{
}

void UFortDayPhaseChangeParams::SetParams(AFortTimeOfDayManager* _LightingAndFogManager, EFortDayPhase _NewDayPhase, UFortDayPhaseChangeParams*& ThisParam)
{
}

void UFortEnemyKilledParams::BreakParams(AFortPawn*& _KilledPawn, AFortPlayerController*& _KilledBy)
{
}

void UFortEnemyKilledParams::SetParams(AFortPawn* _KilledPawn, AFortPlayerController* _KilledBy, UFortEnemyKilledParams*& ThisParam)
{
}

void UFortItemCollectedParams::BreakParams(UFortWorldItemDefinition*& _CollectedItemDefinition, AFortPlayerController*& _CollectedBy, int32& _AmountCollected)
{
}

void UFortItemCollectedParams::SetParams(const UFortWorldItemDefinition* _CollectedItemDefinition, AFortPlayerController* _CollectedBy, int32 _AmountCollected, UFortItemCollectedParams*& ThisParam)
{
}

void UFortItemCraftedParams::BreakParams(UFortSchematicItemDefinition*& _SchematicDefinition, AFortPlayerController*& _CraftedBy, int32& _AmountCrafted, bool& _bItemWasQuickCrafted)
{
}

void UFortItemCraftedParams::SetParams(const UFortSchematicItemDefinition* _SchematicDefinition, AFortPlayerController* _CraftedBy, int32 _AmountCrafted, bool _bItemWasQuickCrafted, UFortItemCraftedParams*& ThisParam)
{
}

void UFortItemDroppedParams::BreakParams(UFortWorldItemDefinition*& _DroppedItemDefinition, AFortPlayerController*& _DroppedBy, int32& _AmountCollected)
{
}

void UFortItemDroppedParams::SetParams(const UFortWorldItemDefinition* _DroppedItemDefinition, AFortPlayerController* _DroppedBy, int32 _AmountCollected, UFortItemDroppedParams*& ThisParam)
{
}

void UFortMinigameEventParams::BreakParams(AFortMinigame*& OutMinigame, APlayerState*& OutPlayerState) const
{
}

void UFortMinigameEventParams::SetParams(AFortMinigame* InMinigame, APlayerState* InPlayerState, UFortMinigameEventParams*& ThisParam)
{
}

void UFortMissionBuildingDamagedParams::BreakParams(AActor*& _Actor, AController*& _DamagedBy, float& _DamageAmount)
{
}

void UFortMissionBuildingDamagedParams::SetParams(AActor* _Actor, AController* _DamagedBy, float _DamageAmount, UFortMissionBuildingDamagedParams*& ThisParam)
{
}

void UFortMissionFailedParams::BreakParams(AFortMission*& _FailedMission)
{
}

void UFortMissionFailedParams::SetParams(AFortMission* _FailedMission, UFortMissionFailedParams*& ThisParam)
{
}

void UFortMissionForceSuccessParams::BreakParams(float& _FractionCompleted)
{
}

void UFortMissionForceSuccessParams::SetParams(float _FractionCompleted, UFortMissionForceSuccessParams*& ThisParam)
{
}

void UFortMissionNeutralCompleteParams::BreakParams(AFortMission*& _NeutrallyCompletedMission)
{
}

void UFortMissionNeutralCompleteParams::SetParams(AFortMission* _NeutrallyCompletedMission, UFortMissionNeutralCompleteParams*& ThisParam)
{
}

void UFortMissionSucceededParams::BreakParams(AFortMission*& _SucceededMission)
{
}

void UFortMissionSucceededParams::SetParams(AFortMission* _SucceededMission, UFortMissionSucceededParams*& ThisParam)
{
}

void UFortNewPlayerHasBegunPlayParams::BreakParams(AFortPlayerController*& _NewPlayerPC)
{
}

void UFortNewPlayerHasBegunPlayParams::SetParams(AFortPlayerController* _NewPlayerPC, UFortNewPlayerHasBegunPlayParams*& ThisParam)
{
}

void UFortNewPlayerParams::BreakParams(AFortPlayerController*& _NewPlayerController)
{
}

void UFortNewPlayerParams::SetParams(AFortPlayerController* _NewPlayerController, UFortNewPlayerParams*& ThisParam)
{
}

void UFortObjectiveFailedParams::BreakParams(AFortObjectiveBase*& _FailedObjective)
{
}

void UFortObjectiveFailedParams::SetParams(AFortObjectiveBase* _FailedObjective, UFortObjectiveFailedParams*& ThisParam)
{
}

void UFortObjectiveNeutralCompleteParams::BreakParams(AFortObjectiveBase*& _NeutrallyCompletedObjective)
{
}

void UFortObjectiveNeutralCompleteParams::SetParams(AFortObjectiveBase* _NeutrallyCompletedObjective, UFortObjectiveNeutralCompleteParams*& ThisParam)
{
}

void UFortObjectiveSucceededParams::BreakParams(AFortObjectiveBase*& _SucceededObjective)
{
}

void UFortObjectiveSucceededParams::SetParams(AFortObjectiveBase* _SucceededObjective, UFortObjectiveSucceededParams*& ThisParam)
{
}

void UFortPawnDiedParams::BreakParams(AFortPawn*& OutKilledPawn, AController*& OutKilledController, AController*& OutKilledBy, FGameplayTagContainer& OutTags)
{
}

void UFortPawnDiedParams::SetParams(AFortPawn* InKilledPawn, AController* InKilledController, AController* InKilledBy, FGameplayTagContainer InTags, UFortPawnDiedParams*& ThisParam)
{
}

void UFortPlayerBuiltParams::BreakParams(ABuildingActor*& _Building, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AFortPlayerController*& _Builder)
{
}

void UFortPlayerBuiltParams::SetParams(ABuildingActor* _Building, EFortBuildingType::Type _BuildingType, AFortPlayerController* _Builder, UFortPlayerBuiltParams*& ThisParam)
{
}

void UFortPlayerDBNOEnterParams::BreakParams(AFortPlayerPawn*& _KilledPlayer, AController*& _KilledBy)
{
}

void UFortPlayerDBNOEnterParams::SetParams(AFortPlayerPawn* _KilledPlayer, AController* _KilledBy, UFortPlayerDBNOEnterParams*& ThisParam)
{
}

void UFortPlayerDBNOInterrogatedParams::BreakParams(AFortPlayerPawn*& OutInterrogatedPlayer, AController*& OutInterrogatedBy) const
{
}

void UFortPlayerDBNOInterrogatedParams::SetParams(AFortPlayerPawn* InInterrogatedPlayer, AController* InInterrogatedBy, UFortPlayerDBNOInterrogatedParams*& ThisParam)
{
}

void UFortPlayerDBNORevivedParams::BreakParams(AFortPlayerPawn*& _RevivedPlayer, AController*& _RevivedBy)
{
}

void UFortPlayerDBNORevivedParams::SetParams(AFortPlayerPawn* _RevivedPlayer, AController* _RevivedBy, UFortPlayerDBNORevivedParams*& ThisParam)
{
}

void UFortPlayerDiedParams::BreakParams(AFortPlayerPawn*& _KilledPlayer, AController*& _KilledPlayerController, AController*& _KilledBy, FGameplayTagContainer& _Tags)
{
}

void UFortPlayerDiedParams::SetParams(AFortPlayerPawn* _KilledPlayer, AController* _KilledPlayerController, AController* _KilledBy, FGameplayTagContainer _Tags, UFortPlayerDiedParams*& ThisParam)
{
}

void UFortPlayerExitParams::BreakParams(AFortPlayerController*& _ExitingPlayerController)
{
}

void UFortPlayerExitParams::SetParams(AFortPlayerController* _ExitingPlayerController, UFortPlayerExitParams*& ThisParam)
{
}

void UFortPlayerReconnectedParams::BreakParams(AFortPlayerController*& _ReconnectedPlayerPC)
{
}

void UFortPlayerReconnectedParams::SetParams(AFortPlayerController* _ReconnectedPlayerPC, UFortPlayerReconnectedParams*& ThisParam)
{
}

void UFortPlayerSpawnedParams::BreakParams(AFortPlayerController*& _SpawnedPlayerController)
{
}

void UFortPlayerSpawnedParams::SetParams(AFortPlayerController* _SpawnedPlayerController, UFortPlayerSpawnedParams*& ThisParam)
{
}

void UFortStartLeavingZoneParams::BreakParams(AFortPlayerController*& _PlayerControllerRequestingLeaving)
{
}

void UFortToggledCursorModeParams::BreakParams(AFortPlayerController*& _PlayerThatToggledCursorMode, bool& InCursorMode)
{
}

void UFortToggledCursorModeParams::SetParams(AFortPlayerController* _PlayerThatToggledCursorMode, bool InCursorMode, UFortToggledCursorModeParams*& ThisParam)
{
}

void UFortToggledEditModeParams::BreakParams(AFortPlayerController*& _PlayerThatToggledEditMode, ABuildingSMActor*& EditableActor, bool& InEditMode)
{
}

void UFortToggledEditModeParams::SetParams(AFortPlayerController* _PlayerThatToggledEditMode, ABuildingSMActor* InEditableActor, bool InEditMode, UFortToggledEditModeParams*& ThisParam)
{
}
