// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modifiers/FortAthenaMutator_WarEffort.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_WarEffort::OnRep_PreloadedItemList()
{
}

void AFortAthenaMutator_WarEffort::SetFundingManagerReady(bool bIsReady)
{
}

void AFortAthenaMutator_WarEffort::SetItemFundedAmount(FGameplayTag ItemFundingTag, int64 CurrentFundingAmount, int64 TargetFundingAmount)
{
}

void AFortAthenaMutator_WarEffort::SetItemFundedPercent(FGameplayTag ItemFundingTag, float FundingPercent)
{
}

void AFortAthenaMutator_WarEffort::SetItemFundedState(FGameplayTag ItemFundingTag, bool bIsActive)
{
}

void AFortAthenaMutator_WarEffort::SetTryBeforeYouBuyItemState(FGameplayTag ItemFundingTag, bool bIsActive)
{
}

void AFortAthenaMutator_WarEffort::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_WarEffort, PreloadedItemList);
	DOREPLIFETIME(AFortAthenaMutator_WarEffort, bCanPreloadItems);
}
