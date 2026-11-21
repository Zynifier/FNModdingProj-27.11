// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "FabricScreenLayoutDataAsset.generated.h"

class UFabricScreenWidget;
class UFabricWidget;

USTRUCT(BlueprintType)
struct FFabricScreenLayout
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricScreenLayout")
	FVector2D GridPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricScreenLayout")
	FName UserOptionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricScreenLayout")
	TSubclassOf<UFabricWidget> FabricWidgetClass;

};

UCLASS(BlueprintType)
class UFabricScreenLayoutDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricScreenLayoutDataAsset")
	TArray<FFabricScreenLayout> Layout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricScreenLayoutDataAsset")
	TSubclassOf<UFabricScreenWidget> FabricScreenWidgetClass;

};

