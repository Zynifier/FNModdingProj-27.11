// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortGiftUINotifications.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FGiftUINotificationInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GiftUINotificationInfo")
	TSoftObjectPtr<UFortItemDefinition> SoftItemPtr;

	UPROPERTY(EditAnywhere, Category="GiftUINotificationInfo")
	int32 Count;

};

UCLASS(Abstract, EditInlineNew)
class UGiftUINotificationHandler : public UObject
{
	GENERATED_BODY()

};

