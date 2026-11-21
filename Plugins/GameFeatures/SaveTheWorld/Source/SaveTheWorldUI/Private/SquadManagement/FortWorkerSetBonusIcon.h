// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "FortBrushSize.h"
#include "FortWorkerSetBonusIcon.generated.h"

class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortWorkerSetBonusIcon : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SetBonusIcon")
	void SetGameplayTag(const FGameplayTag& InGameplayTag);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SetBonusIcon")
	FGameplayTag GameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SetBonusIcon")
	TEnumAsByte<EFortBrushSize::Type> ImageSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="SetBonusIcon", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Icon;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="SetBonusIcon")
	void HandleDifferentGameplayTagSetBP();

};

