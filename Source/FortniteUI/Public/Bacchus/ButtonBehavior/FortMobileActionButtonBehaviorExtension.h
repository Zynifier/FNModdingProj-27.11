// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/MobileEnhancedInputData.h"
#include "Bacchus/FortMobileHUDWidgetBehaviorExtension.h"
#include "FortMobileActionButtonBehaviorExtension.generated.h"

class UFortButtonBehaviorComponentOverride;
class UFortMobileButtonBehaviorComponent;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMobileActionButtonBehaviorExtension : public UFortMobileHUDWidgetBehaviorExtension
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Action")
	TArray<FName> ActionNames;

	UPROPERTY(EditAnywhere, Category="Enhanced Input")
	TArray<FMobileEnhancedInputData> InputActionsData;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Components")
	TArray<TObjectPtr<UFortMobileButtonBehaviorComponent>> ButtonBehaviorComponents;

protected:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Component Overrides")
	TArray<UFortButtonBehaviorComponentOverride*> ButtonBehaviorComponentOverrides;

};

