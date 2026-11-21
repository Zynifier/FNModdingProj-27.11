// Copyright Epic Games, Inc. All Rights Reserved.

#include "WarEffortFundingTypes.h"

int32 UWarEffortFundingLibrary::AdjustDonation(int32 DonationAmount, EWarEffortFundingStationType StationType)
{
	return int32();
}

bool UWarEffortFundingLibrary::DoesChoiceHaveWinner(const FWarEffortFundingMetadata& Metadata, int32 ChoiceIndex)
{
	return false;
}

float UWarEffortFundingLibrary::GetIndexFundedPercent(const FWarEffortFundingMetadata& Metadata, int32 Index, EWarEffortFundingStationType StationType)
{
	return float();
}

bool UWarEffortFundingLibrary::IsIndexFunded(const FWarEffortFundingMetadata& Metadata, int32 Index, EWarEffortFundingStationType StationType)
{
	return false;
}

bool UWarEffortFundingLibrary::IsOption1ChoiceWinner(const FWarEffortFundingMetadata& Metadata, int32 ChoiceIndex)
{
	return false;
}

bool UWarEffortFundingLibrary::IsOption2ChoiceWinner(const FWarEffortFundingMetadata& Metadata, int32 ChoiceIndex)
{
	return false;
}

FString UWarEffortFundingLibrary::WriteTextToBuffer(const FText& Text)
{
	return FString();
}
