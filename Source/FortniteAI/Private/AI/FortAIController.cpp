// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIController.h"

void AFortAIController::ClearAllFocalPoints()
{
}

bool AFortAIController::CreateBuildingActor(TSubclassOf<ABuildingSMActor> BuildingClass, FVector BuildLoc, FRotator BuildRot, bool bMirrored)
{
	return false;
}

UFortAIEncounterInfo* AFortAIController::GetEncounterInfo() const
{
	return nullptr;
}

AActor* AFortAIController::GetGoalActor() const
{
	return nullptr;
}

void AFortAIController::IgnoreProximityForDuration(float DurationToIgnore)
{
}

bool AFortAIController::IsAllowedToSleep()
{
	return false;
}

bool AFortAIController::IsIgnoringProximity(AFortAIController* FortAIController)
{
	return false;
}

void AFortAIController::LockBehaviorResource()
{
}

void AFortAIController::LockMovementResource()
{
}

void AFortAIController::OnActorGoalDestroyed(AActor* DestroyedActor)
{
}

void AFortAIController::OnBuildingActorGoalDestroyed()
{
}

void AFortAIController::SetAlwaysGameplayRelevant(bool bInAlwaysGameplayRelevant)
{
}

void AFortAIController::SetFullPeripheralVision(bool bNewFullPeripheralVision)
{
}

void AFortAIController::SetGoalActor(AActor* InActor, bool bLocationAlwaysKnown)
{
}

void AFortAIController::SetIsSleeping(bool bNewSleepStatus)
{
}

void AFortAIController::SetPawnAIType(EFortressAIType NewAIType, AActor* SpawnSpot)
{
}

void AFortAIController::SetTeam(EFortTeam::Type InTeam)
{
}

void AFortAIController::SetTeamInt(uint8 InTeam)
{
}

void AFortAIController::SetupCustomVIM(UClass* VIM)
{
}

void AFortAIController::UnlockBehaviorResource()
{
}

void AFortAIController::UnlockMovementResource()
{
}

void AFortAIController::WakeUp()
{
}
