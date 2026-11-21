// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortProgressiveContentInterface.generated.h"

UENUM()
enum class EFortProgressiveContentInterfaceCloseReason : uint8
{
	Normal = 0,
	SubscriptionPurchased = 1,
};

UENUM()
enum class EFortProgressiveContentType : uint8
{
	ProgressiveTableOfContentsScreen = 0,
	ProgressiveItemScreen = 1,
};

UINTERFACE()
class UFortProgressiveContentInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortProgressiveContentInterface
{
	GENERATED_BODY()

};

