// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaHUDGamePhaseChangingBase.h"

void UAthenaHUDGamePhaseChangingBase::BP_HandleGamePhaseStepChanged_Implementation(const EAthenaGamePhaseStep Step)
{
}

void UAthenaHUDGamePhaseChangingBase::BP_UpdateMessaging_Implementation(const EAthenaGamePhaseStep Step, const FText& NewMessage, const FText& NewTimeText)
{
}

bool UAthenaHUDGamePhaseChangingBase::GetShowRankedProgressCvar() const
{
	return false;
}

UActorComponent* UAthenaHUDGamePhaseChangingBase::GetSpawnOverrideComponent()
{
	return nullptr;
}

bool UAthenaHUDGamePhaseChangingBase::IsGamePhaseStepNotificationWidgetVisible(const EAthenaGamePhaseStep PhaseStepType) const
{
	return false;
}

void UAthenaHUDGamePhaseChangingBase::UpdateActiveWidgetIndex(const EAthenaGamePhaseStep Index)
{
}
