// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RufusWeeklyMapUpdater.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;
class UTexture2D;

USTRUCT(BlueprintType)
struct FRufusWeeklyMapUpdaterInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Map")
	TSoftObjectPtr<UTexture2D> MapTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Map")
	TSoftObjectPtr<UTexture2D> MapOpacityTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Map")
	TSoftObjectPtr<UTexture2D> MapDiscoveryTexture;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class ARufusWeeklyMapUpdater : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetActiveWeekByIndex(int32 InWeekIndex);

protected:
	UFUNCTION(BlueprintCallable)
	void OverrideDiscoverabilityTexture(UMaterialInstanceDynamic* InStencilMID);

private:
	UPROPERTY(EditAnywhere, Category="RufusWeeklyMapUpdater")
	TArray<FRufusWeeklyMapUpdaterInfo> WeeklyMapTextureInfo;

	UPROPERTY(EditAnywhere, Category="RufusWeeklyMapUpdater")
	TObjectPtr<UMaterialInterface> StencilMaterial;

};

