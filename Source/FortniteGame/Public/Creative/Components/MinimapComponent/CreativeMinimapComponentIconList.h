// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "CreativeMinimapComponentIconList.generated.h"

class UCreativeMinimapComponentIcon;
class UCreativeMinimapComponentIconColorOverride;
class UMaterialInterface;

UENUM(BlueprintType)
enum class ECreativeMinimapComponentIconColorType : uint8
{
	None = 0,
	White = 1,
	Red = 2,
	Orange = 3,
	Yellow = 4,
	Green = 5,
	Teal = 6,
	Blue = 7,
	Purple = 8,
};

UCLASS(BlueprintType)
class UCreativeMinimapComponentIcon : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeMinimapComponentIcon")
	TSoftObjectPtr<UMaterialInterface> MaterialInterface;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeMinimapComponentIcon")
	FVector2D Size;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeMinimapComponentIcon")
	TArray<TObjectPtr<UCreativeMinimapComponentIconColorOverride>> ColorOverrides;

};

UCLASS(BlueprintType)
class UCreativeMinimapComponentIconColorOverride : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeMinimapComponentIconColorOverride")
	FName ParameterName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeMinimapComponentIconColorOverride")
	TMap<ECreativeMinimapComponentIconColorType, FLinearColor> Colors;

};

UCLASS(BlueprintType)
class UCreativeMinimapComponentIconList : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeMinimapComponentIconList")
	TArray<TObjectPtr<UCreativeMinimapComponentIcon>> Icons;

};

