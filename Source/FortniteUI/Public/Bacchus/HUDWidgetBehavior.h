// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "HUDWidgetBehavior.generated.h"

class UFortMobileHUDWidgetBehaviorExtension;
class UFortMobileHudWidgetContentComponent;

UCLASS(Abstract, BlueprintType, Blueprintable)
class FORTNITEUI_API UHUDWidgetBehavior : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HUD Layout")
	FText HUDLayoutToolName;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Content Components")
	TArray<TObjectPtr<UFortMobileHudWidgetContentComponent>> HudWidgetContentComponents;

	UPROPERTY(EditDefaultsOnly, Category="Property Defaults Overrides")
	TMap<FGameplayTag, FString> CustomPropertyDefaultOverrides;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortMobileHUDWidgetBehaviorExtension>> BehaviorExtensions;

};

