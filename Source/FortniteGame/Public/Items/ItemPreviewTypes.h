// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ItemPreviewTypes.generated.h"

class UObject;

UENUM(BlueprintType)
enum class EBackgroundIntensityLevel : uint8
{
	None = 0 UMETA(Hidden),
	LowIntensity = 1,
	HighIntensity = 2,
};

USTRUCT()
struct FPreviewWorldMaterialParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PreviewWorldMaterialParams")
	FName DestinationParamName;

	UPROPERTY(EditDefaultsOnly, Category="PreviewWorldMaterialParams")
	FName SourceParamName;

};

USTRUCT(BlueprintType)
struct FVaultWorldBackgroundData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VaultWorldBackgroundData", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> BackgroundSubstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultWorldBackgroundData")
	FVector BackgroundOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultWorldBackgroundData")
	FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VaultWorldBackgroundData")
	FLinearColor SecondaryColor;

};

