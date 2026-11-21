// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Color.h"
#include "FortMultiActorVisTargetComponent.generated.h"

class AActor;

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortMultiActorVisualizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="FortMultiActorVisualizerComponent")
	TArray<AActor*> Targets;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="FortMultiActorVisualizerComponent")
	bool bShowVisualizer;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="FortMultiActorVisualizerComponent")
	FLinearColor ConnectionColor;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="FortMultiActorVisualizerComponent")
	float LineWidth;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="FortMultiActorVisualizerComponent")
	float MininumSize;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Parent Visualizer")
	FLinearColor ParentColor;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Parent Visualizer")
	float ParentRadiusScale;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Parent Visualizer")
	float ParentHeightScale;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Target Visualizer")
	FLinearColor TargetColor;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Target Visualizer")
	float TargetCapsuleRadiusScale;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Target Visualizer")
	float TargetCapsuleHeightScale;

};

