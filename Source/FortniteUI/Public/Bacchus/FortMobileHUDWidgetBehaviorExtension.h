// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortMobileHUDWidgetBehaviorExtension.generated.h"

class UFortMobileHudWidgetContentComponent;
class UHUDWidgetBehavior;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortMobileHUDWidgetBehaviorExtension : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Content Components")
	TArray<TObjectPtr<UFortMobileHudWidgetContentComponent>> HUDWidgetContentComponents;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UHUDWidgetBehavior> OwnerWidgetBehavior;

};

