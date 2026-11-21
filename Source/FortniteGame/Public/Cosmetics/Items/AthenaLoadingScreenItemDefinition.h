// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaLoadingScreenItemDefinition.generated.h"

class UObject;
class UTexture2D;
class UUserWidget;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaLoadingScreenItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual", meta=(DisplayName="Background Preview Image"))
	TSoftObjectPtr<UTexture2D> BackgroundImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> BackgroundMaterialOrTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual")
	TSoftClassPtr<UUserWidget> BackgroundWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual")
	FVector2D BackgroundDesiredSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual")
	FLinearColor BackgroundColor;

};

