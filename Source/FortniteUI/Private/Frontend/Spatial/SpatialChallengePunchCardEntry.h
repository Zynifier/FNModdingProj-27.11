// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SpatialChallengePunchCardEntry.generated.h"

class UAthenaChallengePunchCard;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class USpatialChallengePunchCardEntry : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengePunchCard> PunchCard_Top;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengePunchCard> PunchCard_Bottom;

};

