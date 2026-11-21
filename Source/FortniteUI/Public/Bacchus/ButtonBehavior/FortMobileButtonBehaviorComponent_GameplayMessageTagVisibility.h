// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_Visibility.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "FortMobileButtonBehaviorComponent_GameplayMessageTagVisibility.generated.h"

USTRUCT()
struct FGameplayMessageVisibility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GameplayMessageVisibility")
	FEventMessageTag EventMessageTag;

	UPROPERTY(EditAnywhere, Category="GameplayMessageVisibility")
	ESlateVisibility MessageReceivedVisibility;

	UPROPERTY(EditAnywhere, Category="GameplayMessageVisibility")
	ESlateVisibility MessageStateClearedVisibility;

};

UCLASS()
class UFortMobileButtonBehaviorComponent_GameplayMessageTagVisibility : public UFortMobileButtonBehaviorComponent_Visibility
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileButtonBehaviorComponent_GameplayMessageTagVisibility")
	TArray<FGameplayMessageVisibility> GameplayMessageVisibilities;

};

