// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/QuickBar/FortQuickBarSlotBase.h"
#include "AthenaQuickBarSlot.generated.h"

class UImage;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaQuickBarSlot : public UFortQuickBarSlotBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetAdded(const EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

	UFUNCTION()
	void OnPawnChanged();

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_Disabled;

	UPROPERTY(BlueprintReadWrite, Category="AthenaQuickBarSlot")
	bool bIsSelected;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickBarSlot")
	FGameplayTag ShowDisabledTag;

};

