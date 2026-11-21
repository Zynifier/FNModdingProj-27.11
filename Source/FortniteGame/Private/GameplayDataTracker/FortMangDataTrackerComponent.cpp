// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayDataTracker/FortMangDataTrackerComponent.h"
#include "Net/UnrealNetwork.h"

bool UFortMangDataTrackerComponent::IsTrackingPerPlayer() const
{
	return false;
}

void UFortMangDataTrackerComponent::OnBotControllerAlertLevelChanged(AFortAthenaAIBotController* BotController, EAlertLevel OldAlertLevel, EAlertLevel NewAlertLevel)
{
}

void UFortMangDataTrackerComponent::OnBotDBNOStatusChanged(AFortAthenaAIBotController* BotController, bool bIsDBNO)
{
}

void UFortMangDataTrackerComponent::OnBotDied(AFortAthenaAIBotController* BotController, AFortPawn* FortPawn)
{
}

void UFortMangDataTrackerComponent::OnBotPawnDBNOStatusChanged(AFortPawn* FortPawn, bool bIsDBNO)
{
}

void UFortMangDataTrackerComponent::OnRep_BotInfos()
{
}

void UFortMangDataTrackerComponent::RegisterCameraInfos(const TArray<FFortMangSentryInfo>& Cameras)
{
}

void UFortMangDataTrackerComponent::RegisterLocalPlayerController(AFortPlayerController* LocalPlayerController)
{
}

void UFortMangDataTrackerComponent::RegisterMangControllers(TArray<AFortAthenaAIBotController*> MangControllers)
{
}

void UFortMangDataTrackerComponent::RegisterTurretInfos(const TArray<FFortMangSentryInfo>& Turrets)
{
}

void UFortMangDataTrackerComponent::UnRegisterLocalPlayerController()
{
}

void UFortMangDataTrackerComponent::UpdateCameraAlertState(ABuildingGameplayActor* CameraToUpdate, EAlertLevel NewAlertLevel)
{
}

void UFortMangDataTrackerComponent::UpdateTurretAlertState(ABuildingGameplayActor* TurretToUpdate, EAlertLevel NewAlertLevel)
{
}

void UFortMangDataTrackerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMangDataTrackerComponent, BotInfos);
}
