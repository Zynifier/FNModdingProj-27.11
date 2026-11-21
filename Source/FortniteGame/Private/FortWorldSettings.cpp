// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortWorldSettings.h"
#include "Net/UnrealNetwork.h"

void AFortWorldSettings::DisableAllTimeOfDayManagers(bool bState)
{
}

#if WITH_EDITOR
TScriptInterface<IFortTimeOfDayManagerInterface> AFortWorldSettings::GetTimeOfDayManager()
{
	return TScriptInterface<IFortTimeOfDayManagerInterface>();
}
#endif

void AFortWorldSettings::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWorldSettings, bDisableAllTimeOfDayManagers);
}

bool AFortWorldSettings::BuildHLODActor(const FBuildHLODActorParams& BuildHLODActorParams)
{
	return false;
}
