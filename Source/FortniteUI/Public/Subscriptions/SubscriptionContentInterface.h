// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SubscriptionContentInterface.generated.h"

UENUM()
enum class EFortSubscriptionContentInterfaceCloseReason : uint8
{
	Normal = 0,
	SubscriptionPurchased = 1,
};

UINTERFACE(MinimalAPI)
class UFortSubscriptionContentInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IFortSubscriptionContentInterface
{
	GENERATED_BODY()

};

