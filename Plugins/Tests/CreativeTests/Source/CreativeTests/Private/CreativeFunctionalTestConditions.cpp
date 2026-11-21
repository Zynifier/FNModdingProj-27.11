// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreativeFunctionalTestConditions.h"

void UCreativeFunctionalTestConditionComponentBase::CleanupAfterTest_Implementation()
{
}

bool UCreativeFunctionalTestConditionComponentBase::ConditionHasBeenSatisfied_Implementation() const
{
	return false;
}

bool UCreativeFunctionalTestConditionComponentBase::GetTestResult_Implementation(FString& TestMessage) const
{
	return false;
}

void UCreativeFunctionalTestConditionComponentBase::SetConditionSatisfied_Implementation(bool bValue)
{
}

void UCreativeFunctionalTestConditionComponentBase::SetupForTest_Implementation()
{
}

void UCreativeFunctionalTestConditionComponent_ReceiveOnChannel::OnReceiveOnChannel_Implementation(AController* Instigator)
{
}

void UCreativeFunctionalTestConditionComponent_ReceiveOnChannel::SetChannelId(const FGameplayTagContainer& NewChannelIds)
{
}
