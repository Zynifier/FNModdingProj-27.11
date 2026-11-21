// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMatchmakingWidgetExtensionInterface.generated.h"

USTRUCT(BlueprintType)
struct FGameSelectionButtonInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameSelectionButtonInfo")
	FText PrimaryText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameSelectionButtonInfo")
	FText SecondaryText;

};

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortMatchmakingWidgetExtensionInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortMatchmakingWidgetExtensionInterface
{
	GENERATED_BODY()

};

