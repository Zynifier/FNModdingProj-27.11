// Copyright Epic Games, Inc. All Rights Reserved.

#include "Subscriptions/FortSubscriptionPlatformModal.h"

void UFortSubscriptionPlatformModal::ExitModal()
{
}

FText UFortSubscriptionPlatformModal::GetSubscriptionNextBillingDateAsText() const
{
	return FText();
}

bool UFortSubscriptionPlatformModal::IsOnActiveSubscriptionPlatform() const
{
	return false;
}

void UFortSubscriptionPlatformModal::SendSubscriptionAnalyticsEvent(const FString& Interaction)
{
}
