// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateTypes.h"
#include "FortUIStyleDefinition.generated.h"

USTRUCT(BlueprintType)
struct FFortUIStyleWindowButtons
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUIStyleWindowButtons")
	FButtonStyle Close;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUIStyleWindowButtons")
	FButtonStyle Minimize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUIStyleWindowButtons")
	FButtonStyle Maximize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUIStyleWindowButtons")
	FButtonStyle Restore;

};

USTRUCT(BlueprintType)
struct FFortUIStyleDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	FFortUIStyleWindowButtons WindowButtons;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"))
class UFortUIStyleDefinitionAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FFortUIStyleDefinition StyleDefinition;

};

