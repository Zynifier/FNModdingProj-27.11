// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortLevelOverlayConfig.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FFortSourceWorldAndOverlayWorld
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSourceWorldAndOverlayWorld")
	bool bSpecifySourceWorld;

	UPROPERTY()
	FString SourceWorldString;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Overlay")
	TSoftObjectPtr<UWorld> OverlayWorld;

	UPROPERTY(EditAnywhere, Category="FortSourceWorldAndOverlayWorld")
	bool bServerOnly;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Overlay", meta=(EditCondition="bSpecifySourceWorld"))
	TSoftObjectPtr<UWorld> SourceWorld;
#endif

};

UCLASS(MinimalAPI, BlueprintType)
class UFortLevelOverlayConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Overlay")
	void GetOverlayList(TArray<FFortSourceWorldAndOverlayWorld>& OutOverlayList) const;

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Overlay", meta=(CallInEditor="true"))
	bool RemoveOverlaysForUncookedMaps(TArray<FString>& OutRemovedOverlays, FString& OutFailureReason);
#endif

private:
	UPROPERTY(EditAnywhere, Category="FortLevelOverlayConfig")
	TArray<FFortSourceWorldAndOverlayWorld> OverlayList;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortLevelOverlayConfig")
	TArray<FFortSourceWorldAndOverlayWorld> EditorOnlyOverlayList;
#endif

};

