// Copyright Epic Games, Inc. All Rights Reserved.

#include "BadNetworkIndicator.h"

float UBadNetworkIndicator::GetPacketLoss() const
{
	return float();
}

float UBadNetworkIndicator::GetPing() const
{
	return float();
}

bool UBadNetworkIndicator::HasBadPacketLoss() const
{
	return false;
}

bool UBadNetworkIndicator::HasBadPing() const
{
	return false;
}

bool UBadNetworkIndicator::HasSeverePacketLoss() const
{
	return false;
}

bool UBadNetworkIndicator::HasSeverePing() const
{
	return false;
}

bool UBadNetworkIndicator::ShouldDisplay() const
{
	return false;
}
