// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponentTypes.h"
#include "FortMobileActionButtonBehavior_Use.generated.h"

class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_Use : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> InterrogateSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> CancelSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> PickUpSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	FGameplayTag CreativeMatchmakingPortalComparisonTag;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<FIconPicker> PawnSpriteOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Visibility Override")
	FGameplayTagQuery ReceiverTagQueryRequiringVisibilityOverride;

	UPROPERTY(EditDefaultsOnly, Category="Visibility Override")
	FGameplayTagQuery InstigatorTagQueryRequiringVisibilityOverride;

	UPROPERTY(EditDefaultsOnly, Category="Visibility Override")
	TArray<FName> OverrideActionNames;

};

