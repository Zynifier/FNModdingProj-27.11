// Copyright Epic Games, Inc. All Rights Reserved.

#include "Research/FortResearchMenuBase.h"

bool UFortResearchMenuBase::AreResearchRespecTokensAvailable() const
{
	return false;
}

int32 UFortResearchMenuBase::GetClaimableResearchPointEstimate()
{
	return int32();
}

int32 UFortResearchMenuBase::GetResearchRespecTokenCount() const
{
	return int32();
}

void UFortResearchMenuBase::RequestPurchaseResearchLevel(const FString& StatId)
{
}

void UFortResearchMenuBase::UseResearchRespecToken()
{
}
