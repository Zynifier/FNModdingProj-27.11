// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortPlayerStateComponent_Habanero.h"
#include "Net/UnrealNetwork.h"

const FRankedProgressReplicatedData& UFortPlayerStateComponent_Habanero::GetRankedProgress() const
{
	static FRankedProgressReplicatedData Dummy;
	return Dummy;
}

void UFortPlayerStateComponent_Habanero::OnRep_RankedProgress()
{
}

void UFortPlayerStateComponent_Habanero::Server_SetRankedProgress_Implementation(const FString& InRankedType, const int32 InRank)
{
}

void UFortPlayerStateComponent_Habanero::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerStateComponent_Habanero, RankedProgress);
}
