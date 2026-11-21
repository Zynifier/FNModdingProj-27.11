// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/CreativeDynamicXpDataAsset.h"

const FCreativeAFKDetectionParameters& UCreativeDynamicXpDataAsset::GetAFKDetectionParameters() const
{
	static FCreativeAFKDetectionParameters Dummy;
	return Dummy;
}

float UCreativeDynamicXpDataAsset::GetAfkMinRewardMult() const
{
	return float();
}

float UCreativeDynamicXpDataAsset::GetCappedSessionLength() const
{
	return float();
}

float UCreativeDynamicXpDataAsset::GetXpBudgetPerMinute() const
{
	return float();
}
