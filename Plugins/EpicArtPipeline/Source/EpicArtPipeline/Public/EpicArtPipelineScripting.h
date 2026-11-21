// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "EpicArtPipeline.h"
#include "EpicArtPipelineScripting.generated.h"

class ULevel;
class ULevelStreaming;
class USkeletalMeshComponent;
class UUserWidget;
class UWorld;

UCLASS(meta=(ScriptName="EpicArtPipelineTools"))
class EPICARTPIPELINE_API UEpicArtPipelineScripting : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="EpicArtPipeline", meta=(DevelopmentOnly))
	static void AddApplicationToMenu(FEpicArtApp AppToRegister);

	UFUNCTION(BlueprintCallable, Category="EpicArtPipeline", meta=(DevelopmentOnly))
	static ULevel* AddLevelsToWorld(UWorld* InWorld, TArray<FString> LevelPackageNames, TSubclassOf<ULevelStreaming> LevelStreamingClass);

	UFUNCTION(BlueprintCallable, Category="EpicArtPipeline", meta=(DevelopmentOnly, ScriptMethod))
	static void Click(UUserWidget* TargetButton);

	UFUNCTION(BlueprintCallable, Category="EpicArtPipeline", meta=(DevelopmentOnly, ScriptMethod))
	static void GetBoundingBox(USkeletalMeshComponent* TargetComponent, FVector& Origin, FVector& Extent);

	UFUNCTION(BlueprintCallable, Category="EpicArtPipeline", meta=(DevelopmentOnly, ScriptMethod))
	static void GetSkinnedPositions(USkeletalMeshComponent* TargetComponent, TArray<FVector>& OutPositions);

	UFUNCTION(BlueprintCallable, Category="EpicArtPipeline")
	static void ResetPipelineMenu();

};

