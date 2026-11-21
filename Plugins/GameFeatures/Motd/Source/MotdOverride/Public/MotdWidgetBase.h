// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "MotdWidgetBase.generated.h"

UENUM()
enum class EMotdCloseReason : uint8
{
	Unknown = 0,
	NoMotds = 1,
	NullPrm = 2,
	PrmParsingFailed = 3,
	User = 4,
	Action = 5,
	DeepLink = 6,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class MOTDOVERRIDE_API UMotdWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

};

