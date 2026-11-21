// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameStateBase.h"
#include "Net/UnrealNetwork.h"

TScriptInterface<IFortTimeOfDayManagerInterface> AFortGameStateBase::GetTimeOfDayManager() const
{
	return TScriptInterface<IFortTimeOfDayManagerInterface>();
}

void AFortGameStateBase::OnRep_TimeOfDayManager()
{
}

void AFortGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameStateBase, FortTimeOfDayManager);
}
