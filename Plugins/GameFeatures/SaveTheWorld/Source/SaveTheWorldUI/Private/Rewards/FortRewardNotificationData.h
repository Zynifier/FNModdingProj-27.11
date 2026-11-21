// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "UObject/NoExportTypes.h"
#include "FortBrushSize.h"
#include "Rewards/FortFrontEndRewardType.h"
#include "FortRewardNotificationData.generated.h"

UCLASS(Abstract, BlueprintType)
class UFortRewardNotificationData : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Rewards")
	virtual bool GetIconBrush(FSlateBrush& IconBrush, EFortBrushSize::Type BrushSize = EFortBrushSize::Medium);

	UPROPERTY(BlueprintReadOnly, Category="Rewards")
	EFrontEndRewardType RewardType;

};

