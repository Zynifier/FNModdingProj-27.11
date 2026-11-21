// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimNodes/AnimNode_RandomPlayer.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/SoftObjectPath.h"
#include "FortAnimSet.generated.h"

class UAnimSequenceBase;
class UAnimationAsset;

USTRUCT()
struct FFortAnimSetRandomAnimation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FGameplayTagQuery Requirements;

	UPROPERTY(EditAnywhere, Category="Settings", meta=(ShowOnlyInnerProperties))
	FRandomPlayerSequenceEntry RandomEntry;

};

UCLASS(MinimalAPI)
class UFortAnimSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(Category="Config", meta=(CallInEditor="true"))
	void UpdateAssets();

	UFUNCTION(Category="Random", meta=(CallInEditor="true"))
	void UpdateReferencesInRandomSection();

	UPROPERTY(EditAnywhere, Category="Config", meta=(ContentDir))
	FDirectoryPath SourceRootPath;

	UPROPERTY(EditAnywhere, Category="Config", meta=(ContentDir))
	TArray<FDirectoryPath> TargetRootPathList;

	UPROPERTY(EditAnywhere, Category="Config")
	TObjectPtr<UAnimSequenceBase> FallbackSequence;

	UPROPERTY(VisibleAnywhere, Category="Warnings")
	TArray<FName> UniqueInSourceAssets;

	UPROPERTY(VisibleAnywhere, Category="Warnings")
	TArray<FName> UniqueInTargetAssets;

	UPROPERTY(EditAnywhere, Category="Random")
	TArray<FFortAnimSetRandomAnimation> RandomAnimations;

	UPROPERTY(VisibleAnywhere, Category="RemapList")
	TMap<FName, TObjectPtr<UAnimationAsset>> AssetRemapping;

};

