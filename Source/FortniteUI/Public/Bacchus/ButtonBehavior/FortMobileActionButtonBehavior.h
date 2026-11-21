// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/MobileEnhancedInputData.h"
#include "Bacchus/HUDWidgetBehavior.h"
#include "FortMobileActionButtonBehavior.generated.h"

class UFortButtonBehaviorComponentOverride;
class UFortMobileButtonBehaviorComponent;
class UPaperSprite;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMobileActionButtonBehavior : public UHUDWidgetBehavior
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	FORTNITEUI_API virtual void HandleInputStackChanged();

	UPROPERTY(EditAnywhere, Category="Action")
	TArray<FName> ActionNames;

	UPROPERTY(EditAnywhere, Category="Enhanced Input")
	TArray<FMobileEnhancedInputData> InputActionsData;

	UPROPERTY(EditAnywhere, Category="Display")
	TObjectPtr<UPaperSprite> Sprite;

	UPROPERTY(EditAnywhere, Category="HUD Layout")
	FGameplayTag HUDLayoutToolSaveTag_Legacy;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Components")
	TArray<TObjectPtr<UFortMobileButtonBehaviorComponent>> ButtonBehaviorComponents;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Component Overrides")
	TArray<UFortButtonBehaviorComponentOverride*> ButtonBehaviorComponentOverrides;

	UPROPERTY(EditAnywhere, Category="FortMobileActionButtonBehavior")
	int32 ForcedZOrder;

};

