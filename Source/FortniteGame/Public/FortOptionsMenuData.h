// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "FortTypes.h"
#include "FortOptionsMenuData.generated.h"

class UUserWidget;

USTRUCT(BlueprintType)
struct FFortOptionsMenuData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortOptionsMenuData")
	ESettingTab OptionTabType;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenuData")
	bool bDisplayOption;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenuData")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenuData")
	FGameplayTag PageWidgetAlias;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenuData", meta=(AllowedClasses="/Script/FortniteUI.FortOptionsTab"))
	TSubclassOf<UUserWidget> PageWidgetClass;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenuData")
	FSlateBrush TabBrush;

};

